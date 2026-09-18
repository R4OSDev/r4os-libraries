// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const r = @import("r4os");
const a = r.abi;
const nv = @import("r4nv_binding");
const Budget = @import("video_allocation").Budget;

pub const Error = error{ Invalid, Unsupported, NoMemory, Busy, Stale, Timeout, Internal };
pub const granule: u64 = 65536;
pub const address_limit: u64 = 1 << 40; // NVDEC method addresses, not the GPU's VA width.
const duration_ns: u64 = 5_000_000_000;
const modifier_base: u64 = 0x0300000000606010; // Uncompressed Turing generic kind 6.
pub const Clock = *const fn () ?a.MonotonicClockInfo;

fn payload(value: anytype) bool {
    return value.version == 1 and value.size >= @sizeOf(@TypeOf(value));
}
fn valid(value: a.GfxBufferHandle) bool {
    return value.id != 0 and value.generation != 0 and value.reserved0 == 0;
}
fn equal(left: anytype, right: @TypeOf(left)) bool {
    return std.meta.eql(left, right);
}
fn result(rc: i32) Error!void {
    return switch (rc) {
        1 => {},
        a.gfx_buffer_error_oom, a.gfx_buffer_error_budget, a.gfx_buffer_error_capacity => error.NoMemory,
        a.gfx_buffer_error_busy => error.Busy,
        a.gfx_buffer_error_stale, a.gfx_buffer_error_closed, a.gfx_queue_error_device_lost => error.Stale,
        a.gfx_queue_error_wait_timeout, a.gfx_queue_error_wait_cancelled => error.Timeout,
        a.gfx_buffer_error_unsupported, a.gfx_buffer_error_unavailable, a.err_no_fn, a.err_no_group => error.Unsupported,
        a.gfx_buffer_error_invalid, a.gfx_buffer_error_overflow => error.Invalid,
        else => error.Internal,
    };
}
fn rounded(bytes: u64) Error!usize {
    if (bytes == 0 or bytes > address_limit - granule) return error.Invalid;
    return @intCast(std.mem.alignForward(u64, bytes, granule));
}
fn extent(offset: u64, bytes: u64, limit: u64) bool {
    return bytes != 0 and bytes <= limit and offset <= limit - bytes;
}

pub const Device = struct {
    binding: a.GfxBackendBinding,
    memory_generation: u64,
    va_start: u64,
    va_end: u64,
    class: u32,

    // Architecture selects a packet format. Actual engine/class admission is
    // performed by the native queue on submission; no GR template is required.
    pub fn query(base: r.program.Context, adapter: u32) Error!Device {
        if (adapter == 0) return error.Invalid;
        const q: r.gfx_queue.Context = .{ .base = base };
        var found: ?a.GfxBackendInfo = null;
        for (0..a.gfx_queue_backend_capacity) |index| {
            var info: a.GfxBackendInfo = .{};
            const rc = q.backendInfo(@intCast(index), &info);
            if (rc == 0) break;
            try result(rc);
            if (!payload(info) or !payload(info.binding)) return error.Internal;
            if (info.binding.adapter_id == adapter) {
                found = info;
                break;
            }
        }
        const info = found orelse return error.Unsupported;
        const profile = info.profile;
        if (info.binding.milestone != a.gfx_queue_milestone_device_execution or
            info.binding.device_generation == 0 or info.binding.reset_generation == 0 or info.memory_generation == 0 or
            info.operations & (@as(u64, 1) << a.gfx_queue_operation_native) == 0 or
            !payload(profile) or profile.interface_id_lo != nv.backend_v1_header.interface_id_lo or
            profile.interface_id_hi != nv.backend_v1_header.interface_id_hi or profile.revision != 1 or
            profile.data_bytes != @sizeOf(nv.R4NvDriverProfile)) return error.Unsupported;
        const protocol = std.mem.bytesToValue(nv.R4NvDriverProfile, profile.data[0..@sizeOf(nv.R4NvDriverProfile)]);
        if (!payload(protocol) or protocol.vendor_id != 0x10de or protocol.rm_release != nv.rm_release or
            protocol.command_abi != nv.command_abi or protocol.reserved0 != 0 or protocol.reserved1 != 0) return error.Unsupported;
        var properties: a.GfxBackendProperties = .{};
        try result(q.backendProperties(&info.binding, &properties));
        if (!payload(properties) or properties.interface_id_lo != profile.interface_id_lo or
            properties.interface_id_hi != profile.interface_id_hi or properties.revision != nv.architecture_version or
            properties.data_bytes != @sizeOf(nv.R4NvArchitecture)) return error.Unsupported;
        for (properties.data[properties.data_bytes..]) |byte| if (byte != 0) return error.Invalid;
        const arch = std.mem.bytesToValue(nv.R4NvArchitecture, properties.data[0..@sizeOf(nv.R4NvArchitecture)]);
        const class: u32 = switch (arch.chipset) {
            0x172, 0x173, 0x174, 0x176, 0x177 => 0xc7b0,
            0x192, 0x193, 0x194, 0x196, 0x197 => 0xc9b0,
            else => return error.Unsupported,
        };
        // This path uses persistent write-back system BOs. Require the driver's
        // acknowledged CPU/GPU coherency policy, never infer it from PCI IDs.
        const flags = nv.architecture_image_layouts | nv.architecture_host_coherent;
        if (arch.version != properties.revision or arch.size != @sizeOf(nv.R4NvArchitecture) or
            arch.vendor_id != 0x10de or arch.rm_release != nv.rm_release or arch.flags != flags or
            arch.bind_alignment != granule or arch.va_start == 0 or arch.va_start >= arch.va_end or
            arch.va_start >= address_limit or arch.va_end > (@as(u64, 1) << 49) or
            (arch.va_start | arch.va_end) % granule != 0) return error.Unsupported;
        if (arch.memory_generation != info.memory_generation) return error.Stale;
        return .{ .binding = info.binding, .memory_generation = arch.memory_generation,
            .va_start = arch.va_start, .va_end = @min(arch.va_end, address_limit), .class = class };
    }
};

// Stable, single-worker owner. Every Resource borrows this Context and its
// budget until close succeeds. The caller retains both through all FFmpeg and
// public frame loans. Failed operations leave exact handles for later cleanup.
pub const Context = struct {
    base: r.program.Context,
    device: Device,
    budget: *Budget,
    clock: Clock,
    queue: a.GfxQueueHandle = .{},
    fence: a.GfxFence = .{},
    poisoned: bool = false,

    fn buffers(self: *const Context) r.gfx_buffers.Context {
        return .{ .base = self.base };
    }
    fn queues(self: *const Context) r.gfx_queue.Context {
        return .{ .base = self.base };
    }
    fn instant(self: *const Context) Error!a.MonotonicClockInfo {
        const clock = self.clock() orelse return error.Internal;
        if (clock.flags & a.monotonic_clock_flag_valid == 0 or clock.frequency_hz != 1_000_000_000 or
            clock.event_frequency_numerator == 0 or clock.event_frequency_denominator == 0) return error.Internal;
        return clock;
    }
    pub fn deadline(self: *const Context) Error!u64 {
        return std.math.add(u64, (try self.instant()).instant_ns, duration_ns) catch error.Internal;
    }
    fn ticks(self: *const Context, until: u64) Error!u64 {
        const clock = try self.instant();
        if (until <= clock.instant_ns) return error.Timeout;
        const numerator: u128 = @as(u128, until - clock.instant_ns) * clock.event_frequency_numerator;
        const denominator: u128 = @as(u128, clock.event_frequency_denominator) * 1_000_000_000;
        return @intCast(@min((numerator + denominator - 1) / denominator, std.math.maxInt(u64) - 1));
    }

    pub const Loan = struct { resource: *const Resource, write: bool };
    // All indirect references (DPB, status, scratch and commands) are listed.
    // The common broker snapshots independent BO/VA loans before returning.
    pub fn submit(self: *Context, commands: *const Resource, command_bytes: u32, loans: []const Loan) Error!void {
        if (self.poisoned) return error.Stale;
        if (self.fence.timeline != 0) return error.Busy;
        if (!commands.ready or commands.owner != self or command_bytes == 0 or command_bytes % 4 != 0 or
            command_bytes > commands.descriptor.byte_length or loans.len > 63) return error.Invalid;
        var bindings: [64]a.GfxNativeResource = undefined;
        bindings[0] = .{ .binding = commands.binding };
        var count: usize = 1;
        for (loans) |loan| {
            const resource = loan.resource;
            if (!resource.ready or resource.owner != self or !valid(resource.binding)) return error.Invalid;
            var duplicate = false;
            for (bindings[0..count]) |*entry| if (equal(entry.binding, resource.binding)) {
                entry.access |= @intFromBool(loan.write);
                duplicate = true;
                break;
            };
            if (!duplicate) {
                bindings[count] = .{ .binding = resource.binding, .access = @intFromBool(loan.write) };
                count += 1;
            }
        }
        const until = try self.deadline();
        if (self.queue.timeline == 0) {
            const binding = self.device.binding;
            try result(self.queues().open(&.{ .adapter_id = binding.adapter_id, .capacity = 1,
                .milestone = binding.milestone, .device_generation = binding.device_generation,
                .reset_generation = binding.reset_generation }, &self.queue));
            if (!payload(self.queue) or self.queue.timeline == 0) return error.Internal;
        }
        const packet = extern struct { header: nv.R4NvNativeSubmitHeader, push: nv.R4NvNativePush }{
            .header = .{ .version = nv.native_submit_version, .size = @sizeOf(nv.R4NvNativeSubmitHeader),
                .engine_mask = nv.native_engine_video, .push_count = 1, .reserved0 = 0, .reserved1 = 0 },
            .push = .{ .address = commands.address, .byte_length = command_bytes, .flags = 0 },
        };
        const submission: a.GfxSubmission = .{ .operation = a.gfx_queue_operation_native, .deadline_ns = until };
        const native: a.GfxNativeSubmission = .{ .interface_id_lo = nv.backend_v1_header.interface_id_lo,
            .interface_id_hi = nv.backend_v1_header.interface_id_hi, .revision = 1,
            .command_bytes = @sizeOf(@TypeOf(packet)), .commands = @intFromPtr(&packet),
            .resource_count = @intCast(count), .resources = @intFromPtr(&bindings) };
        // WB stores precede the doorbell; the driver owns HOST WFI/SYS_MEMBAR
        // and semaphore completion. No MMIO or private physical pinning here.
        asm volatile ("mfence" ::: .{ .memory = true });
        var status: a.GfxFenceStatus = .{};
        try result(self.queues().submitNative(&self.queue, &submission, &native, &status));
        self.fence = status.fence;
        errdefer self.poisoned = true;
        if (!self.matches(status) or status.deadline_ns != until) return error.Internal;
        try self.wait(until);
    }
    fn matches(self: *const Context, status: a.GfxFenceStatus) bool {
        return payload(status) and equal(status.fence, self.fence) and self.fence.adapter_id == self.device.binding.adapter_id and
            self.fence.timeline == self.queue.timeline and self.fence.point != 0 and
            self.fence.device_generation == self.device.binding.device_generation and
            self.fence.reset_generation == self.device.binding.reset_generation and
            status.milestone == a.gfx_queue_milestone_device_execution and
            status.flags & ~@as(u32, 3) == 0 and status.phase <= a.gfx_queue_phase_terminal;
    }
    fn wait(self: *Context, until: u64) Error!void {
        var status: a.GfxFenceStatus = .{};
        try result(self.queues().wait(&self.fence, try self.ticks(until), a.gfx_queue_wait_resources_released, &status));
        if (!self.matches(status) or status.phase != a.gfx_queue_phase_terminal or status.flags != 0) return error.Internal;
        try result(self.queues().release(&self.fence));
        self.fence = .{};
        if (status.result != a.gfx_queue_result_complete) return switch (status.result) {
            a.gfx_queue_result_timeout, a.gfx_queue_result_cancelled => error.Timeout,
            a.gfx_queue_result_device_lost => error.Stale,
            else => error.Internal,
        };
        asm volatile ("mfence" ::: .{ .memory = true });
        // This is only ordered engine completion. The NVDEC owner must inspect
        // fresh picture status before publishing pixels or reusing scratch.
    }
    pub fn close(self: *Context) Error!void {
        self.poisoned = true;
        if (self.fence.timeline != 0) {
            var status: a.GfxFenceStatus = .{};
            try result(self.queues().query(&self.fence, &status));
            if (!self.matches(status)) return error.Internal;
            if (status.phase != a.gfx_queue_phase_terminal) {
                const rc = self.queues().cancel(&self.fence);
                if (rc != a.gfx_queue_error_already_completed) try result(rc);
                return error.Busy;
            }
            if (status.flags != 0) return error.Busy;
            try result(self.queues().release(&self.fence));
            self.fence = .{};
        }
        if (self.queue.timeline != 0) {
            try result(self.queues().close(&self.queue));
            self.queue = .{};
        }
    }
};

pub const Resource = struct {
    owner: ?*Context = null,
    backing: a.GfxBufferReference = .{},
    descriptor: a.GfxBufferDescriptor = .{},
    mapping: a.GfxBufferMap = .{},
    pending: a.GfxBufferHandle = .{},
    range: a.GfxBufferHandle = .{},
    binding: a.GfxBufferHandle = .{},
    address: u64 = 0,
    charged: usize = 0,
    ready: bool = false,
    retiring: bool = false,

    fn begin(self: *Resource, ctx: *Context, bytes: usize) Error!u64 {
        if (self.owner != null) return error.Busy;
        if (ctx.poisoned) return error.Stale;
        const until = try ctx.deadline();
        if (!ctx.budget.reserve(bytes)) return error.NoMemory;
        self.owner = ctx;
        self.charged = bytes;
        return until;
    }
    pub fn system(self: *Resource, ctx: *Context, bytes: u64) Error!void {
        const size = try rounded(bytes);
        const until = try self.begin(ctx, size);
        const requested: a.GfxBufferDescriptor = .{ .byte_length = size, .alignment = granule,
            .usage = a.gfx_buffer_usage_cpu_read | a.gfx_buffer_usage_cpu_write |
                a.gfx_buffer_usage_transfer_source | a.gfx_buffer_usage_transfer_target };
        try result(ctx.buffers().create(&requested, &self.backing));
        try self.describe(false);
        if (self.descriptor.format != a.gfx_buffer_format_bytes or self.descriptor.plane_count != 0 or
            self.descriptor.modifier != 0 or self.descriptor.byte_length != size) return error.Invalid;
        try result(ctx.buffers().mapPersistent(&self.backing.reference, a.gfx_buffer_map_write, 0, size, &self.mapping));
        if (!payload(self.mapping) or !valid(self.mapping.lease) or self.mapping.cpu_address == 0 or
            self.mapping.byte_length != size or self.mapping.cpu_address > std.math.maxInt(usize) - size or
            self.mapping.cache_policy != a.gfx_buffer_cache_write_back or self.mapping.reserved0 != 0) return error.Unsupported;
        @memset(@as([*]u8, @ptrFromInt(self.mapping.cpu_address))[0..size], 0);
        try self.bind(until);
    }
    pub fn video(self: *Resource, ctx: *Context, bytes: u64) Error!void {
        const size = try rounded(bytes);
        const until = try self.begin(ctx, size);
        try self.native(.{ .byte_length = size, .usage = 12 }, until);
        try self.describe(true);
        if (self.descriptor.format != a.gfx_buffer_format_bytes or self.descriptor.plane_count != 0 or
            self.descriptor.modifier != 0 or self.descriptor.byte_length != size) return error.Invalid;
        try self.bind(until);
    }
    pub fn nv12(self: *Resource, ctx: *Context, width: u32, height: u32) Error!void {
        if (width == 0 or height == 0 or width > 4096 or height > 4096 or (width | height) % 16 != 0) return error.Invalid;
        // Native allocation chooses an authenticated modifier. At least 32
        // storage rows guarantee >=2 GOBs for NVDEC even for a 16-row picture.
        const storage_height = @max(height, 32);
        const pitch = std.mem.alignForward(u64, width, 64);
        const upper = try rounded(pitch * std.mem.alignForward(u64, storage_height, 256));
        const chroma_upper = try rounded(pitch * std.mem.alignForward(u64, storage_height / 2, 256));
        const until = try self.begin(ctx, upper + chroma_upper);
        try self.native(.{ .kind = 1, .width = width, .height = storage_height,
            .format = a.gfx_buffer_format_nv12, .usage = 28, .layout = 1 }, until);
        try self.describe(true);
        const d = self.descriptor;
        if (d.format != a.gfx_buffer_format_nv12 or d.plane_count != 2 or d.width != width or d.height != storage_height or
            d.modifier & ~@as(u64, 15) != modifier_base or d.modifier & 15 < 1 or d.modifier & 15 > 5 or
            d.plane_pitches[0] != pitch or d.plane_pitches[1] != pitch or d.plane_offsets[0] != 0 or
            d.plane_offsets[1] % granule != 0 or d.plane_offsets[2] != 0 or d.plane_offsets[3] != 0 or
            d.plane_pitches[2] != 0 or d.plane_pitches[3] != 0) return error.Unsupported;
        const block_rows: u64 = @as(u64, 8) << @intCast(d.modifier & 15);
        const luma = pitch * std.mem.alignForward(u64, storage_height, block_rows);
        const chroma = pitch * std.mem.alignForward(u64, storage_height / 2, block_rows);
        if (d.plane_offsets[1] < luma or !extent(0, luma, d.byte_length) or
            !extent(d.plane_offsets[1], chroma, d.byte_length)) return error.Invalid;
        try self.bind(until);
    }
    fn native(self: *Resource, allocation: a.GfxNativeAllocation, until: u64) Error!void {
        const ctx = self.owner.?;
        var request = allocation;
        request.adapter_id = ctx.device.binding.adapter_id;
        request.memory_generation = ctx.device.memory_generation;
        request.deadline_ns = until;
        var status: a.GfxNativeStatus = .{};
        try result(ctx.buffers().nativeStart(&request, &status));
        self.pending = status.request;
        if (!valid(self.pending)) return error.Internal;
        try result(ctx.buffers().nativeWait(&self.pending, try ctx.ticks(until), &status));
        if (!payload(status) or !equal(status.request, self.pending) or status.phase != 2 or
            status.deadline_ns != until or status.reserved0 != 0 or status.flags != 0) return error.Internal;
        try result(status.result);
        try result(ctx.buffers().nativeReceive(&self.pending, &self.backing));
        self.pending = .{}; // Receive consumes the request.
    }
    fn describe(self: *Resource, device_local: bool) Error!void {
        const ctx = self.owner.?;
        if (!payload(self.backing) or !valid(self.backing.reference) or !valid(self.backing.buffer) or
            self.backing.flags != 0 or self.backing.reserved0 != 0) return error.Internal;
        try result(ctx.buffers().describe(&self.backing.reference, &self.descriptor));
        const d = self.descriptor;
        if (!payload(d) or d.reserved0 != 0 or d.byte_length == 0 or d.byte_length > self.charged or
            d.byte_length % granule != 0 or d.alignment < granule or !std.math.isPowerOfTwo(d.alignment) or
            d.usage & 12 != 12) return error.Invalid;
        if (device_local) {
            if (d.location != a.gfx_buffer_location_device_local or d.adapter_id != ctx.device.binding.adapter_id or
                d.device_generation != ctx.device.memory_generation or d.driver_owner == 0 or d.usage & 3 != 0) return error.Stale;
        } else if (d.location != a.gfx_buffer_location_system or d.adapter_id != 0 or d.driver_owner != 0 or
            d.device_generation != 0 or d.usage & 3 != 3) return error.Invalid;
        const excess = self.charged - @as(usize, @intCast(d.byte_length));
        if (excess != 0) ctx.budget.release(excess);
        self.charged = @intCast(d.byte_length);
    }
    fn virtual(self: *Resource, request: a.GfxVirtualRequest, output: *a.GfxBufferHandle, expected: u64) Error!u64 {
        const ctx = self.owner.?;
        var status: a.GfxVirtualStatus = .{};
        try result(ctx.base.gfxVirtualStart(&request, &status));
        output.* = status.resource;
        if (!valid(output.*)) return error.Internal;
        try result(ctx.base.gfxVirtualWait(output, 0, try ctx.ticks(request.deadline_ns), &status));
        if (!payload(status) or !equal(status.resource, output.*) or !equal(status.parent, request.parent) or
            status.reserved0 != 0 or status.kind != request.kind or status.byte_length != request.byte_length or
            status.deadline_ns != request.deadline_ns or status.flags & 1 == 0 or status.flags & ~@as(u32, 15) != 0) return error.Internal;
        try result(status.result);
        if (status.flags != 1 or status.address % granule != 0 or status.address < ctx.device.va_start or
            !extent(status.address, status.byte_length, ctx.device.va_end) or
            (expected != 0 and expected != status.address)) return error.Unsupported;
        return status.address;
    }
    fn bind(self: *Resource, until: u64) Error!void {
        const ctx = self.owner.?;
        const d = self.descriptor;
        var request: a.GfxVirtualRequest = .{ .kind = 1, .adapter_id = ctx.device.binding.adapter_id,
            .memory_generation = ctx.device.memory_generation, .deadline_ns = until,
            .byte_length = d.byte_length, .alignment = granule,
            .location = @intFromBool(d.location == a.gfx_buffer_location_device_local),
            .flags = if (d.modifier != 0) a.gfx_virtual_flag_blocklinear | (6 << a.gfx_virtual_layout_shift) else 0 };
        // RM chooses the VA; reject an out-of-range result before encoding any
        // 40-bit method. Fixed addresses must never collide with another client.
        self.address = try self.virtual(request, &self.range, 0);
        request.kind = 2;
        request.flags = 0;
        request.alignment = 0;
        request.location = 0;
        request.parent = self.range;
        request.reference = self.backing.reference;
        _ = try self.virtual(request, &self.binding, self.address);
        self.ready = true;
    }
    pub fn mappedBytes(self: *Resource) Error![]u8 {
        if (!self.ready or self.owner == null or self.owner.?.poisoned or self.owner.?.fence.timeline != 0 or
            !valid(self.mapping.lease)) return error.Busy;
        return @as([*]u8, @ptrFromInt(self.mapping.cpu_address))[0..@intCast(self.mapping.byte_length)];
    }
    // Used only by the decoder worker when replacing sequence scratch. All
    // resources share one deadline; the GUI-facing retirement path uses close.
    pub fn closeUntil(self: *Resource, until: u64) Error!void {
        self.close() catch |err| {
            if (err != error.Busy or !self.retiring or !valid(self.range)) return err;
            const ctx = self.owner.?;
            var status: a.GfxVirtualStatus = .{};
            try result(ctx.base.gfxVirtualWait(&self.range, 1, try ctx.ticks(until), &status));
            try self.close();
        };
    }
    pub fn close(self: *Resource) Error!void {
        const ctx = self.owner orelse return;
        self.ready = false;
        // Parent close retires every child and owns any late successful map.
        // Wait for the distinct retirement ACK, not the old creation result.
        if (valid(self.range)) {
            if (!self.retiring) {
                try result(ctx.base.gfxVirtualClose(&self.range, 0));
                self.retiring = true;
            }
            var status: a.GfxVirtualStatus = .{};
            try result(ctx.base.gfxVirtualQuery(&self.range, &status));
            if (!payload(status) or !equal(status.resource, self.range)) return error.Internal;
            if (status.flags & 6 != 6) return error.Busy;
            if (status.flags & ~@as(u32, 7) != 0) return error.Internal;
            try result(ctx.base.gfxVirtualClose(&self.range, 1));
            self.range = .{};
            self.binding = .{};
        }
        if (valid(self.mapping.lease)) {
            try result(ctx.buffers().unmap(&self.mapping.lease));
            self.mapping = .{};
        }
        if (valid(self.pending)) {
            // On timeout nativeClose transfers late allocation cleanup to the
            // resident broker. There is no caller pointer in that request.
            try result(ctx.buffers().nativeClose(&self.pending));
            self.pending = .{};
        }
        if (valid(self.backing.reference)) {
            try result(ctx.buffers().release(&self.backing.reference));
            self.backing = .{};
        }
        ctx.budget.release(self.charged);
        self.* = .{};
    }
};

//! Caller-owned graphics state. No global app context or shared allocator.
//! Backend selection, immutable source retention and logical resource lifetime
//! live here; the common queue and R4D own physical execution and retirement.
const std = @import("std");
const r4os = @import("r4os");
const a = r4os.abi;
pub const c = @import("r4l_contract");
const nv = @import("r4nv_binding");
const live_magic: u64 = 0x5234474658444556;
const closed_magic: u64 = 0x5234474658434c53;
pub const Error = error{ Invalid, Unsupported, Overflow, Limit, Alias, Busy, Stale, Unavailable };
const empty_image = std.mem.zeroes(c.R4GfxCpuImage);
const empty_resource = std.mem.zeroes(c.R4GfxResource);

pub fn code(err: Error) i32 {
    return switch (err) {
        error.Invalid => c.status_invalid, error.Unsupported => c.status_unsupported,
        error.Overflow => c.status_overflow, error.Limit => c.status_limit,
        error.Alias => c.status_alias, error.Busy => c.status_busy,
        error.Stale => c.status_stale, error.Unavailable => c.status_unavailable,
    };
}
pub fn platform(rc: i32) Error!void {
    return switch (rc) {
        a.gfx_buffer_result_ok => {},
        a.gfx_buffer_error_busy => error.Busy,
        a.gfx_buffer_error_stale, a.gfx_buffer_error_closed, a.gfx_queue_error_device_lost => error.Stale,
        a.gfx_buffer_error_unsupported => error.Unsupported,
        a.gfx_buffer_error_overflow => error.Overflow,
        a.gfx_buffer_error_oom, a.gfx_buffer_error_capacity, a.gfx_buffer_error_budget => error.Limit,
        a.err_no_fn, a.err_no_group, a.gfx_buffer_error_unavailable => error.Unavailable,
        else => error.Invalid,
    };
}
pub fn pointer(comptime T: type, address: u64) Error!*T {
    if (address == 0 or address % @alignOf(T) != 0 or address > std.math.maxInt(u64) - @sizeOf(T)) return error.Invalid;
    return @ptrFromInt(address);
}
pub fn overlaps(left: u64, bytes: u64, right: u64, count: u64) bool {
    const end = std.math.add(u64, left, bytes) catch return true;
    const other_end = std.math.add(u64, right, count) catch return true;
    return bytes != 0 and count != 0 and left < other_end and right < end;
}
pub fn outputSafe(comptime T: type, output: *T, device: *Device) Error!void {
    _ = try pointer(T, @intFromPtr(output));
    if (overlaps(@intFromPtr(output), @sizeOf(T), @intFromPtr(device), @sizeOf(Device))) return error.Alias;
}
fn separateInput(input: anytype, output: anytype) Error!void {
    if (overlaps(@intFromPtr(input), @sizeOf(@typeInfo(@TypeOf(input)).pointer.child),
        @intFromPtr(output), @sizeOf(@typeInfo(@TypeOf(output)).pointer.child))) return error.Alias;
}
pub const Resource = struct {
    serial: u64 = 0,
    kind: u32 = 0,
    flags: u32 = 0,
    source_kind: u32 = 0,
    source_generation: u64 = 0,
    source_key: struct { id: u64 = 0, generation: u64 = 0 } = .{},
    public_refs: u32 = 0,
    job_refs: u32 = 0,
    invalidated: bool = false,
    sampler: u32 = 0,
    operation: u32 = 0,
    image: c.R4GfxCpuImage = empty_image,
    backing: a.GfxBufferReference = .{},
    descriptor: a.GfxBufferDescriptor = .{},
    map: a.GfxBufferMap = .{},
};
pub const Job = struct {
    serial: u64 = 0,
    source: c.R4GfxResource = empty_resource,
    target: c.R4GfxResource = empty_resource,
    fence: a.GfxFence = .{},
    backend: u32 = 0,
    bytes: u64 = 0,
    counted: bool = false,
};
pub const Device = struct {
    // These two fields persist through close so reopening cannot revive handles.
    magic: u64 = 0,
    generation: u64 = 0,
    self_address: u64 = 0,
    bundle: r4os.program.Bundle = undefined,
    closing: bool = false,
    preferred_adapter: u32 = 0,
    flags: u32 = 0,
    resource_serial: u64 = 0,
    job_serial: u64 = 0,
    selected: a.GfxBackendInfo = .{ .binding = .{ .device_generation = 1, .reset_generation = 1 } },
    queue: a.GfxQueueHandle = .{},
    retired_queues: [c.device_job_capacity]a.GfxQueueHandle = @splat(.{}),
    counters: c.R4GfxDeviceInfo = std.mem.zeroes(c.R4GfxDeviceInfo),
    resources: [c.device_resource_capacity]Resource = @splat(.{}),
    jobs: [c.device_job_capacity]Job = @splat(.{}),
    // Per-device scratch avoids large render arrays on an application stack.
    images: [c.render_max_images]c.R4GfxCpuImage = undefined,
    image_slots: [c.render_max_images]u32 = undefined,
    image_writes: [c.render_max_images]bool = undefined,
    commands: [c.render_max_commands]c.R4GfxCpuDraw = undefined,

    pub fn base(self: *Device) r4os.program.Context { return .initBundle(&self.bundle); }
    pub fn buffers(self: *Device) r4os.gfx_buffers.Context { return .{ .base = self.base() }; }
    pub fn queues(self: *Device) r4os.gfx_queue.Context { return .{ .base = self.base() }; }
    pub fn backend(self: *const Device) u32 { return if (self.selected.binding.adapter_id == 0) c.render_backend_software else c.render_backend_nvidia; }
    pub fn resource(self: *Device, handle: c.R4GfxResource, public: bool) Error!*Resource {
        if (handle.device_address != self.self_address or handle.device_generation != self.generation or handle.slot == 0 or handle.slot > self.resources.len) return error.Stale;
        const item = &self.resources[handle.slot - 1];
        if (item.serial == 0 or item.serial != handle.generation or item.kind != handle.kind or (public and item.public_refs == 0)) return error.Stale;
        return item;
    }
    pub fn resourceHandle(self: *const Device, index: usize) c.R4GfxResource {
        const item = &self.resources[index];
        return .{ .slot = @intCast(index + 1), .kind = item.kind, .generation = item.serial, .device_generation = self.generation, .device_address = self.self_address };
    }
    pub fn job(self: *Device, handle: c.R4GfxJob) Error!*Job {
        if (handle.device_address != self.self_address or handle.device_generation != self.generation or handle.reserved != 0 or handle.slot == 0 or handle.slot > self.jobs.len) return error.Stale;
        const item = &self.jobs[handle.slot - 1];
        if (item.serial == 0 or item.serial != handle.generation) return error.Stale;
        return item;
    }
    pub fn cleanResource(self: *Device, item: *Resource) bool {
        const memory = self.buffers();
        if (item.map.lease.id != 0) {
            if (memory.unmap(&item.map.lease) != a.gfx_buffer_result_ok) return false;
            item.map = .{};
        }
        if (item.public_refs != 0 or item.job_refs != 0) return true;
        if (item.backing.reference.id != 0 and memory.release(&item.backing.reference) != a.gfx_buffer_result_ok) return false;
        item.* = .{};
        return true;
    }
    pub fn cleanResources(self: *Device) bool {
        var okay = true;
        for (&self.resources) |*item| if (!self.cleanResource(item)) { okay = false; };
        return okay;
    }
    fn closeQueue(self: *Device) Error!void {
        if (self.queue.timeline == 0) return;
        for (&self.jobs) |*item| if (item.serial != 0 and item.fence.timeline == self.queue.timeline) {
            // Common close drops client fence references. Keep this queue open
            // until all exact job receipts have been observed and released.
            for (&self.retired_queues) |*retired| if (retired.timeline == 0) {
                retired.* = self.queue;
                self.queue = .{};
                return;
            };
            return error.Limit;
        };
        const queue_api = self.queues();
        const rc = queue_api.close(&self.queue);
        if (rc != a.gfx_queue_error_stale) try platform(rc);
        self.queue = .{};
    }
    pub fn drainQueues(self: *Device) bool {
        const queue_api = self.queues();
        var okay = true;
        next: for (&self.retired_queues) |*retired| {
            if (retired.timeline == 0) continue;
            for (&self.jobs) |*item| if (item.serial != 0 and item.fence.timeline == retired.timeline) {
                okay = false;
                continue :next;
            };
            const rc = queue_api.close(retired);
            if (rc == a.gfx_queue_ok or rc == a.gfx_queue_error_stale) retired.* = .{} else { okay = false; }
        }
        return okay;
    }
    pub fn ensureQueue(self: *Device) Error!void {
        if (self.queue.timeline != 0) return;
        const value = self.selected.binding;
        const queue_api = self.queues();
        try platform(queue_api.open(&.{ .adapter_id = value.adapter_id, .device_generation = value.device_generation,
            .reset_generation = value.reset_generation, .milestone = value.milestone, .capacity = c.device_job_capacity }, &self.queue));
    }
    pub fn selectBackend(self: *Device) Error!void {
        var candidate: a.GfxBackendInfo = .{ .binding = .{ .device_generation = 1, .reset_generation = 1 } };
        const backend_client: ?nv.BackendV1Client = if (self.flags & c.device_software_only != 0) null else nv.BackendV1Client.init(self.bundle.raw) catch null;
        if (backend_client) |client| {
            const queue_api = self.queues();
            for (1..a.gfx_queue_backend_capacity) |index| {
                var snapshot: a.GfxBackendInfo = .{};
                if (queue_api.backendInfo(@intCast(index), &snapshot) != a.gfx_queue_ok) continue;
                const profile = snapshot.profile;
                const binding = snapshot.binding;
                if (snapshot.version != 1 or snapshot.size < @sizeOf(a.GfxBackendInfo) or binding.version != 1 or binding.size < @sizeOf(a.GfxBackendBinding) or
                    binding.adapter_id == 0 or binding.device_generation == 0 or binding.reset_generation == 0 or binding.milestone != a.gfx_queue_milestone_device_execution or
                    (self.preferred_adapter != 0 and binding.adapter_id != self.preferred_adapter) or
                    profile.version != 1 or profile.size < @sizeOf(a.GfxBackendProfile) or profile.interface_id_lo != nv.backend_v1_header.interface_id_lo or
                    profile.interface_id_hi != nv.backend_v1_header.interface_id_hi or profile.revision != nv.backend_v1_revision or profile.data_bytes != @sizeOf(nv.R4NvDriverProfile)) continue;
                const details = std.mem.bytesToValue(nv.R4NvDriverProfile, profile.data[0..@sizeOf(nv.R4NvDriverProfile)]);
                if (details.version != 1 or details.size != @sizeOf(nv.R4NvDriverProfile) or details.reserved0 != 0 or details.reserved1 != 0) continue;
                var features: nv.R4NvFeatures = undefined;
                if (client.negotiate(&.{ .version = 1, .size = @sizeOf(nv.R4NvDeviceProfile), .vendor_id = details.vendor_id,
                    .copy_class = details.copy_class, .rm_release = details.rm_release, .command_abi = details.command_abi,
                    .adapter_id = binding.adapter_id, .flags = 0, .device_generation = binding.device_generation, .reset_generation = binding.reset_generation }, &features) != nv.status_ok or
                    features.version != 1 or features.size != @sizeOf(nv.R4NvFeatures) or features.features & nv.feature_copy_linear == 0 or features.reserved != 0) continue;
                candidate = snapshot;
                break;
            }
        }
        if (std.meta.eql(self.selected, candidate)) return;
        const previous = self.selected.binding;
        _ = self.drainQueues();
        try self.closeQueue();
        self.selected = candidate;
        // The exact returned generation must still be openable. A raced reset
        // gives software fallback; no cached profile alone authorizes work.
        if (candidate.binding.adapter_id != 0) self.ensureQueue() catch {
            self.selected = .{ .binding = .{ .device_generation = 1, .reset_generation = 1 } };
        };
        const current = self.selected.binding;
        for (&self.resources) |*item| if (item.serial != 0 and item.descriptor.location == a.gfx_buffer_location_device_local) {
            if (item.descriptor.adapter_id != current.adapter_id or item.descriptor.device_generation != current.device_generation or
                (item.descriptor.adapter_id == previous.adapter_id and previous.reset_generation != current.reset_generation)) item.invalidated = true;
        };
        self.counters.backend_changes +|= 1;
    }
    pub fn info(self: *Device) c.R4GfxDeviceInfo {
        var value = self.counters;
        value.version = 1; value.size = @sizeOf(c.R4GfxDeviceInfo); value.generation = self.generation;
        value.adapter_id = self.selected.binding.adapter_id; value.backend = self.backend();
        value.device_generation = self.selected.binding.device_generation; value.reset_generation = self.selected.binding.reset_generation;
        value.formats = c.render_format_xrgb8888 | c.render_format_argb8888 | c.render_format_r8;
        value.operations = c.render_operation_fill | c.render_operation_blit | c.render_operation_over; value.samplers = 3;
        value.gpu_operations = if (value.backend == c.render_backend_nvidia) c.device_gpu_copy else 0;
        value.resource_capacity = self.resources.len; value.job_capacity = self.jobs.len;
        return value;
    }
};
pub fn get(handle: *const c.R4GfxDevice, closing: bool) Error!*Device {
    _ = try pointer(c.R4GfxDevice, @intFromPtr(handle));
    const device = try pointer(Device, handle.address);
    if (device.magic != live_magic or device.self_address != handle.address or device.generation != handle.generation) return error.Stale;
    if (!closing and device.closing) return error.Busy;
    return device;
}
pub fn storageSize() callconv(.c) u64 { return @sizeOf(Device); }
comptime { std.debug.assert(@alignOf(Device) <= c.device_storage_alignment); }
pub fn open(config: *const c.R4GfxDeviceConfig, output: *c.R4GfxDevice) callconv(.c) i32 {
    openDevice(config, output) catch |err| return code(err);
    return c.status_ok;
}
fn openDevice(config: *const c.R4GfxDeviceConfig, output: *c.R4GfxDevice) Error!void {
    _ = try pointer(c.R4GfxDeviceConfig, @intFromPtr(config));
    if (config.version != 1 or config.size != @sizeOf(c.R4GfxDeviceConfig) or config.storage_bytes < @sizeOf(Device) or config.flags & ~c.device_software_only != 0) return error.Invalid;
    const device = try pointer(Device, config.storage_address);
    const raw = try pointer(a.R4XStartContext, config.start_context);
    try outputSafe(c.R4GfxDevice, output, device);
    if (overlaps(@intFromPtr(config), @sizeOf(c.R4GfxDeviceConfig), @intFromPtr(device), @sizeOf(Device)) or
        overlaps(@intFromPtr(raw), @sizeOf(a.R4XStartContext), @intFromPtr(device), @sizeOf(Device)) or
        overlaps(@intFromPtr(config), @sizeOf(c.R4GfxDeviceConfig), @intFromPtr(output), @sizeOf(c.R4GfxDevice))) return error.Alias;
    if (device.magic != 0 and device.magic != closed_magic) return error.Busy;
    if (device.magic == 0 and device.generation != 0) return error.Invalid;
    const generation = std.math.add(u64, device.generation, 1) catch return error.Limit;
    const bundle = r4os.program.bundleValueFromR4XStart(raw) orelse return error.Invalid;
    device.* = .{ .magic = live_magic, .generation = generation, .self_address = @intFromPtr(device),
        .bundle = bundle, .preferred_adapter = config.preferred_adapter, .flags = config.flags };
    // Initial selection has no old queue and cannot require a retained close.
    device.selectBackend() catch unreachable;
    output.* = .{ .address = @intFromPtr(device), .generation = generation };
}
pub fn info(handle: *const c.R4GfxDevice, output: *c.R4GfxDeviceInfo) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    outputSafe(c.R4GfxDeviceInfo, output, device) catch |err| return code(err);
    output.* = device.info();
    return c.status_ok;
}
pub fn refresh(handle: *const c.R4GfxDevice, output: *c.R4GfxDeviceInfo) callconv(.c) i32 {
    const device = get(handle, false) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    outputSafe(c.R4GfxDeviceInfo, output, device) catch |err| return code(err);
    device.selectBackend() catch |err| return code(err);
    output.* = device.info();
    return c.status_ok;
}

pub fn createResource(handle: *const c.R4GfxDevice, descriptor: *const c.R4GfxResourceDesc, output: *c.R4GfxResource) callconv(.c) i32 {
    const device = get(handle, false) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    return @import("device_resources.zig").create(device, descriptor, output) catch |err| code(err);
}
pub fn retainResource(handle: *const c.R4GfxDevice, resource: *const c.R4GfxResource) callconv(.c) i32 {
    const device = get(handle, false) catch |err| return code(err);
    _ = pointer(c.R4GfxResource, @intFromPtr(resource)) catch |err| return code(err);
    const item = device.resource(resource.*, true) catch |err| return code(err);
    item.public_refs = std.math.add(u32, item.public_refs, 1) catch return c.status_limit;
    return c.status_ok;
}
pub fn releaseResource(handle: *const c.R4GfxDevice, resource: *const c.R4GfxResource) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    _ = pointer(c.R4GfxResource, @intFromPtr(resource)) catch |err| return code(err);
    const item = device.resource(resource.*, true) catch |err| return code(err);
    item.public_refs -= 1;
    _ = device.cleanResource(item); // Logical release is committed; retained maps remain tracked.
    return c.status_ok;
}
pub fn resourceInfo(handle: *const c.R4GfxDevice, resource: *const c.R4GfxResource, output: *c.R4GfxResourceInfo) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    separateInput(resource, output) catch |err| return code(err);
    _ = pointer(c.R4GfxResource, @intFromPtr(resource)) catch |err| return code(err);
    outputSafe(c.R4GfxResourceInfo, output, device) catch |err| return code(err);
    const item = device.resource(resource.*, true) catch |err| return code(err);
    output.* = .{ .version = 1, .size = @sizeOf(c.R4GfxResourceInfo), .resource = resource.*, .source_kind = item.source_kind,
        .flags = item.flags | @as(u32, if (item.invalidated) c.resource_invalidated else 0), .source_generation = item.source_generation, .buffer_id = item.backing.buffer.id,
        .references = item.public_refs, .buffer_generation = item.backing.buffer.generation, .image = item.image };
    return c.status_ok;
}
pub fn render(handle: *const c.R4GfxDevice, batch: *const c.R4GfxRenderBatch, output: *c.R4GfxRenderStats) callconv(.c) i32 {
    const device = get(handle, false) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    return @import("device_render.zig").execute(device, batch, output) catch |err| code(err);
}
pub fn submitCopy(handle: *const c.R4GfxDevice, request: *const c.R4GfxCopyRequest, output: *c.R4GfxJob) callconv(.c) i32 {
    const device = get(handle, false) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    return @import("device_jobs.zig").submit(device, request, output) catch |err| code(err);
}
pub fn jobInfo(handle: *const c.R4GfxDevice, job: *const c.R4GfxJob, output: *c.R4GfxJobInfo) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    separateInput(handle, output) catch |err| return code(err);
    return @import("device_jobs.zig").info(device, job, output) catch |err| code(err);
}
pub fn cancelJob(handle: *const c.R4GfxDevice, job: *const c.R4GfxJob) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    return @import("device_jobs.zig").cancel(device, job) catch |err| code(err);
}
pub fn releaseJob(handle: *const c.R4GfxDevice, job: *const c.R4GfxJob) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    return @import("device_jobs.zig").release(device, job) catch |err| code(err);
}
pub fn close(handle: *const c.R4GfxDevice) callconv(.c) i32 {
    const device = get(handle, true) catch |err| return code(err);
    device.closing = true;
    device.closeQueue() catch |err| return code(err);
    var busy = false;
    for (&device.jobs, 0..) |*item, index| if (item.serial != 0) {
        const job: c.R4GfxJob = .{ .slot = @intCast(index + 1), .reserved = 0, .generation = item.serial, .device_generation = device.generation, .device_address = device.self_address };
        _ = @import("device_jobs.zig").cancel(device, &job) catch c.status_busy;
        _ = @import("device_jobs.zig").release(device, &job) catch { busy = true; continue; };
    };
    for (&device.resources) |*item| item.public_refs = 0;
    if (!device.cleanResources()) busy = true;
    if (!device.drainQueues()) busy = true;
    if (busy) return c.status_busy;
    device.magic = closed_magic;
    return c.status_ok;
}

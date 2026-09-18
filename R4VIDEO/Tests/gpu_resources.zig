// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
// Focused owner checks inside the existing allocation case. Real SDK dispatch;
// only the kernel/driver callbacks are modeled. This does not decode pixels.
const std = @import("std");
const t = std.testing;
const r = @import("r4os");
const a = r.abi;
const nv = @import("r4nv_binding");
const gpu = @import("gpu_resources");
const Budget = @import("video_allocation").Budget;
const ff = @cImport(@cInclude("nvdec.h"));
const Decoder = @import("gpu_decoder").Implementation(ff);
var model: *Model = undefined;
const Bo = struct { descriptor: a.GfxBufferDescriptor = .{}, data: ?[]align(65536) u8 = null, live: bool = false, mapped: bool = false };
const Va = struct { request: a.GfxVirtualRequest = .{}, status: a.GfxVirtualStatus = .{}, live: bool = false };
const Model = struct {
    bos: [64]Bo = @splat(.{}),
    vas: [128]Va = @splat(.{}),
    pending: a.GfxNativeAllocation = .{},
    pending_live: bool = false,
    next_va: u64 = 0x100000,
    native_timeout: bool = false,
    bind_timeout: bool = false,
    retire_ready: bool = true,
    queue_timeout: bool = false,
    queue_released: bool = true,
    queue_closed: bool = true,
    fence_released: bool = true,
    cancel_count: u32 = 0,
    fence: a.GfxFence = .{},
    loan_count: usize = 0,
    loans: [64]a.GfxNativeResource = undefined,
    coherent: bool = true,
    class_chip: u32 = 0x174,
    decode: enum { none, success, missing, corrupt } = .none,
    current_slot: u32 = 0,
    reference_slots: [2]u32 = @splat(0),
    fn clean(self: *Model) !void {
        for (&self.bos) |*bo| try t.expect(!bo.live and !bo.mapped and bo.data == null);
        for (&self.vas) |*va| try t.expect(!va.live);
        try t.expect(!self.pending_live and self.queue_closed and self.fence_released);
    }
};
fn handle(slot: usize) a.GfxBufferHandle {
    return .{ .id = @intCast(slot + 1), .generation = 17 };
}
fn index(h: *const a.GfxBufferHandle, limit: usize) ?usize {
    if (h.id == 0 or h.id > limit or h.generation != 17 or h.reserved0 != 0) return null;
    return h.id - 1;
}
fn clock() ?a.MonotonicClockInfo {
    return .{ .instant_ns = 1_000_000, .frequency_hz = 1_000_000_000,
        .event_frequency_numerator = 100, .event_frequency_denominator = 1, .flags = a.monotonic_clock_flag_valid };
}
fn binding() a.GfxBackendBinding {
    return .{ .adapter_id = 9, .device_generation = 23, .reset_generation = 7, .milestone = a.gfx_queue_milestone_device_execution };
}
fn backend(which: u32, output: *a.GfxBackendInfo) callconv(.c) i32 {
    if (which != 0) return 0;
    const protocol: nv.R4NvDriverProfile = .{ .version = 1, .size = @sizeOf(nv.R4NvDriverProfile),
        .vendor_id = 0x10de, .copy_class = 0xc6b5, .rm_release = nv.rm_release, .command_abi = nv.command_abi,
        .reserved0 = 0, .reserved1 = 0 };
    output.* = .{ .binding = binding(), .memory_generation = 31, .operations = 1 << a.gfx_queue_operation_native,
        .profile = .{ .interface_id_lo = nv.backend_v1_header.interface_id_lo, .interface_id_hi = nv.backend_v1_header.interface_id_hi,
            .revision = 1, .data_bytes = @sizeOf(nv.R4NvDriverProfile) } };
    @memcpy(output.profile.data[0..@sizeOf(nv.R4NvDriverProfile)], std.mem.asBytes(&protocol));
    return 1;
}
fn properties(input: *const a.GfxBackendBinding, output: *a.GfxBackendProperties) callconv(.c) i32 {
    std.debug.assert(std.meta.eql(input.*, binding()));
    var arch = std.mem.zeroes(nv.R4NvArchitecture);
    arch.version = nv.architecture_version;
    arch.size = @sizeOf(nv.R4NvArchitecture);
    arch.vendor_id = 0x10de;
    arch.chipset = model.class_chip;
    arch.rm_release = nv.rm_release;
    arch.flags = nv.architecture_image_layouts | @as(u32, if (model.coherent) nv.architecture_host_coherent else 0);
    arch.bind_alignment = 65536;
    arch.va_start = 65536;
    arch.va_end = 1 << 49;
    arch.memory_generation = 31;
    // Deliberately no GR topology/template: it is not NVDEC admission.
    output.* = .{ .interface_id_lo = nv.backend_v1_header.interface_id_lo, .interface_id_hi = nv.backend_v1_header.interface_id_hi,
        .revision = nv.architecture_version, .data_bytes = @sizeOf(nv.R4NvArchitecture) };
    @memcpy(output.data[0..@sizeOf(nv.R4NvArchitecture)], std.mem.asBytes(&arch));
    return 1;
}
fn create(input: *const a.GfxBufferDescriptor, output: *a.GfxBufferReference) callconv(.c) i32 {
    for (&model.bos, 0..) |*bo, i| if (!bo.live) {
        bo.* = .{ .descriptor = input.*, .live = true };
        if (input.location == a.gfx_buffer_location_system)
            bo.data = t.allocator.alignedAlloc(u8, .fromByteUnits(65536), @intCast(input.byte_length)) catch return -7;
        output.* = .{ .buffer = handle(i), .reference = handle(i) };
        return 1;
    };
    return -9;
}
fn describe(input: *const a.GfxBufferHandle, output: *a.GfxBufferDescriptor) callconv(.c) i32 {
    const i = index(input, model.bos.len) orelse return -3;
    if (!model.bos[i].live) return -3;
    output.* = model.bos[i].descriptor;
    return 1;
}
fn release(input: *const a.GfxBufferHandle) callconv(.c) i32 {
    const bo = &model.bos[index(input, model.bos.len) orelse return -3];
    std.debug.assert(bo.live and !bo.mapped);
    for (&model.vas) |*va| std.debug.assert(!va.live or !std.meta.eql(va.request.reference, input.*));
    if (bo.data) |data| t.allocator.free(data);
    bo.* = .{};
    return 1;
}
fn map(input: *const a.GfxBufferHandle, access: u32, offset: u64, bytes: u64, output: *a.GfxBufferMap) callconv(.c) i32 {
    const bo = &model.bos[index(input, model.bos.len) orelse return -3];
    std.debug.assert(bo.live and !bo.mapped and access == 1 and offset == 0 and bytes == bo.descriptor.byte_length);
    bo.mapped = true;
    output.* = .{ .lease = input.*, .cpu_address = @intFromPtr(bo.data.?.ptr), .byte_length = bytes, .cache_policy = a.gfx_buffer_cache_write_back };
    return 1;
}
fn unmap(input: *const a.GfxBufferHandle) callconv(.c) i32 {
    const bo = &model.bos[index(input, model.bos.len) orelse return -3];
    std.debug.assert(bo.mapped);
    bo.mapped = false;
    return 1;
}
fn nativeStart(input: *const a.GfxNativeAllocation, output: *a.GfxNativeStatus) callconv(.c) i32 {
    std.debug.assert(!model.pending_live and input.adapter_id == 9 and input.memory_generation == 31);
    model.pending = input.*;
    model.pending_live = true;
    output.* = .{ .request = handle(100), .phase = 0, .deadline_ns = input.deadline_ns };
    return 1;
}
fn nativeWait(input: *const a.GfxBufferHandle, ticks: u64, output: *a.GfxNativeStatus) callconv(.c) i32 {
    std.debug.assert(model.pending_live and input.id == 101 and ticks > 0 and ticks <= 500);
    if (model.native_timeout) return -11;
    output.* = .{ .request = input.*, .phase = 2, .result = 1, .deadline_ns = model.pending.deadline_ns, .completed_ns = 2_000_000 };
    return 1;
}
fn nativeReceive(input: *const a.GfxBufferHandle, output: *a.GfxBufferReference) callconv(.c) i32 {
    std.debug.assert(model.pending_live and input.id == 101);
    const request = model.pending;
    model.pending_live = false;
    var descriptor: a.GfxBufferDescriptor = .{ .location = a.gfx_buffer_location_device_local,
        .adapter_id = 9, .driver_owner = 2, .device_generation = 31, .alignment = 65536,
        .byte_length = request.byte_length, .usage = request.usage };
    if (request.kind == 1) {
        const pitch = std.mem.alignForward(u64, request.width, 64);
        const luma = pitch * std.mem.alignForward(u64, request.height, 16);
        const offset = std.mem.alignForward(u64, luma, 65536);
        descriptor.modifier = 0x0300000000606011;
        descriptor.width = request.width;
        descriptor.height = request.height;
        descriptor.format = request.format;
        descriptor.plane_count = 2;
        descriptor.plane_pitches = .{ pitch, pitch, 0, 0 };
        descriptor.plane_offsets = .{ 0, offset, 0, 0 };
        descriptor.byte_length = std.mem.alignForward(u64, offset + pitch * std.mem.alignForward(u64, request.height / 2, 16), 65536);
    }
    return create(&descriptor, output);
}
fn nativeClose(input: *const a.GfxBufferHandle) callconv(.c) i32 {
    std.debug.assert(model.pending_live and input.id == 101);
    model.pending_live = false;
    return 1;
}
fn virtualStart(input: *const a.GfxVirtualRequest, output: *a.GfxVirtualStatus) callconv(.c) i32 {
    std.debug.assert(input.adapter_id == 9 and input.memory_generation == 31 and input.fixed_address == 0);
    for (&model.vas, 0..) |*va, i| if (!va.live) {
        const address = if (input.kind == 1) model.next_va else model.vas[index(&input.parent, model.vas.len).?].status.address;
        if (input.kind == 1) model.next_va += input.byte_length;
        va.* = .{ .live = true, .request = input.*, .status = .{ .resource = handle(i), .parent = input.parent,
            .kind = input.kind, .address = address, .byte_length = input.byte_length, .deadline_ns = input.deadline_ns, .flags = 1, .result = 1 } };
        output.* = va.status;
        return 1;
    };
    return -9;
}
fn virtualWait(input: *const a.GfxBufferHandle, until: u32, ticks: u64, output: *a.GfxVirtualStatus) callconv(.c) i32 {
    const va = &model.vas[index(input, model.vas.len) orelse return -3];
    std.debug.assert(va.live and until <= 1 and ticks > 0 and ticks <= 500);
    if (until == 1) {
        model.retire_ready = true;
        return virtualQuery(input, output);
    }
    if (model.bind_timeout and va.request.kind == 2) return -11;
    output.* = va.status;
    return 1;
}
fn virtualQuery(input: *const a.GfxBufferHandle, output: *a.GfxVirtualStatus) callconv(.c) i32 {
    const va = &model.vas[index(input, model.vas.len) orelse return -3];
    std.debug.assert(va.live);
    if (va.status.flags & 4 != 0 and model.retire_ready and model.queue_released) va.status.flags = 7;
    output.* = va.status;
    return 1;
}
fn virtualClose(input: *const a.GfxBufferHandle, mode: u32) callconv(.c) i32 {
    const va = &model.vas[index(input, model.vas.len) orelse return -3];
    std.debug.assert(va.live and va.request.kind == 1);
    if (mode == 0) {
        va.status.flags = 5;
    } else {
        std.debug.assert(va.status.flags == 7);
        for (&model.vas) |*child| if (child.live and std.meta.eql(child.request.parent, input.*)) { child.* = .{}; };
        va.* = .{};
    }
    return 1;
}
fn queueOpen(input: *const a.GfxQueueConfig, output: *a.GfxQueueHandle) callconv(.c) i32 {
    std.debug.assert(model.queue_closed and input.adapter_id == 9 and input.milestone == 1 and input.capacity == 1);
    output.* = .{ .timeline = 91 };
    model.queue_closed = false;
    return 1;
}
fn fenceStatus() a.GfxFenceStatus {
    return .{ .fence = model.fence, .phase = if (model.queue_released) 2 else 1,
        .result = if (model.queue_released) 1 else 0, .flags = if (model.queue_released) 0 else 3,
        .milestone = 1, .deadline_ns = 5_001_000_000, .completed_ns = if (model.queue_released) 2_000_000 else 0 };
}
fn submit(input: *const a.GfxQueueHandle, common: *const a.GfxSubmission, native: *const a.GfxNativeSubmission, output: *a.GfxFenceStatus) callconv(.c) i32 {
    std.debug.assert(input.timeline == 91 and common.operation == a.gfx_queue_operation_native and
        native.command_bytes == 48 and native.resource_count > 0 and native.resource_count <= 64 and model.fence_released);
    const header: *const nv.R4NvNativeSubmitHeader = @ptrFromInt(native.commands);
    const push: *const nv.R4NvNativePush = @ptrFromInt(native.commands + 32);
    std.debug.assert(header.engine_mask == 8 and header.push_count == 1 and push.byte_length == 216);
    const loans: [*]const a.GfxNativeResource = @ptrFromInt(native.resources);
    model.loan_count = native.resource_count;
    @memcpy(model.loans[0..model.loan_count], loans[0..model.loan_count]);
    for (model.loans[0..model.loan_count]) |loan| {
        const va = &model.vas[index(&loan.binding, model.vas.len).?];
        std.debug.assert(va.live and va.request.kind == 2 and va.status.flags == 1);
    }
    if (model.decode != .none) {
        const words = virtualBytes(push.address);
        const params = virtualBytes(@as(u64, word(words, 6 * 4)) << 8);
        const status = virtualBytes(@as(u64, word(words, 13 * 4)) << 8);
        // A preceding successful picture must not leave reusable success here.
        for (status[0..56]) |byte| std.debug.assert(byte == 0xff);
        model.current_slot = (word(params, 180) >> 2) & 127;
        model.reference_slots = .{ word(params, 192) & 127, word(params, 208) & 127 };
        if (model.decode != .missing) {
            @memset(status[0..56], 0);
            std.mem.writeInt(u32, status[0..4], word(params, 100) * word(params, 104), .little);
            if (model.decode == .corrupt) std.mem.writeInt(u32, status[52..56], 1, .little);
        }
    }
    model.fence = .{ .adapter_id = 9, .timeline = 91, .point = 1, .device_generation = 23, .reset_generation = 7 };
    model.fence_released = false;
    model.queue_released = !model.queue_timeout;
    output.* = fenceStatus();
    return 1;
}
fn fenceWait(input: *const a.GfxFence, ticks: u64, until: u32, output: *a.GfxFenceStatus) callconv(.c) i32 {
    std.debug.assert(std.meta.eql(input.*, model.fence) and until == 1 and ticks > 0 and ticks <= 500);
    if (model.queue_timeout) return -11;
    output.* = fenceStatus();
    return 1;
}
fn fenceQuery(input: *const a.GfxFence, output: *a.GfxFenceStatus) callconv(.c) i32 {
    std.debug.assert(std.meta.eql(input.*, model.fence) and !model.fence_released);
    output.* = fenceStatus();
    return 1;
}
fn fenceCancel(input: *const a.GfxFence) callconv(.c) i32 {
    std.debug.assert(std.meta.eql(input.*, model.fence) and !model.fence_released);
    model.cancel_count += 1;
    return 1;
}
fn fenceRelease(input: *const a.GfxFence) callconv(.c) i32 {
    std.debug.assert(std.meta.eql(input.*, model.fence) and model.queue_released and !model.fence_released);
    model.fence_released = true;
    return 1;
}
fn queueClose(input: *const a.GfxQueueHandle) callconv(.c) i32 {
    std.debug.assert(input.timeline == 91 and !model.queue_closed and model.fence_released);
    model.queue_closed = true;
    return 1;
}
fn word(bytes: []const u8, offset: usize) u32 {
    return std.mem.readInt(u32, bytes[offset..][0..4], .little);
}
fn virtualBytes(address: u64) []u8 {
    for (&model.vas) |*va| if (va.live and va.request.kind == 2 and address >= va.status.address and
        address - va.status.address < va.status.byte_length)
    {
        const bo = &model.bos[index(&va.request.reference, model.bos.len).?];
        return bo.data.?[@intCast(address - va.status.address)..];
    };
    @trap();
}
fn picture(seq: ff.struct_r4video_nvdec_sequence, number: u32) ff.struct_r4video_nvdec_picture {
    var p = std.mem.zeroes(ff.struct_r4video_nvdec_picture);
    p.sequence = seq;
    p.frame_num = number;
    p.is_reference = 1;
    p.poc = @splat(@as(i32, @intCast(number * 2)));
    p.scaling4 = @splat(@splat(16));
    p.scaling8 = @splat(@splat(16));
    return p;
}
fn decode(ops: *const ff.struct_r4video_nvdec_ops, p: *const ff.struct_r4video_nvdec_picture, expected: c_int) !?*anyopaque {
    var out: ?*anyopaque = null;
    try t.expectEqual(@as(c_int, 0), ops.allocate.?(ops.owner, &p.sequence, &out));
    try t.expect(out != null);
    try t.expectEqual(@as(c_int, 0), ops.begin.?(ops.owner, out, p));
    const nal = [_]u8{ 0x65, 0x88, 0x80 };
    try t.expectEqual(@as(c_int, 0), ops.slice.?(ops.owner, out, &nal, nal.len));
    try t.expectEqual(expected, ops.end.?(ops.owner, out));
    return out;
}

pub fn run() !void {
    var state: Model = .{};
    model = &state;
    var raw: a.R4XStartContext = .{};
    var table: a.R4XStartR4Draw = .{};
    inline for (.{
        .{ "gfx_queue_backend_info", &backend }, .{ "gfx_queue_backend_properties", &properties },
        .{ "gfx_buffer_create", &create }, .{ "gfx_buffer_describe", &describe }, .{ "gfx_buffer_release", &release },
        .{ "gfx_buffer_map_persistent", &map }, .{ "gfx_buffer_unmap", &unmap },
        .{ "gfx_native_start", &nativeStart }, .{ "gfx_native_wait", &nativeWait }, .{ "gfx_native_receive", &nativeReceive }, .{ "gfx_native_close", &nativeClose },
        .{ "gfx_virtual_start", &virtualStart }, .{ "gfx_virtual_wait", &virtualWait }, .{ "gfx_virtual_query", &virtualQuery }, .{ "gfx_virtual_close", &virtualClose },
        .{ "gfx_queue_open", &queueOpen }, .{ "gfx_queue_close", &queueClose }, .{ "gfx_queue_submit_native", &submit },
        .{ "gfx_fence_wait", &fenceWait }, .{ "gfx_fence_query", &fenceQuery }, .{ "gfx_fence_cancel", &fenceCancel }, .{ "gfx_fence_release", &fenceRelease },
    }) |field| @field(table, field[0]) = @intFromPtr(field[1]);
    var bundle: r.program.Bundle = .{ .raw = &raw, .draw = &table };
    const base = r.program.Context.initBundle(&bundle);
    const device = try gpu.Device.query(base, 9);
    try t.expectEqual(@as(u32, 0xc7b0), device.class);
    try t.expectEqual(gpu.address_limit, device.va_end);
    state.class_chip = 0x192;
    try t.expectEqual(@as(u32, 0xc9b0), (try gpu.Device.query(base, 9)).class);
    state.class_chip = 0x999;
    try t.expectError(error.Unsupported, gpu.Device.query(base, 9));
    state.class_chip = 0x174;
    state.coherent = false;
    try t.expectError(error.Unsupported, gpu.Device.query(base, 9));
    state.coherent = true;
    var budget: Budget = .{ .limit = 8 * 65536 };
    var ctx: gpu.Context = .{ .base = base, .device = device, .budget = &budget, .clock = clock };
    var commands: gpu.Resource = .{};
    var image: gpu.Resource = .{};
    var scratch: gpu.Resource = .{};
    try commands.system(&ctx, 216);
    try scratch.video(&ctx, 129);
    try image.nv12(&ctx, 64, 16);
    try t.expectEqual(@as(u32, 32), image.descriptor.height);
    try t.expectEqual(@as(usize, 4 * 65536), budget.liveBytes());
    try t.expectEqual(@as(u32, 0x601), state.vas[index(&image.range, state.vas.len).?].request.flags);
    @memset((try commands.mappedBytes())[0..216], 0x7a);
    try ctx.submit(&commands, 216, &.{ .{ .resource = &image, .write = true }, .{ .resource = &scratch, .write = false },
        .{ .resource = &scratch, .write = true } });
    try t.expectEqual(@as(usize, 3), state.loan_count);
    try t.expectEqual(@as(u32, 1), state.loans[2].access);
    try t.expectEqual(@as(u64, 0), ctx.fence.timeline);
    try image.close();
    try image.close(); // Repeated cleanup is harmless.
    try scratch.close();
    try commands.close();
    try ctx.close();
    try t.expectEqual(@as(usize, 0), budget.liveBytes());
    try state.clean();

    // A late MAP reply must keep its BO and accounting alive. Closing the VA
    // cascades to its child; only the explicit retirement ACK permits release.
    state = .{ .bind_timeout = true, .retire_ready = false };
    ctx = .{ .base = base, .device = device, .budget = &budget, .clock = clock };
    try t.expectError(error.Timeout, image.nv12(&ctx, 64, 64));
    const held = budget.liveBytes();
    try t.expect(held > 0);
    try t.expectError(error.Busy, image.close());
    try t.expectEqual(held, budget.liveBytes());
    state.retire_ready = true;
    try image.close();
    try state.clean();

    state = .{ .native_timeout = true };
    try t.expectError(error.Timeout, scratch.video(&ctx, 256));
    try t.expect(state.pending_live);
    try scratch.close();
    try state.clean();

    // Never truncate a GPU VA to the NVDEC method's 40-bit field.
    state = .{ .next_va = gpu.address_limit };
    try t.expectError(error.Unsupported, commands.system(&ctx, 216));
    try commands.close();
    try state.clean();

    // Logical timeout/cancel does not make an active job's BOs reusable.
    state = .{ .queue_timeout = true };
    try commands.system(&ctx, 216);
    try image.nv12(&ctx, 64, 64);
    try t.expectError(error.Timeout, ctx.submit(&commands, 216, &.{.{ .resource = &image, .write = true }}));
    try t.expect(ctx.poisoned);
    try t.expectError(error.Busy, commands.mappedBytes());
    try t.expectError(error.Busy, ctx.close());
    try t.expectEqual(@as(u32, 1), state.cancel_count);
    try t.expectError(error.Busy, image.close());
    try t.expectError(error.Busy, commands.close());
    try t.expectEqual(@as(usize, 3 * 65536), budget.liveBytes());
    state.queue_released = true;
    try ctx.close();
    try image.close();
    try commands.close();
    try t.expectEqual(@as(usize, 0), budget.liveBytes());
    try state.clean();

    budget.limit = 65535;
    ctx.poisoned = false;
    try t.expectError(error.NoMemory, commands.system(&ctx, 1));
    try t.expect(commands.owner == null);
    try t.expectEqual(@as(usize, 0), budget.liveBytes());
    try decoderChecks(base, device);
}

fn decoderChecks(base: r.program.Context, device: gpu.Device) !void {
    model.* = .{ .decode = .success };
    var budget: Budget = .{ .limit = 32 * 1024 * 1024 };
    var decoder: Decoder = .{ .ctx = .{ .base = base, .device = device, .budget = &budget, .clock = clock } };
    const ops = decoder.ops();
    const seq: ff.struct_r4video_nvdec_sequence = .{ .profile = 66, .level = 31, .width_mbs = 4, .height_mbs = 4,
        .max_refs = 2, .log2_frame_num = 4, .poc_type = 0, .log2_poc_lsb = 4, .delta_poc_always_zero = 0, .direct_8x8 = 1 };
    var held: [5]?*anyopaque = @splat(null);
    var p = picture(seq, 0);
    held[0] = try decode(&ops, &p, 0);
    try t.expectEqual(@as(u32, 0), model.current_slot);
    const first_reference = decoder.describe(held[0]).?.backing.reference;
    p = picture(seq, 1);
    p.reference_count = 1;
    p.references[0] = .{ .image = held[0], .long_term = 0, .frame_index = 0, .poc = @splat(0) };
    held[1] = try decode(&ops, &p, 0);
    try t.expectEqual(@as(u32, 1), model.current_slot);
    p = picture(seq, 2);
    p.reference_count = 2;
    p.references[0] = .{ .image = held[0], .long_term = 0, .frame_index = 0, .poc = @splat(0) };
    p.references[1] = .{ .image = held[1], .long_term = 0, .frame_index = 1, .poc = @splat(2) };
    held[2] = try decode(&ops, &p, 0);
    try t.expectEqual(@as(u32, 2), model.current_slot);
    p = picture(seq, 3);
    p.reference_count = 2;
    p.references[0] = .{ .image = held[2], .long_term = 0, .frame_index = 2, .poc = @splat(4) };
    p.references[1] = .{ .image = held[1], .long_term = 0, .frame_index = 1, .poc = @splat(2) };
    held[3] = try decode(&ops, &p, 0);
    // Reordered DPB retains actual coloc positions, not the reference-list index.
    try t.expectEqual(@as(u32, 0), model.current_slot);
    try t.expectEqual([2]u32{ 2, 1 }, model.reference_slots);
    try t.expectEqual(first_reference, decoder.describe(held[0]).?.backing.reference);
    ops.release.?(ops.owner, held[0]);
    try decoder.reap();
    p = picture(seq, 4);
    p.reference_count = 2;
    p.references[0] = .{ .image = held[3], .long_term = 0, .frame_index = 3, .poc = @splat(6) };
    p.references[1] = .{ .image = held[2], .long_term = 0, .frame_index = 2, .poc = @splat(4) };
    held[4] = try decode(&ops, &p, 0);
    try t.expectEqual(@as(u32, 1), model.current_slot);
    try t.expectEqual([2]u32{ 0, 2 }, model.reference_slots);
    // Flush and close may retire scratch while the caller still holds images.
    decoder.flush();
    var resized = seq;
    resized.width_mbs = 6;
    model.retire_ready = false;
    p = picture(resized, 0);
    const new_size = try decode(&ops, &p, 0);
    try t.expectEqual(@as(u32, 96), decoder.describe(new_size).?.descriptor.width);
    try t.expectEqual(@as(u32, 64), decoder.describe(held[1]).?.descriptor.width);
    try t.expectError(error.Busy, decoder.close());
    for (held[1..]) |ptr| {
        try t.expect(decoder.describe(ptr) != null);
        ops.release.?(ops.owner, ptr);
    }
    ops.release.?(ops.owner, new_size);
    try decoder.close();
    try t.expectEqual(@as(usize, 0), budget.liveBytes());
    try model.clean();

    for ([_]@FieldType(Model, "decode"){ .missing, .corrupt }) |failure| {
        model.* = .{ .decode = failure };
        decoder = .{ .ctx = .{ .base = base, .device = device, .budget = &budget, .clock = clock } };
        const callbacks = decoder.ops();
        p = picture(seq, 0);
        const ptr = try decode(&callbacks, &p, -6);
        try t.expect(decoder.describe(ptr) == null);
        callbacks.abort.?(callbacks.owner, ptr);
        callbacks.release.?(callbacks.owner, ptr);
        try decoder.close();
        try t.expectEqual(@as(usize, 0), budget.liveBytes());
        try model.clean();
    }
    // Begin can run out of budget after the image and some work BOs exist.
    // The copied callback owner must retain and retire every partial resource.
    model.* = .{ .decode = .success };
    budget.limit = 4 * 65536;
    decoder = .{ .ctx = .{ .base = base, .device = device, .budget = &budget, .clock = clock } };
    const partial = decoder.ops();
    var image: ?*anyopaque = null;
    p = picture(seq, 0);
    try t.expectEqual(@as(c_int, 0), partial.allocate.?(partial.owner, &seq, &image));
    try t.expectEqual(@as(c_int, -4), partial.begin.?(partial.owner, image, &p));
    partial.abort.?(partial.owner, image);
    partial.release.?(partial.owner, image);
    try decoder.close();
    try t.expectEqual(@as(usize, 0), budget.liveBytes());
    try model.clean();
}

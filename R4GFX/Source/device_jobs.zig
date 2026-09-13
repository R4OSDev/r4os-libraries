//! Canonical queue receipts remain referenced until physical retirement.
//! Closing an old queue early would discard those receipts, so the device
//! keeps obsolete queues until their last job has actually been released.
const std = @import("std");
const a = @import("r4os").abi;
const d = @import("device.zig");
const c = d.c;

pub fn submit(device: *d.Device, request: *const c.R4GfxCopyRequest, output: *c.R4GfxJob) d.Error!i32 {
    _ = try d.pointer(c.R4GfxCopyRequest, @intFromPtr(request));
    try d.outputSafe(c.R4GfxJob, output, device);
    if (d.overlaps(@intFromPtr(request), @sizeOf(c.R4GfxCopyRequest), @intFromPtr(output), @sizeOf(c.R4GfxJob))) return error.Alias;
    const source = try device.resource(request.source, true);
    const target = try device.resource(request.target, true);
    if (source.invalidated or target.invalidated) return error.Stale;
    if (source.kind != c.resource_image or target.kind != c.resource_image or target.flags & c.image_target == 0 or
        source.backing.reference.id == 0 or target.backing.reference.id == 0 or std.meta.eql(source.backing.buffer, target.backing.buffer)) return error.Unsupported;
    if (request.byte_length == 0 or request.source_offset > source.image.byte_length or request.target_offset > target.image.byte_length or
        request.byte_length > source.image.byte_length - request.source_offset or request.byte_length > target.image.byte_length - request.target_offset) return error.Invalid;
    const index = for (&device.jobs, 0..) |*item, i| { if (item.serial == 0) break i; } else return error.Limit;
    const serial = std.math.add(u64, device.job_serial, 1) catch return error.Limit;
    if (source.job_refs == std.math.maxInt(u32) or target.job_refs == std.math.maxInt(u32)) return error.Limit;
    if (!device.cleanResources()) return error.Busy;
    try device.selectBackend();
    try device.ensureQueue();
    const queues = device.queues();
    var status: a.GfxFenceStatus = .{};
    try d.platform(queues.submit(&device.queue, &.{ .operation = a.gfx_queue_operation_copy, .source = source.backing.reference, .target = target.backing.reference,
        .source_offset = request.source_offset, .target_offset = request.target_offset, .byte_length = request.byte_length, .deadline_ns = request.deadline_ns }, &status));
    source.job_refs += 1; target.job_refs += 1;
    device.jobs[index] = .{ .serial = serial, .source = request.source, .target = request.target,
        .fence = status.fence, .backend = device.backend(), .bytes = request.byte_length };
    device.job_serial = serial;
    output.* = .{ .slot = @intCast(index + 1), .reserved = 0, .generation = serial, .device_generation = device.generation, .device_address = device.self_address };
    return c.status_ok;
}
fn query(device: *d.Device, item: *d.Job) d.Error!a.GfxFenceStatus {
    const queues = device.queues();
    var status: a.GfxFenceStatus = .{};
    try d.platform(queues.query(&item.fence, &status));
    if (!std.meta.eql(item.fence, status.fence)) return error.Stale;
    if (!item.counted and status.phase == a.gfx_queue_phase_terminal and status.result == a.gfx_queue_result_complete and status.flags & a.gfx_queue_flag_device_active == 0) {
        if (item.backend == c.render_backend_nvidia) device.counters.gpu_copy_bytes +|= item.bytes else {
            device.counters.cpu_read_bytes +|= item.bytes;
            device.counters.cpu_write_bytes +|= item.bytes;
        }
        item.counted = true;
    }
    return status;
}
pub fn info(device: *d.Device, handle: *const c.R4GfxJob, output: *c.R4GfxJobInfo) d.Error!i32 {
    _ = try d.pointer(c.R4GfxJob, @intFromPtr(handle));
    try d.outputSafe(c.R4GfxJobInfo, output, device);
    if (d.overlaps(@intFromPtr(handle), @sizeOf(c.R4GfxJob), @intFromPtr(output), @sizeOf(c.R4GfxJobInfo))) return error.Alias;
    const item = try device.job(handle.*);
    const value = try query(device, item);
    output.* = .{ .version = 1, .size = @sizeOf(c.R4GfxJobInfo), .phase = value.phase, .result = value.result, .flags = value.flags,
        .backend = item.backend, .timeline = value.fence.timeline, .point = value.fence.point,
        .device_generation = value.fence.device_generation, .reset_generation = value.fence.reset_generation };
    return c.status_ok;
}
pub fn cancel(device: *d.Device, handle: *const c.R4GfxJob) d.Error!i32 {
    _ = try d.pointer(c.R4GfxJob, @intFromPtr(handle));
    const item = try device.job(handle.*);
    const queues = device.queues();
    const rc = queues.cancel(&item.fence);
    if (rc != a.gfx_queue_error_already_completed) try d.platform(rc);
    return c.status_ok;
}
pub fn release(device: *d.Device, handle: *const c.R4GfxJob) d.Error!i32 {
    _ = try d.pointer(c.R4GfxJob, @intFromPtr(handle));
    const item = try device.job(handle.*);
    const value = try query(device, item);
    if (value.phase != a.gfx_queue_phase_terminal or value.flags & (a.gfx_queue_flag_device_active | a.gfx_queue_flag_resources_held) != 0) return error.Busy;
    const queues = device.queues();
    try d.platform(queues.release(&item.fence));
    const source = try device.resource(item.source, false);
    const target = try device.resource(item.target, false);
    std.debug.assert(source.job_refs != 0 and target.job_refs != 0);
    source.job_refs -= 1; target.job_refs -= 1;
    _ = device.cleanResource(source); _ = device.cleanResource(target);
    item.* = .{};
    _ = device.drainQueues();
    return c.status_ok;
}

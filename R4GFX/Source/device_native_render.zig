//! Resolve logical state once, then hand immutable values and retained BOs
//! to the common queue. No image map, pixel conversion or GPU wait occurs here.
const std = @import("std");
const a = @import("r4os").abi;
const d = @import("device.zig");
const c = d.c;
const empty_resource = std.mem.zeroes(c.R4GfxResource);
const empty_rect = std.mem.zeroes(c.R4GfxSignedRect);

fn image(device: *d.Device, handle: c.R4GfxResource, target: bool) d.Error!*d.Resource {
    const result = try device.resource(handle, true);
    if (result.invalidated) return error.Stale;
    if (result.kind != c.resource_image or (target and result.flags & c.image_target == 0)) return error.Invalid;
    if (result.backing.reference.id == 0) return error.Unsupported;
    return result;
}
pub fn submit(device: *d.Device, input: *const c.R4GfxRenderRequest, output: *c.R4GfxJob) d.Error!i32 {
    _ = try d.pointer(c.R4GfxRenderRequest, @intFromPtr(input));
    try d.outputSafe(c.R4GfxJob, output, device);
    if (d.overlaps(@intFromPtr(input), @sizeOf(c.R4GfxRenderRequest), @intFromPtr(output), @sizeOf(c.R4GfxJob)) or
        d.overlaps(@intFromPtr(input), @sizeOf(c.R4GfxRenderRequest), @intFromPtr(device), @sizeOf(d.Device))) return error.Alias;
    const request = input.*;
    if (request.version != 1 or request.size != @sizeOf(c.R4GfxRenderRequest) or request.opacity > 255 or
        request.transfer > c.render_transfer_srgb_encode or request.dependency_count > c.copy_max_dependencies or
        (request.dependency_count == 0 and request.dependencies != 0)) return error.Invalid;
    var dependencies: [c.copy_max_dependencies]a.GfxFence = undefined;
    if (request.dependency_count != 0) {
        _ = try d.pointer(c.R4GfxCopyFence, request.dependencies);
        const bytes = @as(u64, request.dependency_count) * @sizeOf(c.R4GfxCopyFence);
        _ = std.math.add(u64, request.dependencies, bytes) catch return error.Overflow;
        if (d.overlaps(request.dependencies, bytes, @intFromPtr(output), @sizeOf(c.R4GfxJob)) or
            d.overlaps(request.dependencies, bytes, @intFromPtr(device), @sizeOf(d.Device))) return error.Alias;
        const source: [*]const c.R4GfxCopyFence = @ptrFromInt(request.dependencies);
        for (source[0..request.dependency_count], 0..) |fence, i| dependencies[i] = @bitCast(fence);
    }
    try device.selectBackend();
    if (device.gpu_operations & c.device_gpu_render == 0) return error.Unsupported;
    const pipeline = try device.resource(request.pipeline, true);
    if (pipeline.kind != c.resource_pipeline) return error.Invalid;
    const fill = pipeline.operation == c.render_operation_fill;
    const target = try image(device, request.target, true);
    const source: ?*d.Resource = if (fill) null else try image(device, request.source, false);
    var command: a.GfxRenderCommand = .{ .kind = if (fill) a.gfx_render_kind_fill else a.gfx_render_kind_sample,
        .blend = if (pipeline.operation == c.render_operation_over) a.gfx_render_blend_over else a.gfx_render_blend_replace,
        .transfer = request.transfer, .color = request.color, .opacity = request.opacity,
        .source_rect = @bitCast(request.source_rect), .target_rect = @bitCast(request.target_rect), .scissor = @bitCast(request.scissor) };
    if (fill) {
        if (!std.meta.eql(request.source, empty_resource) or !std.meta.eql(request.sampler, empty_resource) or
            !std.meta.eql(request.source_rect, empty_rect) or request.transfer != 0) return error.Invalid;
    } else {
        if (request.color != 0) return error.Invalid;
        if (std.meta.eql(source.?.backing.buffer, target.backing.buffer)) return error.Alias;
        const sampler = try device.resource(request.sampler, true);
        if (sampler.kind != c.resource_sampler) return error.Invalid;
        command.filter = sampler.sampler;
    }
    const index = for (&device.jobs, 0..) |*item, i| { if (item.serial == 0) break i; } else return error.Limit;
    const serial = std.math.add(u64, device.job_serial, 1) catch return error.Limit;
    if (target.job_refs == std.math.maxInt(u32) or (source != null and source.?.job_refs == std.math.maxInt(u32))) return error.Limit;
    if (!device.cleanResources()) return error.Busy;
    try device.ensureQueue();
    var submission: a.GfxSubmission = .{ .operation = a.gfx_queue_operation_render, .deadline_ns = request.deadline_ns,
        .target = target.backing.reference, .source = if (source) |value| value.backing.reference else .{},
        .render = command, .dependency_count = request.dependency_count };
    @memcpy(submission.dependencies[0..request.dependency_count], dependencies[0..request.dependency_count]);
    const queues = device.queues();
    var status: a.GfxFenceStatus = .{};
    try d.platform(queues.submit(&device.queue, &submission, &status));
    target.job_refs += 1;
    if (source) |value| value.job_refs += 1;
    device.jobs[index] = .{ .serial = serial, .source = request.source, .target = request.target,
        .fence = status.fence, .backend = c.render_backend_nvidia, .render = true };
    device.job_serial = serial;
    output.* = .{ .slot = @intCast(index + 1), .reserved = 0, .generation = serial, .device_generation = device.generation, .device_address = device.self_address };
    return c.status_ok;
}

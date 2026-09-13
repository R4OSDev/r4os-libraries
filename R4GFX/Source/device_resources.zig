const std = @import("std");
const r4os = @import("r4os");
const a = r4os.abi;
const d = @import("device.zig");
const c = d.c;
const empty_image = std.mem.zeroes(c.R4GfxCpuImage);

pub fn validateImage(image: c.R4GfxCpuImage, borrowed: bool) d.Error!void {
    if (image.width == 0 or image.height == 0 or image.reserved != 0) return error.Invalid;
    const bytes: u64 = switch (image.format) { c.format_xrgb8888, c.format_argb8888 => 4, c.format_r8 => 1, else => return error.Unsupported };
    if (image.pitch < @as(u64, image.width) * bytes) return error.Invalid;
    const length = std.math.mul(u64, image.pitch, image.height) catch return error.Overflow;
    if (length > image.byte_length or (borrowed and image.cpu_address == 0) or (!borrowed and image.cpu_address != 0)) return error.Invalid;
    _ = std.math.add(u64, image.cpu_address, image.byte_length) catch return error.Overflow;
}
fn descriptorImage(descriptor: a.GfxBufferDescriptor) d.Error!c.R4GfxCpuImage {
    if (descriptor.version != 1 or descriptor.size < @sizeOf(a.GfxBufferDescriptor) or
        (descriptor.modifier != 0 and descriptor.location != a.gfx_buffer_location_device_local) or
        descriptor.plane_count != 1 or descriptor.plane_offsets[0] != 0 or descriptor.reserved0 != 0) return error.Unsupported;
    for (1..4) |i| if (descriptor.plane_offsets[i] != 0 or descriptor.plane_pitches[i] != 0) return error.Unsupported;
    const image: c.R4GfxCpuImage = .{ .cpu_address = 0, .byte_length = descriptor.byte_length, .pitch = descriptor.plane_pitches[0],
        .width = descriptor.width, .height = descriptor.height, .format = descriptor.format, .reserved = 0 };
    try validateImage(image, false);
    return image;
}
pub fn create(device: *d.Device, input: *const c.R4GfxResourceDesc, output: *c.R4GfxResource) d.Error!i32 {
    _ = try d.pointer(c.R4GfxResourceDesc, @intFromPtr(input));
    try d.outputSafe(c.R4GfxResource, output, device);
    if (d.overlaps(@intFromPtr(input), @sizeOf(c.R4GfxResourceDesc), @intFromPtr(output), @sizeOf(c.R4GfxResource))) return error.Alias;
    const request = input.*;
    if (request.version != 1 or request.size != @sizeOf(c.R4GfxResourceDesc) or request.reserved != 0) return error.Invalid;
    var candidate = d.Resource{ .kind = request.kind, .flags = request.flags, .source_kind = request.source_kind,
        .source_generation = request.source_generation, .image = request.image, .sampler = request.sampler, .operation = request.operation };
    var raster: a.GuiSharedRasterLease = .{};
    var reference: a.GfxBufferHandle = .{};
    var native: c.R4GfxNativeImage = undefined;
    switch (request.kind) {
        c.resource_sampler, c.resource_pipeline => {
            if (request.flags != 0 or request.source_kind != 0 or request.source_address != 0 or request.source_generation != 0 or !std.meta.eql(request.image, empty_image)) return error.Invalid;
            if (request.kind == c.resource_sampler) {
                if (request.operation != 0) return error.Invalid;
                if (request.sampler != c.render_sampler_nearest and request.sampler != c.render_sampler_bilinear) return error.Unsupported;
            } else {
                if (request.sampler != 0) return error.Invalid;
                if (request.operation != c.render_operation_fill and request.operation != c.render_operation_blit and request.operation != c.render_operation_over) return error.Unsupported;
            }
        },
        c.resource_image => {
            if (request.flags & ~c.image_target != 0 or request.operation != 0 or request.sampler != 0) return error.Invalid;
            switch (request.source_kind) {
                c.source_create_native => {
                    if (request.source_generation != 0 or !std.meta.eql(request.image, empty_image)) return error.Invalid;
                    native = (try d.pointer(c.R4GfxNativeImage, request.source_address)).*;
                    if (native.version != 1 or native.size != @sizeOf(c.R4GfxNativeImage) or native.deadline_ns == 0 or
                        native.deadline_ns == std.math.maxInt(u64) or native.width == 0 or native.height == 0) return error.Invalid;
                    if (native.layout > 1 or (native.format != c.format_xrgb8888 and native.format != c.format_argb8888 and native.format != c.format_r8)) return error.Unsupported;
                    if (device.selected.binding.adapter_id == 0) return error.Unsupported;
                },
                c.source_create_system, c.source_borrow_cpu => {
                    if (request.source_address != 0) return error.Invalid;
                    const borrowed = request.source_kind == c.source_borrow_cpu;
                    try validateImage(request.image, borrowed);
                    if (borrowed) {
                        if (request.source_generation == 0) return error.Invalid;
                        if (d.overlaps(request.image.cpu_address, request.image.byte_length, @intFromPtr(device), @sizeOf(d.Device))) return error.Alias;
                    } else if (request.source_generation != 0) return error.Invalid;
                },
                c.source_import_buffer => {
                    if (!std.meta.eql(request.image, empty_image)) return error.Invalid;
                    reference = (try d.pointer(a.GfxBufferHandle, request.source_address)).*;
                    if (reference.id == 0 or reference.generation == 0 or reference.reserved0 != 0) return error.Invalid;
                    candidate.source_key = .{ .id = reference.id, .generation = reference.generation };
                },
                c.source_shared_raster => {
                    if (request.flags != 0 or !std.meta.eql(request.image, empty_image) or request.source_generation != 0) return error.Invalid;
                    raster = (try d.pointer(a.GuiSharedRasterLease, request.source_address)).*;
                    if (raster.version != 1 or raster.size < @sizeOf(a.GuiSharedRasterLease) or raster.reserved0 != 0 or
                        raster.handle.id == 0 or raster.handle.generation == 0 or raster.raster_generation == 0 or raster.lease_token == 0) return error.Invalid;
                    candidate.source_key = .{ .id = raster.handle.id, .generation = raster.handle.generation };
                    candidate.source_generation = raster.raster_generation;
                },
                else => return error.Unsupported,
            }
        },
        else => return error.Unsupported,
    }
    // Only live logical resources can be reused; a released reference cannot
    // be resurrected by a job still retaining its old backing.
    for (&device.resources, 0..) |*item, index| {
        if (item.public_refs == 0 or item.kind != candidate.kind or item.flags != candidate.flags or item.source_kind != candidate.source_kind or
            item.source_generation != candidate.source_generation or !std.meta.eql(item.source_key, candidate.source_key) or
            item.sampler != candidate.sampler or item.operation != candidate.operation) continue;
        if (candidate.kind == c.resource_image) {
            if (candidate.source_kind == c.source_create_system or candidate.source_kind == c.source_create_native) continue;
            if (candidate.source_kind == c.source_borrow_cpu and !std.meta.eql(item.image, candidate.image)) continue;
            if (candidate.source_kind == c.source_import_buffer) continue; // Mutable BO imports have no immutable generation guarantee.
        }
        item.public_refs = std.math.add(u32, item.public_refs, 1) catch return error.Limit;
        output.* = device.resourceHandle(index);
        return c.status_ok;
    }
    _ = device.cleanResources();
    const serial = std.math.add(u64, device.resource_serial, 1) catch return error.Limit;
    const index = for (&device.resources, 0..) |*item, i| { if (item.serial == 0) break i; } else return error.Limit;
    const item = &device.resources[index];
    item.* = candidate;
    item.serial = serial;
    device.resource_serial = serial;
    errdefer _ = device.cleanResource(item); // A failed release stays in this slot, never disappears.
    if (request.kind == c.resource_image and request.source_kind != c.source_borrow_cpu) {
        const memory = device.buffers();
        switch (request.source_kind) {
            c.source_create_native => {
                var status: a.GfxNativeStatus = .{};
                const allocation: a.GfxNativeAllocation = .{ .adapter_id = device.selected.binding.adapter_id,
                    .memory_generation = device.selected.memory_generation, .deadline_ns = native.deadline_ns, .kind = 1,
                    .width = native.width, .height = native.height, .format = native.format, .layout = native.layout,
                    .usage = a.gfx_buffer_usage_transfer_source | a.gfx_buffer_usage_transfer_target | a.gfx_buffer_usage_render };
                try d.platform(memory.nativeStart(&allocation, &status));
                item.allocation_request = status.request;
                try d.platform(memory.nativeWait(&item.allocation_request, std.math.maxInt(u64), &status));
                try d.platform(status.result);
                try d.platform(memory.nativeReceive(&item.allocation_request, &item.backing));
                item.allocation_request = .{};
            },
            c.source_create_system => {
                const image = request.image;
                var descriptor: a.GfxBufferDescriptor = .{ .byte_length = image.byte_length, .width = image.width, .height = image.height,
                    .format = image.format, .plane_count = 1, .plane_pitches = .{ image.pitch, 0, 0, 0 },
                    .usage = a.gfx_buffer_usage_cpu_read | a.gfx_buffer_usage_cpu_write | a.gfx_buffer_usage_transfer_source | a.gfx_buffer_usage_transfer_target | a.gfx_buffer_usage_render };
                try d.platform(memory.create(&descriptor, &item.backing));
            },
            c.source_import_buffer => try d.platform(memory.import(&reference, &item.backing)),
            c.source_shared_raster => try d.platform(memory.exportRaster(&raster, &item.backing)),
            else => unreachable,
        }
        if (item.backing.reference.id == 0 or item.backing.reference.generation == 0 or item.backing.buffer.id == 0 or item.backing.buffer.generation == 0 or
            item.backing.flags & ~a.gfx_buffer_reference_immutable != 0 or (item.flags & c.image_target != 0 and item.backing.flags & a.gfx_buffer_reference_immutable != 0)) return error.Unsupported;
        try d.platform(memory.describe(&item.backing.reference, &item.descriptor));
        if (item.descriptor.location == a.gfx_buffer_location_device_local and
            (item.descriptor.adapter_id != device.selected.binding.adapter_id or item.descriptor.device_generation != device.selected.memory_generation)) return error.Stale;
        item.image = try descriptorImage(item.descriptor);
        if (request.source_kind != c.source_create_system and request.source_kind != c.source_create_native) {
            device.counters.imports +|= 1;
            device.counters.imported_bytes +|= item.image.byte_length;
        }
    }
    item.public_refs = 1;
    output.* = device.resourceHandle(index);
    return c.status_ok;
}

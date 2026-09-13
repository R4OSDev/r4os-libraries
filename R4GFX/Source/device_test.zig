//! Focused device integration inside the existing R4GFX provider test.
//! Kernel callbacks below model ownership/retirement; R4NV negotiation and
//! the CPU renderer are the actual providers, not test substitutes.
const std = @import("std");
const t = std.testing;
const a = @import("r4os").abi;
const nv = @import("r4nv_binding");
const nv_provider = @import("r4nv_backend");
const d = @import("device.zig");
const c = d.c;
const api = &@import("main.zig").r4gfx_device_v1;
const Model = struct {
    const Object = struct { bytes: [65536]u8 = @splat(0), descriptor: a.GfxBufferDescriptor = .{}, live: bool = false };
    const Ref = struct { object: ?usize = null, generation: u64 = 0, mapped: bool = false };
    const Queue = struct { handle: a.GfxQueueHandle = .{}, config: a.GfxQueueConfig = .{} };
    var objects: [4]Object = @splat(.{});
    var references: [16]Ref = @splat(.{});
    var queues: [4]Queue = @splat(.{});
    var serial: u64 = 0x100000000;
    var exports: usize = 0;
    var maps: usize = 0;
    var fail_unmap = false;
    var premature_closes: usize = 0;
    var inventory_reads: usize = 0;
    var status: a.GfxFenceStatus = .{};
    var job_live = false;
    var job_request: a.GfxSubmission = .{};
    var operations: u64 = 7;
    var dependency_seen = false;
    var native_request: a.GfxNativeAllocation = .{};
    var native_handle: a.GfxBufferHandle = .{};
    var native_result: i32 = 1;
    var native_starts: usize = 0;
    var bad_native_layout = false;
    var binding: a.GfxBackendBinding = .{ .adapter_id = 9, .milestone = 1, .device_generation = 0x200000017, .reset_generation = 0x300000017 };
    var nv_table: nv.BackendV1 = .{ .header = nv.backend_v1_header,
        .negotiate = @ptrCast(&nv_provider.r4nv_negotiate_impl), .encode_copy = @ptrCast(&nv_provider.r4nv_encode_copy_impl),
        .encode_copy_layout = @ptrCast(&nv_provider.r4nv_encode_copy_layout_impl),
        .image_layout = @ptrCast(&nv_provider.r4nv_image_layout_impl) };

    fn reset() void {
        objects = @splat(.{}); references = @splat(.{}); queues = @splat(.{});
        serial = 0x100000000; exports = 0; maps = 0; fail_unmap = false; premature_closes = 0; inventory_reads = 0; job_live = false;
        binding = .{ .adapter_id = 9, .milestone = 1, .device_generation = 0x200000017, .reset_generation = 0x300000017 };
        nv_table.header = nv.backend_v1_header;
        operations = 7; dependency_seen = false;
        native_request = .{}; native_handle = .{}; native_result = 1;
        native_starts = 0; bad_native_layout = false;
    }
    fn ref(handle: a.GfxBufferHandle) *Ref {
        std.debug.assert(handle.id != 0 and handle.id <= references.len and handle.reserved0 == 0);
        const value = &references[handle.id - 1];
        std.debug.assert(value.object != null and value.generation == handle.generation);
        return value;
    }
    fn lend(index: usize, out: *a.GfxBufferReference, immutable: bool) i32 {
        std.debug.assert(out.version == 1 and out.size == 48);
        for (&references, 0..) |*value, i| if (value.object == null) {
            serial += 1;
            value.* = .{ .object = index, .generation = serial };
            out.* = .{ .buffer = .{ .id = @intCast(index + 100), .generation = 1 },
                .reference = .{ .id = @intCast(i + 1), .generation = serial }, .flags = if (immutable) a.gfx_buffer_reference_immutable else 0 };
            return 1;
        };
        return a.gfx_buffer_error_capacity;
    }
    fn create(input: *const a.GfxBufferDescriptor, out: *a.GfxBufferReference) callconv(.c) i32 {
        for (&objects, 0..) |*object, i| if (!object.live) {
            std.debug.assert(input.byte_length <= object.bytes.len);
            object.* = .{ .live = true, .descriptor = input.* };
            return lend(i, out, false);
        };
        return a.gfx_buffer_error_capacity;
    }
    fn describe(input: *const a.GfxBufferHandle, out: *a.GfxBufferDescriptor) callconv(.c) i32 {
        out.* = objects[ref(input.*).object.?].descriptor; return 1;
    }
    fn nativeStart(input: *const a.GfxNativeAllocation, out: *a.GfxNativeStatus) callconv(.c) i32 {
        std.debug.assert(native_handle.id == 0 and input.adapter_id == binding.adapter_id and input.memory_generation == 73 and input.kind == 1);
        serial += 1;
        native_starts += 1;
        native_request = input.*; native_handle = .{ .id = 1, .generation = serial };
        out.* = .{ .request = native_handle, .deadline_ns = input.deadline_ns };
        return 1;
    }
    fn nativeWait(input: *const a.GfxBufferHandle, ticks: u64, out: *a.GfxNativeStatus) callconv(.c) i32 {
        std.debug.assert(std.meta.eql(input.*, native_handle) and ticks == std.math.maxInt(u64));
        out.* = .{ .request = native_handle, .phase = 2, .result = native_result }; return 1;
    }
    fn nativeReceive(input: *const a.GfxBufferHandle, out: *a.GfxBufferReference) callconv(.c) i32 {
        std.debug.assert(std.meta.eql(input.*, native_handle) and native_result == 1);
        // This bounded fixture uses4x4 images with the actual native storage
        // geometry. A tiled view is one GOB; the image allocation is64KB.
        std.debug.assert(native_request.width == 4 and native_request.height == 4 and native_request.layout <= 1);
        const modifier: u64 = if (bad_native_layout) 1 else if (native_request.layout == 1) 0x0300000000606010 else 0;
        const rc = create(&.{ .byte_length = 65536, .alignment = 65536, .modifier = modifier,
            .width = native_request.width, .height = native_request.height, .format = native_request.format,
            .plane_count = 1, .plane_pitches = .{if (native_request.layout == 1) 64 else 256, 0, 0, 0}, .usage = native_request.usage, .location = 1,
            .adapter_id = binding.adapter_id, .device_generation = 73, .driver_owner = 79 }, out);
        if (rc == 1) native_handle = .{};
        return rc;
    }
    fn nativeClose(input: *const a.GfxBufferHandle) callconv(.c) i32 {
        std.debug.assert(std.meta.eql(input.*, native_handle)); native_handle = .{}; return 1;
    }
    fn import(input: *const a.GfxBufferHandle, out: *a.GfxBufferReference) callconv(.c) i32 { return lend(ref(input.*).object.?, out, false); }
    fn release(input: *const a.GfxBufferHandle) callconv(.c) i32 {
        const value = ref(input.*); std.debug.assert(!value.mapped);
        const object = value.object.?; value.object = null;
        for (&references) |*other| if (other.object == object) return 1;
        objects[object].live = false; return 1;
    }
    fn map(input: *const a.GfxBufferHandle, access: u32, offset: u64, bytes: u64, out: *a.GfxBufferMap) callconv(.c) i32 {
        const value = ref(input.*);
        std.debug.assert(!value.mapped and access <= 1 and offset == 0 and bytes == 64);
        value.mapped = true; maps += 1;
        out.* = .{ .lease = input.*, .cpu_address = @intFromPtr(&objects[value.object.?].bytes), .byte_length = bytes };
        return 1;
    }
    fn unmap(input: *const a.GfxBufferHandle) callconv(.c) i32 {
        const value = ref(input.*); std.debug.assert(value.mapped);
        if (fail_unmap) return a.gfx_buffer_error_busy;
        value.mapped = false; return 1;
    }
    fn exportRaster(input: *const a.GuiSharedRasterLease, out: *a.GfxBufferReference) callconv(.c) i32 {
        std.debug.assert(input.handle.id == 0x100000011 and input.handle.generation == 0x200000011 and input.raster_generation == 7 and input.lease_token == 9);
        exports += 1;
        objects[3] = .{ .live = true, .descriptor = .{ .byte_length = 64, .width = 4, .height = 4, .format = c.format_xrgb8888,
            .plane_count = 1, .plane_pitches = .{ 16, 0, 0, 0 }, .usage = 5 } };
        return lend(3, out, true);
    }
    fn backendInfo(index: u32, out: *a.GfxBackendInfo) callconv(.c) i32 {
        inventory_reads += 1;
        if (index != 1) return 0;
        out.* = .{ .binding = binding, .operations = operations, .memory_generation = 73, .profile = .{ .interface_id_lo = nv.backend_v1_header.interface_id_lo,
            .interface_id_hi = nv.backend_v1_header.interface_id_hi, .revision = 1, .data_bytes = 32 } };
        const details: nv.R4NvDriverProfile = .{ .version = 1, .size = 32, .vendor_id = 0x10de, .copy_class = 0xc6b5,
            .rm_release = nv.rm_release, .command_abi = nv.command_abi, .reserved0 = 0, .reserved1 = 0 };
        @memcpy(out.profile.data[0..32], std.mem.asBytes(&details)); return 1;
    }
    fn open(input: *const a.GfxQueueConfig, out: *a.GfxQueueHandle) callconv(.c) i32 {
        if (input.adapter_id != 0) std.debug.assert(input.adapter_id == binding.adapter_id and input.device_generation == binding.device_generation and input.reset_generation == binding.reset_generation);
        for (&queues) |*queue| if (queue.handle.timeline == 0) {
            serial += 1; queue.* = .{ .handle = .{ .timeline = serial }, .config = input.* }; out.* = queue.handle; return 1;
        };
        return a.gfx_queue_error_capacity;
    }
    fn close(input: *const a.GfxQueueHandle) callconv(.c) i32 {
        if (job_live and status.fence.timeline == input.timeline) { premature_closes += 1; return a.gfx_queue_error_busy; }
        for (&queues) |*queue| if (queue.handle.timeline == input.timeline) { queue.* = .{}; return 1; };
        return a.gfx_queue_error_stale;
    }
    fn submit(queue: *const a.GfxQueueHandle, input: *const a.GfxSubmission, out: *a.GfxFenceStatus) callconv(.c) i32 {
        std.debug.assert((input.operation == a.gfx_queue_operation_copy or input.operation == a.gfx_queue_operation_copy_rows or
            input.operation == a.gfx_queue_operation_render or input.operation == a.gfx_queue_operation_present) and input.dependency_count <= 1);
        if (input.dependency_count == 1) {
            std.debug.assert(job_live and std.meta.eql(input.dependencies[0], status.fence));
            dependency_seen = true;
        }
        if (job_live) return a.gfx_queue_error_busy;
        const found = for (&queues) |*entry| { if (entry.handle.timeline == queue.timeline) break entry; } else unreachable;
        status = .{ .fence = .{ .slot = 1, .timeline = queue.timeline, .point = 0x400000017, .adapter_id = found.config.adapter_id,
            .device_generation = found.config.device_generation, .reset_generation = found.config.reset_generation },
            .phase = a.gfx_queue_phase_running, .flags = a.gfx_queue_flag_device_active | a.gfx_queue_flag_resources_held, .milestone = found.config.milestone };
        job_request = input.*; job_live = true; out.* = status; return 1;
    }
    fn query(input: *const a.GfxFence, out: *a.GfxFenceStatus) callconv(.c) i32 {
        std.debug.assert(job_live and std.meta.eql(input.*, status.fence)); out.* = status; return 1;
    }
    fn cancel(input: *const a.GfxFence) callconv(.c) i32 {
        std.debug.assert(job_live and std.meta.eql(input.*, status.fence));
        if (status.phase == a.gfx_queue_phase_terminal) return a.gfx_queue_error_already_completed;
        status.phase = a.gfx_queue_phase_terminal; status.result = a.gfx_queue_result_cancelled; return 1;
    }
    fn drop(input: *const a.GfxFence) callconv(.c) i32 {
        std.debug.assert(job_live and std.meta.eql(input.*, status.fence) and status.phase == a.gfx_queue_phase_terminal and status.flags == 0);
        job_live = false; return 1;
    }
    fn complete() void {
        const source = ref(job_request.source); const target = ref(job_request.target);
        std.debug.assert(!source.mapped and !target.mapped);
        // Tiled execution belongs to NVIDIA's CE model; this generic fixture
        // must never turn an opaque layout into a linear byte copy.
        std.debug.assert(objects[source.object.?].descriptor.modifier == 0 and objects[target.object.?].descriptor.modifier == 0);
        const count = if (job_request.row_count == 0) 1 else job_request.row_count;
        for (0..count) |row| {
            const src = job_request.source_offset + row * job_request.source_pitch;
            const dst = job_request.target_offset + row * job_request.target_pitch;
            @memcpy(objects[target.object.?].bytes[dst..][0..job_request.byte_length], objects[source.object.?].bytes[src..][0..job_request.byte_length]);
        }
        status.phase = a.gfx_queue_phase_terminal; status.result = a.gfx_queue_result_complete; status.flags = 0;
    }
    fn referenceCount() usize { var count: usize = 0; for (&references) |*value| if (value.object != null) { count += 1; }; return count; }
};

fn descriptor(kind: u32) c.R4GfxResourceDesc {
    var value = std.mem.zeroes(c.R4GfxResourceDesc);
    value.version = 1; value.size = @sizeOf(c.R4GfxResourceDesc); value.kind = kind; return value;
}
fn cpuImage(bytes: []u8) c.R4GfxResourceDesc {
    var value = descriptor(c.resource_image); value.flags = c.image_target; value.source_kind = c.source_borrow_cpu; value.source_generation = 1;
    value.image = .{ .cpu_address = @intFromPtr(bytes.ptr), .byte_length = bytes.len, .pitch = 16, .width = 4, .height = 4, .format = c.format_xrgb8888, .reserved = 0 };
    return value;
}
pub fn check() !void {
    Model.reset();
    const storage = try t.allocator.create(d.Device); defer t.allocator.destroy(storage); storage.* = .{};
    const other_storage = try t.allocator.create(d.Device); defer t.allocator.destroy(other_storage); other_storage.* = .{};
    const sys: a.R4XStartR4Sys = .{};
    var draw: a.R4XStartR4Draw = .{ .gfx_buffer_create = @intFromPtr(&Model.create), .gfx_buffer_describe = @intFromPtr(&Model.describe),
        .gfx_native_start = @intFromPtr(&Model.nativeStart), .gfx_native_wait = @intFromPtr(&Model.nativeWait),
        .gfx_native_receive = @intFromPtr(&Model.nativeReceive), .gfx_native_close = @intFromPtr(&Model.nativeClose),
        .gfx_buffer_import = @intFromPtr(&Model.import), .gfx_buffer_release = @intFromPtr(&Model.release), .gfx_buffer_map = @intFromPtr(&Model.map),
        .gfx_buffer_unmap = @intFromPtr(&Model.unmap), .gfx_buffer_export_raster = @intFromPtr(&Model.exportRaster), .gfx_queue_backend_info = @intFromPtr(&Model.backendInfo),
        .gfx_queue_open = @intFromPtr(&Model.open), .gfx_queue_close = @intFromPtr(&Model.close), .gfx_queue_submit = @intFromPtr(&Model.submit),
        .gfx_fence_query = @intFromPtr(&Model.query), .gfx_fence_cancel = @intFromPtr(&Model.cancel), .gfx_fence_release = @intFromPtr(&Model.drop) };
    var imports = [_]a.R4XStartImport{
        .{ .group_id = @intFromEnum(a.R4LGroup.r4sys), .flags = a.r4xstart_import_flag_group_interface, .table = @intFromPtr(&sys) },
        .{ .group_id = @intFromEnum(a.R4LGroup.r4draw), .flags = a.r4xstart_import_flag_group_interface, .table = @intFromPtr(&draw) },
        .{ .module_name = @intFromPtr("R4NV"), .symbol_name = @intFromPtr("BACKEND_V1"), .min_version = nv.backend_v1_revision },
    };
    const raw: a.R4XStartContext = .{ .flags = a.r4xstart_flag_imports_valid, .imports = @intFromPtr(&imports), .import_count = imports.len, .instance_id = 7 };
    var config: c.R4GfxDeviceConfig = .{ .version = 1, .size = @sizeOf(c.R4GfxDeviceConfig), .storage_address = @intFromPtr(storage),
        .storage_bytes = api.storage_size(), .start_context = @intFromPtr(&raw), .preferred_adapter = 0, .flags = 0 };
    var handle: c.R4GfxDevice = undefined; var other: c.R4GfxDevice = undefined;
    try t.expectEqual(c.status_ok, api.device_open(&config, &handle));
    var state: c.R4GfxDeviceInfo = undefined;
    try t.expectEqual(c.status_ok, api.device_info(&handle, &state));
    try t.expect(state.backend == c.render_backend_software and state.gpu_operations == 0 and Model.inventory_reads == 0);
    var alias_bytes: [@sizeOf(c.R4GfxDeviceInfo)]u8 align(8) = @splat(0);
    @memcpy(alias_bytes[0..@sizeOf(c.R4GfxDevice)], std.mem.asBytes(&handle));
    try t.expectEqual(c.status_alias, api.device_info(@ptrCast(&alias_bytes), @ptrCast(&alias_bytes)));
    try t.expectEqualSlices(u8, std.mem.asBytes(&handle), alias_bytes[0..@sizeOf(c.R4GfxDevice)]);
    config.storage_address = @intFromPtr(other_storage); try t.expectEqual(c.status_ok, api.device_open(&config, &other));
    var pixels: [64]u8 align(8) = @splat(0xa5);
    var target: c.R4GfxResource = undefined; var fill: c.R4GfxResource = undefined;
    const image = cpuImage(&pixels);
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &image, &target));
    var fill_desc = descriptor(c.resource_pipeline); fill_desc.operation = c.render_operation_fill;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &fill_desc, &fill));
    try t.expectEqual(c.status_stale, api.resource_retain(&other, &target));
    var commands: [2]c.R4GfxDraw = @splat(std.mem.zeroes(c.R4GfxDraw));
    commands[0].target = target; commands[0].pipeline = fill; commands[0].target_rect = .{ .x = 0, .y = 0, .width = 4, .height = 4 }; commands[0].color = 0x123456;
    commands[1] = commands[0]; commands[1].target_rect.width = 5;
    var batch: c.R4GfxRenderBatch = .{ .commands = @intFromPtr(&commands), .command_count = 2, .flags = 0, .pixel_budget = 32 };
    var stats = std.mem.zeroes(c.R4GfxRenderStats); stats.cpu.pixels = 71;
    const aliased_batch: *c.R4GfxRenderBatch = @ptrCast(&storage.images);
    aliased_batch.* = .{ .commands = 0, .command_count = 0, .flags = 0, .pixel_budget = 0 };
    try t.expectEqual(c.status_alias, api.render(&handle, aliased_batch, &stats));
    try t.expectEqual(c.status_invalid, api.render(&handle, &batch, &stats));
    try t.expect(stats.cpu.pixels == 71 and std.mem.allEqual(u8, &pixels, 0xa5));
    batch.command_count = 1;
    try t.expectEqual(c.status_ok, api.render(&handle, &batch, &stats));
    try t.expect(stats.cpu.pixels == 16 and stats.cpu.write_bytes == 64 and stats.fallback == 0 and Model.maps == 0);
    for (0..16) |i| try t.expectEqual(@as(u32, 0x123456), std.mem.readInt(u32, pixels[i * 4 ..][0..4], .little));
    var twin: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &image, &twin));
    try t.expectEqualDeep(target, twin);
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &twin));
    const old = handle;
    try t.expectEqual(c.status_ok, api.device_close(&handle));
    config.storage_address = @intFromPtr(storage);
    try t.expectEqual(c.status_ok, api.device_open(&config, &handle));
    try t.expect(handle.generation > old.generation);
    try t.expectEqual(c.status_stale, api.resource_retain(&handle, &target));
    try t.expectEqual(c.status_stale, api.device_info(&old, &state));
    try t.expectEqual(c.status_ok, api.device_close(&other));
    // A mismatched optional R4NV interface preserves the same software device.
    imports[2].table = @intFromPtr(&Model.nv_table); imports[2].resolved_version = nv.backend_v1_revision;
    Model.nv_table.header.abi_major = 2;
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &state));
    try t.expect(state.backend == c.render_backend_software);
    Model.nv_table.header = nv.backend_v1_header;
    draw.size = 640; // Legacy R4DRAW has no profile tail.
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &state));
    try t.expect(state.backend == c.render_backend_software);
    draw.size = @sizeOf(a.R4XStartR4Draw);
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &state));
    try t.expect(state.backend == c.render_backend_nvidia and state.gpu_operations == c.device_gpu_copy and state.reset_generation == Model.binding.reset_generation);
    const native_image: c.R4GfxNativeImage = .{ .version = 1, .size = 32, .deadline_ns = 99999999, .width = 4, .height = 4,
        .format = c.format_xrgb8888, .layout = 0 };
    var create_native = descriptor(c.resource_image); create_native.source_kind = c.source_create_native;
    create_native.source_address = @intFromPtr(&native_image); create_native.flags = c.image_target;
    var allocated: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &create_native, &allocated));
    var allocated_info: c.R4GfxResourceInfo = undefined;
    try t.expectEqual(c.status_ok, api.resource_info(&handle, &allocated, &allocated_info));
    try t.expect(allocated_info.image.pitch == 256 and allocated_info.image.byte_length == 65536 and Model.native_handle.id == 0);
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &allocated));
    const untouched = allocated;
    Model.native_result = a.gfx_buffer_error_oom;
    try t.expectEqual(c.status_limit, api.resource_create(&handle, &create_native, &allocated));
    try t.expectEqualDeep(untouched, allocated);
    try t.expect(Model.native_handle.id == 0);
    Model.native_result = 1;
    // Canonical shared raster generation is exported once and never uploaded.
    const lease: a.GuiSharedRasterLease = .{ .handle = .{ .id = 0x100000011, .generation = 0x200000011 }, .raster_generation = 7, .lease_token = 9 };
    var shared_desc = descriptor(c.resource_image); shared_desc.source_kind = c.source_shared_raster; shared_desc.source_address = @intFromPtr(&lease);
    var shared: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &shared_desc, &shared));
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &shared_desc, &twin));
    try t.expectEqualDeep(shared, twin); try t.expect(Model.exports == 1);
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &twin));
    var system = cpuImage(&pixels); system.source_kind = c.source_create_system; system.source_generation = 0; system.image.cpu_address = 0;
    var source: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &system, &source));
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &system, &target));
    // A native imported BO has its own lifetime and must become stale at
    // reset, while the two system images and the immutable raster survive.
    Model.objects[2] = .{ .live = true, .descriptor = Model.objects[0].descriptor };
    Model.objects[2].descriptor.location = a.gfx_buffer_location_device_local;
    Model.objects[2].descriptor.adapter_id = Model.binding.adapter_id;
    Model.objects[2].descriptor.device_generation = Model.binding.device_generation;
    var native_reference: a.GfxBufferReference = .{};
    try t.expectEqual(@as(i32, 1), Model.lend(2, &native_reference, false));
    var native_desc = descriptor(c.resource_image); native_desc.flags = c.image_target;
    native_desc.source_kind = c.source_import_buffer; native_desc.source_address = @intFromPtr(&native_reference.reference);
    var native: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_stale, api.resource_create(&handle, &native_desc, &native));
    Model.objects[2].descriptor.device_generation = 73; // Advertised memory epoch, not queue identity.
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &native_desc, &native));
    try t.expectEqual(@as(i32, 1), Model.release(&native_reference.reference));
    @memset(&Model.objects[0].bytes, 0x31);
    var job: c.R4GfxJob = undefined;
    const copy: c.R4GfxCopyRequest = .{ .source = source, .target = target, .source_offset = 8, .target_offset = 12, .byte_length = 16, .deadline_ns = 99999999 };
    try t.expectEqual(c.status_ok, api.copy_submit(&handle, &copy, &job));
    var receipt: c.R4GfxJobInfo = undefined;
    try t.expectEqual(c.status_ok, api.job_info(&handle, &job, &receipt));
    const old_reset = receipt.reset_generation;
    Model.binding.reset_generation += 1;
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &state));
    try t.expect(state.reset_generation != old_reset and Model.premature_closes == 0);
    var native_info: c.R4GfxResourceInfo = undefined;
    try t.expectEqual(c.status_ok, api.resource_info(&handle, &native, &native_info));
    try t.expect(native_info.flags & c.resource_invalidated != 0);
    var invalid_copy = copy; invalid_copy.source = native;
    var rejected_job: c.R4GfxJob = undefined;
    try t.expectEqual(c.status_stale, api.copy_submit(&handle, &invalid_copy, &rejected_job));
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &native));
    try t.expectEqual(c.status_busy, api.job_release(&handle, &job));
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &source));
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &target));
    try t.expect(Model.referenceCount() == 3); // Two copy sources plus the retained raster.
    Model.complete();
    try t.expectEqual(c.status_ok, api.job_info(&handle, &job, &receipt));
    try t.expect(receipt.reset_generation == old_reset and receipt.flags == 0);
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expect(Model.referenceCount() == 1 and Model.premature_closes == 0);
    try t.expectEqual(c.status_ok, api.device_info(&handle, &state));
    try t.expect(state.gpu_copy_bytes == 16 and state.upload_bytes == 0 and state.imports == 2 and state.imported_bytes == 128 and Model.exports == 1);
    // Cancellation is logical. Close must not lose its still-active fence.
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &system, &source));
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &system, &target));
    var row_copy = std.mem.zeroes(c.R4GfxCopyRequestEx);
    row_copy.version = 1; row_copy.size = @sizeOf(c.R4GfxCopyRequestEx);
    row_copy.copy = .{ .source = source, .target = target, .source_offset = 4, .target_offset = 8, .byte_length = 4, .deadline_ns = 99999999 };
    row_copy.row_count = 3; row_copy.source_pitch = 16; row_copy.target_pitch = 16;
    @memset(&Model.objects[0].bytes, 0x37);
    try t.expectEqual(c.status_ok, api.copy_submit_ex(&handle, &row_copy, &job));
    try t.expectEqual(c.status_ok, api.job_info(&handle, &job, &receipt));
    try t.expectEqual(c.render_backend_software, receipt.backend); // Old native profile lacks row transport.
    var dependency: c.R4GfxCopyFence = undefined;
    try t.expectEqual(c.status_ok, api.job_fence(&handle, &job, &dependency));
    try t.expectEqualDeep(Model.status.fence, @as(a.GfxFence, @bitCast(dependency)));
    row_copy.dependency_count = 1; row_copy.dependencies = @intFromPtr(&dependency);
    try t.expectEqual(c.status_busy, api.copy_submit_ex(&handle, &row_copy, &rejected_job));
    try t.expect(Model.dependency_seen); // Exact identity forwarded; kernel owner case proves admission/order.
    Model.complete();
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expectEqual(c.status_ok, api.device_info(&handle, &state));
    try t.expect(state.gpu_copy_bytes == 16 and state.cpu_read_bytes == 12 and state.cpu_write_bytes == 12);
    for (0..3) |row| try t.expectEqualSlices(u8, &.{0x37,0x37,0x37,0x37}, Model.objects[1].bytes[8 + row * 16 ..][0..4]);
    Model.operations = 15;
    row_copy.dependency_count = 0; row_copy.dependencies = 0;
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &state));
    try t.expectEqual(@as(u32, 7), state.gpu_operations);
    try t.expectEqual(c.status_ok, api.copy_submit_ex(&handle, &row_copy, &job));
    try t.expectEqual(c.status_ok, api.job_info(&handle, &job, &receipt));
    try t.expectEqual(c.render_backend_nvidia, receipt.backend);
    Model.complete();
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expectEqual(c.status_ok, api.device_info(&handle, &state));
    try t.expect(state.gpu_copy_bytes == 28 and state.cpu_read_bytes == 12 and state.cpu_write_bytes == 12);
    var cancelled_copy = copy; cancelled_copy.source = source; cancelled_copy.target = target;
    try t.expectEqual(c.status_ok, api.copy_submit(&handle, &cancelled_copy, &job));
    try t.expectEqual(c.status_busy, api.device_close(&handle));
    try t.expect(Model.status.result == a.gfx_queue_result_cancelled and Model.referenceCount() == 2 and Model.job_live and Model.premature_closes == 0);
    Model.status.flags = 0; // Explicit model acknowledgement of physical stop.
    try t.expectEqual(c.status_ok, api.device_close(&handle));
    try t.expect(Model.referenceCount() == 0 and !Model.job_live and Model.premature_closes == 0);
    // Failed CPU unmap retains backing until explicit recovery.
    try t.expectEqual(c.status_ok, api.device_open(&config, &handle));
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &system, &target));
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &fill_desc, &fill));
    commands[0].target = target; commands[0].pipeline = fill;
    Model.fail_unmap = true;
    try t.expectEqual(c.status_busy, api.render(&handle, &batch, &stats));
    try t.expectEqual(c.status_busy, api.device_close(&handle));
    try t.expect(Model.referenceCount() == 1);
    Model.fail_unmap = false;
    try t.expectEqual(c.status_ok, api.device_close(&handle));
    try t.expect(Model.referenceCount() == 0 and Model.premature_closes == 0);
    try checkNativeRender(&config);
    try checkNativePresent(&config);
    try checkImagePreparation(&config);
    try checkTiledPreparation(&config);
}

fn checkTiledPreparation(config: *const c.R4GfxDeviceConfig) !void {
    for ([_]u32{c.prepare_use_texture,c.prepare_use_scanout}) |uses| {
        Model.reset(); Model.operations = 29;
        var handle: c.R4GfxDevice = undefined;
        try t.expectEqual(c.status_ok,api.device_open(config,&handle));
        const device = try d.get(&handle,false);
        var desc = descriptor(c.resource_image); desc.source_kind = c.source_create_system;
        desc.image = .{ .cpu_address = 0, .byte_length = 64, .pitch = 16, .width = 4, .height = 4, .format = c.format_argb8888, .reserved = 0 };
        var source: c.R4GfxResource = undefined;
        try t.expectEqual(c.status_ok,api.resource_create(&handle,&desc,&source));
        var ready: [1]c.R4GfxCopyFence = undefined;
        var request: c.R4GfxImagePrepareRequest = .{ .version = 1, .size = @sizeOf(c.R4GfxImagePrepareRequest),
            .source = source, .uses = uses, .preference = c.prepare_layout_compatible, .flags = 0,
            .deadline_ns = 99999999, .byte_budget = 65536, .dependency_count = 0, .dependencies = 0,
            .ready_dependencies = @intFromPtr(&ready), .ready_capacity = 1, .reserved = 0 };
        var result: c.R4GfxPreparedImage = undefined;
        const source_resource = try device.resource(source,true);
        source_resource.descriptor.modifier = 1;
        try t.expectEqual(c.status_unsupported,api.image_prepare(&handle,&request,&result));
        try t.expect(Model.native_starts == 0 and Model.referenceCount() == 1);
        source_resource.descriptor.modifier = 0;
        try t.expectEqual(c.status_ok,api.image_prepare(&handle,&request,&result));
        try t.expect(result.flags == c.prepared_copy_pending and Model.maps == 0 and Model.native_request.layout == 1 and
            Model.native_request.usage == @as(u32,if (uses == c.prepare_use_scanout) 60 else 28) and
            Model.job_request.source_pitch == 16 and Model.job_request.target_pitch == 64 and Model.job_request.byte_length == 16);
        // A second conversion forwards readiness to submission. This one-job
        // fixture rejects it as busy; the new target must be cleaned while
        // the first image/job and caller output remain intact.
        request.dependencies = @intFromPtr(&ready); request.dependency_count = 1;
        const untouched = result;
        try t.expectEqual(c.status_busy,api.image_prepare(&handle,&request,&result));
        try t.expectEqualDeep(untouched,result);
        try t.expect(Model.dependency_seen and Model.native_starts == 2 and Model.referenceCount() == 2);
        // Do not fabricate tiled pixel completion in this generic fixture.
        // NVIDIA's separate CE/GR owner case executes and checks those bytes.
        Model.status.phase = a.gfx_queue_phase_terminal; Model.status.flags = 0; Model.status.result = a.gfx_queue_result_failed;
        try t.expectEqual(c.status_ok,api.job_release(&handle,&result.job));
        try t.expectEqual(c.status_ok,api.resource_release(&handle,&result.image));
        try t.expectEqual(c.status_ok,api.resource_release(&handle,&source));
        try t.expect(Model.referenceCount() == 0 and Model.premature_closes == 0);
        try t.expectEqual(c.status_ok,api.device_close(&handle));
    }
}

fn checkImagePreparation(base_config: *const c.R4GfxDeviceConfig) !void {
    for ([_]bool{false,true}) |software| {
        Model.reset(); Model.operations = 29;
        var config = base_config.*; config.flags = if (software) c.device_software_only else 0;
        var handle: c.R4GfxDevice = undefined;
        try t.expectEqual(c.status_ok,api.device_open(&config,&handle));
        const device = try d.get(&handle,false);
        var source_desc = descriptor(c.resource_image);
        source_desc.source_kind = c.source_create_system;
        source_desc.image = .{ .cpu_address = 0, .byte_length = 64, .pitch = 16, .width = 4, .height = 4, .format = c.format_argb8888, .reserved = 0 };
        var source: c.R4GfxResource = undefined;
        try t.expectEqual(c.status_ok,api.resource_create(&handle,&source_desc,&source));
        const source_resource = try device.resource(source,true);
        @memset(Model.objects[Model.ref(source_resource.backing.reference).object.?].bytes[0..64],0x53);
        var ready: [1]c.R4GfxCopyFence = .{std.mem.zeroes(c.R4GfxCopyFence)}; ready[0].timeline = 79;
        const untouched_ready = ready;
        var output: c.R4GfxPreparedImage = std.mem.zeroes(c.R4GfxPreparedImage); output.flags = 79;
        const untouched = output;
        var request: c.R4GfxImagePrepareRequest = .{ .version = 1, .size = @sizeOf(c.R4GfxImagePrepareRequest),
            .source = source, .uses = c.prepare_use_texture, .preference = c.prepare_layout_linear, .flags = c.prepare_force_copy,
            .deadline_ns = 99999999, .byte_budget = 0, .dependencies = 0, .dependency_count = 0,
            .ready_dependencies = @intFromPtr(&ready), .ready_capacity = 1, .reserved = 0 };
        // A budget/capacity rejection precedes both allocation and output.
        try t.expectEqual(c.status_limit,api.image_prepare(&handle,&request,&output));
        try t.expectEqualDeep(untouched,output); try t.expectEqualDeep(untouched_ready,ready);
        try t.expect(Model.native_starts == 0 and Model.referenceCount() == 1 and !Model.job_live);
        request.byte_budget = if (software) 4096 else 65536;
        request.ready_capacity = 0; request.ready_dependencies = 0;
        try t.expectEqual(c.status_limit,api.image_prepare(&handle,&request,&output));
        request.ready_capacity = 1; request.ready_dependencies = @intFromPtr(&output);
        try t.expectEqual(c.status_alias,api.image_prepare(&handle,&request,&output));
        request.ready_dependencies = @intFromPtr(&ready);
        if (!software) {
            Model.bad_native_layout = true;
            try t.expectEqual(c.status_unsupported,api.image_prepare(&handle,&request,&output));
            try t.expect(Model.referenceCount() == 1 and Model.native_handle.id == 0 and !Model.job_live);
            try t.expectEqualDeep(untouched,output); try t.expectEqualDeep(untouched_ready,ready);
            Model.bad_native_layout = false;
        }
        try t.expectEqual(c.status_ok,api.image_prepare(&handle,&request,&output));
        const copy = output;
        try t.expect(copy.flags == c.prepared_copy_pending|@as(u32,if (software) c.prepared_software else 0) and copy.job.slot != 0 and copy.dependency_count == 1);
        try t.expectEqualDeep(@as(c.R4GfxCopyFence,@bitCast(Model.status.fence)),ready[0]);
        try t.expect(Model.maps == 0 and Model.job_request.operation == a.gfx_queue_operation_copy_rows and
            Model.job_request.byte_length == 16 and Model.job_request.row_count == 4 and Model.job_request.source_pitch == 16 and
            Model.job_request.target_pitch == @as(u64,if (software) 16 else 256));
        if (!software) try t.expect(Model.native_request.layout == 0 and Model.native_request.usage == 28);
        try t.expectEqual(c.status_ok,api.resource_release(&handle,&source));
        try t.expectEqual(c.status_busy,api.job_release(&handle,&copy.job));
        try t.expect(Model.referenceCount() == 2);
        Model.complete();
        const target_resource = try device.resource(copy.image,true);
        const target_data = &Model.objects[Model.ref(target_resource.backing.reference).object.?].bytes;
        for (0..4) |y| for (target_data[y*target_resource.image.pitch..][0..16]) |value| try t.expectEqual(@as(u8,0x53),value);
        var info: c.R4GfxDeviceInfo = undefined;
        var job_info: c.R4GfxJobInfo = undefined;
        try t.expectEqual(c.status_ok,api.job_info(&handle,&copy.job,&job_info));
        try t.expectEqual(c.status_ok,api.device_info(&handle,&info));
        try t.expect(info.gpu_copy_bytes == @as(u64,if (software) 0 else 64) and info.cpu_read_bytes == @as(u64,if (software) 64 else 0) and info.cpu_write_bytes == info.cpu_read_bytes);
        // Reuse retains the image and forwards its still-owned predecessor
        // fence, even when input and output readiness arrays are identical.
        request.source = copy.image; request.flags = 0; request.byte_budget = 0;
        request.dependencies = @intFromPtr(&ready); request.dependency_count = 1;
        const prior = ready;
        const allocations = Model.native_starts;
        try t.expectEqual(c.status_ok,api.image_prepare(&handle,&request,&output));
        try t.expect(output.flags == c.prepared_reused|@as(u32,if (software) c.prepared_software else 0) and output.job.slot == 0 and output.dependency_count == 1);
        try t.expectEqualDeep(copy.image,output.image); try t.expectEqualDeep(prior,ready);
        try t.expect(target_resource.public_refs == 2 and Model.native_starts == allocations);
        // The last public references can close while the copy receipt still
        // owns both BOs; job_release performs the final physical retirement.
        try t.expectEqual(c.status_ok,api.resource_release(&handle,&copy.image));
        try t.expectEqual(c.status_ok,api.resource_release(&handle,&output.image));
        try t.expect(Model.referenceCount() == 2);
        try t.expectEqual(c.status_ok,api.job_release(&handle,&copy.job));
        try t.expect(Model.referenceCount() == 0);
        try t.expectEqual(c.status_ok,api.device_close(&handle));
    }
}

fn checkNativeRender(config: *const c.R4GfxDeviceConfig) !void {
    Model.reset(); Model.operations = 13;
    var handle: c.R4GfxDevice = undefined;
    try t.expectEqual(c.status_ok, api.device_open(config, &handle));
    const device = try d.get(&handle, false);
    const timeline = device.queue.timeline;
    const image_request: c.R4GfxNativeImage = .{ .version = 1, .size = 32, .deadline_ns = 99999999,
        .width = 4, .height = 4, .format = c.format_argb8888, .layout = 0 };
    var image_desc = descriptor(c.resource_image);
    image_desc.flags = c.image_target; image_desc.source_kind = c.source_create_native; image_desc.source_address = @intFromPtr(&image_request);
    var source: c.R4GfxResource = undefined; var target: c.R4GfxResource = undefined;
    var pipeline: c.R4GfxResource = undefined; var sampler: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &image_desc, &target));
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &image_desc, &source));
    var pipeline_desc = descriptor(c.resource_pipeline); pipeline_desc.operation = c.render_operation_fill;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &pipeline_desc, &pipeline));
    var request = std.mem.zeroes(c.R4GfxRenderRequest);
    request.version = 1; request.size = @sizeOf(c.R4GfxRenderRequest); request.deadline_ns = 99999999;
    request.target = target; request.pipeline = pipeline; request.opacity = 255; request.color = 0x80402010;
    request.target_rect = .{ .x = -2, .y = 0, .width = 6, .height = 4 }; request.scissor = .{ .x = 0, .y = 1, .width = 3, .height = 2 };
    var job = std.mem.zeroes(c.R4GfxJob); job.generation = 79;
    const untouched = job;
    try t.expectEqual(c.status_unsupported, api.render_submit(&handle, &request, &job));
    try t.expectEqualDeep(untouched, job);
    var info: c.R4GfxDeviceInfo = undefined;
    Model.operations = 29;
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &info));
    try t.expect(info.gpu_operations & c.device_gpu_render != 0 and device.queue.timeline == timeline);
    try t.expectEqual(c.status_ok, api.render_submit(&handle, &request, &job));
    try t.expect(Model.maps == 0 and Model.job_request.operation == a.gfx_queue_operation_render and Model.job_request.byte_length == 0);
    try t.expect(Model.job_request.source.id == 0 and Model.job_request.target.id != 0);
    try t.expectEqualDeep(@as(a.GfxRenderRect, @bitCast(request.target_rect)), Model.job_request.render.target_rect);
    const copied = Model.job_request.render;
    request.target_rect.x = 123;
    try t.expectEqualDeep(copied, Model.job_request.render);
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &target));
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &pipeline));
    try t.expectEqual(c.status_busy, api.job_release(&handle, &job));
    try t.expect(Model.referenceCount() == 2);
    // A transport model receipt, not execution of NVIDIA instructions.
    Model.status.phase = a.gfx_queue_phase_terminal; Model.status.result = a.gfx_queue_result_complete; Model.status.flags = 0;
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expect(Model.referenceCount() == 1);
    try t.expectEqual(c.status_ok, api.device_info(&handle, &info));
    try t.expect(info.gpu_copy_bytes == 0 and info.cpu_write_bytes == 0 and info.cpu_read_bytes == 0);
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &image_desc, &target));
    pipeline_desc.operation = c.render_operation_over;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &pipeline_desc, &pipeline));
    var sampler_desc = descriptor(c.resource_sampler); sampler_desc.sampler = c.render_sampler_bilinear;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &sampler_desc, &sampler));
    request.target = target; request.source = source; request.pipeline = pipeline; request.sampler = sampler;
    request.target_rect.x = -2; request.source_rect = .{ .x = 0, .y = 0, .width = 4, .height = 4 };
    request.color = 0; request.opacity = 127; request.transfer = c.render_transfer_srgb_decode;
    var invalid = request; invalid.source = target;
    try t.expectEqual(c.status_alias, api.render_submit(&handle, &invalid, &job));
    try t.expectEqual(c.status_ok, api.render_submit(&handle, &request, &job));
    try t.expect(Model.job_request.render.kind == a.gfx_render_kind_sample and Model.job_request.render.filter == 1 and
        Model.job_request.render.blend == 1 and Model.job_request.render.transfer == 1 and Model.job_request.render.opacity == 127);
    var dependency: c.R4GfxCopyFence = undefined;
    try t.expectEqual(c.status_ok, api.job_fence(&handle, &job, &dependency));
    invalid = request; invalid.dependency_count = 1; invalid.dependencies = @intFromPtr(&dependency);
    var denied: c.R4GfxJob = undefined;
    try t.expectEqual(c.status_busy, api.render_submit(&handle, &invalid, &denied));
    try t.expect(Model.dependency_seen);
    Model.operations = 13;
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &info));
    try t.expect(info.gpu_operations & c.device_gpu_render == 0 and device.queue.timeline == timeline and Model.premature_closes == 0);
    try t.expectEqual(c.status_unsupported, api.render_submit(&handle, &request, &denied));
    try t.expectEqual(c.status_ok, api.job_cancel(&handle, &job));
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &source));
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &target));
    try t.expectEqual(c.status_busy, api.job_release(&handle, &job));
    try t.expect(Model.referenceCount() == 2 and Model.maps == 0);
    Model.status.flags = 0;
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expectEqual(c.status_ok, api.device_close(&handle));
    try t.expect(Model.referenceCount() == 0 and Model.premature_closes == 0);
}

fn checkNativePresent(config: *const c.R4GfxDeviceConfig) !void {
    Model.reset(); Model.operations = 29;
    var handle: c.R4GfxDevice = undefined;
    try t.expectEqual(c.status_ok, api.device_open(config, &handle));
    const device = try d.get(&handle, false);
    const timeline = device.queue.timeline;
    const native: c.R4GfxNativeImage = .{ .version = 1, .size = 32, .deadline_ns = 99999999,
        .width = 4, .height = 4, .format = c.format_xrgb8888, .layout = 1 };
    var desc = descriptor(c.resource_image);
    desc.flags = c.image_target; desc.source_kind = c.source_create_native; desc.source_address = @intFromPtr(&native);
    var image: c.R4GfxResource = undefined;
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &desc, &image));
    var request: c.R4GfxImagePresentRequest = .{ .version = 1, .size = 72, .source = image, .deadline_ns = 99999999,
        .frame_key = 7, .dependency_count = 0, .reserved = 0, .dependencies = 0 };
    var job = std.mem.zeroes(c.R4GfxJob); job.generation = 79;
    const original = job;
    try t.expectEqual(c.status_unsupported, api.image_present(&handle, &request, &job));
    try t.expectEqualDeep(original, job);
    Model.operations = 61;
    var info: c.R4GfxDeviceInfo = undefined;
    try t.expectEqual(c.status_ok, api.device_refresh(&handle, &info));
    try t.expect(info.gpu_operations & c.device_gpu_present != 0 and device.queue.timeline == timeline);
    request.reserved = 1;
    try t.expectEqual(c.status_invalid, api.image_present(&handle, &request, &job));
    try t.expectEqualDeep(original, job);
    request.reserved = 0;
    try t.expectEqual(c.status_ok, api.image_present(&handle, &request, &job));
    try t.expect(Model.maps == 0 and Model.job_request.operation == a.gfx_queue_operation_present and
        Model.job_request.target.id == 0 and Model.job_request.source_offset == 0 and Model.job_request.target_offset == 0 and
        Model.job_request.byte_length == 16 and Model.job_request.row_count == 4 and Model.job_request.source_pitch == 64 and Model.job_request.target_pitch == 0);
    request.frame_key = 8;
    try t.expect(Model.job_request.frame_key == 7);
    var dependency: c.R4GfxCopyFence = undefined;
    try t.expectEqual(c.status_ok, api.job_fence(&handle, &job, &dependency));
    request.dependency_count = 1; request.dependencies = @intFromPtr(&dependency);
    var denied = original;
    try t.expectEqual(c.status_busy, api.image_present(&handle, &request, &denied));
    try t.expectEqualDeep(original, denied);
    try t.expect(Model.dependency_seen);
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &image));
    try t.expectEqual(c.status_ok, api.job_cancel(&handle, &job));
    try t.expectEqual(c.status_busy, api.job_release(&handle, &job));
    try t.expect(Model.referenceCount() == 1 and Model.maps == 0);
    Model.status.flags = 0;
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expect(Model.referenceCount() == 0);
    try t.expectEqual(c.status_ok, api.resource_create(&handle, &desc, &image));
    request.source = image; request.dependency_count = 0; request.dependencies = 0;
    try t.expectEqual(c.status_ok, api.image_present(&handle, &request, &job));
    // Transport receipt only. The driver model tests CE and visible flip.
    Model.status.phase = a.gfx_queue_phase_terminal; Model.status.result = a.gfx_queue_result_complete; Model.status.flags = 0;
    try t.expectEqual(c.status_ok, api.job_release(&handle, &job));
    try t.expectEqual(c.status_ok, api.device_info(&handle, &info));
    try t.expect(info.gpu_copy_bytes == 64 and info.cpu_read_bytes == 0 and info.cpu_write_bytes == 0);
    try t.expectEqual(c.status_ok, api.resource_release(&handle, &image));
    try t.expectEqual(c.status_ok, api.device_close(&handle));
    try t.expect(Model.referenceCount() == 0 and Model.premature_closes == 0);
}

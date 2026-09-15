const std = @import("std");
const r4os = @import("r4os");
const c = @import("r4l_contract");
const copy = @import("copy.zig");
const shaders = @import("shader_cache.zig");

export fn r4l_entry() linksection(".text.r4l_entry") callconv(.c) void {}

pub const r4nv_negotiate_impl = @import("backend.zig").r4nv_negotiate_impl;
pub const r4nv_encode_copy_impl = @import("backend.zig").r4nv_encode_copy_impl;
pub const r4nv_encode_copy_layout_impl = @import("backend.zig").r4nv_encode_copy_layout_impl;
pub const r4nv_image_layout_impl = @import("image_layout.zig").r4nv_image_layout_impl;
pub const r4nv_shader_info_impl = shaders.r4nv_shader_info_impl;
pub const r4nv_shader_cache_write_impl = shaders.r4nv_shader_cache_write_impl;
pub const r4nv_shader_cache_read_impl = shaders.r4nv_shader_cache_read_impl;

pub export var r4nv_backend_v1: c.BackendV1 align(8) linksection(".data.r4l_exports") = .{
    .header = c.backend_v1_header,
    .negotiate = r4nv_negotiate_impl,
    .encode_copy = r4nv_encode_copy_impl,
    .encode_copy_layout = r4nv_encode_copy_layout_impl,
    .image_layout = r4nv_image_layout_impl,
};
pub export var r4nv_shader_v1: c.ShaderV1 align(8) linksection(".data.r4l_exports") = .{
    .header = c.shader_v1_header,
    .shader_info = r4nv_shader_info_impl,
    .shader_cache_write = r4nv_shader_cache_write_impl,
    .shader_cache_read = r4nv_shader_cache_read_impl,
};
pub export var r4nv_query: r4os.abi.R4LQuery align(8) linksection(".data.r4l_exports") = .{
    .magic = r4os.abi.r4l_abi_magic, .abi_version = r4os.abi.r4l_abi_version,
    .size = r4os.abi.r4l_query_struct_size, .group = 0, .kernel_bridge = 0, .reserved = 0,
};

test "backend and shader ABI preserve operands, executable identity and rejected outputs" {
    try @import("telemetry_checks.zig").run();
    const t = std.testing;
    try @import("image_layout_checks.zig").run(&r4nv_backend_v1);
    try @import("render_image_test.zig").check();
    var profile: c.R4NvDeviceProfile = .{ .version = 1, .size = @sizeOf(c.R4NvDeviceProfile),
        .vendor_id = 0x10de, .copy_class = 0xc6b5, .rm_release = c.rm_release, .command_abi = c.command_abi,
        .adapter_id = 3, .flags = 0, .device_generation = 0x100000007, .reset_generation = 0x200000008 };
    var features = std.mem.zeroes(c.R4NvFeatures);
    try t.expectEqual(c.status_ok, r4nv_backend_v1.negotiate(&profile, &features));
    try t.expect(features.features == 15 and features.gpu_address_bits == 49 and features.max_copy_bytes == 0xffffffff and features.max_command_words == copy.max_words);
    const accepted = features;
    profile.command_abi += 1;
    try t.expectEqual(c.status_unsupported, r4nv_backend_v1.negotiate(&profile, &features));
    try t.expectEqualDeep(accepted, features);
    var request: c.R4NvCopy = .{ .version = 1, .size = @sizeOf(c.R4NvCopy), .source = 0x100000004,
        .target = 0x100100008, .bytes = 64, .semaphore = 0x20020000c, .copy_class = 0xc6b5,
        .rows = 0, .source_pitch = 0, .target_pitch = 0, .point = 0xfffffffe, .flags = 0 };
    var words: [19]u32 = @splat(0xa5a5a5a5);
    var written: u32 = 99;
    try t.expectEqual(c.status_capacity, r4nv_backend_v1.encode_copy(&request, &words, 16, &written));
    try t.expect(written == 99 and words[0] == 0xa5a5a5a5);
    try t.expectEqual(c.status_ok, r4nv_backend_v1.encode_copy(&request, &words, words.len, &written));
    try t.expect(written == 17 and words[3] == 1 and words[4] == 4 and words[5] == 1 and words[6] == 0x100008 and
        words[12] == 2 and words[13] == 0x20000c and words[14] == 0xfffffffe and words[18] == 0xa5a5a5a5);
    const before = words;
    try t.expectEqual(c.status_invalid, r4nv_backend_v1.encode_copy(&request, &words, words.len, &words[0]));
    try t.expectEqualSlices(u32, &before, &words);
    request.source = @as(u64, 1) << 49;
    try t.expectEqual(c.status_invalid, r4nv_backend_v1.encode_copy(&request, &words, words.len, &written));
    try t.expectEqualSlices(u32, &before, &words);

    var layout = std.mem.zeroes(c.R4NvCopyLayout);
    layout.copy = request;
    layout.copy.source = 0x100000000;
    layout.copy.target = 0x100100000;
    layout.copy.bytes = 31;
    layout.copy.rows = 7;
    layout.copy.source_pitch = 128;
    layout.copy.target_pitch = 192;
    layout.source_block = .{ .enabled = 1, .width = 128, .height = 65, .x = 5, .y = 17, .log2_gobs = 2 };
    layout.target_block = .{ .enabled = 1, .width = 192, .height = 79, .x = 21, .y = 31, .log2_gobs = 3 };
    var tiled: [copy.max_words]u32 = @splat(0xa5a5a5a5);
    try t.expectEqual(c.status_capacity, r4nv_backend_v1.encode_copy_layout(&layout, &tiled, tiled.len - 1, &written));
    try t.expect(tiled[0] == 0xa5a5a5a5);
    try t.expectEqual(c.status_ok, r4nv_backend_v1.encode_copy_layout(&layout, &tiled, tiled.len, &written));
    try t.expect(written == 37 and tiled[11] == copy.inc(0x728, 5) and tiled[18] == 5 and tiled[19] == 17 and
        tiled[20] == copy.inc(0x70c, 5) and tiled[27] == 21 and tiled[28] == 31 and tiled[30] == 0x202);
    // Host-only vectors generated from the original C6B5/C7B5 and C56F
    // headers, independently of the Zig encoder. Generator and full sources:
    // ExFiles/Reference/GFX/Nvidia/0.79.18/copy-20260913/.
    const vectors = @embedFile("copy_layout_vectors.bin");
    for (0..2) |i| {
        layout.copy.copy_class = if (i == 0) 0xc6b5 else 0xc7b5;
        try t.expectEqual(c.status_ok, r4nv_backend_v1.encode_copy_layout(&layout, &tiled, tiled.len, &written));
        for (tiled, 0..) |actual, j| try t.expectEqual(std.mem.readInt(u32, vectors[(i * 39 + j) * 4..][0..4], .little), actual);
        const entry = try copy.entryWords(0xabcde01000, written);
        for (entry, 0..) |actual, j| try t.expectEqual(std.mem.readInt(u32, vectors[(i * 39 + 37 + j) * 4..][0..4], .little), actual);
    }
    const tile_before = tiled;
    layout.source_block.x = 120;
    try t.expectEqual(c.status_invalid, r4nv_backend_v1.encode_copy_layout(&layout, &tiled, tiled.len, &written));
    try t.expectEqualSlices(u32, &tile_before, &tiled);
    try @import("shader_cache_checks.zig").run(&r4nv_shader_v1);
}

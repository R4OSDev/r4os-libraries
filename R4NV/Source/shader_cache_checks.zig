// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
//! Host-only cases in the existing provider test, through the exported table.
const std = @import("std");
const c = @import("r4l_contract");
const t = std.testing;

pub fn run(api: *const c.ShaderV1) !void {
    var key: c.R4NvShaderKey = .{ .version = 1, .size = @sizeOf(c.R4NvShaderKey), .vendor_id = 0x10de, .device_id = 0x2484,
        .graphics_class = 0xc797, .shader_model = 86, .rm_release = 570144, .command_abi = 1, .shader_abi = 1, .resource_abi = 3,
        .input_format = 875713089, .output_format = 875713112, .driver_build = 0x100000002,
        .device_uuid = .{ .word0 = 0x100000003, .word1 = 4, .word2 = 5, .word3 = 6 },
        .pipeline_state = .{ .word0 = 0x200000007, .word1 = 8, .word2 = 9, .word3 = 10 } };
    const original_key = key;
    // Independent outputs of the pinned Mesa26.2.2 NAK host checkpoint.
    const hashes = [_][]const u8{
        "1efe5eb9bf14ca597f48dda6460b2e09e7a2c335e7c25671cdf5eb63ed6437c9",
        "1d42b2d4e6e9354020c561b97596b3c910d41c63a7dd119f977c5ba7d02084bc",
        "96e9319486f7503fa1448fdf2b4ab97545acd19a0954a097c2aa451145fb0f76",
        "a27451b864b05ab0b32d16083965674ef4dc2175a6e459fd22055b63dd0b8173",
        "94811e8c07f6e09dcba8c3c0cce8aacedbab7293b76542935ecbf150abd39984",
        "356c276ffdc82e9cc63e49fb5a79b7602ff82d4981804689f7ec8f8c042ccc04",
    };
    const sizes = [_]u32{ 112, 2208, 816, 832, 80, 80 };
    const instructions = [_]u32{ 7, 138, 51, 52, 5, 5 };
    var storage: [c.shader_cache_max_bytes + 8]u8 align(8) = @splat(0xa5);
    const bytes = storage[1 .. 1 + c.shader_cache_max_bytes]; // ABI promises byte alignment.
    var view: c.R4NvShaderView = std.mem.zeroes(c.R4NvShaderView);
    var info: c.R4NvShaderInfo = undefined;
    var written: u32 = 99;
    for (hashes, sizes, instructions, 1..) |hex, size, count, id| {
        const profile: u32 = @intCast(id);
        try t.expectEqual(c.status_ok, api.shader_info(profile, &info));
        try t.expect(info.code_bytes == size and info.instructions == count and info.registers == 24 and info.max_warps_per_sm == 48 and
            info.stage == @as(u32, if (id == 1 or id == 6) 0 else 4) and info.scratch_bytes == 0 and info.stack_bytes == 0 and info.header_bytes == 128);
        try t.expectEqual(c.status_ok, api.shader_cache_write(profile, &key, bytes.ptr, bytes.len, &written));
        try t.expect(written == 384 + size);
        try t.expectEqual(c.status_ok, api.shader_cache_read(&key, bytes.ptr, written, &view));
        try t.expectEqualDeep(info, view.info);
        try t.expect(view.header_address == @intFromPtr(bytes.ptr) + 224 and view.code_address == @intFromPtr(bytes.ptr) + 384);
        var expected: [32]u8 = undefined;
        _ = try std.fmt.hexToBytes(&expected, hex);
        var actual: [32]u8 = undefined;
        std.crypto.hash.sha2.Sha256.hash(@as([*]const u8, @ptrFromInt(view.code_address))[0..size], &actual, .{});
        try t.expectEqualSlices(u8, &expected, &actual);
    }
    try t.expect(storage[0] == 0xa5 and storage[storage.len - 1] == 0xa5);
    const accepted_info = info;
    try t.expectEqual(c.status_unsupported, api.shader_info(7, &info));
    try t.expectEqualDeep(accepted_info, info);
    try t.expectEqual(c.status_ok, api.shader_cache_write(2, &key, bytes.ptr, bytes.len, &written));
    const good = storage;
    const accepted_view = view;
    // Every byte of the longest entry is covered, including reserved bytes,
    // headers, identities, digest and executable instructions.
    for (0..written) |i| {
        bytes[i] ^= 1;
        try t.expectEqual(c.status_cache_miss, api.shader_cache_read(&key, bytes.ptr, written, &view));
        try t.expectEqualDeep(accepted_view, view);
        bytes[i] ^= 1;
    }
    for (0..written) |length| try t.expectEqual(c.status_cache_miss, api.shader_cache_read(&key, bytes.ptr, @intCast(length), &view));
    try t.expectEqual(c.status_cache_miss, api.shader_cache_read(&key, bytes.ptr, written + 1, &view));
    // A valid checksum does not authorize a different program/header.
    bytes[224] ^= 1;
    var hash = std.crypto.hash.sha2.Sha256.init(.{});
    hash.update(bytes[0..352]); hash.update(bytes[384..written]);
    @memcpy(bytes[352..384], &hash.finalResult());
    try t.expectEqual(c.status_cache_miss, api.shader_cache_read(&key, bytes.ptr, written, &view));
    storage = good;
    inline for (.{ "device_id", "input_format", "output_format", "driver_build" }) |field| {
        @field(key, field) += 1;
        try t.expectEqual(c.status_cache_miss, api.shader_cache_read(&key, bytes.ptr, written, &view));
        key = original_key;
    }
    inline for (.{ "device_uuid", "pipeline_state" }) |field| inline for (std.meta.fields(c.R4NvDigest)) |word| {
        @field(@field(key, field), word.name) ^= 1;
        try t.expectEqual(c.status_cache_miss, api.shader_cache_read(&key, bytes.ptr, written, &view));
        key = original_key;
    };
    inline for (.{ "vendor_id", "graphics_class", "shader_model", "rm_release", "command_abi", "shader_abi", "resource_abi" }) |field| {
        @field(key, field) += 1;
        try t.expectEqual(c.status_unsupported, api.shader_cache_read(&key, bytes.ptr, written, &view));
        try t.expectEqual(c.status_unsupported, api.shader_cache_write(4, &key, bytes.ptr, bytes.len, &written));
        key = original_key;
    }
    // Earlier resource ABIs lack the optional grid. Their keys must not select
    // these shaders even though public table/payload sizes are unchanged.
    key.resource_abi = 2;
    try t.expectEqual(c.status_unsupported, api.shader_cache_read(&key, bytes.ptr, written, &view));
    try t.expectEqual(c.status_unsupported, api.shader_cache_write(4, &key, bytes.ptr, bytes.len, &written));
    key = original_key;
    key.device_uuid = std.mem.zeroes(c.R4NvDigest);
    try t.expectEqual(c.status_invalid, api.shader_cache_read(&key, bytes.ptr, written, &view));
    key = original_key;
    try t.expectEqualDeep(accepted_view, view);
    written = 99;
    try t.expectEqual(c.status_capacity, api.shader_cache_write(2, &key, bytes.ptr, bytes.len - 1, &written));
    try t.expectEqual(c.status_unsupported, api.shader_cache_write(7, &key, bytes.ptr, bytes.len, &written));
    try t.expectEqual(c.status_invalid, api.shader_cache_write(4, &key, bytes.ptr, bytes.len, &key.version));
    try t.expectEqual(c.status_invalid, api.shader_cache_write(4, &key, bytes.ptr, bytes.len, @ptrCast(@alignCast(&storage[4]))));
    try t.expectEqual(c.status_invalid, api.shader_cache_write(4, &key, @ptrCast(&key), bytes.len, &written));
    try t.expectEqual(c.status_invalid, api.shader_cache_read(&key, bytes.ptr, bytes.len, @ptrCast(@alignCast(&storage[8]))));
    try t.expectEqual(c.status_invalid, api.shader_cache_read(&key, bytes.ptr, bytes.len, @ptrCast(&key)));
    try t.expectEqualSlices(u8, &good, &storage);
    try t.expectEqualDeep(original_key, key);
    try t.expect(written == 99);
    try t.expectEqual(c.status_ok, api.shader_cache_read(&key, bytes.ptr, bytes.len, &view));
    try t.expect(view.info.profile == 2);
}

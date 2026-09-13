const std = @import("std");
const r4os = @import("r4os");
const c = @import("r4l_contract");
const copy = @import("copy.zig");

export fn r4l_entry() linksection(".text.r4l_entry") callconv(.c) void {}

pub const r4nv_negotiate_impl = @import("backend.zig").r4nv_negotiate_impl;
pub const r4nv_encode_copy_impl = @import("backend.zig").r4nv_encode_copy_impl;

pub export var r4nv_backend_v1: c.BackendV1 align(8) linksection(".data.r4l_exports") = .{
    .header = c.backend_v1_header,
    .negotiate = r4nv_negotiate_impl,
    .encode_copy = r4nv_encode_copy_impl,
};
pub export var r4nv_query: r4os.abi.R4LQuery align(8) linksection(".data.r4l_exports") = .{
    .magic = r4os.abi.r4l_abi_magic, .abi_version = r4os.abi.r4l_abi_version,
    .size = r4os.abi.r4l_query_struct_size, .group = 0, .kernel_bridge = 0, .reserved = 0,
};

test "backend handshake and ABI encoding preserve 64-bit operands and rejected outputs" {
    const t = std.testing;
    var profile: c.R4NvDeviceProfile = .{ .version = 1, .size = @sizeOf(c.R4NvDeviceProfile),
        .vendor_id = 0x10de, .copy_class = 0xc6b5, .rm_release = c.rm_release, .command_abi = c.command_abi,
        .adapter_id = 3, .flags = 0, .device_generation = 0x100000007, .reset_generation = 0x200000008 };
    var features = std.mem.zeroes(c.R4NvFeatures);
    try t.expectEqual(c.status_ok, r4nv_backend_v1.negotiate(&profile, &features));
    try t.expect(features.features == 3 and features.gpu_address_bits == 49 and features.max_copy_bytes == 0xffffffff);
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
}

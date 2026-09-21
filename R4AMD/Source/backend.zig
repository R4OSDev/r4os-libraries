// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const c = @import("r4l_contract");

pub fn negotiate(profile: *const c.R4AmdDeviceProfile, output: *c.R4AmdFeatures) callconv(.c) i32 {
    if (@intFromPtr(profile) == 0 or @intFromPtr(output) == 0 or
        @intFromPtr(profile) % @alignOf(c.R4AmdDeviceProfile) != 0 or
        @intFromPtr(output) % @alignOf(c.R4AmdFeatures) != 0) return c.status_invalid;
    const input_end = std.math.add(usize, @intFromPtr(profile), @sizeOf(c.R4AmdDeviceProfile)) catch return c.status_invalid;
    const output_end = std.math.add(usize, @intFromPtr(output), @sizeOf(c.R4AmdFeatures)) catch return c.status_invalid;
    if (@intFromPtr(profile) < output_end and @intFromPtr(output) < input_end) return c.status_invalid;
    if (profile.version != c.profile_version or profile.size != @sizeOf(c.R4AmdDeviceProfile) or
        profile.flags != 0 or profile.reserved != 0 or profile.adapter_id == 0 or
        profile.device_generation == 0 or profile.reset_generation == 0) return c.status_invalid;
    if (profile.vendor_id != c.vendor_id or profile.device_id == 0 or profile.device_id >= 0xffff or
        profile.gc_version != c.gc_9_1_0 or profile.sdma_version != c.sdma_4_1_0 or
        profile.command_abi != c.command_abi) return c.status_unsupported;
    // Protocol recognition cannot admit an unimplemented encoder. The SDMA,
    // layout and render stages will add capabilities only with actual code.
    output.* = .{ .version = 1, .size = @sizeOf(c.R4AmdFeatures), .command_abi = c.command_abi,
        .features = 0, .gpu_address_bits = 0, .max_command_words = 0, .reserved0 = 0, .reserved1 = 0 };
    return c.status_ok;
}

test "AMD negotiation preserves failures and never advertises a missing encoder" {
    const t = std.testing;
    var profile: c.R4AmdDeviceProfile = .{ .version = 1, .size = @sizeOf(c.R4AmdDeviceProfile),
        .vendor_id = c.vendor_id, .device_id = 0x15d8, .gc_version = c.gc_9_1_0, .sdma_version = c.sdma_4_1_0,
        .command_abi = c.command_abi, .flags = 0, .adapter_id = 7, .reserved = 0, .device_generation = 11, .reset_generation = 13 };
    var result = std.mem.zeroes(c.R4AmdFeatures);
    try t.expectEqual(c.status_ok, negotiate(&profile, &result));
    try t.expect(result.features == 0 and result.max_command_words == 0 and result.gpu_address_bits == 0);
    const original = result;
    profile.vendor_id = 0x10de;
    try t.expectEqual(c.status_unsupported, negotiate(&profile, &result));
    try t.expectEqualDeep(original, result);
    profile.vendor_id = c.vendor_id; profile.command_abi += 1;
    try t.expectEqual(c.status_unsupported, negotiate(&profile, &result));
    try t.expectEqualDeep(original, result);
    profile.command_abi = c.command_abi; profile.reset_generation = 0;
    try t.expectEqual(c.status_invalid, negotiate(&profile, &result));
    try t.expectEqualDeep(original, result);
    profile.reset_generation = 13;
    const before_alias = profile;
    try t.expectEqual(c.status_invalid, negotiate(&profile, @ptrCast(&profile)));
    try t.expectEqualDeep(before_alias, profile);
}

// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const r4os = @import("r4os");
const c = @import("r4l_contract");

export fn r4l_entry() linksection(".text.r4l_entry") callconv(.c) void {}

pub export fn r4amd_get_info_impl(output: *c.R4AmdInfo, output_bytes: u32) callconv(.c) i32 {
    if (output_bytes < @sizeOf(c.R4AmdInfo)) return c.status_invalid;
    output.* = .{
        .version = c.info_version,
        .size = @sizeOf(c.R4AmdInfo),
        .mesa_major = 26,
        .mesa_minor = 2,
        .mesa_patch = 2,
        .implementation_stage = 3,
        .capability_flags = 0,
        .reserved = 0,
    };
    return c.status_ok;
}

pub export var r4amd_info_v1: c.InfoV1 align(8) linksection(".data.r4l_exports") = .{
    .header = c.info_v1_header,
    .get_info = r4amd_get_info_impl,
};

pub export var r4amd_backend_v1: c.BackendV1 align(8) linksection(".data.r4l_exports") = .{
    .header = c.backend_v1_header,
    .negotiate = r4amd_negotiate_impl,
};

pub export fn r4amd_negotiate_impl(profile: *const c.R4AmdDeviceProfile, output: *c.R4AmdFeatures) callconv(.c) i32 {
    return @import("backend.zig").negotiate(profile, output);
}

pub export var r4amd_query: r4os.abi.R4LQuery align(8) linksection(".data.r4l_exports") = .{
    .magic = r4os.abi.r4l_abi_magic,
    .abi_version = r4os.abi.r4l_abi_version,
    .size = r4os.abi.r4l_query_struct_size,
    .group = 0,
    .kernel_bridge = 0,
    .reserved = 0,
};

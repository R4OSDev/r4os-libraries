// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const a = @import("r4os").abi;
const window = @import("r4native").window;
pub export fn r4vk_window_query(raw: *const a.R4XStartContext, id: u32, expected: ?*const a.WindowGraphicsSurface, out: *a.WindowGraphicsReply) callconv(.c) i32 {
    return window.query(raw, id, expected, out);
}
pub export fn r4vk_window_request(raw: *const a.R4XStartContext, request: *const a.WindowGraphicsRequest, out: *a.WindowGraphicsReply) callconv(.c) bool {
    return window.request(raw, request, out);
}
pub export fn r4vk_window_service_dead(raw: *const a.R4XStartContext, service: *const a.ProgramProcessHandle) callconv(.c) bool {
    return window.service_dead(raw, service);
}
pub export fn r4vk_window_wait(raw: *const a.R4XStartContext, owner: *const a.ProgramProcessHandle, revision: u64, ns: u64) callconv(.c) void {
    window.wait(raw, owner, revision, ns);
}

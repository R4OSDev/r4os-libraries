// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const r = @import("r4os");
const a = r.abi;
const threads = @import("threads_api.zig");

// Read-only surface queries use an independently closed endpoint. No shared
// mutable R4L connection, borrowed stack Bundle or process identity survives
// the call. A later service incarnation cannot satisfy an exact old surface.
pub export fn r4vk_window_query(raw: *const a.R4XStartContext, window_id: u32,
    expected: ?*const a.WindowGraphicsSurface, output: *a.WindowGraphicsReply) callconv(.c) i32
{
    const bundle = r.program.bundleValueFromR4XStart(raw) orelse return a.window_graphics_invalid;
    if (bundle.sys != threads.table() or raw.instance_id == 0 or raw.instance_id > std.math.maxInt(u32) or window_id == 0)
        return a.window_graphics_invalid;
    const sys = r.r4sys.Context.init(&bundle);
    var owner: a.ProgramProcessHandle = .{};
    if (sys.programOpenHandle(@intCast(raw.instance_id), &owner) != a.program_handle_ok)
        return a.window_graphics_not_owner;
    if (expected) |identity| {
        if (!std.meta.eql(identity.owner, owner) or identity.window_id != window_id)
            return a.window_graphics_not_owner;
    }
    const services: r.app_services.Services = .{ .sys = sys };
    var connection = switch (services.open("WINSVC")) {
        .connection => |value| value,
        .failure => return a.window_graphics_unavailable,
    };
    defer _ = connection.close();
    const request: a.WindowGraphicsRequest = .{
        .owner = owner, .window_id = window_id,
        .surface = if (expected) |identity| identity.* else .{},
    };
    const response = connection.callTyped(a.WindowGraphicsRequest, a.WindowGraphicsReply,
        a.window_graphics_op_client, &request, r.time_contract.timeoutFinite(r.time_contract.durationFromNanoseconds(250_000_000)));
    const reply = switch (response) {
        .value => |value| value,
        else => return a.window_graphics_unavailable,
    };
    if (reply.version != 1 or reply.size != @sizeOf(a.WindowGraphicsReply) or reply.reserved != 0)
        return a.window_graphics_invalid;
    if (reply.result != a.window_graphics_ok) return reply.result;
    if (reply.surface.version != 1 or reply.surface.size != @sizeOf(a.WindowGraphicsSurface) or
        reply.surface.serial == 0 or reply.surface.reserved != 0 or
        !std.meta.eql(reply.surface.owner, owner) or reply.surface.window_id != window_id)
        return a.window_graphics_invalid;
    if (expected) |identity| if (!std.meta.eql(identity.*, reply.surface)) return a.window_graphics_stale;
    output.* = reply;
    return a.window_graphics_ok;
}

// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const r = @import("r4os");
const a = r.abi;
const threads = @import("threads.zig");

// Read-only surface queries use an independently closed endpoint. No shared
// mutable R4L connection, borrowed stack Bundle or process identity survives
// the call. A later service incarnation cannot satisfy an exact old surface.
pub fn query(raw: *const a.R4XStartContext, window_id: u32,
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
    const message: a.WindowGraphicsRequest = .{
        .owner = owner, .window_id = window_id,
        .surface = if (expected) |identity| identity.* else .{},
    };
    const response = connection.callTyped(a.WindowGraphicsRequest, a.WindowGraphicsReply,
        a.window_graphics_op_client, &message, r.time_contract.timeoutFinite(r.time_contract.durationFromNanoseconds(250_000_000)));
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

pub fn request(raw: *const a.R4XStartContext,
    message: *const a.WindowGraphicsRequest, output: *a.WindowGraphicsReply) callconv(.c) bool
{
    const bundle = r.program.bundleValueFromR4XStart(raw) orelse return false;
    if (bundle.sys != threads.table()) return false;
    const sys = r.r4sys.Context.init(&bundle);
    const services: r.app_services.Services = .{ .sys = sys };
    var connection = switch (services.open("WINSVC")) {
        .connection => |value| value,
        .failure => return false,
    };
    defer _ = connection.close();
    const response = connection.callTyped(a.WindowGraphicsRequest, a.WindowGraphicsReply,
        a.window_graphics_op_client, message, r.time_contract.timeoutFinite(r.time_contract.durationFromNanoseconds(250_000_000)));
    const reply = switch (response) { .value => |value| value, else => return false };
    if (reply.version != 1 or reply.size != @sizeOf(a.WindowGraphicsReply) or reply.reserved != 0) return false;
    output.* = reply;
    return true;
}

pub fn service_dead(raw: *const a.R4XStartContext,
    service: *const a.ProgramProcessHandle) callconv(.c) bool
{
    const bundle = r.program.bundleValueFromR4XStart(raw) orelse return false;
    if (bundle.sys != threads.table()) return false;
    const sys = r.r4sys.Context.init(&bundle);
    var info: a.ProgramInstanceInfo = .{};
    const result = sys.programHandleStatus(service, &info);
    return result == a.program_handle_error_not_found or result == a.program_handle_error_stale or
        (result == a.program_handle_ok and info.id == service.instance_id and info.state == 2);
}

pub fn wait(raw: *const a.R4XStartContext,
    owner: *const a.ProgramProcessHandle, revision: u64, duration_ns: u64) callconv(.c) void
{
    const bundle = r.program.bundleValueFromR4XStart(raw) orelse return;
    if (bundle.sys != threads.table() or duration_ns == 0) return;
    const sys = r.r4sys.Context.init(&bundle);
    const timeout = r.time_contract.timeoutFinite(r.time_contract.durationFromNanoseconds(@min(duration_ns, 25_000_000)));
    const ticks = r.time_contract.timeoutToTicks(timeout, sys.monotonicHz()) catch return;
    const services: r.app_services.Services = .{ .sys = sys };
    var connection = switch (services.open("WINSVC")) {
        .connection => |value| value,
        .failure => { sys.sleepTicks(@max(ticks, 1)); return; },
    };
    defer _ = connection.close();
    const message: a.WindowGraphicsWait = .{ .owner = owner.*, .known_revision = revision, .deadline_tick = sys.ticks() +| @max(ticks, 1) };
    const result = connection.callTyped(a.WindowGraphicsWait, a.WindowGraphicsReply, a.window_graphics_op_wait, &message, timeout);
    switch (result) {
        .timed_out => {},
        .value => |reply| if (reply.result != a.window_graphics_ok and reply.result != a.window_graphics_timeout) { sys.sleepTicks(@max(ticks, 1)); },
        else => sys.sleepTicks(@max(ticks, 1)),
    }
}

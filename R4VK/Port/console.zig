// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const a = @import("r4os").abi;
const threads = @import("r4native").threads;
const std = @import("std");
const local = @import("process_local.zig");

const NativeFailure = struct {
    claimed: std.atomic.Value(bool) = .init(false),
};
var native_failure_key: u8 = 0;
fn initNativeFailure(value: *NativeFailure) void { value.* = .{}; }

// GUI callers have no console transcript. An explicit caller-owned path
// retains the first native failure without changing its return value or
// manufacturing a completion receipt. Later teardown errors cannot replace
// the original cause. No output or allocation occurs while disabled.
pub export fn r4vk_native_failure(stage: [*:0]const u8, result: i32, detail: i64,
    identity: u64, point: u64) callconv(.c) void
{
    const table = threads.table();
    if (table.env_get == 0 or table.file_write == 0) return;
    const get: a.R4SysFns.env_get = @ptrFromInt(table.env_get);
    var path: [256:0]u8 = @splat(0);
    const count = get("R4VK_NATIVE_FAILURE_FILE", &path, path.len);
    if (count <= 0 or count >= path.len) return;
    path[@intCast(count)] = 0;
    const value = local.getOrCreate(NativeFailure, &native_failure_key, initNativeFailure) orelse return;
    if (value.claimed.cmpxchgStrong(false, true, .acq_rel, .acquire) != null) return;
    var line: [512]u8 = undefined;
    const text = std.fmt.bufPrint(&line,
        "R4VK native first failure: stage={s} result={d} detail={d} identity={d} point={d}\n",
        .{std.mem.span(stage), result, detail, identity, point}) catch return;
    const write: a.R4SysFns.file_write = @ptrFromInt(table.file_write);
    _ = write(&path, text.ptr, @intCast(text.len));
}

// Optional caller-owned diagnosis. No runtime allocation, option cache or
// process-state lookup: device construction may be initializing those owners.
pub export fn r4vk_device_startup_trace_enabled() callconv(.c) bool {
    const table = threads.table();
    if (table.env_get == 0 or table.write == 0) return false;
    const get: a.R4SysFns.env_get = @ptrFromInt(table.env_get);
    var option: [4]u8 = undefined;
    return get("R4VK_DEVICE_TRACE", &option, option.len) == 1 and option[0] == '1';
}
pub export fn r4vk_device_startup_trace(message: [*:0]const u8) callconv(.c) void {
    if (!r4vk_device_startup_trace_enabled()) return;
    const table = threads.table();
    const write: a.R4SysFns.write = @ptrFromInt(table.write);
    const text = std.mem.span(message);
    _ = write(text.ptr, @intCast(text.len));
    _ = write("\n", 1);
}

// R4SYS resolves the current caller's output on each write. No application
// stream or Bundle is cached in shared library storage.
pub export fn r4vk_console_write(bytes: [*]const u8, count: u32) callconv(.c) i32 {
    const address = threads.table().write;
    if (address == 0) return -1;
    const write: a.R4SysFns.write = @ptrFromInt(address);
    return write(bytes, count);
}

// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
//! Opt-in metadata diagnostics, never pixel maps or completion receipts.
const std = @import("std");
const a = @import("r4os").abi;
const d = @import("device.zig");
pub const Trace = struct {
    device: *d.Device,
    enabled: bool,
    stage: []const u8 = "validate",
    pub fn init(device: *d.Device) Trace {
        var enabled = false;
        if (device.bundle.sys) |table| if (table.env_get != 0 and table.write != 0) {
            const get: a.R4SysFns.env_get = @ptrFromInt(table.env_get);
            var value: [8]u8 = undefined;
            enabled = get("R4GFX_YUV_TRACE", &value, value.len) == 1 and value[0] == '1';
        };
        return .{ .device = device, .enabled = enabled };
    }
    pub fn detail(self: Trace, comptime fmt: []const u8, args: anytype) void {
        if (!self.enabled) return;
        const table = self.device.bundle.sys orelse return;
        const write: a.R4SysFns.write = @ptrFromInt(table.write);
        var bytes: [512]u8 = undefined;
        const line = std.fmt.bufPrint(&bytes, fmt ++ "\n", args) catch return;
        _ = write(line.ptr, @intCast(line.len));
    }
    pub fn failure(self: Trace, err: d.Error) void {
        if (err == error.Busy) return;
        self.detail("R4GFX YUV stage={s} failure={s}", .{ self.stage, @errorName(err) });
    }
};

// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const r = @import("r4os");
const threads = @import("threads.zig");
const local = @import("process_local.zig");
const State = struct {
    phase: std.atomic.Value(u32) = .init(0),
    raw: r.abi.R4XStartContext = undefined,
    bundle: r.program.Bundle = undefined,
};
var key: u8 = 0;
fn initialize(value: *State) void { value.* = .{}; }

/// Retains only a process-owned startup snapshot and immutable platform tables.
/// The app's import table follows its ordinary program lifetime. No caller
/// Bundle, stack context or GUI object survives this call.
pub fn bind(raw: *const r.abi.R4XStartContext) bool {
    const candidate = r.program.bundleValueFromR4XStart(raw) orelse return false;
    if (candidate.sys != threads.table() or raw.instance_id != threads.thrd_current().instance_id) return false;
    const value = local.getOrCreate(State, &key, initialize) orelse return false;
    if (value.phase.cmpxchgStrong(0, 1, .acq_rel, .acquire) == null) {
        value.raw = raw.*;
        value.bundle = candidate;
        value.bundle.raw = &value.raw;
        value.phase.store(2, .release);
    } else while (value.phase.load(.acquire) != 2) threads.thrd_yield();
    return std.meta.eql(value.raw, raw.*);
}
pub fn bundle() ?*const r.program.Bundle {
    const value = (local.lookup(State, &key) catch return null) orelse return null;
    return if (value.phase.load(.acquire) == 2) &value.bundle else null;
}

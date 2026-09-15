// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
// Mutable native-library state belongs to the calling process. Only the
// address of the key is shared; the kernel publishes one resident context.
const std = @import("std");
const r4os = @import("r4os");
const a = r4os.abi;
const threads = @import("threads_api.zig");

fn function(comptime name: []const u8) @field(a.R4SysFns, name) {
    return @ptrFromInt(@field(threads.table().*, name));
}

pub fn lookup(comptime T: type, key: *const anyopaque) error{Unavailable}!?*T {
    var value: u64 = 0;
    if (function("program_local_get")(@intFromPtr(key), &value) != a.program_local_ok)
        return error.Unavailable;
    return if (value == 0) null else @ptrFromInt(value);
}

// init runs before publication without any kernel owner lock. It must not
// recursively look up its own key or acquire resources outside the region:
// a losing candidate is simply released. Process retirement owns the region;
// there is no destructor callback into an unloaded library.
pub fn getOrCreate(comptime T: type, key: *const anyopaque, comptime init: fn (*T) void) ?*T {
    if (lookup(T, key) catch return null) |existing| return existing;
    const bytes = comptime std.mem.alignForward(usize, @sizeOf(T), 4096);
    comptime std.debug.assert(@sizeOf(T) > 0 and @alignOf(T) <= 4096 and bytes <= a.vm_commit_resident_max_bytes);
    var region: a.ProgramVmRegionInfo = .{};
    if (function("vm_reserve")(bytes, 4096, a.vm_region_flags_default, &region) != a.vm_ok) return null;
    if (region.id == 0 or region.base == 0 or region.base % 4096 != 0 or region.len < bytes) @trap();
    if (function("vm_commit")(region.id, 0, bytes, a.vm_commit_flag_resident) != a.vm_ok) {
        _ = function("vm_release")(region.id);
        return null;
    }
    const candidate: *T = @ptrFromInt(region.base);
    init(candidate);
    var value: u64 = 0;
    const result = function("program_local_publish")(@intFromPtr(key), region.base, &value);
    if (result == a.program_local_ok) {
        if (value != region.base) @trap();
        return candidate;
    }
    // A failed release stays in the process VM ledger for its normal reaper.
    _ = function("vm_release")(region.id);
    return if (result == a.program_local_existing and value != 0) @ptrFromInt(value) else null;
}

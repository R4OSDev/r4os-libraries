// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const a = @import("r4os").abi;
var devices_address: std.atomic.Value(usize) = .init(0);

// Keep only an immutable boot-lifetime table, never a caller's Bundle.
pub fn bind(devices: *const a.R4XStartR4Dev) bool {
    if (devices.magic != a.r4xstart_r4dev_magic or devices.abi_version < 1 or
        devices.size < @offsetOf(a.R4XStartR4Dev, "memory_pressure_snapshot") + 8 or
        devices.memory_pressure_snapshot == 0) return false;
    const old = devices_address.cmpxchgStrong(0, @intFromPtr(devices), .acq_rel, .acquire);
    return old == null or old.? == @intFromPtr(devices);
}

pub fn snapshot() ?a.ProgramMemoryPressureSnapshot {
    const address = devices_address.load(.acquire);
    if (address == 0) return null;
    const devices: *const a.R4XStartR4Dev = @ptrFromInt(address);
    const query: a.R4DevFns.memory_pressure_snapshot = @ptrFromInt(devices.memory_pressure_snapshot);
    var value: a.ProgramMemoryPressureSnapshot = .{};
    if (query(&value) <= 0 or value.version != a.memory_pressure_snapshot_version or
        value.size < @sizeOf(a.ProgramMemoryPressureSnapshot) or value.total_physical_bytes == 0 or
        value.free_physical_bytes > value.total_physical_bytes or
        value.app_available_bytes > value.free_physical_bytes) return null;
    return value;
}

pub export fn os_get_total_physical_memory(output: *u64) callconv(.c) bool {
    const value = snapshot() orelse return false;
    output.* = value.total_physical_bytes;
    return true;
}

pub export fn os_get_available_system_memory(output: *u64) callconv(.c) bool {
    const value = snapshot() orelse return false;
    // Conservative allocation headroom: preserve the system reserve and
    // commitments. This is a snapshot, not a reservation or an OOM guarantee.
    output.* = @min(value.app_available_bytes, value.commit_headroom_bytes);
    return true;
}

pub export fn os_get_page_size(output: *u64) callconv(.c) bool {
    // The native x86_64 R4SYS VM ABI and SDK allocator use 4 KiB pages.
    output.* = 4096;
    return true;
}

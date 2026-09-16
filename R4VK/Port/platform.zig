// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
// Only immutable boot-lifetime platform tables may be bound here.
const std = @import("std");
const a = @import("r4os").abi;
var draw_address: std.atomic.Value(usize) = .init(0);
var devices_address: std.atomic.Value(usize) = .init(0);

pub fn bind(draw: *const a.R4XStartR4Draw, devices: *const a.R4XStartR4Dev) bool {
    if (draw.magic != a.r4xstart_r4draw_magic or devices.magic != a.r4xstart_r4dev_magic or
        draw.size < @offsetOf(a.R4XStartR4Draw, "gfx_queue_backend_info") + 8 or
        draw.gfx_queue_backend_info == 0 or
        devices.size < @offsetOf(a.R4XStartR4Dev, "memory_pressure_snapshot") + 8 or
        devices.memory_pressure_snapshot == 0) return false;
    const old_draw = draw_address.cmpxchgStrong(0, @intFromPtr(draw), .acq_rel, .acquire);
    if (old_draw != null and old_draw.? != @intFromPtr(draw)) return false;
    const old_devices = devices_address.cmpxchgStrong(0, @intFromPtr(devices), .acq_rel, .acquire);
    return old_devices == null or old_devices.? == @intFromPtr(devices);
}

// The private SDK C facades each contain exactly one table pointer. No
// caller Bundle, temporary wrapper or captured device binding is retained.
pub export fn r4vk_get_graphics_tables(draw: *usize, devices: *usize) callconv(.c) c_int {
    const d = draw_address.load(.acquire);
    const v = devices_address.load(.acquire);
    if (d == 0 or v == 0) return 0;
    draw.* = d;
    devices.* = v;
    return 1;
}

// The x86_64 R4SYS VM contract and shared SDK allocator use 4 KiB pages.
pub export fn os_get_page_size(output: *u64) callconv(.c) bool {
    output.* = 4096;
    return true;
}

// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
// Process metadata uses the existing caller-bound R4SYS service. The library
// never reports its own module path in place of the application's executable.
const std = @import("std");
const r4os = @import("r4os");
const threads = @import("threads.zig");

// No CPUID topology guesses: read the actual kernel scheduler capacity. This
// optional v22 tail does not raise the baseline for users of other helpers.
pub fn cpuCapacity() ?r4os.abi.CpuCapacity {
    const table = threads.table();
    if (table.abi_version < 22 or table.size < @offsetOf(r4os.abi.R4XStartR4Sys, "cpu_capacity") + 8 or
        table.cpu_capacity == 0) return null;
    const query: r4os.abi.R4SysFns.cpu_capacity = @ptrFromInt(table.cpu_capacity);
    var value: r4os.abi.CpuCapacity = .{};
    if (query(&value) != r4os.abi.thread_ok or value.available_cpus == 0 or
        value.available_cpus > value.configured_cpus) return null;
    return value;
}

// Reserves one byte for NUL; returns the full path or failure, never truncates.
// The returned slice borrows out. No process/global cache or allocation.
pub fn modulePath(out: []u8) ?[:0]const u8 {
    const table = threads.table();
    if (out.len < 2 or table.program_module_path == 0) return null;
    const capacity: u32 = @intCast(@min(out.len - 1, std.math.maxInt(u32)));
    const call: r4os.abi.R4SysFns.program_module_path = @ptrFromInt(table.program_module_path);
    const result = call(out.ptr, capacity);
    if (result <= 0 or result > capacity) return null;
    const len: usize = @intCast(result);
    out[len] = 0;
    return out[0..len :0];
}

pub const EnvironmentError = error{ Unavailable, NotFound, BufferTooSmall, Invalid };

// One explicit read of the caller's inherited/mutable environment. C getenv
// adapters must separately own any borrowed-string lifetime or option cache.
pub fn environmentValue(name: [*:0]const u8, out: []u8) EnvironmentError![:0]const u8 {
    const table = threads.table();
    if (table.env_get == 0) return error.Unavailable;
    if (out.len == 0) return error.BufferTooSmall;
    const capacity: u32 = @intCast(@min(out.len - 1, std.math.maxInt(u32)));
    const call: r4os.abi.R4SysFns.env_get = @ptrFromInt(table.env_get);
    const result = call(name, out.ptr, capacity);
    if (result < 0) return switch (result) {
        -2 => error.NotFound,
        -3 => error.BufferTooSmall,
        -4 => error.Unavailable,
        else => error.Invalid,
    };
    if (result > capacity) return error.Invalid;
    const len: usize = @intCast(result);
    out[len] = 0;
    return out[0..len :0];
}

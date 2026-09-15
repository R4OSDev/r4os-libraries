// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
// Mesa's default C allocation uses the shared SDK algorithm, with one
// explicitly owned heap per calling process. No caller data lives in R4L BSS.
const std = @import("std");
const r4os = @import("r4os");
const a = r4os.abi;
const threads = @import("threads_api.zig");
const Context = struct { heap: r4os.vm_allocator.Heap };
const Header = struct {
    magic: u64,
    owner: *Context,
    raw: [*]u8,
    raw_bytes: usize,
    bytes: usize,
};
const live: u64 = 0x5244564B414C4C31;
var context_key: u8 = 0;

fn function(comptime name: []const u8) @field(a.R4SysFns, name) {
    return @ptrFromInt(@field(threads.table().*, name));
}
fn context() ?*Context {
    const key = @intFromPtr(&context_key);
    var value: u64 = 0;
    if (function("program_local_get")(key, &value) != a.program_local_ok) return null;
    if (value != 0) return @ptrFromInt(value);

    // Bootstrap only the heap metadata through VM. Normal C allocations use
    // its existing small-block free lists and reusable direct-region cache.
    const bytes = comptime std.mem.alignForward(usize, @sizeOf(Context), 4096);
    comptime std.debug.assert(bytes <= a.vm_commit_resident_max_bytes);
    var region: a.ProgramVmRegionInfo = .{};
    if (function("vm_reserve")(bytes, 4096, a.vm_region_flags_default, &region) != a.vm_ok) return null;
    if (region.id == 0 or region.base == 0 or region.base % 4096 != 0 or region.len < bytes) @trap();
    if (function("vm_commit")(region.id, 0, bytes, a.vm_commit_flag_resident) != a.vm_ok) {
        _ = function("vm_release")(region.id);
        return null;
    }
    const candidate: *Context = @ptrFromInt(region.base);
    candidate.* = .{ .heap = .{ .api = threads.table() } };
    const result = function("program_local_publish")(key, region.base, &value);
    if (result == a.program_local_ok) {
        std.debug.assert(value == region.base);
        return candidate;
    }
    // Losing candidates and failed commits never enter a shared list. Any
    // failed VM release remains owned by the existing process VM reaper.
    _ = function("vm_release")(region.id);
    return if (result == a.program_local_existing and value != 0) @ptrFromInt(value) else null;
}
fn allocate(bytes: usize, alignment: usize) ?*anyopaque {
    if (alignment == 0 or !std.math.isPowerOfTwo(alignment)) return null;
    const aligned = @max(alignment, @alignOf(Header));
    const overhead = std.math.add(usize, @sizeOf(Header), aligned - 1) catch return null;
    const total = std.math.add(usize, @max(bytes, 1), overhead) catch return null;
    const owner = context() orelse return null;
    const allocator = owner.heap.allocator();
    const raw = allocator.rawAlloc(total, .fromByteUnits(@alignOf(Header)), @returnAddress()) orelse return null;
    const address = std.mem.alignForward(usize, @intFromPtr(raw) + @sizeOf(Header), aligned);
    const header: *Header = @ptrFromInt(address - @sizeOf(Header));
    header.* = .{ .magic = live, .owner = owner, .raw = raw, .raw_bytes = total, .bytes = bytes };
    return @ptrFromInt(address);
}
fn describe(pointer: *anyopaque) *Header {
    const header: *Header = @ptrFromInt(@intFromPtr(pointer) - @sizeOf(Header));
    const owner = context() orelse @trap();
    if (header.magic != live or header.owner != owner) @trap();
    return header;
}
pub export fn malloc(bytes: usize) callconv(.c) ?*anyopaque {
    return allocate(bytes, 16);
}
pub export fn free(pointer: ?*anyopaque) callconv(.c) void {
    const address = pointer orelse return;
    const header = describe(address);
    const owner = header.owner;
    const raw = header.raw;
    const bytes = header.raw_bytes;
    header.magic = 0;
    owner.heap.allocator().rawFree(raw[0..bytes], .fromByteUnits(@alignOf(Header)), @returnAddress());
}
pub export fn calloc(count: usize, width: usize) callconv(.c) ?*anyopaque {
    const bytes = std.math.mul(usize, count, width) catch return null;
    const pointer = malloc(bytes) orelse return null;
    @memset(@as([*]u8, @ptrCast(pointer))[0..bytes], 0);
    return pointer;
}
pub export fn realloc(pointer: ?*anyopaque, bytes: usize) callconv(.c) ?*anyopaque {
    if (pointer == null) return malloc(bytes);
    const header = describe(pointer.?);
    if (bytes == 0) {
        free(pointer);
        return null;
    }
    const next = malloc(bytes) orelse return null; // Original remains live.
    const amount = @min(bytes, header.bytes);
    @memcpy(@as([*]u8, @ptrCast(next))[0..amount], @as([*]const u8, @ptrCast(pointer.?))[0..amount]);
    free(pointer);
    return next;
}
pub export fn reallocarray(pointer: ?*anyopaque, count: usize, width: usize) callconv(.c) ?*anyopaque {
    const bytes = std.math.mul(usize, count, width) catch return null;
    return realloc(pointer, bytes);
}
pub export fn aligned_alloc(alignment: usize, bytes: usize) callconv(.c) ?*anyopaque {
    if (alignment == 0 or !std.math.isPowerOfTwo(alignment) or bytes % alignment != 0) return null;
    return allocate(bytes, alignment);
}
pub export fn posix_memalign(output: *?*anyopaque, alignment: usize, bytes: usize) callconv(.c) c_int {
    if (alignment < @sizeOf(usize) or !std.math.isPowerOfTwo(alignment)) return 22;
    const pointer = allocate(bytes, alignment) orelse return 12;
    output.* = pointer;
    return 0;
}

pub fn stats() ?r4os.vm_allocator.Stats {
    const owner = context() orelse return null;
    return owner.heap.stats();
}

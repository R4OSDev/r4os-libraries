// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const c = @import("r4l_contract");
const Sha256 = std.crypto.hash.sha2.Sha256;
const key_offset = 64;
const binary_offset = key_offset + @sizeOf(c.R4NakCacheKey);
const digest_offset = binary_offset + @sizeOf(c.R4NakBinary);
pub const code_offset = digest_offset + 32;
pub const max_code_bytes = 16 * 1024 * 1024;
const compiler_id = blk: {
    @setEvalBranchQuota(10000);
    var value: [32]u8 = undefined;
    Sha256.hash("Mesa26.2.2:55b1234c8653dad9b85ba3de7b777a0d957909baf4628f0c00e21d4ba89c004cb687a1dcf8da46ed0a092231dd4f859027509f83ad8c558750845ba470902615;Rust1.85.1;R4NAK-port1;constants4", &value, .{});
    break :blk value;
};
pub fn span(address: usize, size: usize) bool {
    return address != 0 and size != 0 and size <= std.math.maxInt(usize) - address;
}
pub fn overlaps(a: usize, a_size: usize, b: usize, b_size: usize) bool {
    return a < b + b_size and b < a + a_size;
}
fn nonzero(d: c.R4NakDigest) bool {
    return d.h0 | d.h1 | d.h2 | d.h3 != 0;
}
fn validKey(key: *const c.R4NakCacheKey) bool {
    return key.version == 1 and key.size == @sizeOf(c.R4NakCacheKey) and key.vendor_id == 0x10de and
        key.device_id != 0 and key.device_id <= 0xffff and key.chipset != 0 and
        (key.sm == 75 or key.sm == 86 or key.sm == 89 or key.sm == 120) and
        (key.stage == 0 or key.stage == 4 or key.stage == 5) and
        key.driver_version != 0 and key.command_abi != 0 and key.resource_abi != 0 and key.constants_abi == 4 and
        key.format != 0 and key.device_generation != 0 and key.reset_generation != 0 and key.pipeline_layout != 0 and
        nonzero(key.source_hash) and nonzero(key.pipeline_hash);
}
fn validBinary(key: *const c.R4NakCacheKey, binary: *const c.R4NakBinary, bytes: usize) bool {
    return binary.version == 1 and binary.size == @sizeOf(c.R4NakBinary) and binary.status == 0 and
        binary.sm == key.sm and binary.stage == key.stage and
        binary.gprs >= 4 and binary.gprs <= 255 and binary.max_warps != 0 and
        bytes > 0 and bytes <= max_code_bytes and bytes % 16 == 0 and binary.code_bytes == bytes and
        binary.instructions != 0 and binary.instructions <= bytes / 16 and
        std.meta.eql(binary.source_hash, key.source_hash);
}
// Types contain only explicit 32/64-bit scalar fields and nested structures.
// Walk the schema instead of serializing host padding or addresses.
fn encode(comptime T: type, output: []u8, value: T) void {
    switch (@typeInfo(T)) {
        .int => std.mem.writeInt(T, output[0..@sizeOf(T)], value, .little),
        .@"struct" => inline for (std.meta.fields(T)) |f| encode(f.type, output[@offsetOf(T, f.name)..], @field(value, f.name)),
        else => @compileError("Nonportable cache field"),
    }
}
fn decode(comptime T: type, bytes: []const u8) T {
    switch (@typeInfo(T)) {
        .int => return std.mem.readInt(T, bytes[0..@sizeOf(T)], .little),
        .@"struct" => {
            var value: T = std.mem.zeroes(T);
            inline for (std.meta.fields(T)) |f| @field(value, f.name) = decode(f.type, bytes[@offsetOf(T, f.name)..]);
            return value;
        },
        else => @compileError("Nonportable cache field"),
    }
}
fn digest(prefix: []const u8, code: []const u8) [32]u8 {
    var h: Sha256 = .init(.{});
    h.update(prefix);
    h.update(code);
    return h.finalResult();
}
pub export fn r4nak_cache_write_impl(key: *const c.R4NakCacheKey, binary: *const c.R4NakBinary, code: [*]const u8, code_length: u64, bytes: [*]u8, capacity: u64, written: *u64) callconv(.c) i32 {
    if (!validKey(key) or !validBinary(key, binary, code_length) or !span(@intFromPtr(code), code_length) or !span(@intFromPtr(bytes), capacity)) return c.status_invalid;
    const total = code_offset + code_length;
    if (capacity < total) return c.status_capacity;
    if (overlaps(@intFromPtr(bytes), total, @intFromPtr(code), code_length) or
        overlaps(@intFromPtr(bytes), total, @intFromPtr(key), @sizeOf(c.R4NakCacheKey)) or
        overlaps(@intFromPtr(bytes), total, @intFromPtr(binary), @sizeOf(c.R4NakBinary)) or
        overlaps(@intFromPtr(bytes), total, @intFromPtr(written), @sizeOf(u64)) or
        overlaps(@intFromPtr(written), @sizeOf(u64), @intFromPtr(code), code_length) or
        overlaps(@intFromPtr(written), @sizeOf(u64), @intFromPtr(key), @sizeOf(c.R4NakCacheKey)) or
        overlaps(@intFromPtr(written), @sizeOf(u64), @intFromPtr(binary), @sizeOf(c.R4NakBinary))) return c.status_invalid;
    var header: [code_offset]u8 = @splat(0);
    @memcpy(header[0..8], "R4NAKC01");
    encode(u32, header[8..], 1);
    encode(u32, header[12..], c.compiler_revision);
    encode(u64, header[16..], total);
    encode(u32, header[24..], @sizeOf(c.R4NakCacheKey));
    encode(u32, header[28..], @sizeOf(c.R4NakBinary));
    @memcpy(header[32..64], &compiler_id);
    encode(c.R4NakCacheKey, header[key_offset..], key.*);
    var executable = binary.*;
    executable.peak_bytes = 0;
    executable.elapsed_ns = 0;
    executable.log_length = 0;
    encode(c.R4NakBinary, header[binary_offset..], executable);
    @memcpy(header[digest_offset..], &digest(header[0..digest_offset], code[0..code_length]));
    @memcpy(bytes[0..code_offset], &header);
    @memcpy(bytes[code_offset..][0..code_length], code[0..code_length]);
    written.* = total;
    return c.status_ok;
}
pub export fn r4nak_cache_read_impl(key: *const c.R4NakCacheKey, bytes: [*]const u8, length: u64, output: *c.R4NakBinary, code: [*]u8, capacity: u64) callconv(.c) i32 {
    if (!validKey(key) or !span(@intFromPtr(bytes), length) or !span(@intFromPtr(code), capacity)) return c.status_invalid;
    if (length < code_offset or length > code_offset + max_code_bytes) return c.status_cache_miss;
    const input = bytes[0..length];
    if (!std.mem.eql(u8, input[0..8], "R4NAKC01") or decode(u32, input[8..]) != 1 or decode(u32, input[12..]) != c.compiler_revision or
        decode(u64, input[16..]) != length or decode(u32, input[24..]) != @sizeOf(c.R4NakCacheKey) or
        decode(u32, input[28..]) != @sizeOf(c.R4NakBinary) or !std.mem.eql(u8, input[32..64], &compiler_id)) return c.status_cache_miss;
    const stored_key = decode(c.R4NakCacheKey, input[key_offset..]);
    const stored_binary = decode(c.R4NakBinary, input[binary_offset..]);
    if (!std.meta.eql(stored_key, key.*) or !validBinary(key, &stored_binary, length - code_offset) or
        stored_binary.peak_bytes != 0 or stored_binary.elapsed_ns != 0 or stored_binary.log_length != 0 or
        !std.mem.eql(u8, input[digest_offset..code_offset], &digest(input[0..digest_offset], input[code_offset..]))) return c.status_cache_miss;
    if (capacity < stored_binary.code_bytes) return c.status_capacity;
    if (overlaps(@intFromPtr(code), stored_binary.code_bytes, @intFromPtr(bytes), length) or
        overlaps(@intFromPtr(output), @sizeOf(c.R4NakBinary), @intFromPtr(bytes), length) or
        overlaps(@intFromPtr(output), @sizeOf(c.R4NakBinary), @intFromPtr(code), stored_binary.code_bytes) or
        overlaps(@intFromPtr(code), stored_binary.code_bytes, @intFromPtr(key), @sizeOf(c.R4NakCacheKey)) or
        overlaps(@intFromPtr(output), @sizeOf(c.R4NakBinary), @intFromPtr(key), @sizeOf(c.R4NakCacheKey))) return c.status_invalid;
    @memcpy(code[0..stored_binary.code_bytes], input[code_offset..]);
    output.* = stored_binary;
    return c.status_ok;
}

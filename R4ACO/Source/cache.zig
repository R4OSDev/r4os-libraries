// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const std = @import("std");
const c = @import("r4l_contract");
const Sha256 = std.crypto.hash.sha2.Sha256;
const key_offset = 64;
const binary_offset = key_offset + @sizeOf(c.R4AcoCacheKey);
const digest_offset = binary_offset + @sizeOf(c.R4AcoBinary);
pub const code_offset = digest_offset + 32;
pub const max_code_bytes = 16 * 1024 * 1024;
// The native build hashes the complete source/toolchain/port input closure.
extern fn r4aco_native_identity() callconv(.c) *const [32]u8;

pub fn span(address: usize, size: usize) bool {
    return address != 0 and size != 0 and size <= std.math.maxInt(usize) - address;
}
pub fn overlaps(a: usize, a_size: usize, b: usize, b_size: usize) bool {
    return a < b + b_size and b < a + a_size;
}
fn nonzero(d: c.R4AcoDigest) bool {
    return d.h0 | d.h1 | d.h2 | d.h3 != 0;
}
fn validKey(key: *const c.R4AcoCacheKey) bool {
    return key.version == 1 and key.size == @sizeOf(c.R4AcoCacheKey) and key.vendor_id == 0x1002 and
        key.gfx_profile == (@import("gpu_profile.zig").select(key.device_id, key.chip_revision) orelse return false) and
        (key.stage == 0 or key.stage == 4 or key.stage == 5) and (key.resource_abi == 1 or key.resource_abi == 2) and
        key.driver_version != 0 and key.command_abi != 0 and key.reserved == 0 and
        (key.stage == 5 or key.format != 0) and key.device_generation != 0 and key.reset_generation != 0 and key.pipeline_layout != 0 and
        nonzero(key.source_hash) and nonzero(key.pipeline_hash);
}
fn validBinary(key: *const c.R4AcoCacheKey, binary: *const c.R4AcoBinary, bytes: usize) bool {
    if (!(binary.version == 1 and binary.size == @sizeOf(c.R4AcoBinary) and binary.status == 0 and binary.reserved == 0 and
        binary.device_id == key.device_id and binary.chip_revision == key.chip_revision and binary.stage == key.stage and
        binary.gfx_profile == key.gfx_profile and binary.resource_abi == key.resource_abi and binary.sgprs >= 16 and binary.sgprs <= 112 and binary.sgprs % 16 == 0 and
        binary.vgprs >= 4 and binary.vgprs <= 256 and binary.vgprs % 4 == 0 and binary.lds_bytes <= 65536 and
        binary.scratch_bytes_per_wave <= 64 * 1024 * 1024 and binary.float_mode <= 255 and
        bytes > 0 and bytes <= max_code_bytes and bytes % 4 == 0 and binary.code_bytes == bytes and
        binary.exec_bytes != 0 and binary.exec_bytes <= bytes and binary.exec_bytes % 4 == 0 and binary.symbol_count <= 32 and
        std.meta.eql(binary.source_hash, key.source_hash))) return false;
    if (binary.stage == 5) {
        if (binary.workgroup_x == 0 or binary.workgroup_x > 1024 or binary.workgroup_y == 0 or binary.workgroup_y > 1024 or
            binary.workgroup_z == 0 or binary.workgroup_z > 1024 or
            @as(u64, binary.workgroup_x) * binary.workgroup_y * binary.workgroup_z > 1024 or
            binary.user_sgprs != 9 or binary.input_vgprs != 3 or binary.spi_ps_input_ena != 0 or
            binary.spi_ps_input_addr != 0 or binary.spi_shader_col_format != 0) return false;
    } else {
        if (binary.workgroup_x != 0 or binary.workgroup_y != 0 or binary.workgroup_z != 0 or binary.lds_bytes != 0) return false;
        if (binary.stage == 0) {
            if (binary.user_sgprs != 9 or binary.input_vgprs != 4 or binary.spi_ps_input_ena != 0 or
                binary.spi_ps_input_addr != 0 or binary.spi_shader_col_format != 0) return false;
        } else if (binary.user_sgprs != 6 or binary.input_vgprs != 24 or binary.spi_ps_input_ena != 0xffff or
            binary.spi_ps_input_addr != 0xffff or binary.spi_shader_col_format != 9) return false;
    }
    const symbols: *const [32]u64 = @ptrCast(&binary.symbols);
    for (symbols, 0..) |symbol, i| {
        if (i >= binary.symbol_count) {
            if (symbol != 0) return false;
            continue;
        }
        const kind: u32 = @truncate(symbol);
        const offset = symbol >> 32;
        if (kind < 1 or kind > 3 or offset >= binary.exec_bytes / 4) return false;
        for (symbols[0..i]) |previous| if (previous >> 32 == offset) return false;
    }
    return true;
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
pub export fn r4aco_cache_write_impl(key: *const c.R4AcoCacheKey, binary: *const c.R4AcoBinary, code: [*]const u8, code_length: u64, bytes: [*]u8, capacity: u64, written: *u64) callconv(.c) i32 {
    if (!validKey(key) or !validBinary(key, binary, code_length) or !span(@intFromPtr(code), code_length) or !span(@intFromPtr(bytes), capacity)) return c.status_invalid;
    const total = code_offset + code_length;
    if (capacity < total) return c.status_capacity;
    if (overlaps(@intFromPtr(bytes), total, @intFromPtr(code), code_length) or
        overlaps(@intFromPtr(bytes), total, @intFromPtr(key), @sizeOf(c.R4AcoCacheKey)) or
        overlaps(@intFromPtr(bytes), total, @intFromPtr(binary), @sizeOf(c.R4AcoBinary)) or
        overlaps(@intFromPtr(bytes), total, @intFromPtr(written), @sizeOf(u64)) or
        overlaps(@intFromPtr(written), @sizeOf(u64), @intFromPtr(code), code_length) or
        overlaps(@intFromPtr(written), @sizeOf(u64), @intFromPtr(key), @sizeOf(c.R4AcoCacheKey)) or
        overlaps(@intFromPtr(written), @sizeOf(u64), @intFromPtr(binary), @sizeOf(c.R4AcoBinary))) return c.status_invalid;
    var header: [code_offset]u8 = @splat(0);
    @memcpy(header[0..8], "R4ACOC01");
    encode(u32, header[8..], 1);
    encode(u32, header[12..], c.compiler_revision);
    encode(u64, header[16..], total);
    encode(u32, header[24..], @sizeOf(c.R4AcoCacheKey));
    encode(u32, header[28..], @sizeOf(c.R4AcoBinary));
    @memcpy(header[32..64], r4aco_native_identity());
    encode(c.R4AcoCacheKey, header[key_offset..], key.*);
    var executable = binary.*;
    executable.peak_bytes = 0;
    executable.elapsed_ns = 0;
    executable.log_length = 0;
    encode(c.R4AcoBinary, header[binary_offset..], executable);
    @memcpy(header[digest_offset..], &digest(header[0..digest_offset], code[0..code_length]));
    @memcpy(bytes[0..code_offset], &header);
    @memcpy(bytes[code_offset..][0..code_length], code[0..code_length]);
    written.* = total;
    return c.status_ok;
}
pub export fn r4aco_cache_read_impl(key: *const c.R4AcoCacheKey, bytes: [*]const u8, length: u64, output: *c.R4AcoBinary, code: [*]u8, capacity: u64) callconv(.c) i32 {
    if (!validKey(key) or !span(@intFromPtr(bytes), length) or !span(@intFromPtr(code), capacity)) return c.status_invalid;
    if (length < code_offset or length > code_offset + max_code_bytes) return c.status_cache_miss;
    const input = bytes[0..length];
    if (!std.mem.eql(u8, input[0..8], "R4ACOC01") or decode(u32, input[8..]) != 1 or decode(u32, input[12..]) != c.compiler_revision or
        decode(u64, input[16..]) != length or decode(u32, input[24..]) != @sizeOf(c.R4AcoCacheKey) or
        decode(u32, input[28..]) != @sizeOf(c.R4AcoBinary) or !std.mem.eql(u8, input[32..64], r4aco_native_identity())) return c.status_cache_miss;
    const stored_key = decode(c.R4AcoCacheKey, input[key_offset..]);
    const stored_binary = decode(c.R4AcoBinary, input[binary_offset..]);
    if (!std.meta.eql(stored_key, key.*) or !validBinary(key, &stored_binary, length - code_offset) or
        stored_binary.peak_bytes != 0 or stored_binary.elapsed_ns != 0 or stored_binary.log_length != 0 or
        !std.mem.eql(u8, input[digest_offset..code_offset], &digest(input[0..digest_offset], input[code_offset..]))) return c.status_cache_miss;
    if (capacity < stored_binary.code_bytes) return c.status_capacity;
    if (overlaps(@intFromPtr(code), stored_binary.code_bytes, @intFromPtr(bytes), length) or
        overlaps(@intFromPtr(output), @sizeOf(c.R4AcoBinary), @intFromPtr(bytes), length) or
        overlaps(@intFromPtr(output), @sizeOf(c.R4AcoBinary), @intFromPtr(code), stored_binary.code_bytes) or
        overlaps(@intFromPtr(code), stored_binary.code_bytes, @intFromPtr(key), @sizeOf(c.R4AcoCacheKey)) or
        overlaps(@intFromPtr(output), @sizeOf(c.R4AcoBinary), @intFromPtr(key), @sizeOf(c.R4AcoCacheKey))) return c.status_invalid;
    @memcpy(code[0..stored_binary.code_bytes], input[code_offset..]);
    output.* = stored_binary;
    return c.status_ok;
}

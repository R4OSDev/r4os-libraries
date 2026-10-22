//! SDK-local transport, not a library helper implementation. The compiler selects the
//! original owner function and native types. Private values remain opaque.
const std = @import("std");
const schema = @import("schema");
const abi = schema.abi;
comptime {
    if (@import("fingerprint.zig").fingerprint != schema.fingerprint) @compileError("Library helper boundary drift: regenerate before compiling consumers");
}
pub export fn R4LibrariesVerifyAbi(fingerprint: u64) callconv(.c) i32 {
    return if (fingerprint == schema.fingerprint) 0 else abi.io_error_invalid;
}
pub const present: u32 = 1;
pub const native_error: u32 = 2;
pub const use_default: u32 = 4;
pub const Slot = extern struct {
    ptr: ?*anyopaque = null,
    length: u64 = 0,
    bits: u64 = 0,
    status: i32 = 0,
    flags: u32 = 0,
};
const Error = error{ InvalidArgument, InvalidType, InvalidField };
fn object(comptime T: type, pointer: ?*anyopaque) Error!*T {
    const ptr = pointer orelse return error.InvalidArgument;
    if (@intFromPtr(ptr) % @alignOf(T) != 0) return error.InvalidArgument;
    return @ptrCast(@alignCast(ptr));
}
fn decode(comptime T: type, value: Slot) Error!T {
    return switch (@typeInfo(T)) {
        .void => {},
        .bool => if (value.bits < 2) value.bits != 0 else error.InvalidArgument,
        .int => |n| if (n.bits == 0) 0 else if (n.signedness == .signed) @bitCast(@as(std.meta.Int(.unsigned, n.bits), @truncate(value.bits))) else @intCast(value.bits & std.math.maxInt(T)),
        .float => (try object(T, value.ptr)).*, // No floating-point C ABI.
        .@"enum" => |e| blk: {
            // A non-exhaustive enum admits unknown representable values. Let
            // its original owner reject an unsupported format/operation with
            // the native error, rather than inventing a transport failure.
            if (!e.is_exhaustive) {
                if (@typeInfo(e.tag_type).int.signedness == .unsigned and value.bits > std.math.maxInt(e.tag_type)) return error.InvalidArgument;
                break :blk @enumFromInt(try decode(e.tag_type, value));
            }
            inline for (e.fields) |field| if (value.bits == field.value) break :blk @field(T, field.name);
            break :blk error.InvalidArgument;
        },
        .pointer => |p| blk: {
            if (p.size == .slice) {
                if (value.length > std.math.maxInt(isize) / @max(1, @sizeOf(p.child))) return error.InvalidArgument;
                if (value.length == 0) break :blk @as(T, @constCast(&.{}));
                const ptr = value.ptr orelse return error.InvalidArgument;
                if (@intFromPtr(ptr) % @alignOf(p.child) != 0) return error.InvalidArgument;
                const items: [*]p.child = @ptrCast(@alignCast(ptr));
                break :blk items[0..@intCast(value.length)];
            }
            const ptr = value.ptr orelse return error.InvalidArgument;
            if (p.child != anyopaque and @typeInfo(p.child) != .@"fn" and @intFromPtr(ptr) % @alignOf(p.child) != 0) return error.InvalidArgument;
            break :blk @ptrCast(@alignCast(ptr));
        },
        .optional => |o| if ((value.flags & present) == 0) null else try decode(o.child, value),
        .@"struct", .@"union", .array => (try object(T, value.ptr)).*,
        else => @compileError("Unsupported library helper argument: " ++ @typeName(T)),
    };
}
fn store(comptime T: type, value: T, output: ?*anyopaque) Error!Slot {
    return switch (@typeInfo(T)) {
        .void => .{},
        .bool => .{ .bits = @intFromBool(value), .flags = present },
        .int => |n| .{ .bits = if (n.signedness == .signed) @as(u64, @bitCast(@as(i64, value))) else @intCast(value), .flags = present },
        .@"enum" => .{ .bits = @intFromEnum(value), .flags = present },
        .pointer => |p| .{ .ptr = @ptrCast(@constCast(if (p.size == .slice) value.ptr else value)), .length = if (p.size == .slice) value.len else 0, .flags = present },
        .optional => |o| if (value) |item| try store(o.child, item, output) else .{},
        .error_union => |e| blk: {
            const result = value catch |err| {
                const name = @errorName(err);
                break :blk .{ .ptr = @ptrCast(@constCast(name.ptr)), .length = name.len, .flags = native_error };
            };
            break :blk try store(e.payload, result, output);
        },
        .float, .@"struct", .@"union", .array => blk: {
            (try object(T, output)).* = value;
            break :blk .{ .ptr = output, .flags = present };
        },
        else => @compileError("Unsupported library helper result: " ++ @typeName(T)),
    };
}
fn failed() Slot {
    return .{ .status = abi.io_error_invalid };
}

pub export fn R4LibrariesInvoke(fingerprint: u64, operation: u32, values: ?[*]const Slot, count: u32, output: ?*anyopaque) callconv(.c) Slot {
    @setEvalBranchQuota(32_000_000);
    if (fingerprint != schema.fingerprint) return failed();
    inline for (schema.functions, 0..) |entry, index| {
        if (operation == index) {
            const function = @field(entry.owner, entry.name);
            const F = @TypeOf(function);
            const info = @typeInfo(F).@"fn";
            if (count != info.params.len or (count != 0 and values == null)) return failed();
            var args: std.meta.ArgsTuple(F) = undefined;
            inline for (info.params, 0..) |param, i| args[i] = decode(param.type.?, values.?[i]) catch return failed();
            return store(info.return_type.?, @call(.auto, function, args), output) catch failed();
        }
    }
    return failed();
}
pub export fn R4LibrariesConstruct(fingerprint: u64, type_id: u32, values: ?[*]const Slot, count: u32, output: ?*anyopaque) callconv(.c) Slot {
    @setEvalBranchQuota(32_000_000);
    if (fingerprint != schema.fingerprint) return failed();
    inline for (schema.types, 0..) |T, id| {
        if (comptime schema.context(T) or schema.canonical(T)) continue;
        if (id == type_id) {
            const ptr = object(T, output) catch return failed();
            switch (@typeInfo(T)) {
                .@"struct" => |s| {
                    if (count != s.fields.len or (count != 0 and values == null)) return failed();
                    inline for (s.fields, 0..) |field, i| {
                        const slot = values.?[i];
                        @field(ptr.*, field.name) = if ((slot.flags & use_default) != 0) blk: {
                            const default = field.default_value_ptr orelse return failed();
                            const value: *const field.type = @ptrCast(@alignCast(default));
                            break :blk value.*;
                        } else decode(field.type, slot) catch return failed();
                    }
                    return .{ .ptr = output, .flags = present };
                },
                .@"enum", .array, .optional, .pointer => {
                    if (count != 1 or values == null) return failed();
                    ptr.* = decode(T, values.?[0]) catch return failed();
                    return .{ .ptr = output, .flags = present };
                },
                else => return failed(),
            }
        }
    }
    return failed();
}
pub export fn R4LibrariesInspect(fingerprint: u64, type_id: u32, source: ?*anyopaque, output: ?*anyopaque) callconv(.c) Slot {
    @setEvalBranchQuota(32_000_000);
    if (fingerprint != schema.fingerprint) return failed();
    inline for (schema.types, 0..) |T, i| if (type_id == i) {
        if (comptime schema.context(T) or schema.canonical(T)) return failed();
        const value = object(T, source) catch return failed();
        return switch (@typeInfo(T)) {
            .@"union" => |u| if (u.tag_type != null) .{ .bits = @intFromEnum(std.meta.activeTag(value.*)), .flags = present } else failed(),
            .@"struct" => failed(),
            else => store(T, value.*, output) catch failed(),
        };
    };
    return failed();
}
fn access(comptime T: type, field_index: u32, source: ?*anyopaque, update: ?*const Slot, output: ?*anyopaque) Slot {
    const object_ptr = object(T, source) catch return failed();
    switch (@typeInfo(T)) {
        .@"struct" => |s| inline for (s.fields, 0..) |field, i| {
            if (field_index == i) {
                if (update) |value| @field(object_ptr.*, field.name) = decode(field.type, value.*) catch return failed();
                return if (update != null) .{} else store(field.type, @field(object_ptr.*, field.name), output) catch failed();
            }
        },
        .@"union" => |u| inline for (u.fields, 0..) |field, i| {
            if (field_index == i) {
                if (update) |value| {
                    object_ptr.* = @unionInit(T, field.name, decode(field.type, value.*) catch return failed());
                    return .{};
                }
                if (u.tag_type != null and @intFromEnum(std.meta.activeTag(object_ptr.*)) != @intFromEnum(@field(u.tag_type.?, field.name))) return failed();
                return store(field.type, @field(object_ptr.*, field.name), output) catch failed();
            }
        },
        else => {},
    }
    return failed();
}
pub export fn R4LibrariesField(fingerprint: u64, type_id: u32, field_index: u32, source: ?*anyopaque, update: ?*const Slot, output: ?*anyopaque) callconv(.c) Slot {
    @setEvalBranchQuota(32_000_000);
    if (fingerprint != schema.fingerprint) return failed();
    inline for (schema.types, 0..) |T, i| {
        if (comptime schema.context(T) or schema.canonical(T)) continue;
        if (type_id == i) return access(T, field_index, source, update, output);
    }
    return failed();
}

//! Language-boundary adapters, with no codec/font/image implementation.
const std = @import("std");
const r4os = @import("r4os");

pub const Session = struct {
    bundle: r4os.program.Bundle,
    sys: r4os.r4sys.Context,
};
pub fn openSession(output: *Session, raw: *const r4os.abi.R4XStartContext) bool {
    output.bundle = r4os.program.bundleValueFromR4XStart(raw) orelse return false;
    output.sys = r4os.r4sys.Context.init(&output.bundle);
    return true;
}
pub fn system(session: *Session) *r4os.r4sys.Context {
    return &session.sys;
}

/// Callbacks use their original C ABI. The caller retains this descriptor at
/// its exact address until every object/allocation using it has been freed.
pub const Memory = struct {
    user: ?*anyopaque = null,
    allocate: *const fn (?*anyopaque, usize, usize) callconv(.c) ?[*]u8,
    release: *const fn (?*anyopaque, [*]u8, usize, usize) callconv(.c) void,
    pub fn allocator(self: *Memory) std.mem.Allocator {
        return .{ .ptr = self, .vtable = &vtable };
    }
    const vtable: std.mem.Allocator.VTable = .{ .alloc = alloc, .resize = resize, .remap = remap, .free = free };
    fn alloc(ctx: *anyopaque, len: usize, alignment: std.mem.Alignment, _: usize) ?[*]u8 {
        const self: *Memory = @ptrCast(@alignCast(ctx));
        return self.allocate(self.user, len, alignment.toByteUnits());
    }
    fn resize(_: *anyopaque, _: []u8, _: std.mem.Alignment, _: usize, _: usize) bool {
        return false;
    }
    fn remap(_: *anyopaque, _: []u8, _: std.mem.Alignment, _: usize, _: usize) ?[*]u8 {
        return null;
    }
    fn free(ctx: *anyopaque, bytes: []u8, alignment: std.mem.Alignment, _: usize) void {
        const self: *Memory = @ptrCast(@alignCast(ctx));
        self.release(self.user, bytes.ptr, bytes.len, alignment.toByteUnits());
    }
};
/// Explicitly release a slice returned by a helper with the same allocator.
pub fn freeBytes(allocator: std.mem.Allocator, bytes: []u8) void {
    allocator.free(bytes);
}

/// Concrete clients for the public color/JPEG specializations. Foreign
/// consumers never need to invent the private Zig client layout.
pub fn colorClient(raw: *const r4os.abi.R4XStartContext) !@import("../../R4GFX/Bindings/Zig/r4gfx_abi.zig").ColorV1Client {
    return @import("../../R4GFX/Bindings/Zig/r4gfx_abi.zig").ColorV1Client.init(raw);
}
pub fn videoClient(raw: *const r4os.abi.R4XStartContext) !@import("../../R4VIDEO/Bindings/Zig/r4video.zig").VideoV1Client {
    return @import("../../R4VIDEO/Bindings/Zig/r4video.zig").VideoV1Client.init(raw);
}

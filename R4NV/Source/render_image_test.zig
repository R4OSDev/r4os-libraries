const std = @import("std");
const t = std.testing;
const render = @import("render_image.zig");
const reference = @embedFile("Fixtures/render-image.bin");
fn word(data: []const u8, at: usize) u32 { return std.mem.readInt(u32, data[at..][0..4], .little); }
fn wide(data: []const u8, at: usize) u64 { return std.mem.readInt(u64, data[at..][0..8], .little); }
pub fn check() !void {
    try @import("render_test.zig").check();
    for (0..6) |index| {
        const record = reference[index * 108..][0..108];
        var image: render.Image = .{ .address = wide(record, 0), .bytes = wide(record, 8), .width = word(record, 16), .height = word(record, 20),
            .pitch = word(record, 24), .format = @enumFromInt(word(record, 28)), .layout = if (word(record, 32) == 0) .linear else .blocklinear, .log2_gobs = @intCast(word(record, 36)) };
        const tic = try render.texture(image);
        const rt = try render.target(image);
        try t.expectEqualSlices(u8, record[40..72], std.mem.asBytes(&tic));
        try t.expectEqualSlices(u8, record[72..108], std.mem.asBytes(&rt.words));
        image.bytes -= 1; try t.expectError(error.Bounds, render.texture(image)); image.bytes += 1;
        if (image.layout == .linear) {
            image.address += 32;
            _ = try render.texture(image);
            try t.expectError(error.Unsupported, render.target(image));
        } else {
            image.pitch += 64; image.bytes += 64 * std.mem.alignForward(u64, image.height, @as(u64, 8) << @intCast(image.log2_gobs));
            try t.expectError(error.Unsupported, render.texture(image));
        }
    }
    for ([_]render.Filter{.nearest, .bilinear}, 0..) |filter, index| {
        const sampler = render.sampler(filter);
        try t.expectEqualSlices(u8, reference[648 + index * 32..][0..32], std.mem.asBytes(&sampler));
    }
}

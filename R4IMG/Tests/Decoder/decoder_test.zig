const std = @import("std");
const r4img = @import("r4img");

const rgba_png = @embedFile("Fixtures/rgba.png");
const transparent_png = @embedFile("Fixtures/transparent.png");
const baseline_jpeg = @embedFile("Fixtures/baseline.jpg");
const progressive_jpeg = @embedFile("Fixtures/progressive.jpg");
const basic_svg = @embedFile("Fixtures/basic.svg");

const ParallelDecode = struct {
    bytes: []const u8,
    precise: bool,
    pixels: []u32,
    rgba: []u16,
    scratch: []u8,
    golden: []const u8,
    ready: *std.atomic.Value(u32),
    start: *std.atomic.Value(bool),
    passed: bool = true,

    fn decode(self: *ParallelDecode) ![]const u8 {
        if (self.precise) {
            const image = try r4img.pngDecode16(self.bytes, self.rgba, self.scratch);
            return std.mem.sliceAsBytes(image.rgba);
        }
        const image = try r4img.r4imgDecode(self.bytes, "", self.pixels, self.scratch);
        return std.mem.sliceAsBytes(image.pixels);
    }

    fn run(self: *ParallelDecode) void {
        _ = self.ready.fetchAdd(1, .release);
        while (!self.start.load(.acquire)) std.atomic.spinLoopHint();
        for (0..400) |_| {
            const actual = self.decode() catch {
                self.passed = false;
                return;
            };
            if (!std.mem.eql(u8, self.golden, actual)) {
                self.passed = false;
                return;
            }
        }
    }
};

test "parallel PNG JPEG and full-precision PNG retain their own scratch and pixels" {
    var fixture = @import("png_fixture.zig").Builder.init();
    fixture.header();
    fixture.rgba16(.{ 1, 257, 0x1234, 65535, 0xabcd, 0x8001, 3, 0x7ffd });
    const sources = [_][]const u8{ rgba_png, baseline_jpeg, fixture.view() };
    var ready: std.atomic.Value(u32) = .init(0);
    var start: std.atomic.Value(bool) = .init(false);
    var workers: [3]ParallelDecode = undefined;
    var initialized: usize = 0;
    defer for (workers[0..initialized]) |worker| {
        std.testing.allocator.free(worker.golden);
        std.testing.allocator.free(worker.scratch);
        std.testing.allocator.free(worker.rgba);
        std.testing.allocator.free(worker.pixels);
    };
    for (&workers, sources, 0..) |*worker, encoded, index| {
        const info = try r4img.r4imgProbe(encoded, "");
        const count = try info.pixelCount();
        worker.* = .{
            .bytes = encoded,
            .precise = index == 2,
            .pixels = try std.testing.allocator.alloc(u32, count),
            .rgba = try std.testing.allocator.alloc(u16, count * 4),
            .scratch = try std.testing.allocator.alloc(u8, if (index == 2)
                try r4img.pngScratchBytes16(info, encoded.len)
            else
                try r4img.scratchBytesFor(info, encoded.len)),
            .golden = &.{},
            .ready = &ready,
            .start = &start,
        };
        initialized += 1;
        worker.golden = try std.testing.allocator.dupe(u8, try worker.decode());
    }
    var threads: [3]std.Thread = undefined;
    for (&threads, &workers, 0..) |*thread, *worker, index| {
        thread.* = std.Thread.spawn(.{}, ParallelDecode.run, .{worker}) catch |err| {
            start.store(true, .release);
            for (threads[0..index]) |started| started.join();
            return err;
        };
    }
    while (ready.load(.acquire) != workers.len) std.atomic.spinLoopHint();
    start.store(true, .release);
    for (threads) |thread| thread.join();
    for (workers) |worker| try std.testing.expect(worker.passed);
}

const SvgLinkCapture = struct {
    count: usize = 0,
    node: u16 = 0,
    x: i32 = 0,
    y: i32 = 0,
    width: i32 = 0,
    height: i32 = 0,

    fn record(context: ?*anyopaque, node: u16, x: i32, y: i32, width: i32, height: i32) callconv(.c) void {
        const self: *SvgLinkCapture = @ptrCast(@alignCast(context orelse return));
        self.* = .{ .count = self.count + 1, .node = node, .x = x, .y = y, .width = width, .height = height };
    }
};

fn decodeFixture(bytes: []const u8, content_type: []const u8) !r4img.Image {
    const info = try r4img.r4imgProbe(bytes, content_type);
    const pixels = try std.testing.allocator.alloc(u32, try info.pixelCount());
    errdefer std.testing.allocator.free(pixels);
    const scratch = try std.testing.allocator.alloc(u8, try r4img.scratchBytesFor(info, bytes.len));
    defer std.testing.allocator.free(scratch);
    return r4img.r4imgDecode(bytes, content_type, pixels, scratch);
}

test "PNG RGBA fixture decodes with intrinsic dimensions and alpha" {
    try @import("color_metadata_test.zig").check();
    const image = try decodeFixture(rgba_png, "image/png;charset=binary");
    defer std.testing.allocator.free(image.pixels);
    try std.testing.expectEqual(@as(u32, 10), image.info.width);
    try std.testing.expectEqual(@as(u32, 10), image.info.height);
    try std.testing.expectEqual(r4img.Format.png, image.info.format);
    try std.testing.expectEqual(@as(usize, 100), image.pixels.len);
    try std.testing.expectEqual(@as(u32, 0xFF0000FF), image.pixels[0]);

    const transparent = try decodeFixture(transparent_png, "image/png");
    defer std.testing.allocator.free(transparent.pixels);
    var has_transparency = false;
    for (transparent.pixels) |pixel| {
        if (pixel >> 24 < 0xFF) has_transparency = true;
    }
    try std.testing.expect(has_transparency);
}

test "baseline and progressive JPEG fixtures decode through the same bounded path" {
    try @import("raster_color_test.zig").check();
    const baseline = try decodeFixture(baseline_jpeg, "image/jpeg");
    defer std.testing.allocator.free(baseline.pixels);
    try std.testing.expectEqual(r4img.Format.jpeg, baseline.info.format);
    try std.testing.expectEqual(@as(u32, 100), baseline.info.width);
    try std.testing.expectEqual(@as(u32, 100), baseline.info.height);
    try std.testing.expectEqual(@as(u32, 0xFF), baseline.pixels[0] >> 24);

    const progressive = try decodeFixture(progressive_jpeg, "image/jpeg");
    defer std.testing.allocator.free(progressive.pixels);
    try std.testing.expectEqual(r4img.Format.jpeg, progressive.info.format);
    try std.testing.expect(progressive.info.width > 0 and progressive.info.height > 0);
    try std.testing.expectEqual(@as(u32, 0xFF), progressive.pixels[0] >> 24);
}

test "BMP uses the common RGBA decoder path" {
    var bytes: [70]u8 = .{0} ** 70;
    putU16(&bytes, 0, 0x4D42);
    putU32(&bytes, 2, bytes.len);
    putU32(&bytes, 10, 54);
    putU32(&bytes, 14, 40);
    putU32(&bytes, 18, 2);
    putU32(&bytes, 22, 2);
    putU16(&bytes, 26, 1);
    putU16(&bytes, 28, 24);
    putU32(&bytes, 34, 16);
    bytes[54] = 255;
    bytes[57] = 255;
    bytes[58] = 255;
    bytes[59] = 255;
    bytes[62] = 255;
    bytes[65] = 255;

    const image = try decodeFixture(&bytes, "image/bmp");
    defer std.testing.allocator.free(image.pixels);
    try std.testing.expectEqual(r4img.Format.bmp, image.info.format);
    try std.testing.expectEqual(@as(u32, 2), image.info.width);
    try std.testing.expectEqual(@as(u32, 2), image.info.height);
}

test "SVG fixture uses the bounded common decoder and reports links" {
    const info = try r4img.r4imgProbe(basic_svg, "image/svg+xml;charset=utf-8");
    try std.testing.expectEqual(r4img.Format.svg, info.format);
    try std.testing.expectEqual(@as(u32, 64), info.width);
    try std.testing.expectEqual(@as(u32, 40), info.height);
    const pixels = try std.testing.allocator.alloc(u32, try info.pixelCount());
    defer std.testing.allocator.free(pixels);
    const scratch = try std.testing.allocator.alloc(u8, try r4img.scratchBytesFor(info, basic_svg.len));
    defer std.testing.allocator.free(scratch);
    var links = SvgLinkCapture{};
    const image = try r4img.r4imgDecodeSvg(basic_svg, "image/svg+xml", pixels, scratch, .{
        .links = .{ .context = &links, .record = SvgLinkCapture.record },
    });
    try std.testing.expectEqual(@as(u32, 0xFF112233), image.pixels[0]);
    try std.testing.expectEqual(@as(u32, 0xFFCC3300), image.pixels[12 * 64 + 14]);
    try std.testing.expectEqual(@as(usize, 1), links.count);
    try std.testing.expectEqual(@as(u16, 42), links.node);
    try std.testing.expectEqual(@as(i32, 48), links.x);
    try std.testing.expectEqual(@as(i32, 28), links.y);
    try std.testing.expectEqual(@as(i32, 12), links.width);
    try std.testing.expectEqual(@as(i32, 8), links.height);

    const target_info = r4img.Info{ .format = .svg, .width = 128, .height = 80, .channels = 4 };
    const target_pixels = try std.testing.allocator.alloc(u32, try target_info.pixelCount());
    defer std.testing.allocator.free(target_pixels);
    const target_scratch = try std.testing.allocator.alloc(u8, try r4img.scratchBytesFor(target_info, basic_svg.len));
    defer std.testing.allocator.free(target_scratch);
    var scaled_links = SvgLinkCapture{};
    const scaled = try r4img.r4imgDecodeSvgAt(basic_svg, "image/svg+xml", target_pixels, target_scratch, 128, 80, .{
        .links = .{ .context = &scaled_links, .record = SvgLinkCapture.record },
        .background = 0x00FFFFFF,
    });
    try std.testing.expectEqual(@as(u32, 128), scaled.info.width);
    try std.testing.expectEqual(@as(u32, 80), scaled.info.height);
    try std.testing.expectEqual(@as(u32, 0xFF112233), scaled.pixels[0]);
    try std.testing.expectEqual(@as(usize, 1), scaled_links.count);
    try std.testing.expectEqual(@as(i32, 96), scaled_links.x);
    try std.testing.expectEqual(@as(i32, 56), scaled_links.y);
    try std.testing.expectEqual(@as(i32, 24), scaled_links.width);
    try std.testing.expectEqual(@as(i32, 16), scaled_links.height);

    // Detailed source geometry can remain large at icon output size. The
    // advertised scratch must include row workspace, independent of pixels.
    var detailed: [32 * 1024]u8 = undefined;
    const prefix = "<svg width='1' height='1' viewBox='0 0 4096 4096'><path d='M0 0 ";
    @memcpy(detailed[0..prefix.len], prefix);
    var length = prefix.len;
    for (0..128) |_| {
        const curves = "C0 4096 4096 0 4096 4096 C4096 0 0 4096 0 0 ";
        @memcpy(detailed[length .. length + curves.len], curves);
        length += curves.len;
    }
    const suffix = "z'/></svg>";
    @memcpy(detailed[length .. length + suffix.len], suffix);
    length += suffix.len;
    const icon_info = try r4img.r4imgProbe(detailed[0..length], "image/svg+xml");
    const icon_scratch = try std.testing.allocator.alloc(u8, try r4img.scratchBytesFor(icon_info, length));
    defer std.testing.allocator.free(icon_scratch);
    var icon_pixels: [1]u32 = undefined;
    const icon = try r4img.r4imgDecode(detailed[0..length], "image/svg+xml", &icon_pixels, icon_scratch);
    try std.testing.expectEqual(@as(u32, 1), icon.info.width);
    try std.testing.expectEqual(@as(u32, 1), icon.info.height);
    try std.testing.expectEqual(@as(u32, 0), icon.pixels[0]);
}

test "malformed MIME truncated data and decoded-size limits fail closed" {
    try std.testing.expectError(error.UnsupportedFormat, r4img.r4imgProbe(rgba_png, "text/plain"));
    try std.testing.expectError(error.InvalidImage, r4img.r4imgProbe(rgba_png[0..20], "image/png"));
    const too_large = r4img.Info{ .format = .png, .width = 4096, .height = 4096, .channels = 4 };
    try std.testing.expectError(error.TooLarge, too_large.pixelCount());
    try std.testing.expectError(error.UnsupportedFormat, r4img.r4imgProbe("<!ENTITY x SYSTEM 'file'><svg/>", "image/svg+xml"));
    var invalid_pixels: [64]u32 = undefined;
    var invalid_scratch: [160 * 1024]u8 = undefined;
    try std.testing.expectError(error.UnsupportedFeature, r4img.r4imgDecodeSvg(
        "<svg width='8' height='8'><use href='https://example.test/remote.svg#x'/></svg>",
        "image/svg+xml",
        invalid_pixels[0..],
        invalid_scratch[0..],
        .{},
    ));
}

fn putU16(bytes: []u8, offset: usize, value: u16) void {
    bytes[offset] = @truncate(value);
    bytes[offset + 1] = @truncate(value >> 8);
}

fn putU32(bytes: []u8, offset: usize, value: u32) void {
    bytes[offset] = @truncate(value);
    bytes[offset + 1] = @truncate(value >> 8);
    bytes[offset + 2] = @truncate(value >> 16);
    bytes[offset + 3] = @truncate(value >> 24);
}

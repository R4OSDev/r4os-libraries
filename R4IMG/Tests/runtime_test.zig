const std = @import("std");
const project = @import("project");
const r4img = @import("r4img");
const r4os = @import("r4os");

const rgba_png = @embedFile("Decoder/Fixtures/rgba.png");
const baseline_jpeg = @embedFile("Decoder/Fixtures/baseline.jpg");
const basic_svg = @embedFile("Decoder/Fixtures/basic.svg");
const module_name: [:0]const u8 = "R4IMG";
const api_name: [:0]const u8 = "API_V1";

fn makeContext(imports: []const r4os.abi.R4XStartImport) r4os.abi.R4XStartContext {
    return .{
        .flags = r4os.abi.r4xstart_flag_imports_valid,
        .imports = @intFromPtr(imports.ptr),
        .import_count = @intCast(imports.len),
    };
}

fn makeApi() !struct { raw: r4os.abi.R4XStartContext, imports: [1]r4os.abi.R4XStartImport } {
    var imports = [1]r4os.abi.R4XStartImport{.{
        .group_id = 0,
        .min_version = 1,
        .resolved_version = 1,
        .flags = 0,
        .module_name = @intFromPtr(module_name.ptr),
        .symbol_name = @intFromPtr(api_name.ptr),
        .table = @intFromPtr(&project.r4img_api_v1),
    }};
    return .{ .raw = makeContext(&imports), .imports = imports };
}

const LinkCapture = struct {
    count: usize = 0,
    node: u16 = 0,

    fn record(context: ?*anyopaque, node: u16, _: i32, _: i32, _: i32, _: i32) callconv(.c) void {
        const self: *LinkCapture = @ptrCast(@alignCast(context orelse return));
        self.count += 1;
        self.node = node;
    }
};

test "productive PNG JPEG and BMP decode cross the loaded API_V1 table" {
    var fixture = try makeApi();
    fixture.raw.imports = @intFromPtr(&fixture.imports);
    const api = r4img.Context.init(&fixture.raw) orelse return error.MissingRuntimeBinding;

    const info = try api.probe(rgba_png, "image/png");
    try std.testing.expectEqual(r4img.Format.png, info.format);
    try std.testing.expectEqual(@as(u32, 10), info.width);
    const pixels = try std.testing.allocator.alloc(u32, try info.pixelCount());
    defer std.testing.allocator.free(pixels);
    const scratch = try std.testing.allocator.alloc(u8, try api.scratchBytesFor(info, rgba_png.len));
    defer std.testing.allocator.free(scratch);
    const image = try api.decode(rgba_png, "image/png", pixels, scratch);
    try std.testing.expectEqual(@as(usize, 100), image.pixels.len);
    try std.testing.expectEqual(@as(u32, 0xFF0000FF), image.pixels[0]);

    const jpeg_info = try api.probe(baseline_jpeg, "image/jpeg");
    try std.testing.expectEqual(r4img.Format.jpeg, jpeg_info.format);
    try std.testing.expectEqual(@as(u32, 100), jpeg_info.width);
    const jpeg_pixels = try std.testing.allocator.alloc(u32, try jpeg_info.pixelCount());
    defer std.testing.allocator.free(jpeg_pixels);
    const jpeg_scratch = try std.testing.allocator.alloc(u8, try api.scratchBytesFor(jpeg_info, baseline_jpeg.len));
    defer std.testing.allocator.free(jpeg_scratch);
    const jpeg = try api.decode(baseline_jpeg, "image/jpeg", jpeg_pixels, jpeg_scratch);
    try std.testing.expectEqual(@as(usize, 10_000), jpeg.pixels.len);
    try std.testing.expectEqual(@as(u32, 0xFF), jpeg.pixels[0] >> 24);

    var bmp_bytes: [70]u8 = .{0} ** 70;
    putU16(&bmp_bytes, 0, 0x4D42);
    putU32(&bmp_bytes, 2, bmp_bytes.len);
    putU32(&bmp_bytes, 10, 54);
    putU32(&bmp_bytes, 14, 40);
    putU32(&bmp_bytes, 18, 2);
    putU32(&bmp_bytes, 22, 2);
    putU16(&bmp_bytes, 26, 1);
    putU16(&bmp_bytes, 28, 24);
    putU32(&bmp_bytes, 34, 16);
    bmp_bytes[54] = 255;
    bmp_bytes[57] = 255;
    bmp_bytes[58] = 255;
    bmp_bytes[59] = 255;
    bmp_bytes[62] = 255;
    bmp_bytes[65] = 255;
    const bmp_info = try api.probe(&bmp_bytes, "image/bmp");
    try std.testing.expectEqual(r4img.Format.bmp, bmp_info.format);
    try std.testing.expectEqual(@as(u32, 2), bmp_info.width);
    const bmp_pixels = try std.testing.allocator.alloc(u32, try bmp_info.pixelCount());
    defer std.testing.allocator.free(bmp_pixels);
    const bmp_scratch = try std.testing.allocator.alloc(u8, try api.scratchBytesFor(bmp_info, bmp_bytes.len));
    defer std.testing.allocator.free(bmp_scratch);
    const bmp = try api.decode(&bmp_bytes, "image/bmp", bmp_pixels, bmp_scratch);
    try std.testing.expectEqual(@as(usize, 4), bmp.pixels.len);

    const diagnostic = try api.decoderDiagnostic();
    try std.testing.expect(!diagnostic.allocation_failed);
    try std.testing.expect(diagnostic.scratch_peak != 0);
}

test "SVG callbacks and scaling cross only the runtime table" {
    var fixture = try makeApi();
    fixture.raw.imports = @intFromPtr(&fixture.imports);
    const api = r4img.Context.init(&fixture.raw) orelse return error.MissingRuntimeBinding;
    const info = try api.probe(basic_svg, "image/svg+xml");
    const pixels = try std.testing.allocator.alloc(u32, try info.pixelCount());
    defer std.testing.allocator.free(pixels);
    const scratch = try std.testing.allocator.alloc(u8, try api.scratchBytesFor(info, basic_svg.len));
    defer std.testing.allocator.free(scratch);
    var links = LinkCapture{};
    const image = try api.decodeSvg(basic_svg, "image/svg+xml", pixels, scratch, .{
        .links = .{ .context = &links, .record = LinkCapture.record },
    });
    try std.testing.expectEqual(@as(usize, 1), links.count);
    try std.testing.expectEqual(@as(u16, 42), links.node);

    var destination: [16]u32 = undefined;
    const scaled = try api.scaleComposite(image, &destination, 4, 4, 0x00FFFFFF);
    try std.testing.expectEqual(@as(usize, 16), scaled.len);
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

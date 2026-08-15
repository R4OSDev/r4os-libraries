// Windows bitmap FON/FNT import support used by the in-system Fonts app.
//
// This is deliberately a guest-side SDK helper: it converts classic bitmap
// and Windows-1.x vector FNT resources into bitmap R4F files. Vector strokes
// are rasterized once at import time. No host converter and no original font
// data in the kernel are involved in an installation.

const std = @import("std");
const r4f = @import("font_format.zig");

const RT_FONT: u16 = 8;
const FNT_HEADER_SIZE: usize = 118;
// Windows-1.x FNTs omit the trailing dfReserved byte before dfCharOffset.
// Their bitmap data may still start at byte 118, but their character table
// always starts at byte 117.
const FNT_V1_CHAR_TABLE_OFFSET: usize = 117;

pub const FaceInfo = struct {
    family: []const u8,
    style: []const u8,
    face_index: usize,
    face_count: usize,
    pixel_width: u16,
    pixel_height: u16,
    max_width: u16,
    glyph_count: u16,
    vector: bool,
};

const FntInfo = struct {
    version: u16,
    size: u32,
    df_type: u16,
    ascent: u16,
    external_leading: u16,
    italic: bool,
    underline: bool,
    strikeout: bool,
    weight: u16,
    charset: u8,
    pix_width: u16,
    pix_height: u16,
    avg_width: u16,
    max_width: u16,
    first_char: u8,
    last_char: u8,
    width_bytes: u16,
    face_offset: u32,
    bits_offset: u32,
};

pub const RasterGlyph = struct {
    codepoint: u32,
    width: u16,
    height: u16,
    advance: i16,
    data: []const u8,
};

/// A monochrome source-face preview rendered into caller-owned RGB pixels.
/// This lets the installer preview a bitmap FNT before it writes an R4F file.
pub const Preview = struct {
    width: u16,
    height: u16,
};

const RasterOptions = struct {
    family_name: []const u8,
    face_name: []const u8,
    style_name: []const u8,
    source_name: []const u8,
    pixel_height: u16,
    ascent: i16,
    descent: i16,
    line_height: i16,
    weight: u16,
    style_flags: u32,
    charset: u16,
};

const Table = struct {
    tag: u32,
    offset: u32 = 0,
    size: u32,
    flags: u32 = 0,
};

/// Number of selectable bitmap/vector resources carried by a FON container.
pub fn faceCount(data: []const u8) usize {
    if (isNeExecutable(data)) return neFontCount(data);
    return if (looksLikeFnt(data)) 1 else 0;
}

/// Inspects one resource without allocating or converting it.
pub fn inspect(data: []const u8, face_index: usize) !FaceInfo {
    const source = try selectedFnt(data, face_index);
    const info = try parseFntInfo(source.bytes);
    const family = readFntString(source.bytes, info.face_offset, "Windows FNT");
    return .{
        .family = family,
        .style = styleName(info),
        .face_index = face_index,
        .face_count = source.count,
        .pixel_width = info.pix_width,
        .pixel_height = info.pix_height,
        .max_width = info.max_width,
        .glyph_count = glyphCount(info),
        .vector = isVectorFnt(info),
    };
}

/// Converts one selected FNT resource into a newly allocated bitmap R4F file.
/// Windows-1.x vector paths are rasterized at their native source grid.
pub fn convert(allocator: std.mem.Allocator, data: []const u8, source_name: []const u8, face_index: usize) ![]u8 {
    const source = try selectedFnt(data, face_index);
    const info = try parseFntInfo(source.bytes);
    if (info.pix_height == 0) return error.NotRasterFnt;

    var owned_glyphs: std.ArrayList([]u8) = .empty;
    defer {
        for (owned_glyphs.items) |glyph| allocator.free(glyph);
        owned_glyphs.deinit(allocator);
    }
    var glyphs: std.ArrayList(RasterGlyph) = .empty;
    defer glyphs.deinit(allocator);

    try extractGlyphs(allocator, source.bytes, info, &owned_glyphs, &glyphs);

    const family = readFntString(source.bytes, info.face_offset, "Windows FNT");
    return writeRasterFont(allocator, glyphs.items, .{
        .family_name = family,
        .face_name = family,
        .style_name = styleName(info),
        .source_name = source_name,
        .pixel_height = info.pix_height,
        .ascent = @intCast(@min(info.ascent, info.pix_height)),
        .descent = @intCast(info.pix_height -| info.ascent),
        .line_height = @intCast(info.pix_height + info.external_leading),
        .weight = if (info.weight == 0) 400 else info.weight,
        .style_flags = fntStyleFlags(info),
        .charset = fntCharset(info.charset),
    });
}

/// Rasterizes ASCII sample text from an FNT resource without installing it.
/// `pixels` uses `pixel_width` as its row stride and is filled with white
/// background plus black glyph pixels.
pub fn rasterizePreview(
    allocator: std.mem.Allocator,
    data: []const u8,
    face_index: usize,
    sample: []const u8,
    pixels: []u32,
    pixel_width: u16,
    pixel_height: u16,
) !Preview {
    if (pixel_width == 0 or pixel_height == 0 or pixels.len < @as(usize, pixel_width) * pixel_height) return error.BadPreviewBuffer;
    const source = try selectedFnt(data, face_index);
    const info = try parseFntInfo(source.bytes);

    var owned_glyphs: std.ArrayList([]u8) = .empty;
    defer {
        for (owned_glyphs.items) |glyph| allocator.free(glyph);
        owned_glyphs.deinit(allocator);
    }
    var glyphs: std.ArrayList(RasterGlyph) = .empty;
    defer glyphs.deinit(allocator);
    try extractGlyphs(allocator, source.bytes, info, &owned_glyphs, &glyphs);

    const stride: usize = pixel_width;
    const raster_len = stride * pixel_height;
    @memset(pixels[0..raster_len], 0x00FFFFFF);
    var pen_x: usize = 0;
    for (sample) |ch| {
        const codepoint: u32 = ch;
        var selected: ?RasterGlyph = null;
        for (glyphs.items) |glyph| {
            if (glyph.codepoint == codepoint) {
                selected = glyph;
                break;
            }
        }
        const glyph = selected orelse continue;
        const bytes_per_row: usize = (@as(usize, glyph.width) + 7) / 8;
        const rows = @min(@as(usize, glyph.height), @as(usize, pixel_height));
        const columns = @min(@as(usize, glyph.width), @as(usize, pixel_width) -| pen_x);
        var row: usize = 0;
        while (row < rows) : (row += 1) {
            var column: usize = 0;
            while (column < columns) : (column += 1) {
                if ((glyph.data[row * bytes_per_row + column / 8] & (@as(u8, 0x80) >> @intCast(column & 7))) != 0) {
                    pixels[row * stride + pen_x + column] = 0x00000000;
                }
            }
        }
        const advance: usize = if (glyph.advance > 0) @intCast(glyph.advance) else glyph.width;
        pen_x = @min(@as(usize, pixel_width), pen_x + advance + 1);
        if (pen_x >= pixel_width) break;
    }
    return .{ .width = pixel_width, .height = @min(info.pix_height, pixel_height) };
}

const FntSource = struct {
    bytes: []const u8,
    count: usize,
};

fn selectedFnt(data: []const u8, face_index: usize) !FntSource {
    if (isNeExecutable(data)) {
        const count = neFontCount(data);
        if (face_index >= count) return error.FontResourceNotFound;
        return .{ .bytes = try extractNeFont(data, face_index), .count = count };
    }
    if (!looksLikeFnt(data) or face_index != 0) return error.UnsupportedFontFormat;
    return .{ .bytes = data, .count = 1 };
}

fn parseFntInfo(data: []const u8) !FntInfo {
    if (data.len < FNT_HEADER_SIZE) return error.ShortFntHeader;
    const version = le16(data, 0);
    if (version != 0x0100 and version != 0x0200 and version != 0x0300) return error.UnsupportedFntVersion;
    const size = le32(data, 2);
    if (size != 0 and size > data.len) return error.TruncatedFnt;
    const first = data[95];
    const last = data[96];
    if (last < first) return error.BadFntCharRange;
    return .{
        .version = version,
        .size = size,
        .df_type = le16(data, 66),
        .ascent = le16(data, 74),
        .external_leading = le16(data, 78),
        .italic = data[80] != 0,
        .underline = data[81] != 0,
        .strikeout = data[82] != 0,
        .weight = le16(data, 83),
        .charset = data[85],
        .pix_width = le16(data, 86),
        .pix_height = le16(data, 88),
        .avg_width = le16(data, 91),
        .max_width = le16(data, 93),
        .first_char = first,
        .last_char = last,
        .width_bytes = le16(data, 99),
        .face_offset = le32(data, 105),
        .bits_offset = le32(data, 113),
    };
}

fn extractGlyphs(
    allocator: std.mem.Allocator,
    data: []const u8,
    info: FntInfo,
    owned_glyphs: *std.ArrayList([]u8),
    glyphs: *std.ArrayList(RasterGlyph),
) !void {
    if (isVectorFnt(info)) {
        if (info.version != 0x0100) return error.UnsupportedVectorFntVersion;
        return extractV1VectorGlyphs(allocator, data, info, owned_glyphs, glyphs);
    }
    if (info.version == 0x0100) {
        return extractV1Glyphs(allocator, data, info, owned_glyphs, glyphs);
    }
    return extractV2Glyphs(allocator, data, info, owned_glyphs, glyphs);
}

fn extractV1Glyphs(
    allocator: std.mem.Allocator,
    data: []const u8,
    info: FntInfo,
    owned_glyphs: *std.ArrayList([]u8),
    glyphs: *std.ArrayList(RasterGlyph),
) !void {
    if (info.bits_offset == 0 or info.width_bytes == 0) return error.NotRasterFnt;
    const count = glyphCount(info);
    const offset_table_bytes = if (info.pix_width == 0) (@as(usize, count) + 1) * 2 else 0;
    if (FNT_V1_CHAR_TABLE_OFFSET + offset_table_bytes > data.len or info.bits_offset > data.len) return error.ShortFntCharTable;
    const bitmap_end = @as(usize, info.bits_offset) + @as(usize, info.width_bytes) * info.pix_height;
    if (bitmap_end > data.len) return error.TruncatedFntBitmap;

    var index: usize = 0;
    while (index < count) : (index += 1) {
        var width: u16 = info.pix_width;
        var bit_offset: usize = @as(usize, info.pix_width) * index;
        if (width == 0) {
            const start = le16(data, FNT_V1_CHAR_TABLE_OFFSET + index * 2);
            const end = le16(data, FNT_V1_CHAR_TABLE_OFFSET + (index + 1) * 2);
            if (end < start) return error.BadFntGlyphOffset;
            bit_offset = start;
            width = end - start;
        }
        if (width == 0) width = if (info.avg_width != 0) info.avg_width else info.max_width;
        if (width == 0) return error.BadFntGlyphWidth;
        const bytes_per_row: usize = (@as(usize, width) + 7) / 8;
        const glyph = try allocator.alloc(u8, bytes_per_row * info.pix_height);
        @memset(glyph, 0);
        errdefer allocator.free(glyph);

        var row: usize = 0;
        while (row < info.pix_height) : (row += 1) {
            var column: usize = 0;
            while (column < width) : (column += 1) {
                const source_bit = bit_offset + column;
                if (source_bit >= @as(usize, info.width_bytes) * 8) return error.BadFntBitmapWidth;
                const source_byte = @as(usize, info.bits_offset) + row * info.width_bytes + source_bit / 8;
                if ((data[source_byte] & (@as(u8, 0x80) >> @intCast(source_bit & 7))) != 0) {
                    glyph[row * bytes_per_row + column / 8] |= @as(u8, 0x80) >> @intCast(column & 7);
                }
            }
        }
        try owned_glyphs.append(allocator, glyph);
        try glyphs.append(allocator, .{
            .codepoint = @as(u32, info.first_char) + @as(u32, @intCast(index)),
            .width = width,
            .height = info.pix_height,
            .advance = @intCast(width),
            .data = glyph,
        });
    }
}

fn extractV1VectorGlyphs(
    allocator: std.mem.Allocator,
    data: []const u8,
    info: FntInfo,
    owned_glyphs: *std.ArrayList([]u8),
    glyphs: *std.ArrayList(RasterGlyph),
) !void {
    if (info.bits_offset == 0 or info.pix_height == 0) return error.NotRasterFnt;
    const count = glyphCount(info);
    const table_bytes = (@as(usize, count) + 1) * 4;
    if (FNT_V1_CHAR_TABLE_OFFSET + table_bytes > data.len or info.bits_offset > data.len) return error.ShortFntCharTable;

    var index: usize = 0;
    while (index < count) : (index += 1) {
        const entry = FNT_V1_CHAR_TABLE_OFFSET + index * 4;
        const next_entry = entry + 4;
        const stroke_offset = le16(data, entry);
        const next_stroke_offset = le16(data, next_entry);
        if (next_stroke_offset < stroke_offset) return error.BadFntGlyphOffset;
        const start = @as(usize, info.bits_offset) + stroke_offset;
        const end = @as(usize, info.bits_offset) + next_stroke_offset;
        if (end > data.len or start > end) return error.BadFntGlyphOffset;

        var width = le16(data, entry + 2);
        if (width == 0) width = if (info.avg_width != 0) info.avg_width else info.max_width;
        if (width == 0) width = 1;
        const bytes_per_row: usize = (@as(usize, width) + 7) / 8;
        const glyph = try allocator.alloc(u8, bytes_per_row * info.pix_height);
        @memset(glyph, 0);
        errdefer allocator.free(glyph);
        try rasterizeVectorPath(glyph, width, info.pix_height, data[start..end]);
        try owned_glyphs.append(allocator, glyph);
        try glyphs.append(allocator, .{
            .codepoint = @as(u32, info.first_char) + @as(u32, @intCast(index)),
            .width = width,
            .height = info.pix_height,
            .advance = @intCast(width),
            .data = glyph,
        });
    }
}

fn rasterizeVectorPath(glyph: []u8, width: u16, height: u16, source: []const u8) !void {
    const bytes_per_row: usize = (@as(usize, width) + 7) / 8;
    var pen_x: i32 = 0;
    var pen_y: i32 = 0;
    var cursor: usize = 0;
    while (cursor < source.len) {
        var pen_up = false;
        if (source[cursor] == 0x80) {
            pen_up = true;
            cursor += 1;
        }
        if (cursor + 2 > source.len) return error.BadVectorPath;
        const dx: i32 = @as(i8, @bitCast(source[cursor]));
        const dy: i32 = @as(i8, @bitCast(source[cursor + 1]));
        cursor += 2;
        const next_x = pen_x + dx;
        const next_y = pen_y + dy;
        if (!pen_up) drawVectorLine(glyph, bytes_per_row, width, height, pen_x, pen_y, next_x, next_y);
        pen_x = next_x;
        pen_y = next_y;
    }
}

fn drawVectorLine(glyph: []u8, bytes_per_row: usize, width: u16, height: u16, x0_input: i32, y0_input: i32, x1: i32, y1: i32) void {
    var x0 = x0_input;
    var y0 = y0_input;
    const dx: i32 = if (x1 >= x0) x1 - x0 else x0 - x1;
    const sx: i32 = if (x0 < x1) 1 else -1;
    const dy_abs: i32 = if (y1 >= y0) y1 - y0 else y0 - y1;
    const sy: i32 = if (y0 < y1) 1 else -1;
    var err: i32 = dx - dy_abs;
    while (true) {
        if (x0 >= 0 and y0 >= 0 and x0 < width and y0 < height) {
            const row: usize = @intCast(y0);
            const column: usize = @intCast(x0);
            glyph[row * bytes_per_row + column / 8] |= @as(u8, 0x80) >> @intCast(column & 7);
        }
        if (x0 == x1 and y0 == y1) break;
        const twice_error = err * 2;
        if (twice_error > -dy_abs) {
            err -= dy_abs;
            x0 += sx;
        }
        if (twice_error < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

fn extractV2Glyphs(
    allocator: std.mem.Allocator,
    data: []const u8,
    info: FntInfo,
    owned_glyphs: *std.ArrayList([]u8),
    glyphs: *std.ArrayList(RasterGlyph),
) !void {
    if (info.bits_offset == 0 or info.width_bytes == 0 or info.pix_height == 0) return error.NotRasterFnt;
    const header_size: usize = if (info.version >= 0x0300) 148 else FNT_HEADER_SIZE;
    const entry_size: usize = if (info.version >= 0x0300) 6 else 4;
    const count = glyphCount(info);
    if (data.len < header_size + (@as(usize, count) + 1) * entry_size or info.bits_offset >= data.len) return error.ShortFntCharTable;

    var index: usize = 0;
    while (index < count) : (index += 1) {
        const entry = header_size + index * entry_size;
        var width = le16(data, entry);
        if (width == 0) width = if (info.pix_width != 0) info.pix_width else info.avg_width;
        if (width == 0) return error.BadFntGlyphWidth;
        const bytes_per_row: usize = (@as(usize, width) + 7) / 8;
        const raw_offset: u32 = if (entry_size == 6) le32(data, entry + 2) else le16(data, entry + 2);
        const glyph_base = v2GlyphBase(data, info, raw_offset, bytes_per_row) orelse return error.BadFntGlyphOffset;
        var glyph = try allocator.alloc(u8, bytes_per_row * info.pix_height);
        errdefer allocator.free(glyph);
        var row: usize = 0;
        while (row < info.pix_height) : (row += 1) {
            const source = glyph_base + row * info.width_bytes;
            if (source + bytes_per_row > data.len) return error.TruncatedFntBitmap;
            @memcpy(glyph[row * bytes_per_row .. row * bytes_per_row + bytes_per_row], data[source .. source + bytes_per_row]);
        }
        try owned_glyphs.append(allocator, glyph);
        try glyphs.append(allocator, .{
            .codepoint = @as(u32, info.first_char) + @as(u32, @intCast(index)),
            .width = width,
            .height = info.pix_height,
            .advance = @intCast(width),
            .data = glyph,
        });
    }
}

fn v2GlyphBase(data: []const u8, info: FntInfo, raw_offset: u32, bytes_per_row: usize) ?usize {
    const absolute: usize = raw_offset;
    const relative = @as(usize, info.bits_offset) + raw_offset;
    if (raw_offset >= info.bits_offset and absolute + bytes_per_row <= data.len) return absolute;
    if (relative + bytes_per_row <= data.len) return relative;
    return null;
}

fn glyphCount(info: FntInfo) u16 {
    return @as(u16, info.last_char) - @as(u16, info.first_char) + 1;
}

fn isVectorFnt(info: FntInfo) bool {
    return (info.df_type & 1) != 0 or info.pix_height == 0 or info.bits_offset == 0 or (info.version != 0x0100 and info.width_bytes == 0);
}

fn styleName(info: FntInfo) []const u8 {
    return if (info.italic) "Italic" else if (info.weight >= 700) "Bold" else "Regular";
}

fn fntStyleFlags(info: FntInfo) u32 {
    var flags: u32 = 0;
    if (info.pix_width != 0) flags |= r4f.STYLE_MONOSPACE;
    if (info.italic) flags |= r4f.STYLE_ITALIC;
    if (info.weight >= 700) flags |= r4f.STYLE_BOLD;
    if (info.underline) flags |= r4f.STYLE_UNDERLINE;
    if (info.strikeout) flags |= r4f.STYLE_STRIKEOUT;
    return flags;
}

fn fntCharset(charset: u8) u16 {
    return if (charset == 0xFF) r4f.CHARSET_CP437 else r4f.CHARSET_WINDOWS_1252;
}

fn readFntString(data: []const u8, offset: u32, fallback: []const u8) []const u8 {
    if (offset >= data.len) return fallback;
    var begin: usize = offset;
    // The stock Windows 3.x vector FONs leave one alignment NUL before the
    // face name although dfFace points at that byte.
    if (data[begin] == 0 and begin + 1 < data.len and data[begin + 1] >= 0x20) begin += 1;
    var end = begin;
    while (end < data.len and data[end] != 0 and data[end] >= 0x20) : (end += 1) {}
    return if (end > begin) data[begin..end] else fallback;
}

fn isNeExecutable(data: []const u8) bool {
    if (data.len < 0x40 or !std.mem.eql(u8, data[0..2], "MZ")) return false;
    const offset = le32(data, 0x3C);
    return offset + 2 <= data.len and std.mem.eql(u8, data[offset .. offset + 2], "NE");
}

fn looksLikeFnt(data: []const u8) bool {
    if (data.len < FNT_HEADER_SIZE) return false;
    const version = le16(data, 0);
    return version == 0x0100 or version == 0x0200 or version == 0x0300;
}

fn neFontCount(data: []const u8) usize {
    if (!isNeExecutable(data)) return 0;
    const ne_offset = le32(data, 0x3C);
    if (ne_offset + 0x26 >= data.len) return 0;
    const resource_offset = ne_offset + le16(data, ne_offset + 0x24);
    if (resource_offset + 2 > data.len) return 0;
    var cursor: usize = resource_offset + 2;
    var count: usize = 0;
    while (cursor + 8 <= data.len) {
        const type_id = le16(data, cursor);
        if (type_id == 0) break;
        const resource_count = le16(data, cursor + 2);
        cursor += 8;
        if (cursor + @as(usize, resource_count) * 12 > data.len) return count;
        if ((type_id & 0x7FFF) == RT_FONT) count += resource_count;
        cursor += @as(usize, resource_count) * 12;
    }
    return count;
}

fn extractNeFont(data: []const u8, wanted_index: usize) ![]const u8 {
    if (!isNeExecutable(data)) return error.NotNeExecutable;
    const ne_offset = le32(data, 0x3C);
    if (ne_offset + 0x26 >= data.len) return error.ShortNeHeader;
    const resource_offset = ne_offset + le16(data, ne_offset + 0x24);
    if (resource_offset + 2 > data.len) return error.NoResourceTable;
    const align_shift = le16(data, resource_offset);
    var cursor: usize = resource_offset + 2;
    var seen: usize = 0;
    while (cursor + 8 <= data.len) {
        const type_id = le16(data, cursor);
        if (type_id == 0) break;
        const count = le16(data, cursor + 2);
        cursor += 8;
        if (cursor + @as(usize, count) * 12 > data.len) return error.ShortResourceRecords;
        var index: usize = 0;
        while (index < count) : (index += 1) {
            if ((type_id & 0x7FFF) != RT_FONT) continue;
            const record = cursor + index * 12;
            const offset: usize = @as(usize, le16(data, record)) << @intCast(align_shift);
            const length: usize = @as(usize, le16(data, record + 2)) << @intCast(align_shift);
            if (seen == wanted_index) {
                if (length == 0 or offset >= data.len or offset + length > data.len) return error.BadFontResource;
                return data[offset .. offset + length];
            }
            seen += 1;
        }
        cursor += @as(usize, count) * 12;
    }
    return error.FontResourceNotFound;
}

fn writeRasterFont(allocator: std.mem.Allocator, glyphs: []const RasterGlyph, opts: RasterOptions) ![]u8 {
    if (glyphs.len == 0 or glyphs.len > std.math.maxInt(u16) or opts.pixel_height == 0) return error.BadGlyphCount;
    var max_width: u16 = 0;
    var max_bytes_per_row: u16 = 0;
    for (glyphs) |glyph| {
        if (glyph.height != opts.pixel_height or glyph.width == 0) return error.UnsupportedBitmapSize;
        const bytes_per_row: u16 = @intCast((@as(usize, glyph.width) + 7) / 8);
        if (glyph.data.len < @as(usize, bytes_per_row) * opts.pixel_height) return error.ShortGlyphData;
        max_width = @max(max_width, glyph.width);
        max_bytes_per_row = @max(max_bytes_per_row, bytes_per_row);
    }

    var names: std.ArrayList(u8) = .empty;
    defer names.deinit(allocator);
    try names.append(allocator, 0);
    const family_offset = try addName(&names, allocator, opts.family_name);
    const face_offset = try addName(&names, allocator, opts.face_name);
    const style_offset = try addName(&names, allocator, opts.style_name);
    const source_offset = try addName(&names, allocator, opts.source_name);

    var face: std.ArrayList(u8) = .empty;
    defer face.deinit(allocator);
    try writeFaceRecord(&face, allocator, .{
        .kind = r4f.FONT_KIND_BITMAP,
        .style_flags = opts.style_flags,
        .weight = opts.weight,
        .charset_flags = charsetFlags(opts.charset) | r4f.CHARSET_FLAG_UNICODE,
        .units_per_em = opts.pixel_height,
        .ascent = opts.ascent,
        .descent = opts.descent,
        .line_height = opts.line_height,
        .family_off = family_offset,
        .face_off = face_offset,
        .style_off = style_offset,
        .source_off = source_offset,
    });

    var strike: std.ArrayList(u8) = .empty;
    defer strike.deinit(allocator);
    try appendU16(&strike, allocator, 0);
    try appendU16(&strike, allocator, 0);
    try appendU16(&strike, allocator, opts.pixel_height);
    try appendU16(&strike, allocator, opts.pixel_height);
    try appendU16(&strike, allocator, max_width);
    try appendU16(&strike, allocator, opts.pixel_height);
    try appendI16(&strike, allocator, opts.ascent);
    try appendI16(&strike, allocator, opts.descent);
    try appendI16(&strike, allocator, opts.line_height);
    try appendI16(&strike, allocator, opts.ascent);
    try appendU16(&strike, allocator, r4f.BITMAP_FORMAT_MONO1_MSB);
    try appendU16(&strike, allocator, max_bytes_per_row);
    try appendU32(&strike, allocator, @intCast(glyphs.len));
    try appendU32(&strike, allocator, 0);
    try appendU32(&strike, allocator, 0);
    try appendU32(&strike, allocator, 0);

    var glyph_map: std.ArrayList(u8) = .empty;
    defer glyph_map.deinit(allocator);
    try appendU32(&glyph_map, allocator, @intCast(glyphs.len));
    for (glyphs, 0..) |glyph, glyph_id| {
        try appendU16(&glyph_map, allocator, 0);
        try appendU16(&glyph_map, allocator, opts.charset);
        try appendU32(&glyph_map, allocator, glyph.codepoint);
        try appendU32(&glyph_map, allocator, @intCast(glyph_id));
        try appendU32(&glyph_map, allocator, 0);
    }

    var metrics: std.ArrayList(u8) = .empty;
    defer metrics.deinit(allocator);
    try appendU32(&metrics, allocator, @intCast(glyphs.len));
    for (glyphs, 0..) |glyph, glyph_id| {
        try appendU32(&metrics, allocator, @intCast(glyph_id));
        try appendI16(&metrics, allocator, glyph.advance);
        try appendI16(&metrics, allocator, 0);
        try appendI16(&metrics, allocator, 0);
        try appendI16(&metrics, allocator, opts.ascent);
        try appendI16(&metrics, allocator, 0);
        try appendI16(&metrics, allocator, 0);
        try appendI16(&metrics, allocator, @intCast(glyph.width));
        try appendI16(&metrics, allocator, @intCast(glyph.height));
        try appendU16(&metrics, allocator, 0);
        try appendU16(&metrics, allocator, 0);
    }

    var bitmap: std.ArrayList(u8) = .empty;
    defer bitmap.deinit(allocator);
    const records_size: usize = 8 + glyphs.len * r4f.BITMAP_GLYPH_RECORD_SIZE;
    try appendU32(&bitmap, allocator, @intCast(glyphs.len));
    try appendU32(&bitmap, allocator, @intCast(records_size));
    var payload_offset: u32 = @intCast(records_size);
    for (glyphs, 0..) |glyph, glyph_id| {
        const size: u32 = @intCast(@as(usize, max_bytes_per_row) * glyph.height);
        try appendU32(&bitmap, allocator, @intCast(glyph_id));
        try appendU16(&bitmap, allocator, 0);
        try appendU16(&bitmap, allocator, r4f.BITMAP_FORMAT_MONO1_MSB);
        try appendU32(&bitmap, allocator, payload_offset);
        try appendU32(&bitmap, allocator, size);
        payload_offset += size;
    }
    for (glyphs) |glyph| {
        const glyph_bytes_per_row: usize = (@as(usize, glyph.width) + 7) / 8;
        var row: usize = 0;
        while (row < glyph.height) : (row += 1) {
            const source = row * glyph_bytes_per_row;
            try bitmap.appendSlice(allocator, glyph.data[source .. source + glyph_bytes_per_row]);
            var padding = glyph_bytes_per_row;
            while (padding < max_bytes_per_row) : (padding += 1) try bitmap.append(allocator, 0);
        }
    }

    const tables = [_]Table{
        .{ .tag = r4f.TABLE_NAME, .size = @intCast(names.items.len) },
        .{ .tag = r4f.TABLE_FACE, .size = @intCast(face.items.len) },
        .{ .tag = r4f.TABLE_STRIKE, .size = @intCast(strike.items.len) },
        .{ .tag = r4f.TABLE_GLYPH_MAP, .size = @intCast(glyph_map.items.len) },
        .{ .tag = r4f.TABLE_GLYPH_METRICS, .size = @intCast(metrics.items.len) },
        .{ .tag = r4f.TABLE_BITMAP_DATA, .size = @intCast(bitmap.items.len) },
    };
    const payloads = [_][]const u8{ names.items, face.items, strike.items, glyph_map.items, metrics.items, bitmap.items };
    return writeContainer(allocator, r4f.FLAG_HAS_BITMAP, @intCast(glyphs.len), tables[0..], payloads[0..]);
}

const FaceRecordOptions = struct {
    kind: u16,
    style_flags: u32,
    weight: u16,
    charset_flags: u32,
    units_per_em: u16,
    ascent: i16,
    descent: i16,
    line_height: i16,
    family_off: u32,
    face_off: u32,
    style_off: u32,
    source_off: u32,
};

fn writeFaceRecord(out: *std.ArrayList(u8), allocator: std.mem.Allocator, opts: FaceRecordOptions) !void {
    try appendU16(out, allocator, 0);
    try appendU16(out, allocator, opts.kind);
    try appendU32(out, allocator, opts.style_flags);
    try appendU16(out, allocator, opts.weight);
    try appendU16(out, allocator, 5);
    try appendU32(out, allocator, opts.charset_flags);
    try appendU16(out, allocator, opts.units_per_em);
    try appendI16(out, allocator, opts.ascent);
    try appendI16(out, allocator, opts.descent);
    try appendI16(out, allocator, 0);
    try appendI16(out, allocator, 0);
    try appendI16(out, allocator, 0);
    try appendI16(out, allocator, opts.line_height);
    try appendU32(out, allocator, opts.family_off);
    try appendU32(out, allocator, opts.face_off);
    try appendU32(out, allocator, opts.style_off);
    try appendU32(out, allocator, opts.source_off);
    try appendU16(out, allocator, 0);
    try appendU16(out, allocator, 0);
    try appendU32(out, allocator, 0);
    try appendU32(out, allocator, 0);
    try appendU32(out, allocator, 0);
    try appendU16(out, allocator, 0);
}

fn writeContainer(allocator: std.mem.Allocator, flags: u32, glyph_count: u32, defs: []const Table, payloads: []const []const u8) ![]u8 {
    if (defs.len != payloads.len) return error.BadTableList;
    var tables = try allocator.alloc(Table, defs.len);
    defer allocator.free(tables);
    var cursor: usize = align4(r4f.HEADER_SIZE + defs.len * r4f.TABLE_ENTRY_SIZE);
    for (defs, 0..) |definition, index| {
        cursor = align4(cursor);
        tables[index] = definition;
        tables[index].offset = @intCast(cursor);
        cursor += payloads[index].len;
    }
    const file_size = align4(cursor);
    var out: std.ArrayList(u8) = .empty;
    errdefer out.deinit(allocator);
    try out.ensureTotalCapacity(allocator, file_size);
    try out.appendSlice(allocator, &r4f.MAGIC);
    try appendU16(&out, allocator, r4f.VERSION);
    try appendU16(&out, allocator, r4f.HEADER_SIZE);
    try appendU32(&out, allocator, flags);
    try appendU32(&out, allocator, @intCast(file_size));
    try appendU32(&out, allocator, r4f.HEADER_SIZE);
    try appendU16(&out, allocator, @intCast(tables.len));
    try appendU16(&out, allocator, 1);
    try appendU16(&out, allocator, 1);
    try appendU16(&out, allocator, 0);
    try appendU32(&out, allocator, glyph_count);
    for (tables) |table| {
        try appendU32(&out, allocator, table.tag);
        try appendU32(&out, allocator, table.offset);
        try appendU32(&out, allocator, table.size);
        try appendU32(&out, allocator, table.flags);
    }
    try padTo(&out, allocator, align4(out.items.len));
    for (payloads, 0..) |payload, index| {
        try padTo(&out, allocator, tables[index].offset);
        try out.appendSlice(allocator, payload);
    }
    try padTo(&out, allocator, file_size);
    return out.toOwnedSlice(allocator);
}

fn addName(out: *std.ArrayList(u8), allocator: std.mem.Allocator, value: []const u8) !u32 {
    const offset: u32 = @intCast(out.items.len);
    try out.appendSlice(allocator, value);
    try out.append(allocator, 0);
    return offset;
}

fn charsetFlags(charset: u16) u32 {
    return if (charset == r4f.CHARSET_CP437) r4f.CHARSET_FLAG_CP437 else r4f.CHARSET_FLAG_WINDOWS_1252;
}

fn appendU16(out: *std.ArrayList(u8), allocator: std.mem.Allocator, value: u16) !void {
    var bytes: [2]u8 = undefined;
    std.mem.writeInt(u16, bytes[0..], value, .little);
    try out.appendSlice(allocator, &bytes);
}

fn appendI16(out: *std.ArrayList(u8), allocator: std.mem.Allocator, value: i16) !void {
    try appendU16(out, allocator, @bitCast(value));
}

fn appendU32(out: *std.ArrayList(u8), allocator: std.mem.Allocator, value: u32) !void {
    var bytes: [4]u8 = undefined;
    std.mem.writeInt(u32, bytes[0..], value, .little);
    try out.appendSlice(allocator, &bytes);
}

fn padTo(out: *std.ArrayList(u8), allocator: std.mem.Allocator, target: usize) !void {
    while (out.items.len < target) try out.append(allocator, 0);
}

fn align4(value: usize) usize {
    return (value + 3) & ~@as(usize, 3);
}

fn le16(data: []const u8, offset: usize) u16 {
    return @as(u16, data[offset]) | (@as(u16, data[offset + 1]) << 8);
}

fn le32(data: []const u8, offset: usize) u32 {
    return @as(u32, data[offset]) |
        (@as(u32, data[offset + 1]) << 8) |
        (@as(u32, data[offset + 2]) << 16) |
        (@as(u32, data[offset + 3]) << 24);
}

test "version 1 bitmap FNT converts to R4F" {
    const allocator = std.testing.allocator;
    var fnt: [138]u8 = .{0} ** 138;
    fnt[0] = 0;
    fnt[1] = 1;
    fnt[2] = 138;
    fnt[68] = 8;
    fnt[74] = 7;
    fnt[83] = 144;
    fnt[84] = 1;
    fnt[86] = 8;
    fnt[88] = 8;
    fnt[91] = 8;
    fnt[93] = 8;
    fnt[95] = 'A';
    fnt[96] = 'A';
    fnt[99] = 1;
    fnt[105] = 130;
    fnt[113] = 118;
    fnt[118] = 0x18;
    fnt[119] = 0x24;
    fnt[120] = 0x42;
    fnt[121] = 0x7E;
    fnt[122] = 0x42;
    fnt[123] = 0x42;
    fnt[130] = 'T';
    fnt[131] = 0;
    const r4f_bytes = try convert(allocator, fnt[0..], "TEST.FNT", 0);
    defer allocator.free(r4f_bytes);
    try std.testing.expectEqualSlices(u8, &r4f.MAGIC, r4f_bytes[0..4]);
    try std.testing.expectEqual(@as(usize, 1), faceCount(fnt[0..]));
}

test "version 1 bitmap FNT previews before installation" {
    const allocator = std.testing.allocator;
    var fnt: [138]u8 = .{0} ** 138;
    fnt[0] = 0;
    fnt[1] = 1;
    fnt[2] = 138;
    fnt[68] = 8;
    fnt[74] = 7;
    fnt[86] = 8;
    fnt[88] = 8;
    fnt[91] = 8;
    fnt[93] = 8;
    fnt[95] = 'A';
    fnt[96] = 'A';
    fnt[99] = 1;
    fnt[105] = 130;
    fnt[113] = 118;
    fnt[118] = 0x18;
    fnt[119] = 0x24;
    fnt[120] = 0x42;
    fnt[121] = 0x7E;
    fnt[122] = 0x42;
    fnt[123] = 0x42;
    fnt[130] = 'T';
    fnt[131] = 0;
    var pixels: [8 * 8]u32 = undefined;
    const preview = try rasterizePreview(allocator, fnt[0..], 0, "A", pixels[0..], 8, 8);
    try std.testing.expectEqual(@as(u16, 8), preview.height);
    try std.testing.expectEqual(@as(u32, 0x00000000), pixels[3]);
}

test "version 1 variable bitmap FNT uses the legacy offset table" {
    const allocator = std.testing.allocator;
    var fnt: [140]u8 = .{0} ** 140;
    fnt[0] = 0;
    fnt[1] = 1;
    fnt[2] = 140;
    fnt[74] = 7;
    fnt[88] = 8;
    fnt[91] = 8;
    fnt[93] = 8;
    fnt[95] = 'A';
    fnt[96] = 'A';
    fnt[99] = 1;
    fnt[113] = 128;
    fnt[FNT_V1_CHAR_TABLE_OFFSET] = 0;
    fnt[FNT_V1_CHAR_TABLE_OFFSET + 2] = 8;
    fnt[128] = 0x18;
    fnt[129] = 0x24;
    fnt[130] = 0x42;
    fnt[131] = 0x7E;
    fnt[132] = 0x42;
    fnt[133] = 0x42;
    const r4f_bytes = try convert(allocator, fnt[0..], "VARIABLE.FNT", 0);
    defer allocator.free(r4f_bytes);
    try std.testing.expectEqualSlices(u8, &r4f.MAGIC, r4f_bytes[0..4]);
}

test "version 1 vector FNT rasterizes to R4F" {
    const allocator = std.testing.allocator;
    var fnt: [140]u8 = .{0} ** 140;
    fnt[0] = 0;
    fnt[1] = 1;
    fnt[66] = 1;
    fnt[74] = 7;
    fnt[88] = 8;
    fnt[91] = 8;
    fnt[93] = 8;
    fnt[95] = 'A';
    fnt[96] = 'A';
    fnt[113] = 130;
    fnt[FNT_V1_CHAR_TABLE_OFFSET + 2] = 8;
    fnt[FNT_V1_CHAR_TABLE_OFFSET + 4] = 5;
    fnt[130] = 0x80;
    fnt[131] = 1;
    fnt[132] = 1;
    fnt[133] = 0;
    fnt[134] = 6;
    const info = try inspect(fnt[0..], 0);
    try std.testing.expect(info.vector);
    const r4f_bytes = try convert(allocator, fnt[0..], "VECTOR.FNT", 0);
    defer allocator.free(r4f_bytes);
    try std.testing.expectEqualSlices(u8, &r4f.MAGIC, r4f_bytes[0..4]);
}

test "bundled legacy FON sources convert to bounded R4F strikes" {
    const allocator = std.testing.allocator;
    const sources = [_]struct { path: []const u8, name: []const u8 }{
        .{ .path = "Injection/Temp/Fonts/COURA.FON", .name = "COURA.FON" },
        .{ .path = "Injection/Temp/Fonts/HELVA.FON", .name = "HELVA.FON" },
        .{ .path = "Injection/Temp/Fonts/TMSRA.FON", .name = "TMSRA.FON" },
        .{ .path = "Injection/Temp/Fonts/MODERN.FON", .name = "MODERN.FON" },
        .{ .path = "Injection/Temp/Fonts/ROMAN.FON", .name = "ROMAN.FON" },
        .{ .path = "Injection/Temp/Fonts/SCRIPT.FON", .name = "SCRIPT.FON" },
    };
    for (sources) |source| {
        const input = try std.Io.Dir.cwd().readFileAlloc(std.testing.io, source.path, allocator, .limited(64 * 1024));
        defer allocator.free(input);
        const count = faceCount(input);
        try std.testing.expect(count > 0);
        var face_index: usize = 0;
        while (face_index < count) : (face_index += 1) {
            const converted = try convert(allocator, input, source.name, face_index);
            defer allocator.free(converted);
            const strike = r4fStrike(converted) orelse return error.BadR4fStrike;
            try std.testing.expect(strike.width <= 40);
            try std.testing.expect(strike.height <= 40);
            try std.testing.expect(converted.len <= 64 * 1024);
            try std.testing.expect(r4fRuntimeBitmapPayloads(converted, strike));
        }
    }
}

const R4fStrike = struct { width: u16, height: u16, bytes_per_row: u16 };

fn r4fStrike(bytes: []const u8) ?R4fStrike {
    if (bytes.len < r4f.HEADER_SIZE or !std.mem.eql(u8, bytes[0..4], &r4f.MAGIC)) return null;
    const table_offset: usize = le32(bytes, 16);
    const table_count: usize = le16(bytes, 20);
    if (table_offset + table_count * r4f.TABLE_ENTRY_SIZE > bytes.len) return null;
    var index: usize = 0;
    while (index < table_count) : (index += 1) {
        const entry = table_offset + index * r4f.TABLE_ENTRY_SIZE;
        if (le32(bytes, entry) != r4f.TABLE_STRIKE) continue;
        const offset: usize = le32(bytes, entry + 4);
        const size: usize = le32(bytes, entry + 8);
        if (size < r4f.STRIKE_RECORD_SIZE or offset + size > bytes.len) return null;
        return .{
            .width = le16(bytes, offset + 8),
            .height = le16(bytes, offset + 10),
            .bytes_per_row = le16(bytes, offset + 22),
        };
    }
    return null;
}

fn r4fRuntimeBitmapPayloads(bytes: []const u8, strike: R4fStrike) bool {
    const table_offset: usize = le32(bytes, 16);
    const table_count: usize = le16(bytes, 20);
    var index: usize = 0;
    while (index < table_count) : (index += 1) {
        const entry = table_offset + index * r4f.TABLE_ENTRY_SIZE;
        if (le32(bytes, entry) != r4f.TABLE_BITMAP_DATA) continue;
        const offset: usize = le32(bytes, entry + 4);
        const size: usize = le32(bytes, entry + 8);
        if (size < 8 or offset + size > bytes.len) return false;
        const table = bytes[offset .. offset + size];
        const count: usize = le32(table, 0);
        const payload_start: usize = le32(table, 4);
        if (payload_start < 8 + count * r4f.BITMAP_GLYPH_RECORD_SIZE or payload_start > table.len) return false;
        const glyph_size: usize = @as(usize, strike.bytes_per_row) * strike.height;
        var glyph_index: usize = 0;
        while (glyph_index < count) : (glyph_index += 1) {
            const record = 8 + glyph_index * r4f.BITMAP_GLYPH_RECORD_SIZE;
            const data_offset: usize = le32(table, record + 8);
            const data_size: usize = le32(table, record + 12);
            if (data_offset < payload_start or data_size != glyph_size or data_offset + data_size > table.len) return false;
        }
        return true;
    }
    return false;
}

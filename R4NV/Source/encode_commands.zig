// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
// NVIDIA clc7b7.h/clc9b7.h (MIT). Full notice: ../ThirdParty/Nvidia/LICENSES.txt.
const p = @import("encode_picture.zig");
pub const Error = p.Error || error{ Alias };
pub const word_count = 61;
pub const Span = struct { address: u64, bytes: u64 };
pub const Surface = struct { luma: Span, chroma: Span };
pub const Reference = struct { surface: Surface, coloc: Span };
pub const Buffers = struct {
    picture: Span,
    status: Span,
    history: Span,
    bitstream: Span,
    input: Surface,
    output: Surface,
    coloc: Span,
    reference: ?Reference,
};

/// The BO owner must first admit the actual input modifier, padded pixels and
/// complete tiled plane extents. This serializer checks method/address limits,
/// minimum pixel footprints and disjoint retained ranges; it cannot inspect a
/// BO descriptor or infer a layout from a GPU address. Input/output planes may
/// be slices of one backing allocation when their retained spans are disjoint.
pub fn encode(class: u32, picture: p.Picture, b: Buffers, index: u32) Error![word_count]u32 {
    if (class != 0xc7b7 and class != 0xc9b7) return error.Unsupported;
    const req = try p.requirements(picture);
    if (index == 0xffffffff or (picture.kind == .predicted) != (b.reference != null)) return error.Bounds;
    var spans: [12]Span = undefined;
    var count: usize = 0;
    const pic = try retain(&spans, &count, b.picture, p.picture_bytes);
    const status = try retain(&spans, &count, b.status, 144);
    const history = try retain(&spans, &count, b.history, req.history);
    const bitstream = try retain(&spans, &count, b.bitstream, picture.bitstream_bytes);
    const rows = ((picture.sequence.height + 15) / 16) * 16;
    const input_y = try retain(&spans, &count, b.input.luma, @as(u64, picture.input.luma_pitch) * rows);
    const input_uv = try retain(&spans, &count, b.input.chroma, @as(u64, picture.input.chroma_pitch) *
        @as(u32, if (picture.input.tiled_16x16) (rows / 2 + 15) & ~@as(u32, 15) else rows / 2));
    const recon_y_bytes = @as(u64, picture.reference.luma_pitch) * rows;
    const recon_uv_bytes = @as(u64, picture.reference.chroma_pitch) * ((rows / 2 + 15) & ~@as(u32, 15));
    const output_y = try retain(&spans, &count, b.output.luma, recon_y_bytes);
    const output_uv = try retain(&spans, &count, b.output.chroma, recon_uv_bytes);
    const coloc = try retain(&spans, &count, b.coloc, req.coloc);
    var ref_y: u32 = 0;
    var ref_uv: u32 = 0;
    var ref_coloc: u32 = 0;
    if (b.reference) |reference| {
        ref_y = try retain(&spans, &count, reference.surface.luma, recon_y_bytes);
        ref_uv = try retain(&spans, &count, reference.surface.chroma, recon_uv_bytes);
        ref_coloc = try retain(&spans, &count, reference.coloc, req.coloc);
    }
    var words: [word_count]u32 = @splat(0);
    words[0..2].* = .{ inc(0, 1), class };
    words[2..4].* = .{ inc(0x200, 1), 1 }; // Select the H.264 firmware app.
    words[4] = inc(0x400, 16); words[5] = ref_y;
    words[21] = inc(0x440, 16); words[22] = ref_uv;
    words[38] = inc(0x700, 20);
    // CQP H.264, reconstructed output/coloc and one slice-status record.
    // No encryption, external hints, QP maps, RC scratch, ME-only or subframes.
    words[39..59].* = .{ 0xb03, index, 0, 0, pic, 0, status, bitstream, history,
        0, ref_coloc, coloc, output_y, input_y, 0, 0, input_uv, 0, 0, output_uv };
    words[59..61].* = .{ inc(0x300, 1), 0 };
    // The native queue owner appends HOST WFI/SYS_MEMBAR/physical semaphore.
    // Keeping every inactive method zero also clears a preceding P picture.
    return words;
}
fn retain(spans: *[12]Span, count: *usize, span: Span, minimum: u64) Error!u32 {
    const limit = @as(u64, 1) << 40;
    if (span.address == 0 or span.address & 255 != 0 or span.address >= limit or
        span.bytes < minimum or span.bytes > limit - span.address) return error.Bounds;
    for (spans[0..count.*]) |previous| {
        if (span.address < previous.address + previous.bytes and previous.address < span.address + span.bytes)
            return error.Alias;
    }
    spans[count.*] = span; count.* += 1;
    return @intCast(span.address >> 8);
}
fn inc(method: u32, count: u32) u32 { return 0x20000000 | (count << 16) | (method >> 2); }

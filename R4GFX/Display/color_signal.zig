//! Joint receiver/source/pixel/link admission. This shared userland helper has no
//! hardware access. Protocol facts are pinned in the0.79.25 reference catalog:
//! CTA/libdisplay-info, NVIDIA570.144 nvtiming.h/dpsdp.h/nvkms-dpy.c.
const std = @import("std");
pub const Error = error{ Invalid, Incomplete, Unsupported, Bandwidth };
pub const Transfer = enum { srgb, pq, hlg };
pub const Primaries = enum { bt709, bt2020 };
pub const Range = enum { full, limited };
pub const Format = enum { xr24, xr30 };
pub const Metadata = struct {
    // RGB and white xy in units1/50000. Luminance fields use CTA units:
    // max/mastering/CLL/FALL1cd/m2, min mastering0.0001cd/m2.
    primaries: [6]u16 = @splat(0),
    white: [2]u16 = @splat(0),
    max_mastering: u16 = 0,
    min_mastering: u16 = 0,
    max_cll: u16 = 0,
    max_fall: u16 = 0,

    pub fn validate(self: Metadata) Error!void {
        const coordinates = self.primaries ++ self.white;
        var named = false;
        for (coordinates) |value| { if (value > 50000) return error.Invalid; named = named or value != 0; }
        if (named) {
            for (0..4) |i| {
                const x: u32 = coordinates[2 * i]; const y: u32 = coordinates[2 * i + 1];
                if (y == 0 or x + y > 50000) return error.Invalid;
            }
            const rx: i64 = coordinates[0]; const ry: i64 = coordinates[1];
            const gx: i64 = coordinates[2]; const gy: i64 = coordinates[3];
            const bx: i64 = coordinates[4]; const by: i64 = coordinates[5];
            if ((gx - rx) * (by - ry) - (gy - ry) * (bx - rx) == 0) return error.Invalid;
        }
        if ((self.max_mastering == 0 and self.min_mastering != 0) or
            (self.max_mastering != 0 and @as(u32, self.min_mastering) > @as(u32, self.max_mastering) * 10000) or
            (self.max_cll != 0 and self.max_fall > self.max_cll)) return error.Invalid;
    }
};
pub const Signal = struct {
    format: Format,
    transfer: Transfer,
    primaries: Primaries,
    range: Range,
    bpc: u8,
    // Same0.0001cd/m2 units as COLOR_V1. Values describe the encoded output.
    reference_white: u32,
    peak: u32,
    black: u32 = 0,
    metadata: ?Metadata = null,
};
/// Only implemented source stages are set. Receiver EDID never populates
/// these masks: bit0/1 formats XR24/XR30, bpc8/10, color709/2020,
/// range full/limited; EOTF uses CTA bits SDR=1,PQ=4,HLG=8.
pub const Source = struct {
    formats: u8 = 0,
    bpc: u8 = 0,
    primaries: u8 = 0,
    ranges: u8 = 0,
    eotf: u8 = 0,
    static_metadata: bool = false,
    dp_vsc: bool = false,
    /// Public platform state is a bounded copy of driver-confirmed facts.
    /// EDID must never be used to construct these source masks.
    pub fn fromPublished(state: anytype, transport: Transport) Error!Source {
        if (state.version != 1 or state.size < 128 or state.flags & 1 == 0) return error.Incomplete;
        if (state.formats & ~@as(u32, 3) != 0 or state.depths & ~@as(u32, 3) != 0 or
            state.color_spaces & ~@as(u32, 3) != 0 or state.ranges & ~@as(u32, 3) != 0 or state.transfers & ~@as(u32, 13) != 0) return error.Invalid;
        return .{ .formats = @intCast(state.formats), .bpc = @intCast(state.depths), .primaries = @intCast(state.color_spaces),
            .ranges = @intCast(state.ranges), .eotf = @intCast(state.transfers), .dp_vsc = state.flags & 32 != 0,
            .static_metadata = state.flags & @as(u32, switch (transport) { .hdmi => 8, .displayport => 16, .dvi => 0 }) != 0 };
    }
};
pub const Transport = enum { dvi, hdmi, displayport };
pub fn publishedSignal(state: anytype, metadata: ?Metadata) Error!Signal {
    if (state.version != 1 or state.size < 128 or state.flags & 3 != 3) return error.Incomplete;
    return decodeSignal(state, metadata);
}
/// Decodes the independent mode extension. Its pipeline bits are a caller
/// claim; source/receiver/link admission must still succeed before commit.
pub fn requestedSignal(value: anytype) Error!Signal {
    if (value.version != 1 or value.size != 80 or value.reserved0 != 0 or value.metadata_valid > 1) return error.Invalid;
    if (value.pipeline != 7) return error.Incomplete;
    const metadata: Metadata = .{ .primaries = value.metadata.primaries, .white = value.metadata.white,
        .max_mastering = value.metadata.max_mastering, .min_mastering = value.metadata.min_mastering,
        .max_cll = value.metadata.max_cll, .max_fall = value.metadata.max_fall };
    if (value.metadata_valid == 0 and !std.meta.eql(metadata, Metadata{})) return error.Invalid;
    try metadata.validate();
    const signal = try decodeSignal(value, if (value.metadata_valid != 0) metadata else null);
    if (signal.reference_white == 0 or signal.peak < signal.reference_white or signal.peak > 100_000_000 or signal.black >= signal.reference_white or
        (signal.format == .xr24) != (signal.bpc == 8) or (signal.transfer == .srgb) != (signal.metadata == null)) return error.Invalid;
    if (signal.transfer != .srgb and (signal.format != .xr30 or signal.primaries != .bt2020)) return error.Incomplete;
    return signal;
}
pub fn signalRequest(comptime T: type, signal: Signal) Error!T {
    var value: T = .{ .format = if (signal.format == .xr24) 0x34325258 else 0x30335258,
        .bpc = signal.bpc, .primaries = if (signal.primaries == .bt709) 1 else 3,
        .transfer = switch (signal.transfer) { .srgb => 1, .pq => 3, .hlg => 4 },
        .range = if (signal.range == .full) 1 else 2, .pipeline = 7,
        .reference_white = signal.reference_white, .peak = signal.peak, .black = signal.black,
        .metadata_valid = @intFromBool(signal.metadata != null) };
    if (signal.metadata) |metadata| value.metadata = .{ .primaries = metadata.primaries, .white = metadata.white,
        .max_mastering = metadata.max_mastering, .min_mastering = metadata.min_mastering,
        .max_cll = metadata.max_cll, .max_fall = metadata.max_fall };
    _ = try requestedSignal(value);
    return value;
}
fn decodeSignal(state: anytype, metadata: ?Metadata) Error!Signal {
    return .{ .format = switch (state.format) { 0x34325258 => .xr24, 0x30335258 => .xr30, else => return error.Unsupported },
        .bpc = switch (state.bpc) { 8 => 8, 10 => 10, else => return error.Unsupported },
        .primaries = switch (state.primaries) { 1 => .bt709, 3 => .bt2020, else => return error.Unsupported },
        .transfer = switch (state.transfer) { 1 => .srgb, 3 => .pq, 4 => .hlg, else => return error.Unsupported },
        .range = switch (state.range) { 1 => .full, 2 => .limited, else => return error.Unsupported },
        .reference_white = state.reference_white, .peak = state.peak, .black = state.black, .metadata = metadata };
}
pub fn publishedLink(state: anytype, transport: Transport) Error!Link {
    if (state.version != 1 or state.size < 128 or state.flags & 3 != 3) return error.Incomplete;
    return switch (transport) {
        .dvi => .{ .dvi = state.max_tmds_clock_hz },
        .hdmi => .{ .hdmi = .{ .max_tmds_hz = state.max_tmds_clock_hz, .scdc = state.flags & 64 != 0 } },
        .displayport => .{ .displayport = .{ .payload_bits_per_second = state.dp_payload_bits_per_second,
            .vsc = state.flags & 32 != 0, .hdr_sdp = state.flags & 16 != 0 } },
    };
}
pub const Pipeline = struct { linear_composition: bool, output_transform: bool, opaque_output: bool };
pub const Link = union(enum) {
    dvi: u64, // Source TMDS ceiling. DVI is RGB8/full/SDR only.
    hdmi: struct { max_tmds_hz: u64, scdc: bool },
    displayport: struct { payload_bits_per_second: u64, vsc: bool, hdr_sdp: bool },
};
pub const Plan = struct {
    bpp: u8,
    tmds_hz: u64 = 0,
    metadata: [36]u8 = @splat(0),
    metadata_bytes: u8 = 0,
    clear_hdr: bool,
};
pub const Luminance = struct { maximum: ?f64 = null, frame_average: ?f64 = null, minimum: ?f64 = null };
pub fn luminance(codes: [3]u8) Luminance {
    const maximum: ?f64 = if (codes[0] == 0) null else 50 * std.math.pow(f64, 2, @as(f64, @floatFromInt(codes[0])) / 32);
    const fraction = @as(f64, @floatFromInt(codes[2])) / 255;
    return .{ .maximum = maximum,
        .frame_average = if (codes[1] == 0) null else 50 * std.math.pow(f64, 2, @as(f64, @floatFromInt(codes[1])) / 32),
        .minimum = if (codes[2] == 0 or maximum == null) null else maximum.? * fraction * fraction / 100 };
}
fn payload(transfer: Transfer, value: Metadata) Error![26]u8 {
    if (transfer == .srgb) return error.Invalid;
    try value.validate();
    var bytes: [26]u8 = @splat(0);
    bytes[0] = if (transfer == .pq) 2 else 3;
    const fields = value.primaries ++ value.white ++ [4]u16{ value.max_mastering, value.min_mastering, value.max_cll, value.max_fall };
    for (fields, 0..) |field, i| std.mem.writeInt(u16, bytes[2 + 2 * i..][0..2], field, .little);
    return bytes;
}
pub fn hdmiMetadata(transfer: Transfer, value: Metadata) Error![30]u8 {
    var bytes: [30]u8 = @splat(0);
    bytes[0] = 0x87; bytes[1] = 1; bytes[2] = 26;
    bytes[4..].* = try payload(transfer, value);
    var sum: u8 = 0; for (bytes) |byte| sum +%= byte;
    bytes[3] = 0 -% sum;
    return bytes;
}
pub fn dpMetadata(transfer: Transfer, value: Metadata) Error![36]u8 {
    var bytes: [36]u8 = @splat(0);
    // DP1.3 non-audio InfoFrame SDP:30-byte body, version in HB3[7:2].
    bytes[1] = 0x87; bytes[2] = 29; bytes[3] = 0x13 << 2;
    bytes[4] = 1; bytes[5] = 26;
    bytes[6..32].* = try payload(transfer, value);
    return bytes;
}
/// DP VSC revision5: RGB encoding, named colorimetry, range and depth.
/// MSA must select VSC and DPCD0x2210 bit3 must be present before use.
pub fn dpVsc(signal: Signal) Error![36]u8 {
    if (signal.bpc != 8 and signal.bpc != 10) return error.Unsupported;
    var bytes: [36]u8 = @splat(0);
    bytes[1] = 7; bytes[2] = 5; bytes[3] = 19;
    bytes[20] = if (signal.primaries == .bt2020) 6 else 0;
    bytes[21] = @as(u8, if (signal.bpc == 10) 2 else 1) | @as(u8, if (signal.range == .limited) 0x80 else 0);
    bytes[22] = 1; // Graphics content.
    return bytes;
}
/// An explicit SDR static-metadata packet retires a previous HDR state.
/// Sending this once is distinct from merely stopping packet transmission.
pub fn dpSdrMetadata() [36]u8 {
    var bytes: [36]u8 = @splat(0);
    bytes[1] = 0x87; bytes[2] = 29; bytes[3] = 0x13 << 2;
    bytes[4] = 1; bytes[5] = 26;
    return bytes;
}
/// Receiver is the R4GFX EDID Report supplied by its canonical parser module.
/// Keeping it generic avoids importing that parser under a second module owner.
pub fn admit(receiver: anytype, signal: Signal, source: Source, pipeline: Pipeline, link: Link, pixel_clock_hz: u64, vic: u16) Error!Plan {
    if (!receiver.complete()) return error.Incomplete;
    if (!receiver.digital or receiver.colors & 1 == 0 or pixel_clock_hz == 0 or vic > 127 or
        (signal.bpc != 8 and signal.bpc != 10) or signal.reference_white == 0 or signal.reference_white > signal.peak or signal.peak > 100_000_000 or signal.black >= signal.reference_white)
        return error.Invalid;
    if (source.formats & ~@as(u8, 3) != 0 or source.bpc & ~@as(u8, 3) != 0 or source.primaries & ~@as(u8, 3) != 0 or
        source.ranges & ~@as(u8, 3) != 0 or source.eotf & ~@as(u8, 13) != 0) return error.Invalid;
    const hdr = signal.transfer != .srgb;
    const format_bit: u8 = if (signal.format == .xr24) 1 else 2;
    const bpc_bit: u8 = if (signal.bpc == 8) 1 else 2;
    const color_bit: u8 = if (signal.primaries == .bt709) 1 else 2;
    const range_bit: u8 = if (signal.range == .full) 1 else 2;
    const eotf_bit: u8 = switch (signal.transfer) { .srgb => 1, .pq => 4, .hlg => 8 };
    if (source.formats & format_bit == 0 or source.bpc & bpc_bit == 0 or source.primaries & color_bit == 0 or
        source.ranges & range_bit == 0 or source.eotf & eotf_bit == 0) return error.Unsupported;
    if (!pipeline.linear_composition or !pipeline.output_transform or !pipeline.opaque_output) return error.Incomplete;
    if ((signal.format == .xr24 and signal.bpc != 8) or (signal.format == .xr30 and signal.bpc != 10)) return error.Invalid;
    if (signal.primaries == .bt2020 and receiver.colorimetry & 0x80 == 0) return error.Unsupported;
    if (hdr) {
        if (signal.format != .xr30 or signal.bpc < 10 or signal.primaries != .bt2020 or signal.metadata == null) return error.Incomplete;
        if (!source.static_metadata or !receiver.hdr_present or receiver.hdr_eotf & eotf_bit == 0 or receiver.hdr_static & 1 == 0) return error.Unsupported;
        try signal.metadata.?.validate();
    } else if (signal.metadata != null) return error.Invalid;
    var result: Plan = .{ .bpp = signal.bpc * 3, .clear_hdr = !hdr };
    switch (link) {
        .dvi => |limit| {
            if (hdr or signal.bpc != 8 or signal.primaries != .bt709 or signal.range != .full) return error.Unsupported;
            if (limit == 0 or pixel_clock_hz > @min(limit, 165_000_000)) return error.Bandwidth;
            result.tmds_hz = pixel_clock_hz;
        },
        .hdmi => |limits| {
            if (!receiver.hdmi) return error.Unsupported;
            if (signal.bpc > 8 and receiver.hdmi_deep_color & 1 == 0) return error.Unsupported;
            if (signal.range != (if (vic <= 1) Range.full else Range.limited) and !receiver.rgb_quantization_selectable) return error.Unsupported;
            const numerator = std.math.mul(u64, pixel_clock_hz, signal.bpc) catch return error.Bandwidth;
            result.tmds_hz = numerator / 8 + @intFromBool(numerator % 8 != 0);
            const sink_limit = if (receiver.max_tmds_hz == 0) @as(u64, 165_000_000) else receiver.max_tmds_hz;
            if (limits.max_tmds_hz == 0 or result.tmds_hz > @min(limits.max_tmds_hz, sink_limit) or
                (result.tmds_hz > 340_000_000 and (!limits.scdc or !receiver.scdc))) return error.Bandwidth;
            if (hdr) { result.metadata[0..30].* = try hdmiMetadata(signal.transfer, signal.metadata.?); result.metadata_bytes = 30; }
        },
        .displayport => |limits| {
            if (signal.bpc > 8 and receiver.bits_per_color < signal.bpc) return error.Unsupported;
            if ((hdr or signal.primaries == .bt2020 or signal.range == .limited) and (!source.dp_vsc or !limits.vsc)) return error.Unsupported;
            if (hdr and !limits.hdr_sdp) return error.Unsupported;
            const required = std.math.mul(u64, pixel_clock_hz, result.bpp) catch return error.Bandwidth;
            if (limits.payload_bits_per_second == 0 or required >= limits.payload_bits_per_second) return error.Bandwidth;
            if (hdr) { result.metadata = try dpMetadata(signal.transfer, signal.metadata.?); result.metadata_bytes = 36; }
        },
    }
    return result;
}

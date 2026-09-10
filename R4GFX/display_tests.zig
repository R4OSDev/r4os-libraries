const std = @import("std");
const edid = @import("Display/edid.zig");
const t = std.testing;
const qemu = @embedFile("Tests/Display/Fixtures/qemu.edid");
const television = @embedFile("Tests/Display/Fixtures/hisense-55u8k.edid");
const apple = @embedFile("Tests/Display/Fixtures/apple-xdr-dp.edid");
const ossipc = @embedFile("Tests/Display/Fixtures/ossipc-hisense-base.bin");
fn fix(bytes: []u8) void {
    var sum: u8 = 0;
    for (bytes[0 .. bytes.len - 1]) |byte| sum +%= byte;
    bytes[bytes.len - 1] = 0 -% sum;
}
fn contains(report: *const edid.Report, width: u32, height: u32) bool {
    for (report.modes[0..report.mode_count]) |mode| if (mode.width == width and mode.height == height and mode.valid()) return true;
    return false;
}
test "licensed receiver fixtures and actual OssiPC base preserve missing extension uncertainty" {
    var result: edid.Report = .{};
    try edid.parse(ossipc, &result);
    try t.expect(result.declared_extensions > 0);
    try t.expect(!result.complete());
    try t.expect(result.warnings & edid.Warning.missing != 0);
    try t.expectEqual(@as(usize, 0), result.audio_count);
    try t.expect(!result.hdmi and !result.basic_audio);
    try t.expect(result.mode_count > 0);
    try edid.parse(qemu, &result);
    try t.expect(result.complete());
    try t.expect(contains(&result, 1280, 800));
    var base = qemu[0..128].*;
    base[35] = 0x80; base[36] = 0; base[37] = 0; base[126] = 0;
    @memset(base[108..126], 0);
    base[111] = 0xfd; base[112] = 0x0a; // legal EDID 1.4 maximum-rate offsets
    base[19] = 4;
    fix(&base);
    try edid.parse(&base, &result);
    var nominal = false;
    for (result.modes[0..result.mode_count]) |mode| {
        if (mode.width == 720 and mode.height == 400 and mode.millihz() == 70_000 and !mode.valid()) nominal = true;
    }
    try t.expect(nominal and result.complete());
    base[112] = 1; fix(&base);
    try t.expectError(error.InvalidBase, edid.parse(&base, &result));
    try edid.parse(television, &result);
    // Upstream's .ref diagnoses a 420 bitmap index 24 with only 19 SVDs.
    // The raw receiver blob is malformed; never silently accept its extension.
    try t.expect(result.warnings & edid.Warning.malformed != 0);
    try t.expect(!result.hdmi and result.audio_count == 0);
    var corrected = television[0..256].*;
    corrected[128 + 105] &= 7; // Test-only repair of the out-of-range bitmap.
    fix(corrected[128..]);
    try edid.parse(&corrected, &result);
    try t.expect(result.complete());
    try t.expect(result.hdmi and result.basic_audio and result.audio_count > 0);
    try t.expect(contains(&result, 3840, 2160));
    try t.expect(result.colors & 8 != 0);
    try edid.parse(apple, &result);
    try t.expect(result.complete());
    try t.expectEqual(@as(u8, 6), result.valid_extensions);
    try t.expect(contains(&result, 6016, 3384));
}
test "extension checksums and malformed lengths cannot leak partial audio or timing claims" {
    var bytes = television[0..256].*;
    var result: edid.Report = .{};
    bytes[140] ^= 1;
    try edid.parse(&bytes, &result);
    try t.expect(result.warnings & edid.Warning.checksum != 0);
    try t.expect(!result.hdmi and !result.basic_audio and result.audio_count == 0);
    bytes = television[0..256].*;
    bytes[130] = 5; // One-byte collection cannot hold the original first block.
    fix(bytes[128..]);
    try edid.parse(&bytes, &result);
    try t.expect(result.warnings & edid.Warning.malformed != 0);
    try t.expect(!result.hdmi and result.audio_count == 0);
    bytes = television[0..256].*;
    bytes[126] = 0;
    fix(bytes[0..128]);
    try edid.parse(&bytes, &result);
    try t.expect(result.warnings & edid.Warning.extra != 0);
    try t.expect(!result.hdmi and result.audio_count == 0);
}
test "bounded parser rejects truncated base and preserves output on fatal errors" {
    var sentinel = edid.Report{ .serial = 0xcafe1234 };
    const before = sentinel;
    for (0..128) |len| try t.expectError(error.InvalidLength, edid.parse(qemu[0..len], &sentinel));
    try t.expectEqualDeep(before, sentinel);
    var bytes = qemu[0..256].*;
    bytes[127] ^= 1;
    try t.expectError(error.InvalidBase, edid.parse(&bytes, &sentinel));
    try t.expectEqualDeep(before, sentinel);
    var oversized: [edid.max_blocks * 128 + 128]u8 = .{0} ** (edid.max_blocks * 128 + 128);
    try t.expectError(error.TooLarge, edid.parse(&oversized, &sentinel));
    // Mutate every extension byte with a repaired outer checksum: malformed
    // nested lengths and timing arithmetic must remain bounded in ReleaseSafe.
    for (128..255) |index| {
        for ([_]u8{ 0, 1, 127, 128, 255 }) |value| {
            bytes = qemu[0..256].*;
            bytes[index] = value;
            fix(bytes[128..]);
            edid.parse(&bytes, &sentinel) catch |err| switch (err) { error.Capacity => {}, else => return err };
        }
    }
}
test "DisplayID v2 detailed timing validates its inner checksum and block bounds" {
    var bytes = qemu[0..256].*;
    @memset(bytes[128..], 0);
    const block = bytes[128..];
    block[0] = 0x70; block[1] = 0x20; block[2] = 23; block[3] = 2;
    block[5] = 0x22; block[6] = 0; block[7] = 20;
    const data = block[8..28];
    // Type VII: 148500 kHz - 1; 1920x1080, total 2200x1125.
    const clock: u32 = 148499;
    data[0] = @truncate(clock); data[1] = @truncate(clock >> 8); data[2] = @truncate(clock >> 16); data[3] = 128;
    for ([_]u16{ 1919, 279, 87, 43, 1079, 44, 3, 4 }, 0..) |value, i| {
        data[4 + 2 * i] = @truncate(value); data[5 + 2 * i] = @truncate(value >> 8);
    }
    fix(block[1..29]); fix(block);
    var report: edid.Report = .{};
    try edid.parse(&bytes, &report);
    try t.expect(report.complete());
    try t.expect(contains(&report, 1920, 1080));
    block[20] ^= 1; fix(block);
    try edid.parse(&bytes, &report);
    try t.expect(report.warnings & edid.Warning.malformed != 0);
    block[2] = 123; fix(block);
    try edid.parse(&bytes, &report);
    try t.expect(report.warnings & edid.Warning.malformed != 0);
}
test "CTA 420-only timing never becomes an ordinary RGB mode by accident" {
    var bytes = qemu[0..256].*;
    @memset(bytes[128..], 0);
    const block = bytes[128..];
    block[0] = 2; block[1] = 3; block[2] = 7;
    block[4] = 0xe2; block[5] = 0x0e; block[6] = 97;
    fix(block);
    var report: edid.Report = .{};
    try edid.parse(&bytes, &report);
    var found = false;
    for (report.modes[0..report.mode_count]) |mode| if (mode.vic == 97) {
        try t.expect(mode.flags & edid.timing.y420_only != 0); found = true;
    };
    try t.expect(found);
    block[2] = 9; block[7] = 0x41; block[8] = 97; fix(block);
    try edid.parse(&bytes, &report);
    for (report.modes[0..report.mode_count]) |mode| if (mode.vic == 97) try t.expect(mode.flags & edid.timing.y420_only == 0);
}

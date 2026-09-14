const std = @import("std");
const t = std.testing;
const topology = @import("../../Display/topology.zig");
const Point = topology.Point;
const Rect = topology.Rect;
pub fn check(report: *const @import("../../Display/edid.zig").Report) !void {
    const key = try topology.Key.fromReport(0x10de250401000900, 4, report);
    try t.expect(key.persistable());
    var refreshed = report.*;
    refreshed.mode_count = 0; // EDID mode changes do not rename the monitor.
    try t.expectEqualDeep(key, try topology.Key.fromReport(key.adapter, key.connector, &refreshed));
    var second = key; second.connector = 8;
    const outputs = [_]topology.Output{
        .{ .key = key, .primary = true, .view = .{ .pixel_w = 3840, .pixel_h = 2160, .scale = 240 }, .refresh_millihz = 60_000 },
        .{ .key = second, .view = .{ .origin = .{ .x = -1080 }, .pixel_w = 1920, .pixel_h = 1080, .rotation = .clockwise90 }, .refresh_millihz = 100_000 },
    };
    const layout = try topology.Layout.init(&outputs, 1);
    const control = @import("../../Display/control.zig");
    const wire_layout = control.encode(&layout);
    try t.expectEqualDeep(layout, try control.decode(&wire_layout));
    var bad_wire = wire_layout; bad_wire.outputs[0].scale = 0;
    try t.expectError(error.Invalid, control.decode(&bad_wire));
    bad_wire = wire_layout; bad_wire.outputs[0].rotation = 4;
    try t.expectError(error.Invalid, control.decode(&bad_wire));
    var translated = layout;
    for (translated.outputs[0..translated.count]) |*value| value.view.origin.x += 123;
    try t.expect(control.matches(&layout, &(try control.normalized(translated))));
    const preferences = @import("../../Display/preferences.zig");
    const saved = try (preferences.Config{}).remember(&layout);
    var text: [preferences.max_bytes]u8 = undefined;
    const encoded = try saved.encode(&text);
    const parsed = try preferences.Config.parse(encoded);
    try t.expectEqualDeep(saved, parsed);
    const catalog = @import("../../Display/desktop_outputs.zig");
    var first: catalog.Snapshot = .{ .count = 1, .revision = 9 };
    first.entries[0].key = key;
    var next = first;
    next.entries[0].presentation.sequence = 16;
    next.entries[0].presentation.observed_sequence = 15;
    next.entries[0].presentation.observed_ns = 700;
    try t.expect(first.sameOutputs(&next));
    next.entries[0].presentation.flags = @import("r4os").abi.display_presentation_info_occluded;
    try t.expect(!first.sameOutputs(&next));
    var restoration: catalog.modes.Restoration = .{};
    var identity: @import("r4os").abi.GfxOutputId = .{ .adapter_id = 17, .connector_id = 4,
        .device_generation = 3, .connection_generation = 7 };
    try t.expect(!restoration.seen(outputs[0], identity));
    restoration.record(outputs[0], identity);
    try t.expect(restoration.seen(outputs[0], identity));
    var different = outputs[0]; different.refresh_millihz = 100_000;
    try t.expect(!restoration.seen(different, identity));
    identity.connection_generation += 1;
    try t.expect(!restoration.seen(outputs[0], identity));
    restoration.record(outputs[0], identity);
    try t.expect(restoration.seen(outputs[0], identity));
    identity.device_generation += 1;
    try t.expect(!restoration.seen(outputs[0], identity));
    try t.expect(!catalog.modes.sameTiming(outputs[0], different));
    different.refresh_millihz = 0;
    try t.expect(catalog.modes.sameTiming(outputs[0], different));
    var unknown = key; unknown.receiver[0] ^= 1;
    try t.expect(parsed.find(unknown) == null);
    try t.expectEqualDeep(outputs[1], parsed.find(second).?);
    const primary_only = try topology.Layout.init(outputs[0..1], 2);
    const remembered = try parsed.remember(&primary_only);
    try t.expectEqualDeep(outputs[1], remembered.find(second).?);
    try t.expectError(error.Format, preferences.Config.parse("R4S_FORMAT=1\nSCHEMA=UNKNOWN\n"));
    try t.expectError(error.Format, preferences.Config.parse(encoded[0..encoded.len - 4]));
    try t.expectEqualDeep(Rect{ .w = 1920, .h = 1080 }, try outputs[0].view.logical());
    try t.expectEqualDeep(Rect{ .x = -1080, .w = 1080, .h = 1920 }, try outputs[1].view.logical());
    try t.expectEqualDeep(Point{ .x = 0, .y = 1079 }, try outputs[1].view.physical(.{ .x = -1080 }));
    try t.expectEqualDeep(Point{ .x = -1080 }, try outputs[1].view.fromPhysical(.{ .x = 0, .y = 1079 }));
    try t.expectEqual(@as(?usize, 1), layout.at(.{ .x = -1, .y = 700 }));
    try t.expectEqual(@as(?usize, 0), layout.at(.{ .x = 0, .y = 700 }));
    try t.expectEqual(@as(?usize, null), layout.at(.{ .x = 0, .y = 1080 }));
    const gap = layout.nearest(.{ .x = 500, .y = 1200 }).?;
    try t.expect(gap.index == 0 and gap.point.x == 500 and gap.point.y == 1079);
    try t.expect(outputs[0].interval().? == 16_666_666 and outputs[1].interval().? == 10_000_000);
    const desktop_window = Rect{ .x = -900, .y = 100, .w = 600, .h = 700 };
    try t.expectEqualDeep(desktop_window, try layout.rescue(desktop_window, 24));
    const unplugged = try topology.Layout.init(outputs[0..1], 2);
    try t.expectEqualDeep(Rect{ .x = 0, .y = 100, .w = 600, .h = 700 }, try unplugged.rescue(desktop_window, 24));
    try t.expectEqualDeep(Rect{ .x = 0, .y = 0, .w = 4000, .h = 3000 }, try unplugged.rescue(.{ .x = -5000, .y = -3000, .w = 4000, .h = 3000 }, 24));
    var clone = outputs;
    clone[0].clone_group = 1; clone[1].clone_group = 1;
    clone[1].view = .{ .pixel_w = 1920, .pixel_h = 1080 };
    const mirrored = try topology.Layout.init(&clone, 3);
    try t.expectEqual(@as(?usize, 0), mirrored.at(.{ .x = 700, .y = 900 }));
    try t.expect(clone[0].interval() != clone[1].interval()); // Geometry equality does not couple refresh.
    clone[1].view.origin.x = 1;
    try t.expectError(error.Clone, topology.Layout.init(&clone, 4));
    clone[0].clone_group = 0; clone[1].clone_group = 0;
    try t.expectError(error.Overlap, topology.Layout.init(&clone, 4));
    clone = outputs; clone[1].key = key;
    try t.expectError(error.Duplicate, topology.Layout.init(&clone, 4));
    clone = outputs; clone[1].primary = true;
    try t.expectError(error.Primary, topology.Layout.init(&clone, 4));
    clone = outputs; clone[0].enabled = false;
    try t.expectError(error.Primary, topology.Layout.init(&clone, 4));
    var invalid = outputs[0].view; invalid.scale = 0;
    try t.expectError(error.Invalid, invalid.logical());
    invalid = outputs[0].view; invalid.origin.x = std.math.maxInt(i32);
    try t.expectError(error.Bounds, invalid.logical());
    const fractional = topology.Viewport{ .origin = .{ .x = -2560, .y = -1440 }, .pixel_w = 3840, .pixel_h = 2160, .scale = 180 };
    try t.expectEqualDeep(Rect{ .x = -2560, .y = -1440, .w = 2560, .h = 1440 }, try fractional.logical());
    try t.expectEqualDeep(Rect{ .x = 1, .y = 1, .w = 2, .h = 2 }, (try fractional.physicalDamage(.{ .x = -2559, .y = -1439, .w = 1, .h = 1 })).?);
    for ([_]topology.Rotation{ .normal, .clockwise90, .clockwise180, .clockwise270 }) |rotation| {
        for ([_]u32{ 60, 120, 150, 180, 240 }) |scale| {
            const view = topology.Viewport{ .origin = .{ .x = -13, .y = 29 }, .pixel_w = 17, .pixel_h = 11, .scale = scale, .rotation = rotation };
            const full = try view.logical();
            try t.expectEqualDeep(Rect{ .w = 17, .h = 11 }, (try view.physicalDamage(full)).?);
            // Every native pixel maps into a logical cell whose conservative
            // damage includes it, including fractional and rotated edges.
            for (0..11) |y| for (0..17) |x| {
                const native = Point{ .x = @intCast(x), .y = @intCast(y) };
                const logical = try view.fromPhysical(native);
                try t.expect(full.contains(logical));
                const damage = (try view.physicalDamage(.{ .x = logical.x, .y = logical.y, .w = 1, .h = 1 })).?;
                try t.expect(damage.contains(native));
                const center = try view.physical(logical);
                try t.expect(center.x >= 0 and center.x < 17 and center.y >= 0 and center.y < 11);
                if (scale >= 120) try t.expectEqualDeep(logical, try view.fromPhysical(center));
            };
        }
    }
}

//! Shared discovery and persistence vocabulary for Desktop and its settings
//! application. Policy, images, workers and confirmation belong to callers.
const std = @import("std");
const a = @import("r4os").abi;
pub const topology = @import("topology.zig");
pub const preferences = @import("preferences.zig");
pub const control = @import("control.zig");
pub const modes = @import("mode_control.zig");
const edid = @import("edid.zig");
pub const Entry = struct {
    info: a.GfxOutputInfo = .{},
    target: a.GfxOutputTarget = .{},
    presentation: a.DisplayPresentationInfo = .{},
    key: topology.Key = .{},
    name: [14]u8 = @splat(0),
    pub fn active(self: *const Entry) bool { return self.target.connector_id != 0; }
};
pub const Snapshot = struct {
    entries: [topology.capacity]Entry = @splat(.{}),
    count: usize = 0,
    revision: u64 = 0,
    /// Presentation liveness may change without a connector-catalog revision.
    /// Frame/IRQ counters are deliberately excluded: they are not topology.
    pub fn sameOutputs(self: *const Snapshot, other: *const Snapshot) bool {
        if (self.revision != other.revision or self.count != other.count) return false;
        for (self.entries[0..self.count], other.entries[0..other.count]) |left, right| {
            if (!std.meta.eql(left.key, right.key) or !std.meta.eql(left.target, right.target)) return false;
            const l = left.presentation; const r = right.presentation;
            if (l.flags != r.flags or l.width != r.width or l.height != r.height or l.format != r.format or
                l.policies != r.policies or l.buffer_count != r.buffer_count or l.plane_count != r.plane_count or
                l.interval_ns != r.interval_ns or l.path != r.path) return false;
        }
        return true;
    }
    pub fn read(draw: anytype) !Snapshot {
        var before: a.GfxDisplayRevision = .{};
        const outputs = draw.outputs();
        if (outputs.revision(&before) != a.gfx_output_ok) return error.Unavailable;
        if (before.present > 32 or before.present > before.capacity) return error.Capacity;
        var result: Snapshot = .{ .revision = before.revision };
        for (0..before.present) |i| {
            var value: Entry = .{};
            if (outputs.info(@intCast(i), &value.info) != a.gfx_output_ok or value.info.topology_revision != before.revision) return error.Stale;
            if (value.info.flags & a.gfx_output_flag_connected == 0 or value.info.flags & a.gfx_output_flag_receiver_only != 0) continue;
            if (result.count == result.entries.len) return error.Capacity;
            // Driver adapter IDs encode the stable PCI location. Connection
            // and device generations deliberately do not enter saved keys.
            value.key = .{ .adapter = value.info.identity.adapter_id, .connector = value.info.identity.connector_id };
            if (value.info.edid_bytes != 0 and value.info.edid_bytes <= edid.max_blocks * 128 and value.info.edid_bytes % 128 == 0) {
                var bytes: [edid.max_blocks * 128]u8 = undefined;
                var complete = true;
                for (0..value.info.edid_bytes / 128) |block_index| {
                    var block: a.GfxEdidBlock = .{};
                    if (outputs.edid(&value.info.identity, @intCast(block_index), &block) != a.gfx_output_ok or
                        !std.meta.eql(block.identity, value.info.identity) or block.byte_count != 128 or block.block_index != block_index) {
                        complete = false; break;
                    }
                    @memcpy(bytes[block_index * 128..][0..128], &block.data);
                }
                if (complete) {
                    var report: edid.Report = .{};
                    edid.parse(bytes[0..value.info.edid_bytes], &report) catch { complete = false; };
                    if (complete and report.complete()) {
                        @memcpy(value.name[0..13], &report.name);
                        value.key = topology.Key.fromReport(value.key.adapter, value.key.connector, &report) catch value.key;
                    }
                }
            }
            if (value.info.flags & a.gfx_output_flag_active != 0) for (0..topology.capacity) |head| {
                var target: a.GfxOutputTarget = .{};
                if (draw.displayOutputTarget(value.info.identity.adapter_id, @intCast(head), &target) != a.gfx_output_ok or
                    target.connector_id != value.info.identity.connector_id or target.device_generation != value.info.identity.device_generation or
                    target.connection_generation != value.info.identity.connection_generation) continue;
                var presentation: a.DisplayPresentationInfo = .{};
                if (draw.displayOutputPresentationInfo(&target, &presentation) != a.gfx_output_ok) return error.Stale;
                if (presentation.width == 0 or presentation.height == 0 or presentation.width > 65536 or presentation.height > 65536 or
                    presentation.flags & (a.display_presentation_info_lost | a.display_presentation_info_occluded) != 0) continue;
                value.target = target; value.presentation = presentation; break;
            };
            result.entries[result.count] = value; result.count += 1;
        }
        var after: a.GfxDisplayRevision = .{};
        if (outputs.revision(&after) != a.gfx_output_ok or after.revision != before.revision) return error.Stale;
        return result;
    }
};

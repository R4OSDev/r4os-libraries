// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
//! Bounded per-device mappings. Stable decoder BOs and target images keep their
//! VA across frames; completed jobs release uses, not the cached mappings.
const std = @import("std");
const a = @import("r4os").abi;
const d = @import("device.zig");
const resource = @import("native_resource.zig");
pub const capacity = 64;
pub const Entry = struct { resource: resource.Resource = .{}, uses: u32 = 0, touched: u64 = 0 };
pub const Owner = struct {
    profile: ?resource.Profile = null,
    entries: [capacity]Entry = @splat(.{}),
    uploads: [d.c.device_job_capacity]resource.Resource = @splat(.{}),
    uploaded: [d.c.device_job_capacity]bool = @splat(false),
    serial: u64 = 0,
    closing: bool = false,

    pub fn ensure(self: *Owner, device: *d.Device) d.Error!resource.Profile {
        if (self.profile) |profile| {
            if (!std.meta.eql(profile.binding, device.selected.binding) or profile.memory_generation != device.selected.memory_generation)
                self.closing = true;
            if (self.closing) return error.Busy;
            return profile;
        }
        if (self.closing or device.closing) return error.Busy;
        const profile = try resource.Profile.query(device);
        self.profile = profile;
        return profile;
    }
    pub fn acquire(self: *Owner, device: *d.Device, reference: a.GfxBufferHandle, deadline: u64) d.Error!usize {
        const profile = try self.ensure(device);
        self.serial +|= 1;
        // A borrowed reference is imported before a cache lookup. Matching the
        // canonical buffer identity must never make a stale reference usable.
        const free = for (&self.entries, 0..) |*entry, i| { if (!entry.resource.live()) break i; } else {
            var victim: ?usize = null;
            for (&self.entries, 0..) |*entry, i| if (entry.uses == 0 and !entry.resource.retiring) {
                if (victim == null or entry.touched < self.entries[victim.?].touched) victim = i;
            };
            if (victim) |index| {
                self.entries[index].resource.failed = error.Busy;
                self.entries[index].resource.close(device) catch {};
            }
            return error.Busy;
        };
        const entry = &self.entries[free];
        entry.* = .{ .touched = self.serial };
        entry.resource.import(device, profile, reference, deadline) catch |err| {
            entry.resource.failed = err;
            entry.resource.close(device) catch {};
            return err;
        };
        for (&self.entries, 0..) |*other, index| {
            if (index == free or !other.resource.live() or other.resource.retiring or other.resource.failed != null or
                !std.meta.eql(other.resource.backing.buffer, entry.resource.backing.buffer)) continue;
            if (!std.meta.eql(other.resource.descriptor, entry.resource.descriptor)) {
                entry.resource.failed = error.Stale;
                entry.resource.close(device) catch {};
                return error.Stale;
            }
            entry.resource.failed = error.Busy;
            entry.resource.close(device) catch {};
            other.touched = self.serial;
            return index;
        }
        return free;
    }
    pub fn upload(self: *Owner, device: *d.Device, slot: usize, deadline: u64) d.Error!*resource.Resource {
        const profile = try self.ensure(device);
        const item = &self.uploads[slot];
        if (item.failed) |err| return err;
        if (item.retiring) return error.Busy;
        if (!item.live()) item.system(device, profile, deadline) catch |err| { item.failed = err; return err; };
        return item;
    }
    pub fn step(self: *Owner, device: *d.Device) void {
        const profile = self.profile orelse return;
        if (device.closing or !std.meta.eql(profile.binding, device.selected.binding) or profile.memory_generation != device.selected.memory_generation)
            self.closing = true;
        const now = device.base().monotonicNanoseconds();
        var live = false;
        for (&self.entries) |*entry| {
            const item = &entry.resource;
            if (!item.live()) continue;
            if (entry.uses == 0) self.advance(item, device, profile, now);
            live = live or item.live();
        }
        for (&self.uploads, 0..) |*item, slot| {
            if (!item.live()) continue;
            if (device.jobs[slot].serial == 0) self.advance(item, device, profile, now);
            if (!item.live()) self.uploaded[slot] = false;
            live = live or item.live();
        }
        if (self.closing and !live) self.* = .{};
    }
    fn advance(self: *Owner, item: *resource.Resource, device: *d.Device, profile: resource.Profile, now: ?u64) void {
        if (!item.ready and (now == null or now.? >= item.deadline)) item.failed = error.Unavailable;
        if (self.closing or item.failed != null or item.retiring) { item.close(device) catch {}; return; }
        _ = item.step(device, profile) catch |err| { item.failed = err; return; };
    }
    pub fn hold(self: *Owner, indices: []const u8) void {
        for (indices) |index| {
            std.debug.assert(index < capacity and self.entries[index].resource.ready);
            self.entries[index].uses += 1;
        }
    }
    pub fn release(self: *Owner, indices: []const u8) void {
        for (indices) |index| {
            std.debug.assert(index < capacity and self.entries[index].uses != 0);
            self.entries[index].uses -= 1;
        }
    }
    pub fn contains(self: *const Owner, buffer: a.GfxBufferHandle) bool {
        for (&self.entries) |*entry| if (entry.resource.live() and std.meta.eql(entry.resource.backing.buffer, buffer)) return true;
        return false;
    }
    pub fn trim(self: *Owner, device: *d.Device) d.Error!void {
        var busy = false;
        for (&self.entries) |*entry| {
            if (!entry.resource.live() or entry.uses != 0) continue;
            entry.resource.failed = error.Busy;
            entry.resource.close(device) catch { busy = true; };
        }
        if (busy) return error.Busy;
    }
};

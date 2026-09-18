// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
//! Single-worker NVENC session. The input preparer supplies padded NV12 in the
//! engine's 16x16 tiled layout, in a raw linear VA allocation. A generic NVIDIA
//! block-linear image is NOT that layout. Public admission stays in the caller.
const std = @import("std");
const gpu = @import("gpu_resources");
const enc = @import("r4nv_encode");
const a = @import("r4os").abi;
pub const Error = gpu.Error || enc.picture.Error || enc.commands.Error || enc.StatusError;
const Work = enum { parameters, status, bitstream, commands, history };
const work_kinds = std.enums.values(Work);

// NVENC writes its reconstructed reference format itself. These opaque planes
// never become ordinary graphics images or CPU-readable decoded frames.
pub const Storage = struct {
    pitch: u32,
    rows: u32,
    chroma_offset: u64,
    bytes: u64,

    pub fn forSequence(sequence: enc.Sequence) Error!Storage {
        const dims = try enc.headers.dimensions(sequence);
        // The GR preparer writes linear R8 targets, whose pitch must be128
        // aligned. NVENC also accepts this multiple of its64-byte granularity.
        const pitch = std.mem.alignForward(u32, dims.width_mbs * 16, 128);
        const rows = dims.height_mbs * 16;
        const chroma_offset = std.mem.alignForward(u64, @as(u64, pitch) * rows, 256);
        return .{ .pitch = pitch, .rows = rows, .chroma_offset = chroma_offset,
            .bytes = chroma_offset + @as(u64, pitch) * std.mem.alignForward(u32, rows / 2, 16) };
    }
    pub fn layout(self: Storage) enc.picture.Layout {
        return .{ .luma_pitch = self.pitch, .chroma_pitch = self.pitch, .tiled_16x16 = true };
    }
    fn planes(self: Storage, resource: *const gpu.Resource) enc.commands.Surface {
        return .{ .luma = .{ .address = resource.address, .bytes = self.chroma_offset },
            .chroma = .{ .address = resource.address + self.chroma_offset, .bytes = self.bytes - self.chroma_offset } };
    }
};

pub const Packet = struct { bytes: usize, key: bool };
pub const Session = struct {
    ctx: gpu.Context,
    work: [work_kinds.len]gpu.Resource = @splat(.{}),
    recon: [2]gpu.Resource = @splat(.{}),
    coloc: [2]gpu.Resource = @splat(.{}),
    sequence: enc.Sequence = undefined,
    storage: Storage = undefined,
    headers: enc.headers.ParameterSets = .{},
    bitstream_bytes: u32 = 0,
    packet_bytes: usize = 0,
    key_interval: u32 = 0,
    picture_index: u32 = 0,
    frame_num: u16 = 0,
    idr_id: u16 = 0,
    since_idr: u32 = 0,
    reference: ?usize = null,
    initialized: bool = false,
    ready: bool = false,
    failed: bool = false,
    closing: bool = false,

    fn resource(self: *Session, kind: Work) *gpu.Resource {
        return &self.work[@intFromEnum(kind)];
    }
    pub fn open(self: *Session, sequence: enc.Sequence, packet_bytes: u32, key_interval: u32) Error!void {
        if (self.initialized or self.closing or self.ctx.poisoned) return error.Busy;
        if (self.ctx.device.engine != .encode or !enc.supported(self.ctx.device.class)) return error.Unsupported;
        const headers = try enc.parameterSets(sequence);
        if (packet_bytes > enc.max_bitstream_bytes or packet_bytes < 4096 + headers.length or
            key_interval == 0 or key_interval > 65535) return error.Bounds;
        const storage = try Storage.forSequence(sequence);
        self.initialized = true; // Every partial BO remains reachable for close.
        self.sequence = sequence;
        self.storage = storage;
        self.headers = headers;
        self.bitstream_bytes = packet_bytes - @as(u32, @intCast(headers.length));
        self.packet_bytes = packet_bytes;
        self.key_interval = key_interval;
        errdefer self.failed = true;
        const req = try enc.picture.requirements(self.makePicture(true));
        const sizes = [_]u64{ enc.picture.picture_bytes, enc.status_bytes, self.bitstream_bytes,
            enc.commands.word_count * 4, req.history };
        for (&self.work, sizes, work_kinds) |*bo, bytes, kind| {
            if (kind == .history) try bo.video(&self.ctx, bytes) else try bo.system(&self.ctx, bytes);
        }
        for (&self.recon, &self.coloc) |*recon, *coloc| {
            try recon.video(&self.ctx, storage.bytes);
            try coloc.video(&self.ctx, req.coloc);
        }
        self.ready = true;
    }
    fn makePicture(self: *const Session, key: bool) enc.picture.Picture {
        return .{ .sequence = self.sequence, .input = self.storage.layout(), .reference = self.storage.layout(),
            .kind = if (key) .idr else .predicted, .frame_num = if (key) 0 else self.frame_num,
            .idr_pic_id = self.idr_id, .bitstream_bytes = self.bitstream_bytes };
    }
    fn span(bo: *const gpu.Resource) enc.commands.Span {
        return .{ .address = bo.address, .bytes = bo.descriptor.byte_length };
    }
    /// Input preparation and its producer fence must have physically finished.
    /// `input` must contain this session's Storage layout including every padded
    /// macroblock pixel. This private boundary does not reinterpret public BOs.
    /// Only the compressed access unit is copied into the caller's packet arena.
    pub fn encodePrepared(self: *Session, input: *const gpu.Resource, force_idr: bool, output: []u8) Error!Packet {
        if (self.failed or self.closing or self.ctx.poisoned) return error.Stale;
        if (!self.ready or self.ctx.fence.timeline != 0) return error.Busy;
        if (self.picture_index == std.math.maxInt(u32)) return error.Bounds;
        const d = input.descriptor;
        if (!input.ready or input.owner != &self.ctx or d.location != a.gfx_buffer_location_device_local or
            d.format != a.gfx_buffer_format_bytes or d.modifier != 0 or d.plane_count != 0 or
            d.byte_length < self.storage.bytes or output.len < self.packet_bytes) return error.Invalid;
        const key = force_idr or self.reference == null or self.since_idr >= self.key_interval or self.frame_num == 0;
        const target: usize = if (self.reference) |last| last ^ 1 else 0;
        const picture = self.makePicture(key);
        const params = try enc.picture.encode(self.ctx.device.class, picture);
        const buffers: enc.commands.Buffers = .{ .picture = span(self.resource(.parameters)),
            .status = span(self.resource(.status)), .history = span(self.resource(.history)),
            .bitstream = span(self.resource(.bitstream)), .input = self.storage.planes(input),
            .output = self.storage.planes(&self.recon[target]), .coloc = span(&self.coloc[target]),
            .reference = if (!key) .{ .surface = self.storage.planes(&self.recon[self.reference.?]),
                .coloc = span(&self.coloc[self.reference.?]) } else null };
        const commands = try enc.commands.encode(self.ctx.device.class, picture, buffers, self.picture_index);
        @memcpy((try self.resource(.parameters).mappedBytes())[0..params.len], &params);
        @memcpy((try self.resource(.status).mappedBytes())[0..enc.status_bytes], &enc.pendingStatus());
        @memcpy((try self.resource(.commands).mappedBytes())[0..@sizeOf(@TypeOf(commands))], std.mem.asBytes(&commands));
        var loans: [10]gpu.Context.Loan = undefined;
        var count: usize = 0;
        for (work_kinds) |kind| {
            if (kind == .commands) continue;
            loans[count] = .{ .resource = self.resource(kind), .write = kind != .parameters };
            count += 1;
        }
        loans[count] = .{ .resource = input, .write = false }; count += 1;
        loans[count] = .{ .resource = &self.recon[target], .write = true }; count += 1;
        loans[count] = .{ .resource = &self.coloc[target], .write = true }; count += 1;
        if (!key) {
            loans[count] = .{ .resource = &self.recon[self.reference.?], .write = false }; count += 1;
            loans[count] = .{ .resource = &self.coloc[self.reference.?], .write = false }; count += 1;
        }
        // Failed engine work cannot advance the DPB, reuse input, or publish a
        // packet. A timeout leaves the exact queue fence in the shared owner.
        errdefer self.failed = true;
        try self.ctx.submit(self.resource(.commands), @sizeOf(@TypeOf(commands)), loans[0..count]);
        const status = try enc.pictureStatus(try self.resource(.status).mappedBytes(), .succeeded,
            .{ .picture_index = self.picture_index, .kind = picture.kind,
                .macroblocks = (try enc.headers.dimensions(self.sequence)).macroblocks, .buffer_bytes = self.bitstream_bytes });
        const slice = try enc.sliceBytes(try self.resource(.bitstream).mappedBytes(), status, picture.kind);
        const prefix = if (key) self.headers.length else 0;
        if (slice.len > output.len - prefix) return error.Capacity;
        @memcpy(output[0..prefix], self.headers.data[0..prefix]);
        @memcpy(output[prefix..][0..slice.len], slice);
        self.reference = target;
        self.picture_index += 1;
        self.frame_num = picture.frame_num +% 1;
        if (key) { self.idr_id +%= 1; self.since_idr = 1; } else self.since_idr += 1;
        return .{ .bytes = prefix + slice.len, .key = key };
    }
    /// Abort invalidates prediction only after the active fence retires. A
    /// failed/poisoned session must be closed and recreated by the coordinator.
    pub fn reset(self: *Session) Error!void {
        if (!self.ready or self.failed or self.closing or self.ctx.poisoned) return error.Stale;
        if (self.ctx.fence.timeline != 0) return error.Busy;
        self.reference = null;
        self.frame_num = 0;
        self.since_idr = 0;
    }
    pub fn close(self: *Session) Error!void {
        self.closing = true;
        self.ready = false;
        // Queue closure is a prerequisite, never a request to forget a DMA loan.
        try self.ctx.close();
        var failure: ?Error = null;
        for (&self.work) |*bo| bo.close() catch |err| { failure = err; };
        for (&self.recon) |*bo| bo.close() catch |err| { failure = err; };
        for (&self.coloc) |*bo| bo.close() catch |err| { failure = err; };
        if (failure) |err| return err;
    }
};

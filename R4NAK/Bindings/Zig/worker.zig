// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
//! Consumer-owned asynchronous compiler worker. Keep this object, its inputs
//! and outputs at stable addresses until join succeeds. No frame-path waits.
const std = @import("std");
const r4os = @import("r4os");
const c = @import("r4nak");
const a = r4os.abi;
pub const Worker = struct {
    sys: r4os.r4sys.Context,
    client: c.CompilerV1Client,
    program: a.ProgramProcessHandle,
    handle: a.ProgramJoinHandle = .{},
    request: c.R4NakRequest = std.mem.zeroes(c.R4NakRequest),
    result: c.R4NakBinary = std.mem.zeroes(c.R4NakBinary),
    cancel_requested: std.atomic.Value(bool) = .init(false),
    live_bytes: u64 = 0,

    pub fn init(app: *r4os.App) !Worker {
        const sys = app.system();
        const client = try c.CompilerV1Client.init(app.startContext());
        var program: a.ProgramProcessHandle = .{};
        if (sys.programOpenHandle(@intCast(app.startContext().instance_id), &program) != a.program_handle_ok or
            sys.monotonicNanoseconds() == null) return error.RuntimeUnavailable;
        return .{ .sys = sys, .client = client, .program = program };
    }
    pub fn start(self: *Worker, request: c.R4NakRequest) i32 {
        if (self.handle.thread_id != 0 or self.live_bytes != 0) return c.status_busy;
        self.request = request;
        self.result = std.mem.zeroes(c.R4NakBinary);
        self.cancel_requested.store(false, .release);
        if (self.sys.threadCreateHandle(entry, @intFromPtr(self), 1024 * 1024, 0, &self.handle) != a.thread_ok) return c.status_memory;
        return c.status_ok;
    }
    pub fn cancel(self: *Worker) void {
        self.cancel_requested.store(true, .release);
    }
    /// Null means the handle is still owned, including failed retirement.
    /// The caller must keep all storage and may retry; no timeout frees it.
    pub fn join(self: *Worker, ticks: u64) ?i32 {
        if (self.handle.thread_id == 0) return null;
        var code: i32 = 0;
        if (self.sys.threadHandleJoin(&self.handle, ticks, &code) != a.thread_ok) return null;
        self.handle = .{};
        return code;
    }
    fn at(user: u64) *Worker {
        return @ptrFromInt(user);
    }
    fn allocate(user: u64, bytes: u64, alignment: u64) callconv(.c) u64 {
        const self = at(user);
        const memory = self.sys.allocator().rawAlloc(bytes, .fromByteUnits(alignment), @returnAddress()) orelse return 0;
        self.live_bytes += bytes;
        return @intFromPtr(memory);
    }
    fn release(user: u64, address: u64, bytes: u64, alignment: u64) callconv(.c) void {
        const self = at(user);
        const memory: [*]u8 = @ptrFromInt(address);
        self.sys.allocator().rawFree(memory[0..bytes], .fromByteUnits(alignment), @returnAddress());
        self.live_bytes -= bytes;
    }
    fn clock(user: u64) callconv(.c) u64 {
        return at(user).sys.monotonicNanoseconds() orelse 0;
    }
    fn abortWorker(user: u64, status: i32) callconv(.c) void {
        at(user).sys.threadExit(status);
    }
    fn cancelled(user: u64) callconv(.c) u32 {
        const self = at(user);
        return @intFromBool(self.cancel_requested.load(.acquire) or self.sys.programShouldClose());
    }
    fn retired(user: u64, generation: u64) callconv(.c) u32 {
        const self = at(user);
        if (generation == self.program.generation) return 0;
        var cursor: a.ProgramInventoryCursor = .{};
        var summary: a.ProgramInventorySummary = .{};
        if (self.sys.programInventoryBegin(&cursor, &summary) != a.program_handle_ok) return 0;
        var rows: [32]a.ProgramInstanceSnapshot = undefined;
        for (0..64) |_| {
            var page: a.ProgramInventoryPageInfo = .{};
            if (self.sys.programInventoryPrograms(&cursor, &rows, &page) != a.program_handle_ok or
                page.status == a.program_inventory_status_restart or page.returned > rows.len) return 0;
            for (rows[0..page.returned]) |row| if (row.handle.generation == generation) {
                // Program inventory exposes done(2) only after heavy retirement
                // is ready. close_requested(1) is deliberately insufficient.
                return @intFromBool(row.info.state == 2);
            };
            if (page.status == a.program_inventory_status_complete and page.has_more == 0) return 1;
        }
        return 0;
    }
    fn entry(user: u64) callconv(.c) i32 {
        const self = at(user);
        const runtime: c.R4NakRuntime = .{
            .version = 1,
            .size = @sizeOf(c.R4NakRuntime),
            .user = user,
            .owner_generation = self.program.generation,
            .allocate = @intFromPtr(&allocate),
            .release = @intFromPtr(&release),
            .clock_ns = @intFromPtr(&clock),
            .abort_worker = @intFromPtr(&abortWorker),
            .owner_retired = @intFromPtr(&retired),
            .cancelled = @intFromPtr(&cancelled),
        };
        return self.client.compile(&runtime, &self.request, &self.result);
    }
};

/// Optional disk adapter; caller supplies private staging/backup names in the
/// same volume. Cache misses retain no bytes and never enter the GPU path.
pub fn loadCache(sys: *const r4os.r4sys.Context, client: *const c.CompilerV1Client, path: [*:0]const u8, key: *const c.R4NakCacheKey, output: *c.R4NakBinary, code: []u8) i32 {
    const info = sys.fileInfo(path) orelse return c.status_cache_miss;
    if (info.size == 0 or info.size > 16 * 1024 * 1024 + 4096) return c.status_cache_miss;
    const bytes = sys.allocator().alloc(u8, @intCast(info.size)) catch return c.status_memory;
    defer sys.allocator().free(bytes);
    if (sys.fileRead(path, bytes) != @as(i32, @intCast(bytes.len))) return c.status_cache_miss;
    return client.cache_read(key, bytes.ptr, bytes.len, output, code.ptr, code.len);
}
pub fn saveCache(sys: *const r4os.r4sys.Context, client: *const c.CompilerV1Client, path: [*:0]const u8, staging: [*:0]const u8, backup: [*:0]const u8, key: *const c.R4NakCacheKey, binary: *const c.R4NakBinary, code: []const u8) i32 {
    if (code.len == 0 or code.len > 16 * 1024 * 1024) return c.status_invalid;
    const bytes = sys.allocator().alloc(u8, code.len + 4096) catch return c.status_memory;
    defer sys.allocator().free(bytes);
    var written: u64 = 0;
    const status = client.cache_write(key, binary, code.ptr, code.len, bytes.ptr, bytes.len, &written);
    if (status != 0) return status;
    if (sys.fileWrite(staging, bytes[0..written]) != @as(i32, @intCast(written))) {
        _ = sys.fileDelete(staging);
        return c.status_cache_miss;
    }
    const replaced = sys.fileReplaceAtomic(path, staging, backup, r4os.r4sys.file_replace_atomic_flag_consume_stage);
    if (replaced != r4os.r4sys.file_replace_atomic_result_ok) {
        _ = sys.fileDelete(staging);
        return c.status_cache_miss;
    }
    _ = sys.fileDelete(backup);
    return c.status_ok;
}

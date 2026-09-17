// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const a = @import("r4os").abi;
const threads = @import("r4native").threads;

// R4SYS resolves the current caller's output on each write. No application
// stream or Bundle is cached in shared library storage.
pub export fn r4vk_console_write(bytes: [*]const u8, count: u32) callconv(.c) i32 {
    const address = threads.table().write;
    if (address == 0) return -1;
    const write: a.R4SysFns.write = @ptrFromInt(address);
    return write(bytes, count);
}

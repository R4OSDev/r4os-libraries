// Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
const r4os = @import("r4os");
pub const threads = @import("threads_api.zig");
pub const memory = @import("memory.zig");
pub const time = @import("time.zig");
pub const math = @import("math.zig");

pub fn bind(kernel: *const r4os.abi.R4XStartR4Sys) bool {
    if (kernel.abi_version < 20 or kernel.size < @offsetOf(r4os.abi.R4XStartR4Sys, "program_local_publish") + 8) return false;
    inline for (.{ "vm_reserve", "vm_commit", "vm_release", "program_local_get", "program_local_publish", "sleep_ticks" }) |field|
        if (@field(kernel.*, field) == 0) return false;
    return threads.bind(kernel);
}

comptime {
    _ = memory;
    _ = time;
    _ = math;
}

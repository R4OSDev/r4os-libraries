const std = @import("std");
const project = @import("project");
const r4std = @import("r4std");
const r4os = @import("r4os");

const module_name: [:0]const u8 = "R4STD";
const export_names = [_][:0]const u8{ "TEXT_V1", "SETTINGS_V1", "DATE_V1", "TIME_V1", "CONFIG_V1" };

fn makeContext(imports: []const r4os.abi.R4XStartImport) r4os.abi.R4XStartContext {
    return .{
        .flags = r4os.abi.r4xstart_flag_imports_valid,
        .imports = @intFromPtr(imports.ptr),
        .import_count = @intCast(imports.len),
    };
}

fn makeImports() [5]r4os.abi.R4XStartImport {
    const tables = [_]usize{
        @intFromPtr(&project.r4std_text_v1),
        @intFromPtr(&project.r4std_settings_v1),
        @intFromPtr(&project.r4std_date_v1),
        @intFromPtr(&project.r4std_time_v1),
        @intFromPtr(&project.r4std_config_v1),
    };
    var imports: [5]r4os.abi.R4XStartImport = undefined;
    for (&imports, export_names, tables) |*item, export_name, table| {
        item.* = .{
            .group_id = 0,
            .min_version = 1,
            .resolved_version = 1,
            .flags = 0,
            .module_name = @intFromPtr(module_name.ptr),
            .symbol_name = @intFromPtr(export_name.ptr),
            .table = table,
        };
    }
    return imports;
}

test "text settings date and time calls cross local runtime tables" {
    r4std.resetForTesting();
    defer r4std.resetForTesting();
    var imports = makeImports();
    var raw = makeContext(&imports);
    raw.imports = @intFromPtr(&imports);
    try std.testing.expect(r4std.init(&raw));

    const utf8 = try r4std.text.Utf8Text.init("Gru\xC3\x9F");
    try std.testing.expectEqual(@as(usize, 4), utf8.scalarCount());
    var canonical_buffer: [64]u8 = undefined;
    const canonical = try r4std.settings.canonicalizeSystemText("A\nB\r\n", &canonical_buffer);
    try std.testing.expectEqualStrings(r4std.settings.utf8_bom ++ "A\r\nB\r\n", canonical);

    var settings_buffer: [128]u8 = undefined;
    var writer = r4std.settings.Writer.init(&settings_buffer);
    writer.writeHeader("TEST");
    writer.writePairU32("COUNT", 42);
    try std.testing.expect(writer.ok());
    const document = r4std.settings.Document.init(writer.bytes());
    try std.testing.expectEqual(@as(?u32, 42), document.u32Value("COUNT"));

    try std.testing.expect(r4std.date.validDateValue(2000, 2, 29));
    try std.testing.expect(!r4std.date.validDateValue(1900, 2, 29));
    const parsed = r4std.date.parseDateIso("2026-08-14") orelse return error.DateParseFailed;
    var date_buffer: [16]u8 = undefined;
    try std.testing.expectEqualStrings("2026-08-14", r4std.date.formatDateIso(&date_buffer, parsed));

    var time_config = r4std.time.Config{};
    try std.testing.expect(time_config.loadFromBytes("TIMEZONE=Europe/Berlin\r\nCLOCK_FORMAT=12H\r\n"));
    try std.testing.expectEqual(@as(usize, 15), time_config.selectedIndex());
    try std.testing.expectEqual(r4os.abi.clock_format_12h, time_config.selectedClockFormat());
    try std.testing.expectEqual(@as(i16, 60), r4std.time.standardOffsetAt(15));
    var summer = std.mem.zeroes(r4os.abi.TimeState);
    summer.valid = 1;
    summer.year = 2026;
    summer.month = 6;
    summer.day = 1;
    try std.testing.expectEqual(@as(i16, 120), r4std.time.offsetAtState(15, summer));
}

test "writeback state remains caller-owned across table calls" {
    r4std.resetForTesting();
    defer r4std.resetForTesting();
    var imports = makeImports();
    var raw = makeContext(&imports);
    raw.imports = @intFromPtr(&imports);
    try std.testing.expect(r4std.init(&raw));

    var state = r4std.settings.Writeback.init(r4std.settings.WritebackPolicy.forHz(.soon, 100));
    state.markDirty(10);
    try std.testing.expect(state.isDirty());
    const Saver = struct {
        pub fn save(_: @This()) i32 {
            return 1;
        }
    };
    const flush = state.flushNow(11, Saver{});
    try std.testing.expect(flush.action == .saved);
    try std.testing.expect(!state.isDirty());
}

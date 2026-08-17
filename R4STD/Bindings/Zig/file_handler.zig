const std = @import("std");
const r4os = @import("r4os");
const app_assoc = @import("app_assoc.zig");
const catalog_contract = r4os.subsystem_catalog;
const launch_contract = r4os.subsystem_launch;

pub const max_choices: usize = app_assoc.max_apps + 16;
pub const Input = catalog_contract.Input;

pub const TargetKind = enum {
    direct_program,
    application,
    subsystem,
};

pub const Target = struct {
    kind: TargetKind,
    handler_id: []const u8,
    format_id: []const u8 = "",
    title: []const u8,
    app_path: []const u8,
    args: []const u8,
    policy: r4os.abi.LaunchPolicy,
};

pub const ResolutionState = enum {
    unknown,
    selected,
    ambiguous,
};

pub const Resolution = struct {
    state: ResolutionState = .unknown,
    target: ?Target = null,
};

pub const ChoiceKind = enum {
    application,
    subsystem,
};

pub const Choice = struct {
    kind: ChoiceKind,
    handler_id: []const u8,
    format_id: []const u8 = "",
    title: []const u8,
    app_path: []const u8,
    policy: r4os.abi.LaunchPolicy = .gui,
    app: ?*const app_assoc.AppEntry = null,
};

pub const ChoiceList = struct {
    items: [max_choices]Choice = undefined,
    count: usize = 0,

    pub fn slice(self: *const ChoiceList) []const Choice {
        return self.items[0..self.count];
    }
};

pub const Error = catalog_contract.ResolveError || launch_contract.Error || error{
    InvalidAssociation,
    TooManyChoices,
};

pub fn resolve(
    config: *const app_assoc.Config,
    catalog: *const catalog_contract.Catalog,
    input: Input,
    args_out: []u8,
    out: *Resolution,
) Error!void {
    out.* = .{};
    if (app_assoc.isR4XPath(input.path)) {
        if (args_out.len == 0) return error.BufferTooSmall;
        args_out[0] = 0;
        out.* = .{ .state = .selected, .target = .{
            .kind = .direct_program,
            .handler_id = "",
            .title = "R4X App",
            .app_path = input.path,
            .args = args_out[0..0],
            .policy = .auto,
        } };
        return;
    }

    if (app_assoc.extensionOfPath(input.path)) |extension| {
        if (config.extensionByName(extension)) |entry| switch (entry.handler_kind) {
            .none => return,
            .app => {
                const app_target = config.resolvePath(input.path, args_out) orelse return error.InvalidAssociation;
                out.* = .{ .state = .selected, .target = targetFromApp(app_target) };
                return;
            },
            .subsystem => {
                var extension_storage: [app_assoc.ext_max + 2]u8 = undefined;
                extension_storage[0] = '.';
                @memcpy(extension_storage[1 .. extension.len + 1], extension);
                const association = [_]catalog_contract.Association{.{
                    .extension = extension_storage[0 .. extension.len + 1],
                    .subsystem_id = entry.subsystemIdText(),
                    .format_id = entry.formatIdText(),
                }};
                var subsystem_resolution: catalog_contract.Resolution = .{};
                try catalog_contract.resolve(catalog, input, .{ .user_associations = &association }, &subsystem_resolution);
                return finishSubsystemResolution(subsystem_resolution, input.path, args_out, out);
            },
        };
    }

    var subsystem_resolution: catalog_contract.Resolution = .{};
    try catalog_contract.resolve(catalog, input, .{}, &subsystem_resolution);
    try finishSubsystemResolution(subsystem_resolution, input.path, args_out, out);
}

pub fn collectChoices(
    config: *const app_assoc.Config,
    catalog: *const catalog_contract.Catalog,
    input: Input,
    out: *ChoiceList,
) Error!void {
    out.* = .{};
    try appendApps(config, out);

    if (app_assoc.extensionOfPath(input.path)) |extension| {
        if (config.extensionByName(extension)) |entry| if (entry.handler_kind == .subsystem) {
            var extension_storage: [app_assoc.ext_max + 2]u8 = undefined;
            extension_storage[0] = '.';
            @memcpy(extension_storage[1 .. extension.len + 1], extension);
            const association = [_]catalog_contract.Association{.{
                .extension = extension_storage[0 .. extension.len + 1],
                .subsystem_id = entry.subsystemIdText(),
                .format_id = entry.formatIdText(),
            }};
            var configured: catalog_contract.Resolution = .{};
            try catalog_contract.resolve(catalog, input, .{ .user_associations = &association }, &configured);
            for (configured.slice()) |candidate| try appendSubsystem(out, candidate);
        };
    }

    var matching: catalog_contract.Resolution = .{};
    try catalog_contract.resolve(catalog, input, .{}, &matching);
    for (matching.slice()) |candidate| try appendSubsystem(out, candidate);
}

pub fn collectExtensionChoices(
    config: *const app_assoc.Config,
    catalog: *const catalog_contract.Catalog,
    extension_value: []const u8,
    out: *ChoiceList,
) Error!void {
    out.* = .{};
    try appendApps(config, out);
    var dotted: [app_assoc.ext_max + 2]u8 = undefined;
    const extension = if (extension_value.len != 0 and extension_value[0] == '.') extension_value[1..] else extension_value;
    if (extension.len == 0 or extension.len > app_assoc.ext_max) return;
    dotted[0] = '.';
    @memcpy(dotted[1 .. extension.len + 1], extension);
    const mapped_extension = dotted[0 .. extension.len + 1];
    for (catalog.entries[0..catalog.count]) |entry| {
        for (entry.guest_formats) |format_id| {
            if (!entry.mapsExtension(format_id, mapped_extension)) continue;
            try appendSubsystem(out, .{
                .subsystem_id = entry.subsystem_id,
                .format_id = format_id,
                .host_path = entry.host_path,
                .display_name = entry.display_name,
                .module_version = entry.module_version,
                .evidence = .extension,
            });
        }
    }
}

pub fn targetForChoice(choice: Choice, guest_path: []const u8, args_out: []u8) Error!Target {
    return switch (choice.kind) {
        .application => blk: {
            const app = choice.app orelse return error.InvalidAssociation;
            const args = app_assoc.expandArgs(app.argsText(), guest_path, args_out) orelse return error.BufferTooSmall;
            break :blk .{
                .kind = .application,
                .handler_id = app.idText(),
                .title = app.titleText(),
                .app_path = app.pathText(),
                .args = args,
                .policy = app.policy,
            };
        },
        .subsystem => .{
            .kind = .subsystem,
            .handler_id = choice.handler_id,
            .format_id = choice.format_id,
            .title = choice.title,
            .app_path = choice.app_path,
            .args = try launch_contract.encode(guest_path, &.{}, args_out),
            .policy = .gui,
        },
    };
}

fn finishSubsystemResolution(
    subsystem_resolution: catalog_contract.Resolution,
    guest_path: []const u8,
    args_out: []u8,
    out: *Resolution,
) Error!void {
    switch (subsystem_resolution.state) {
        .unknown => out.* = .{},
        .ambiguous => out.* = .{ .state = .ambiguous },
        .selected => {
            const candidate = subsystem_resolution.selected().?;
            out.* = .{ .state = .selected, .target = .{
                .kind = .subsystem,
                .handler_id = candidate.subsystem_id,
                .format_id = candidate.format_id,
                .title = candidate.display_name,
                .app_path = candidate.host_path,
                .args = try launch_contract.encode(guest_path, &.{}, args_out),
                .policy = .gui,
            } };
        },
    }
}

fn targetFromApp(target: app_assoc.LaunchTarget) Target {
    return .{
        .kind = if (target.kind == .direct_program) .direct_program else .application,
        .handler_id = target.app_id,
        .title = target.title,
        .app_path = target.app_path,
        .args = target.args,
        .policy = target.policy,
    };
}

fn appendApps(config: *const app_assoc.Config, out: *ChoiceList) Error!void {
    for (config.apps[0..config.app_count]) |*app| {
        if (config.appById(app.idText()) == null) continue;
        try appendChoice(out, .{
            .kind = .application,
            .handler_id = app.idText(),
            .title = app.titleText(),
            .app_path = app.pathText(),
            .policy = app.policy,
            .app = app,
        });
    }
}

fn appendSubsystem(out: *ChoiceList, candidate: catalog_contract.Candidate) Error!void {
    try appendChoice(out, .{
        .kind = .subsystem,
        .handler_id = candidate.subsystem_id,
        .format_id = candidate.format_id,
        .title = candidate.display_name,
        .app_path = candidate.host_path,
        .policy = .gui,
    });
}

fn appendChoice(out: *ChoiceList, choice: Choice) Error!void {
    for (out.items[0..out.count]) |prior| {
        if (prior.kind == choice.kind and std.ascii.eqlIgnoreCase(prior.handler_id, choice.handler_id) and
            std.ascii.eqlIgnoreCase(prior.format_id, choice.format_id)) return;
    }
    if (out.count >= out.items.len) return error.TooManyChoices;
    out.items[out.count] = choice;
    out.count += 1;
}

fn fixtureCatalog() catalog_contract.Catalog {
    const formats = &[_][]const u8{"basic.qbasic-source"};
    const extensions = &[_][]const u8{"basic.qbasic-source:.bas"};
    const features = &[_][]const u8{"basic.qbasic-source:probe.text-token-v1.7072696e74"};
    var catalog: catalog_contract.Catalog = .{};
    catalog.entries[0] = .{
        .subsystem_id = "test.basic",
        .host_path = "/R4OS/SUBSYSTEMS/test.basic/SUBSYSOK.R4X",
        .display_name = "Test BASIC Runtime",
        .module_name = "SUBSYSOK",
        .module_version = "0.66.2",
        .guest_formats = formats,
        .guest_extensions = extensions,
        .guest_features = features,
    };
    catalog.count = 1;
    return catalog;
}

test "unified resolver preserves app behavior and launches subsystem by stable id" {
    var config = app_assoc.Config.initDefault();
    const catalog = fixtureCatalog();
    var args: [launch_contract.max_args_bytes]u8 = undefined;
    var result: Resolution = .{};
    try resolve(&config, &catalog, .{
        .path = "C:\\README.TXT",
        .probe_prefix = "hello",
        .file_size = 5,
        .probe_window_complete = true,
    }, args[0..], &result);
    try std.testing.expectEqual(TargetKind.application, result.target.?.kind);
    try std.testing.expectEqualStrings("NOTEPAD", result.target.?.handler_id);

    _ = config.loadFromBytes(
        \\R4S_FORMAT=1
        \\SCHEMA=APPASSOC
        \\EXT.BAS.HANDLER=SUBSYSTEM
        \\EXT.BAS.SUBSYSTEM=test.basic
        \\EXT.BAS.FORMAT=basic.qbasic-source
        \\EXT.BAS.TYPE=BASIC Source
        \\EXT.BAS.SHORT=BAS
        \\EXT.BAS.PREFIX=[BAS]
        \\EXT.BAS.RANK=3
    );
    const guest = "C:\\Games and Tools\\GORILLA.BAS";
    try resolve(&config, &catalog, .{
        .path = guest,
        .probe_prefix = "print 42",
        .file_size = 8,
        .probe_window_complete = true,
    }, args[0..], &result);
    try std.testing.expectEqual(TargetKind.subsystem, result.target.?.kind);
    try std.testing.expectEqualStrings("test.basic", result.target.?.handler_id);
    try std.testing.expectEqualStrings(guest, (try launch_contract.parse(result.target.?.args)).guest_path);
}

test "removed handler suppresses automatic launch while Open With stays complete" {
    var config = app_assoc.Config.initDefault();
    const catalog = fixtureCatalog();
    const txt_index = for (config.extensions[0..config.extension_count], 0..) |entry, index| {
        if (std.ascii.eqlIgnoreCase(entry.extText(), "TXT")) break index;
    } else unreachable;
    try std.testing.expect(config.setExtensionNone(txt_index));
    var args: [launch_contract.max_args_bytes]u8 = undefined;
    var result: Resolution = .{};
    try resolve(&config, &catalog, .{
        .path = "C:\\README.TXT",
        .probe_prefix = "print 42",
        .file_size = 8,
        .probe_window_complete = true,
    }, args[0..], &result);
    try std.testing.expectEqual(ResolutionState.unknown, result.state);

    var choices: ChoiceList = .{};
    try collectChoices(&config, &catalog, .{
        .path = "C:\\GORILLA.BAS",
        .probe_prefix = "print 42",
        .file_size = 8,
        .probe_window_complete = true,
    }, &choices);
    try std.testing.expect(choices.count >= 4);
    try std.testing.expectEqual(ChoiceKind.subsystem, choices.items[choices.count - 1].kind);
}

test "extension choices resolve subsystem metadata without copying its catalog" {
    const config = app_assoc.Config.initDefault();
    const catalog = fixtureCatalog();
    var choices: ChoiceList = .{};
    try collectExtensionChoices(&config, &catalog, "BAS", &choices);
    try std.testing.expectEqualStrings("test.basic", choices.items[choices.count - 1].handler_id);
    try std.testing.expectEqualStrings("Test BASIC Runtime", choices.items[choices.count - 1].title);
}

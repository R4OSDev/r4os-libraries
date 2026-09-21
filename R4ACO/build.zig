const std = @import("std");
pub fn build(b: *std.Build) void {
    b.addNamedLazyPath("binding", b.path("Bindings/Zig/r4aco.zig"));
    const sdk_build = b.lazyImport(@This(), "r4os_sdk") orelse return;
    const sdk = sdk_build.sdk(b, b.dependencyFromBuildZig(sdk_build, .{}), .{});
    const artifact = sdk.addR4MF(b.path("module.R4MF"));
    const host = sdk.createR4osModule(b.graph.host, .ReleaseSafe);
    const implementation = b.createModule(.{ .root_source_file = b.path("Contract/Generated/implementation_abi.zig"), .target = b.graph.host });
    implementation.addImport("r4os", host);
    const binding = b.createModule(.{ .root_source_file = b.path("Bindings/Zig/r4aco.zig"), .target = b.graph.host });
    binding.addImport("r4os", host);
    const conformance = b.createModule(.{ .root_source_file = b.path("Tests/Generated/contract_conformance.zig"), .target = b.graph.host });
    conformance.addImport("implementation", implementation);
    conformance.addImport("binding", binding);
    conformance.addIncludePath(b.path("Bindings/C"));
    conformance.addIncludePath(sdk.profile.c_include_root);
    conformance.addIncludePath(sdk.profile.contract_c_include_root);
    conformance.addCSourceFile(.{ .file = b.path("Tests/Generated/contract_conformance.c"), .flags = &.{ "-std=c11", "-Werror" } });
    const abi_check = b.addRunArtifact(b.addTest(.{ .root_module = conformance }));
    const native = b.addSystemCommand(&.{ "pwsh", "-NoLogo", "-NoProfile", "-File" });
    native.addFileArg(b.path("Tools/Build.ps1"));
    native.has_side_effects = true;
    artifact.output.generated.file.step.dependOn(&native.step);
    b.getInstallStep().dependOn(&abi_check.step);
    const test_step = b.step("test", "R4ACO contract and real upstream portability");
    test_step.dependOn(&abi_check.step);
    test_step.dependOn(&native.step);
}

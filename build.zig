const std = @import("std");

/// Das Rootpaket baut keine Runtime-Library. Es stellt ausschliesslich die
/// versionierten Consumer-Bindings als benannte Paketpfade bereit; jede R4L
/// bleibt in ihrer eigenen Einheit baubar und getestet.
pub fn build(b: *std.Build) void {
    b.addNamedLazyPath("r4std_zig_binding", b.path("R4STD/Bindings/Zig/r4std.zig"));
    b.addNamedLazyPath("r4std_c_include", b.path("R4STD/Bindings/C"));
    b.addNamedLazyPath("r4img_zig_binding", b.path("R4IMG/Bindings/Zig/r4img.zig"));
    b.addNamedLazyPath("r4img_c_include", b.path("R4IMG/Bindings/C"));
    b.addNamedLazyPath("r4font_zig_binding", b.path("R4FONT/Bindings/Zig/r4font.zig"));
    b.addNamedLazyPath("r4font_c_include", b.path("R4FONT/Bindings/C"));
    b.addNamedLazyPath("r4font_app_fonts", b.path("R4FONT/Bindings/Zig/app_fonts.zig"));
    b.addNamedLazyPath("r4font_font_tools", b.path("R4FONT/Bindings/Zig/font_tools.zig"));
}

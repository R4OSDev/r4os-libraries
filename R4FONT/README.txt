R4FONT.R4L
==========

R4FONT is an independent Runtime-R4L for validated font sources. It exports
the versioned API_V1:1 table and owns its implementation, contract, baseline,
Zig and C bindings, FreeType, Brotli, and zlib integration. The core SDK does
not contain R4FONT types or decoder sources.

Supported inputs include TTF, OpenType/CFF, WOFF, WOFF2, and SFNT collections
with CMAP, metrics, kerning, and deterministic Alpha8 rasterization. Source
data, decoder state, raster buffers, and reconstruction allocations belong to
the calling process.

Consumers declare IMPORT=R4FONT:API_V1:1 and bind
Bindings/Zig/r4font.zig or Bindings/C/r4font.h. Docs/API.md is generated from
the contract.

Build and test:

    Build.bat R4FONT test
    ./Build.sh R4FONT test

The optional host profile compares the same 32-pixel glyph-raster workload
under both manifest optimization modes. It is not part of the normal test
gate:

    Build.bat R4FONT profile -Dhost-test-optimize=ReleaseSmall
    Build.bat R4FONT profile -Dhost-test-optimize=ReleaseFast
    ./Build.sh R4FONT profile -Dhost-test-optimize=ReleaseSmall
    ./Build.sh R4FONT profile -Dhost-test-optimize=ReleaseFast

Verify vendored sources and generated fixtures:

    python R4FONT/ThirdParty/r4font/Tools/verify_vendor.py --check
    python R4FONT/Tests/Tools/generate_minimal_fonts.py --check


Input bounds and ownership (0.78.65)
-----------------------------------
R4FONT 0.2.2 reads the WOFF/WOFF2 size field only with at least 20 input bytes.
The FNT import helper transfers each bitmap to its owning list exactly once;
a later RasterGlyph allocation failure no longer frees it twice. FON/NE
header and resource offsets use checked, input-bounded arithmetic, including
resource alignment shifts. FONTS 0.1.4 embeds the corrected import helper.
No decoder API, interface layout or upstream library version changes.
The existing vendor byte manifest records the corrected local bridge.
Focused checks reuse the small R4F/FNT/FON/WOFF examples; no raster profiles
or long font runs are added.

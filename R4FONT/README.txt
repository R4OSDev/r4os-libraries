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

Verify vendored sources and generated fixtures:

    python R4FONT/ThirdParty/r4font/Tools/verify_vendor.py --check
    python R4FONT/Tests/Tools/generate_minimal_fonts.py --check

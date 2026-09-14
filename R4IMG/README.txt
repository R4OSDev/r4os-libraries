R4IMG.R4L
=========

R4IMG is the independent Runtime-R4L for raster and vector image formats. It
owns its implementation, stb_image integration, local V1 contract, and
generated Zig and C bindings. Consumers import R4IMG:API_V1:1 and call only
the loaded function table. Pixel and scratch buffers always remain owned by
the calling process.

The current implementation supports PNG, JPEG, BMP, and a bounded static SVG
2 subset with ARGB output, alpha composition, aspect-ratio handling, software
rasterization, and bounded scaling. Optional consumer callbacks handle SVG
text and link regions.

Build and test:

    Build.bat R4IMG test
    ./Build.sh R4IMG test

The optional host profile compares the same opaque Full-HD bilinear scaling
workload under both manifest optimization modes. It is not part of the normal
test gate:

    Build.bat R4IMG profile -Dhost-test-optimize=ReleaseSmall
    Build.bat R4IMG profile -Dhost-test-optimize=ReleaseFast
    ./Build.sh R4IMG profile -Dhost-test-optimize=ReleaseSmall
    ./Build.sh R4IMG profile -Dhost-test-optimize=ReleaseFast

Tests cover the contract, provider, real decoder paths, runtime table, and an
independent C consumer.

Color-aware consumers additionally import PNG_V1 for PNG metadata, ICC
extraction and full-precision RGBA16 samples, or RASTER_V1 for JPEG ICC/Exif
and BMP V4/V5 characterization. The ColorDecoder(R4GFX) facade connects these
metadata interfaces to the shared COLOR_V1 CMM without decoder-owned color
math. Untagged sRGB is an explicit application policy; unknown/linked/CMYK
source descriptions are never silently relabeled. API_V1 remains unchanged.
See Docs/API.md for layouts and workspace Docs/Desktop/GrafikFarbe07925.txt
for pipeline ownership, display profiles and output limitations.

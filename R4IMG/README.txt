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

Tests cover the contract, provider, real decoder paths, runtime table, and an
independent C consumer.

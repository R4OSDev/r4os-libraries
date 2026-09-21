# R4OS Runtime Libraries

This repository contains the independent Runtime-R4L units R4STD, R4IMG, R4GFX, R4NV,
R4NAK, R4VK, R4GL, R4VIDEO, R4ENC, R4FONT, R4AMD, and R4ACO. Each library owns its implementation, contract, baseline, Zig and C
bindings, manifest, and tests.

## Build and validation

Build and test all libraries on Windows:

    Build.bat test

Build and test one unit:

    Build.bat R4STD test
    Build.bat R4IMG test
    Build.bat R4FONT test
    ./Build.sh R4GFX test
    ./Build.sh R4NV test
    ./Build.sh R4NAK
    ./Build.sh R4VK
    ./Build.sh R4GL
    ./Build.sh R4VIDEO -Doffline=true

R4NAK is the freestanding C/Rust SPIR-V/NIR/NAK runtime compiler. Its first
build needs the pinned host tools and sources described in `R4NAK/README.md`.
R4VK is the native Mesa Vulkan provider under development. Its regular build
prepares the matching NVK/NIL/NAK dependencies; see `R4VK/README.md`. It remains
available as an optional runtime in slim/full images. R4GL provides native
Mesa software EGL/OpenGL without a GPU or host Rust compiler; see
`R4GL/README.md` for the current profile and lifecycle contract.
R4VIDEO provides bounded H.264 software decoding through VIDEO_V1. Its pinned
FFmpeg build uses clang/NASM; offline builds require the cached archive. It is
included in normal profiles with corresponding sources; see `R4VIDEO/README.md`.

R4AMD and R4ACO provide the AMD foundation and compile genuine pinned
AddrLib/ACO/NIR sources during their normal build. They currently expose
only build identity and remain outside normal image profiles; see their READMEs.

Both `Build.bat` and `./Build.sh` use the shared PowerShell 7 `Build.ps1`. Dependency paths are mapped by
`Settings.R4S`.

Detailed German migration notes are preserved in
`DOCUMENTATION.de.txt`.

## License

Original R4OS material is licensed under Apache License 2.0. Vendored code and
test fixtures retain their upstream licenses; see `THIRD_PARTY_NOTICES.md`
and the license files beside that material.

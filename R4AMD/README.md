# R4AMD

R4AMD is the AMD render/layout/media library owner. Version 0.1.0 provides a generated
`INFO_V1:1` ABI with immutable build identity and **zero GPU capabilities**.
It does not yet expose rendering or shader compilation to applications.
AMDGPU.R4D owns all physical device access.

Build from the Libraries repository with `./Build.sh R4AMD` on Linux or
`Build.bat R4AMD` on Windows. Both use PowerShell 7 and the workspace
`Settings.R4S`. The normal build runs C/Zig ABI conformance and translates
real Mesa 26.2.2 GFX9 AddrLib sources for
`x86_64-unknown-none-elf`. Use the same starter with `test` for those checks.

The native proof requires Clang/LLVM 19.1.7 and Zig 0.16.0 headers;
R4ACO additionally needs Python 3, Mako and PyYAML. These are the existing
Mesa toolchain prerequisites. Build orchestration is shared at
`Shared/Native/BuildPortability.ps1`; output is isolated by module, host
and upstream version under `Artifacts/Native`. Every invocation rebuilds;
no NAK/NVK cache entry or prepared source is modified or reused.

The genuine native objects are currently portability evidence, not linked
into the R4L. `portability.json` records object hashes, compiler/header
inputs and every unresolved symbol. Runtime/link integration belongs to
0.80.12; see `Docs/Drivers/AMDModulgrundlage08002.txt` in the workspace.
`IMAGE_SCOPE=none` keeps this foundation out of normal system profiles.

`ThirdParty/Sources.json` pins original bytes and patch order. Originals
and full license notices are preserved beside the source. The AddrLib
release patch avoids including POSIX `signal.h` with `DEBUG=0`. It does
not implement signals. C++ exceptions and RTTI are disabled; allocation,
assertions, stream helpers, atomics and FPU context must be supplied by the
R4OS runtime/worker owners before any callable backend is admitted.

Original R4OS code: Apache License 2.0. Third-party material keeps its
own license; see the repository `THIRD_PARTY_NOTICES.md`.

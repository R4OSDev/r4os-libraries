# R4NAK host compiler

This tool builds the pinned Mesa 26.2.2 NIR/NAK compiler and translates six
documented R4NV shader profiles for SM86. It produces actual machine code,
the NVIDIA shader header, input NIR and readable NAK assembly. It does not
open a GPU or implement an R4OS runtime compiler.

From the workspace root on Debian 13:

```sh
Repositories/Libraries/R4NV/Tools/Compiler/Build.sh -InstallDependencies -VerifyReproducible
```

Once the host tools and seven source archives are present, use `-Offline`.
Normal library and image builds do not download or rebuild Mesa. This optional
host build is deliberately outside the interactive rendering path.

On Windows, run the same `Build.ps1` through `Build.bat` from an x64 developer
environment with these tools on PATH:

- PowerShell 7, Git, curl and tar with xz support.
- LLVM 19.1.7 `clang-cl`, matching libclang, and the Windows SDK/MSVC link
  environment required by the native `x86_64-pc-windows-msvc` Rust target.
- Rust 1.85.1, bindgen 0.71.1 and cbindgen 0.27.0.
- Meson 1.7.0, Ninja 1.12.1, Python 3.10 or newer, Mako, PyYAML and packaging.
- Flex/Bison as recognized by Mesa, if its configuration requests them.

The script checks the fixed compiler-tool versions before preparing sources.
`Sources.lock.json` is the authoritative version/hash list. Windows automatic
dependency installation is not implemented. A native Windows execution of
this new path is still pending; Linux success is not a Windows build result.

The Rust installation must contain its full copyright notices. If they are
outside its standard documentation directory, pass `-RustCopyrightFile PATH`.
On Debian the script uses the installed Rust standard-library copyright file.

## Build boundaries

`MesaStandalone.patch` only adjusts Mesa's build selection and removes
Linux winsys/DRM hardware-test bindings from the standalone compiler. It
enables the real NIR implementation, never its header-only stub. NAK/NIR
instruction lowering, optimization, register allocation and encoding remain
the original pinned code. NVK, DRM, CLC/LLVM, display stacks and shader disk
caches are not selected. libclang is a host binding generator dependency;
there is no LLVM JIT in R4OS.

The six Rust crates and Mesa archive are verified before extraction. Meson
uses only locally cached sources and is forced to use the pinned Rust crates.
The prepared source tree is checked against a file manifest before reuse.
Original sources, local overlay sources, build products and generated shader
outputs remain separate. All workspace paths come from the script and the
Libraries `Settings.R4S` mappings.

Cache/source trees reside in `DevKit/Toolchains/MesaNAK` and `DevKit/.Cache`.
Outputs default to `Artifacts/Tools/R4NAK/Linux-x64` or `Windows-x64`; use
`-OutputDirectory` to select another location relative to the workspace.
`build.json` records the input recipe, tool versions, output hashes, size and
elapsed time. It is written only after the complete output set succeeds.
The host package includes all original source/license archives and Rust
runtime notices under `Legal`; distribute that directory with the host tool.
Nothing from this directory is automatically installed in an R4OS image.

`-VerifyReproducible` translates each profile twice and requires byte-identical
machine code, metadata, NIR and assembly. It performs no hardware or guest test.
The shader output is a compiler artifact, not a GPU execution result.

## Fixed shader contract

The target is SM86 with 48 maximum resident warps per multiprocessor, matching
the pinned Mesa device-information table. A real renderer must match the GPU
and negotiate its graphics class before using these artifacts. Other shader
models require explicit additional profiles and verification.

| ID | Source profile | Inputs and result |
| --- | --- | --- |
| 1 | Rectangle vertex | Attribute 0: clip-space vec4; 1: normalized UV vec2; 2: premultiplied tint vec4. Writes position and screen-linear UV/tint. |
| 2 | Texture fragment | Samples a 2D texture and multiplies its premultiplied RGBA by the premultiplied tint. |
| 3 | sRGB decode fragment | Unpremultiplies, converts sRGB to linear light, premultiplies and applies the tint. |
| 4 | sRGB encode fragment | Applies a linear-light tint, unpremultiplies, converts to sRGB and premultiplies. |
| 5 | Solid fragment | Writes the interpolated premultiplied tint. |
| 6 | Solid vertex | Uses attributes 0 and 2; writes position/tint without unused UV outputs. Pair with profile 5. |

Profiles 1 and 2–4 share their UV/tint interface. Profile 6 pairs with 5,
so the fixed pipeline does not require disabling out-of-range attribute
exceptions for unused vertex outputs.

Nearest/bilinear filtering is sampler state. Resource ABI2 holds a combined
TIC/TSC word in constant buffer 1 at byte 0 and normalized minU/minV/maxU/maxV
source-texel-center bounds at bytes 16..31. Texture shaders clamp interpolated
UVs to those bounds before sampling, including bilinear crops and one-texel
views. ABI1 cache keys cannot select these programs. The driver builds the
bounds from the retained source image and canonical rectangle; no cropped
texture copy is required. NAK's internal graphics constants use buffer 0:
sample locations at byte 0, masks at byte 16 and an optional
printf pointer at byte 48. These single-sample profiles read none of those
internal constants and contain no printf. Both sRGB conversions preserve
zero-alpha pixels without division by zero; their texture/render views must
avoid a second automatic sRGB transfer.

`Source/shaders.c` is the source of truth. Metadata uses explicit JSON fields;
no host C-structure layout is serialized. Compilation fails on spills, local
scratch or call-stack allocation in these bounded profiles. Generated NAK
assembly is diagnostic text, not external `nvdisasm` output.

## Runtime materialization

After a successful reproducible build, run on either host:

```powershell
pwsh -NoProfile -File Repositories/Libraries/R4NV/Tools/Compiler/EmitRuntime.ps1
```

`-CompilerOutputDirectory` optionally selects a different verified output set.
The emitter checks the current recipe inputs and all recorded code, metadata,
NIR and assembly hashes before replacing generated runtime files. It also
validates the six profiles, target and bounded metadata. Modified headers
are rejected even when the machine-code file itself is unchanged.

The checked-in `Source/Generated/Shaders` files contain only the six programs,
metadata and provenance. R4NV's separate `SHADER_V1` table exposes a bounded,
driver/GPU/compiler/ABI/format/pipeline-state-bound byte cache. The regular
R4NV build consumes these files without running Mesa or a host compiler.
Native allocations and the asynchronous render queue consume the fixed
profiles. The 0.79.19 texture checkpoint includes CPU/f64 reference images
and a separate f32 method/descriptor model. Real SM86 pixel execution and
the dynamic R4OS compiler port remain separate work in 0.79.19/0.79.34.

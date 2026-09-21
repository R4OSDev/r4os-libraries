# Third-Party Notices

This repository vendors the following external material. The named upstream
license applies to that material; Apache License 2.0 applies only to original
R4OS material.

| Unit | Component | Version | License | Local license/provenance |
| --- | --- | --- | --- | --- |
| R4IMG | stb_image | 2.30 | MIT (selected from the upstream MIT/public-domain dual offer) | `R4IMG/ThirdParty/stb/LICENSE-MIT` and `R4IMG/ThirdParty/stb/stb_image.h` |
| R4IMG tests | Web Platform Tests image fixtures | commit 4a5810a124fa0523dd2494996bf1542d4b67f394 | BSD-3-Clause | `R4IMG/Tests/Decoder/Fixtures/LICENSE-WPT-BSD-3-Clause.txt` |
| R4FONT | FreeType | 2.14.3 | FreeType License 1.0 | `R4FONT/ThirdParty/r4font/freetype/FTL.TXT` |
| R4FONT | Google Brotli | 1.2.0 | MIT | `R4FONT/ThirdParty/r4font/brotli/LICENSE` |
| R4FONT | zlib | 1.3.1 | zlib License | `R4FONT/ThirdParty/r4font/ZLIB-LICENSE` |
| R4GFX | LittleCMS ICC core | 2.18 | MIT | `R4GFX/ThirdParty/LittleCMS/LICENSE` and `UPSTREAM.json` |
| R4VIDEO | FFmpeg libavcodec/libavutil H.264 subset | 9.0.1 | LGPL-2.1-or-later; GPL/nonfree disabled | `R4VIDEO/ThirdParty/Sources.json` and `COPYING.LGPLv2.1`; original notices retained in prepared sources |
| Shared native math | Zig stdlib and bundled musl | Zig 0.16.0, exact file hashes pinned | MIT and original per-file permissive notices | `Shared/Native/Math/Sources.json` and `Shared/Native/Math/NOTICES.txt` |
| Shared native numeric/string scanner | Bundled musl, original and adapted units | Zig 0.16.0, exact file hashes pinned | MIT | `Shared/Native/Scan/Sources.json` and `Shared/Native/Scan/NOTICES.txt` |

Exact upstream commits, included paths, local patches, hashes, and verification
commands are recorded in
`R4FONT/ThirdParty/r4font/UPSTREAM.json` and
`R4FONT/ThirdParty/r4font/VENDOR.sha256`.

## Test fixtures

Some R4FONT test fonts originate from Web Platform Tests under BSD-3-Clause or
from Philip Taylor under MIT. R4IMG also contains four byte-for-byte WPT image
fixtures under BSD-3-Clause. Per-file paths, hashes, transformations, and
notices are recorded in `R4FONT/Tests/Fixtures/FIXTURES.json` and
`R4IMG/Tests/Decoder/Fixtures/FIXTURES.json` with their adjacent license
files. Other listed fixtures are original or generated R4OS material.

## R4GFX receiver information

R4GFX color management incorporates the LittleCMS ICC core. Its source files
retain their original notices. The R4OS port supplies caller-owned memory,
memory-only profile I/O, deterministic virtual-profile dates and native
context locking; `R4GFX/ThirdParty/LittleCMS/UPSTREAM.json` identifies the
original source archive and files. CGATS, PostScript utilities and the
optional GPL plugins are excluded. The full MIT notice is installed as
`LITTLECMS-LICENSE.txt`.

The compiled EDID helper includes 154 CTA timing records derived from the
MIT-licensed libdisplay-info table. Receiver tests include its unchanged
QEMU, Hisense 55U8K and Apple XDR EDID fixtures. Copyright (c) 2022 The
libdisplay-info Contributors. Exact hashes, transformations and the MIT
license are in `R4GFX/ThirdParty/DisplayInfo/PROVENANCE.json` and `LICENSE`.
The OssiPC 65U8QF base block is an earlier original R4OS measurement.
The parser implementation itself is original R4OS code; no Linux GPL
implementation has been incorporated.

HF-VSDB SCDC and low-rate scrambling field meanings follow the pinned
libdisplay-info cta.c; its source hash is also recorded in that provenance.

## R4NV command encoding

R4NV/Source/copy.zig contains the existing NVIDIA 570.144 and Nouveau-based CE encoding implementation, now shared with NVIDIA.R4D. Full NVIDIA and Red Hat MIT notices are preserved in the source and R4NV/ThirdParty/Nvidia/LICENSES.txt. No firmware is embedded in R4NV.R4L. The existing distributed NVIDIA-GSP-RUNTIME-LICENSE.txt contains these notices.

## R4NV host shader compiler

`R4NV/Tools/Compiler` builds Mesa 26.2.2 NIR/NAK from its checksum-pinned
original source archive. `MesaStandalone.patch` changes build selection and
the hardware-test binding boundary; the shader compiler implementation keeps
its original per-file notices and licenses. The selected NIR/NAK code is
predominantly MIT; Mesa utility files retain their individual terms. The full
archive and its license directory remain in the host package under `Legal`.

The pinned Rust build dependencies are paste 1.0.14, rustc-hash 2.1.1,
syn 2.0.87, quote 1.0.35, proc-macro2 1.0.86 and unicode-ident 1.0.12.
Their original archives, including their MIT/Apache and Unicode data notices
as applicable, are also included under `Legal/Sources`. Rust 1.85.1 runtime
notices come from the installed matching toolchain and are copied in full.
Exact URLs and source hashes are in `R4NV/Tools/Compiler/Sources.lock.json`.

The R4NV fixed-shader descriptions and host orchestration are original
Apache-2.0 R4OS code. This host compiler package is separate from R4NV.R4L
and is not installed in system images. The runtime library has not acquired
a dependency on Linux, Rust std or the host Mesa binary.

`R4NV/Source/Generated/Shaders` contains compiled output of those original
R4OS shader descriptions, their NVIDIA headers and a provenance manifest.
The runtime embeds seven fixed programs per selected SM75/86/89/120 target; it does not embed the NAK/NIR
compiler implementation. The manifest identifies the compiler recipe and
each original machine-code, metadata, NIR and assembly artifact.

## R4NV generation-specific rendering

`render_image.zig`, `render.zig` and `Generated/Render` derive image/state
fields from the pinned Mesa26.2.2 NVIDIA class headers and MIT NIL/NVK
sources, with NVIDIA570.144 `nvmisc.h` used by the host reference generator.
Full NVIDIA, Collabora and Red Hat notices remain in the derived sources,
`R4NV/ThirdParty/Nvidia/LICENSES.txt` and the distributed NVIDIA GSP runtime
license. The reference archive is `Nvidia/0.79.19/render-state-20260913`.
The seven fixed shaders per target remain compiled original R4OS descriptions.
C597/C797/C997/CD97 state comes from the corresponding original class header;
Tools/RenderState/Generate.ps1 records each source and generated-output hash.
No host compiler is linked into R4OS. Generation evidence: GFX/0.79.33.


## R4NV H.264 NVDEC encoding (0.79.40)

`R4NV/Source/video.zig` derives wire definitions from NVIDIA's MIT
`nvdec_drv.h`, `clc7b0.h` and `clc9b0.h`. Buffer sizing, EOS and reference
marking use the MIT Mesa NVK H.264 implementation at commit
`684c1b339bddbed6f11af93161da1c1bba77edb1`, copyright 2024 Collabora, Ltd
and Red Hat, Inc. Full notices are in `R4NV/ThirdParty/Nvidia/LICENSES.txt`.
`Source/nvdec_h264_vectors.json` identifies every input hash and the independent
C-header fixture generator. Original sources and reproducible evidence are
retained under `ExFiles/Reference/GFX/0.79.40`. No CUDA, CUVID or NVDECODE
runtime is linked. This compiled helper does not itself enable a hardware codec.

## R4GFX YUV color interpretation (0.79.40)

The original R4GFX YUV arithmetic follows ITU-T H.273 (07/2024) and ITU-R
BT.1886-0. The SDR presentation mapping was checked against libplacebo commit
`3330a515d62139259c26239014f286e233bd3a5c`. No libplacebo implementation is
compiled or copied into R4GFX. Unmodified reference documents, source headers,
license, URLs and SHA256 hashes are retained for local study under
`ExFiles/Reference/GFX/0.79.40/YuvSources` in the workspace. Original R4GFX and
fixed NIR shader changes remain Apache-2.0; reference rights remain unchanged.

## R4NV telemetry decoder (0.79.29)

R4NV/Source/telemetry.zig derives the RUSD layout and fixed-point temperature
units from MIT NVIDIA 570.144 cl00de.h and nvfixedtypes.h at commit
8ec351aeb96a93a4bb69ccc12a542bf8a8df2b6f. Complete original notices remain in
the source and R4NV/ThirdParty/Nvidia/LICENSES.txt, and in the distributed
NVIDIA runtime license. The pure decoder is statically used by NVIDIA.R4D;
it adds no firmware binary or external runtime dependency to R4NV.R4L.


## R4NAK native runtime compiler (0.79.34)

R4NAK links a freestanding port of Mesa 26.2.2 SPIR-V/NIR/NAK, selected Mesa
utilities and generated NVIDIA class definitions. Mesa's applicable original
MIT/BSD-style notices remain intact. The source pin and six build-time Rust
crates are shared with `R4NV/Tools/Compiler/Sources.lock.json`.

`R4NAK/Tools/Sources.lock.json` additionally pins official Rust 1.85.1 sources
(core/alloc), compiler_builtins 0.1.140, hashbrown 0.15.2 without optional
features, and stb_sprintf 1.10 at commit
2c980bb59875b0d32144a71867fbdebb2f77cd20. Rust/hashbrown retain their MIT or
Apache-2.0 terms; compiler_builtins includes Apache-2.0 with LLVM exception
and MIT components. stb_sprintf retains its complete MIT/Unlicense text.

`R4NAK/ThirdParty/NOTICES.txt` collects complete original source notices and
licenses; `notices.json` records each source/hash. The byte-identical file is
distributed as `R4OS/LICENSES/R4NAK-NOTICES.txt`. Original source archives and
precise versions/hashes remain in the two locks. No host libc, Rust std,
Linux kernel code, LLVM JIT or GPU firmware is linked into R4NAK.R4L.

The port's runtime adapters, compiler contract, worker, executable cache,
build orchestration and self-authored diagnostic shader remain original
Apache-2.0 R4OS material. Upstream lowering algorithms retain their licenses.


## R4GL native EGL/OpenGL provider (0.79.39, in progress)

R4GL uses the same pinned Mesa 26.2.2 source. Its ordered patches, generator
plan and native unit/flag selection live under `R4GL/Port` and `R4GL/Tools`.
Selected libc++ sources bundled with Zig retain Apache-2.0 WITH LLVM-exception;
their exact hashes are in `R4GL/Tools/CppSources.json`. Original Mesa source
and header notices, the complete Mesa license inventory and LLVM license
are retained in `R4GL/ThirdParty/NOTICES.txt`, with per-file provenance in
`notices.json`. This header/license superset does not claim all components
are linked. Original Khronos EGL/GL/KHR headers in `Bindings/C` retain their
notices and have exact source hashes in `ThirdParty/headers.json`.
Distribution installs the byte-identical bundle as `R4GL-NOTICES.txt`.
Shared native math/scanner notices remain with their existing owners.

## R4VK native Vulkan provider (0.79.35, in progress)

R4VK uses the same checksum-pinned Mesa 26.2.2 source as R4NV/R4NAK.
`R4VK/Tools/Prepare.ps1` verifies that source manifest before copying private
NVK C/header inputs and applying `Port/MesaRuntime.patch`. Original Intel,
Collabora, Red Hat and other Mesa copyright/license notices remain in every
copied file. The original Mesa Vulkan registry, NVK configuration and NIL
format generators produce the port's tables; their output notices are retained.
The generated preparation record identifies the inputs, patch and output hashes.
The native R4VK binary retains the compiler/runtime license bundle and
additional NVK/NIL/Vulkan source notices in R4VK/ThirdParty/NOTICES.txt.
Distribution stages the identical text as R4OS/LICENSES/R4VK-NOTICES.txt.
The native physical-device constructor and memory/queue queries retain the
original Mesa nvk_physical_device.c copyright (2022 Collabora Ltd. and Red Hat
Inc., MIT). Full original source and the patched private copy are archived in
GFX/0.79.35/Evidence/NvkPhysical. Native backend admission and heap descriptions
in Port/nvk_physical.c are original Apache-2.0 code.
The persistent native compiler owner uses the same freestanding Rust NAK
archive and original Rust/Mesa notices listed under R4NAK above. Its private
arena/worker adapter is original Apache-2.0 code; no Rust compiler algorithm
or upstream copyright notice is replaced.

`R4VK/Tools/BuildNil.ps1` compiles the original MIT NIL Rust sources with
their copyright notices retained. Private copies adapt only the freestanding
prelude, native rounding and image-construction error boundary. Original
layout and descriptor calculations remain intact; the native worker and C
result adapters are original Apache-2.0 R4OS material. Rust runtime dependency
notices are the same as those listed under R4NAK above.

The native R4VK formatting adapter uses the existing `R4NAK/ThirdParty/stb/`
copy of stb_sprintf, with its complete MIT/Unlicense text retained there.
Private generated Vulkan entrypoint headers change native ELF visibility only;
their original Mesa notices and non-R4OS visibility remain intact.
The private NVK/common-instance and debug-log changes preserve their original
Collabora/Red Hat/Intel MIT notices. Native option defaults, console transport
and stdio/log adapters are original Apache-2.0 code; formatting continues to
use the licensed stb_sprintf copy above.

The native device-description adapter checks architecture constants against
the pinned `src/nouveau/winsys/nouveau_device.c` and NVIDIA class headers.
Active unit counts, memory sizes and PCI identity are supplied by NVIDIA.R4D;
the adapter does not copy the Linux DRM discovery implementation.

`R4VK/Tools/PrepareShaders.ps1` builds pinned Mesa CLC and its NIR binding
generator as host tools. LLVM/Clang retain their upstream Apache-2.0-with-
LLVM-exception terms; LLVM-SPIRV retains BSD-3-Clause and Expat terms, and
SPIRV-Tools retains Apache-2.0. Host
packages keep their full original notices and are not part of the R4OS image.
The query/indirect-copy OpenCL sources retain Collabora, Red Hat and Valve
MIT notices. Generated SPIR-V/NIR helpers retain Mesa's generated MIT notice.
`MesaGenerators.patch` changes metadata lifetime/export only, preserving shader
algorithms and complete serialized data. No third-party material is relicensed.
## R4VIDEO private NVDEC bridge

`R4VIDEO/Port/nvdec.c` adapts H.264 parameter/reference mapping from FFmpeg's
`libavcodec/nvdec_h264.c` (copyright 2016 Anton Khirnov), under LGPL-2.1-or-later.
Its notice remains in the adapter. `FFmpegNvdec.patch` adds only private
R4VIDEO hardware-format/callback registration; original FFmpeg source notices
remain intact. The adapter uses R4OS worker callbacks, without CUDA/CUVID.

The R4VIDEO GPU owner compiles R4NV's H.264 encoder from `R4NV/Source/video.zig`.
Its NVIDIA/Mesa MIT source attribution and full notices remain in that source,
`R4NV/Source/nvdec_h264_vectors.json` and `R4NV/ThirdParty/Nvidia/LICENSES.txt`.
The R4VIDEO resource, lifetime and public-lease integration is original
Apache-2.0 R4OS code.


## R4ENC / OpenH264

`R4ENC` builds Cisco OpenH264 2.6.0 encoder/common/processing sources and x86
assembly under their original BSD-2-Clause terms. The full source license is
`R4ENC/ThirdParty/OpenH264-LICENSE.txt`; the original archive SHA256 is pinned
in `R4ENC/ThirdParty/Sources.json`. `Port/r4os.patch` adapts the private
freestanding synchronization and clock boundary while preserving notices.
No Cisco binary package or proprietary NVIDIA encoder library is included.
Shared formatting reuses the licensed stb_sprintf copy described above;
shared math retains `Shared/Native/Math/NOTICES.txt`. The R4OS runtime and
codec adapters are original Apache-2.0 material. Distribution stages
`R4ENC-NOTICES.txt` and the full `OpenH264-BSD-2-Clause.txt` source license.

R4NV NVENC status decoding follows NVIDIA open-gpu-doc nvenc_drv.h (MIT).
Original-header fixture provenance is in R4NV/Source/nvenc_status_vectors.json;
the full notice is retained in R4NV/ThirdParty/Nvidia/LICENSES.txt.

## AMD source foundations (0.80.2)

R4AMD and R4ACO preserve selected Mesa 26.2.2 originals under their
`ThirdParty/Mesa26.2.2/Original` directories. `ThirdParty/Sources.json`
records each file hash and license evidence. ACO, NIR, AMD register data,
AddrLib and the selected Mesa utilities use their original MIT notices;
`u_atomic.h` explicitly claims no copyright. Mesa's complete `licenses/`
text collection is retained as context, including texts that do not apply
to the selected code. It does not imply inclusion of GPL implementations.
The BLAKE3 1.8.2 header follows the upstream Apache-2.0 option; its exact
license is in `R4ACO/ThirdParty/Blake3-1.8.2/LICENSE_A2`.

R4AMD's ordered patch disables the unused POSIX signal header in release
AddrLib; originals are unchanged. R4ACO needs no source patch for the selected
translation units. The shared R4OS C/C++ headers and Zig libc++ headers
retain their existing provenance. No unresolved runtime symbol is replaced
by a successful placeholder, and the proof objects are not linked into the
foundation R4Ls yet.

R4VK also preserves the original RADV directory as reference-only material
in `R4VK/ThirdParty/AMDReference`. Its `Sources.json` lists all original
file hashes and the exact Mesa archive. RADV and its Linux winsys are not
compiled or enabled by 0.80.2. R4OS integration is assigned to 0.80.23-25.

## AMD SDMA copy encoder (0.80.10)

R4AMD's pure `Source/copy.zig`, also compiled into AMDGPU, follows Mesa 26.2.2
`src/amd/common/ac_cmdbuf_sdma.c/.h` and `sid.h` (MIT). Unchanged originals,
SHA256 and copyright notices remain in R4AMD/ThirdParty. The port preserves
the full MIT grant and AMD/Valve copyrights. `R4AMD/Tools/ExportLegal.ps1`
exports the original notices and complete MIT text to `R4AMD-NOTICES.txt`,
which is mandatory in the distribution legal plan. AddrLib portability
objects are still separate from this callable Zig SDMA implementation.

## AMD GFX9 PM4 encoder (0.80.11)

R4AMD/Source/pm4.zig derives GC9 command framing/cache/fence behavior from
AMD gfx_v9_0.c/soc15d.h and Mesa 26.2.2 ac_cmdbuf_cp.c/.h. The driver retains
unchanged Linux sources; R4AMD retains unchanged Mesa sources. Full MIT
notices accompany both source catalogs and distribution legal exports.
The new encoder preserves AMD 2012/2016 and Valve 2024 copyright notices.

## AMD linked AddrLib and image descriptors (0.80.12)

R4AMD now links all sixteen original Mesa 26.2.2 AddrLib C++ units and two
R4OS bridges. Earlier portability-only statements describe 0.80.2, not this
runtime. The runtime admits only Picasso GC9.1. The ordered signal.h patch
is applied to a build copy. No original source is modified.

The modifier specialization in images.zig follows ac_surface.c (Red Hat
2011 and AMD 2017, MIT). image_descriptors.cpp follows ac_descriptors.c and
ac_formats.c (AMD 2015, Valve 2024, MIT). Original makeregheader.py/regdb.py
and gfx9.json generate register masks. drm_fourcc.h retains Intel's original
notice. All 69 source identities and license evidence remain in the catalog.
R4AMD-NOTICES.txt now includes all compiled AddrLib/header notices, source
and generator notices and the complete MIT grant. The distribution includes
the same export.

## AMD linked SPIR-V/NIR/ACO compiler (0.80.13)

R4ACO now links 373 original/generated Mesa compiler units, six pinned
Zig-bundled libc++ units, the shared C/C++ runtime, native math/scan and R4OS
adapters. ThirdParty/Sources.json pins 620 original files; Tools/CppSources.json
pins the complete required libc++ selection, including functional.cpp.
These runtime objects replace the earlier 0.80.2 portability-only state.

The ordered Port/Jobs.patch applies to a private build copy. It isolates
allocation-bearing Mesa globals per job, removes environment-selected shader
replacement/disassembly paths and adds bounded ACO cancellation checkpoints.
Original source bytes remain unchanged. Native opcode tables use constexpr
initialization; no dynamic ELF constructor is required. The private new.cpp
header adjustment disables unsupported ELF symbol interposition only.

Mesa files preserve their original permissive notices; BLAKE3 uses the
Apache-2.0 option, libc++ uses Apache-2.0 WITH LLVM-exception, and stb retains
its MIT/public-domain choices. Math/scan retain their existing musl/other
per-file terms. Tools/ExportLegal.ps1 exports original notices and complete
applicable license texts as R4ACO-NOTICES.txt into the distribution.
No Linux DRM binary, LLVM JIT or GPU firmware is linked into R4ACO.R4L.

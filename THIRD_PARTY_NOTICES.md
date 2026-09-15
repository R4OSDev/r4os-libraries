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


## R4NV telemetry decoder (0.79.29)

R4NV/Source/telemetry.zig derives the RUSD layout and fixed-point temperature
units from MIT NVIDIA 570.144 cl00de.h and nvfixedtypes.h at commit
8ec351aeb96a93a4bb69ccc12a542bf8a8df2b6f. Complete original notices remain in
the source and R4NV/ThirdParty/Nvidia/LICENSES.txt, and in the distributed
NVIDIA runtime license. The pure decoder is statically used by NVIDIA.R4D;
it adds no firmware binary or external runtime dependency to R4NV.R4L.

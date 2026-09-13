R4NV Runtime-R4L API
====================

NVIDIA backend command encoding and explicit software/driver protocol pairing. Physical GPU ownership remains in NVIDIA.R4D.

BACKEND_V1
----------

Versioned, allocation-free NVIDIA encoding backend.

- ELF-Symbol: `r4nv_backend_v1`
- ABI-Major: 1
- Revision: 2
- Interface-ID: `0x52344f5330373931:0x52344e5642454e44`
- Tabellengroesse: 56 Byte

- Slot 0, Offset 32: `negotiate` - Validates a driver-supplied profile; reported features describe encoding support, not physical qualification.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..
- Slot 1, Offset 40: `encode_copy` - Encodes virtual CE copies and system-scope semaphore release. Validation precedes every output write.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..
- Slot 2, Offset 48: `encode_copy_layout` - Encodes pitch/blocklinear conversion through C6B5/C7B5, bounded by max_layout_command_words. Original encode_copy and its limits remain available. No retained state or device access.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..

SHADER_V1
---------

Independent fixed-shader metadata and executable byte-cache boundary. BACKEND_V1 remains unchanged; native rendering, GPU memory and compilation are separate owners.

- ELF-Symbol: `r4nv_shader_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x52344f5330373934:0x52344e5653484452`
- Tabellengroesse: 56 Byte

- Slot 0, Offset 32: `shader_info` - Returns metadata for a pinned fixed shader, including the matched solid vertex/fragment pair, without publishing rendering capability.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Bounded pure operation over caller-owned storage. No allocation, I/O, GPU access, retained pointer or compilation. Rejection preserves all outputs..
- Slot 1, Offset 40: `shader_cache_write` - Writes the checked key, compiler identity, original NVIDIA header and machine code with an integrity digest. No compiler work or hardware submission. Output bytes, written count and key must not overlap.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Bounded pure operation over caller-owned storage. No allocation, I/O, GPU access, retained pointer or compilation. Rejection preserves all outputs..
- Slot 2, Offset 48: `shader_cache_read` - Returns a view only after exact key/compiler/layout/length/integrity and fixed-program matching. Incompatible or damaged cache data returns CACHE_MISS with output unchanged. The input key must come from the current driver/renderer, not the cached entry.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Bounded pure operation over caller-owned storage. No allocation, I/O, GPU access, retained pointer or compilation. Rejection preserves all outputs..

Typen
-----

- `R4NvDeviceProfile`: 48 Byte, Alignment 8. Exact live driver binding plus its pinned command/firmware profile.
- `R4NvFeatures`: 48 Byte, Alignment 8. Actual encoder limits; no rendering or hardware validation claim.
- `R4NvCopy`: 64 Byte, Alignment 8. GPU virtual operands supplied by the owning driver. Zero rows denotes a linear transfer; otherwise bytes per row.
- `R4NvDriverProfile`: 32 Byte, Alignment 4. Immutable driver protocol payload in GfxBackendProfile.data. Version 1, size 32, vendor 0x10de and actual allocated copy-engine class; reserved fields zero. Identity/revision are BACKEND_V1. Kernel-assigned adapter and generations come from the accompanying binding, never these bytes.
- `R4NvCopyBlock`: 24 Byte, Alignment 4. Optional 2D blocklinear plane. enabled is zero or one; all other fields zero when disabled. Width/pitch and x are bytes with remapping disabled; height/y are rows. 512-byte GOBs, one GOB wide, log2_gobs 0..5, depth one, no compression.
- `R4NvCopyLayout`: 112 Byte, Alignment 8. Independent copy-layout request; original R4NvCopy remains unchanged. Block operands are plane-base addresses aligned to 512; pitched operands already include logical x/y offsets. Both full plane spans and all transfer bounds must fit; aliases are rejected before command writes.
- `R4NvDigest`: 32 Byte, Alignment 8. 32-byte identity; each word is the little-endian value of eight consecutive digest bytes. No pointer or padding.
- `R4NvShaderKey`: 120 Byte, Alignment 8. Version1 exact-size key from the actual driver/renderer. Nonzero artifact-version token, device identity, input/output format and complete pipeline-state digest. Only SM86/AMPERE_B is supported. Keys contain no GPU addresses or live resource handles; GPU allocations still require current-generation binding by the renderer.
- `R4NvShaderInfo`: 88 Byte, Alignment 8. Fixed shader metadata and source/toolchain identity. Stage0 is vertex; stage4 is fragment. Header is128 little-endian bytes; code is SM86 machine code. Encoding support is not GPU qualification.
- `R4NvShaderView`: 104 Byte, Alignment 8. Borrowed byte ranges inside the caller-owned immutable cache input. Keep that storage alive until the renderer has copied/uploaded both ranges. Addresses have byte alignment and must not be cast to aligned u32 pointers without checking. No pointer is retained by the library.

Besitzregeln
------------

- hardware: The library creates command words only. NVIDIA.R4D validates mappings, current generation, channel state and completion; only that driver submits or frees GPU resources.
- outputs: Inputs are immutable for the call. Output commands and written count must be separate from each other and request metadata. Rejection leaves both outputs unchanged.
- version: BACKEND_V1 is independent of R4GFX and the platform ABI. Optional consumers validate the library header and negotiate the actual driver profile; absent/incompatible backends keep software available.
- shader_cache: Immutable byte caches bind exact driver/GPU/compiler/ABI/format/pipeline identities. No executable GPU address survives in a cache. Renderer-owned native shader/pipeline allocations must be recreated or validated after device/reset generation changes.

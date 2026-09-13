R4NV Runtime-R4L API
====================

NVIDIA backend command encoding and explicit software/driver protocol pairing. Physical GPU ownership remains in NVIDIA.R4D.

BACKEND_V1
----------

Versioned, allocation-free NVIDIA encoding backend.

- ELF-Symbol: `r4nv_backend_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x52344f5330373931:0x52344e5642454e44`
- Tabellengroesse: 48 Byte

- Slot 0, Offset 32: `negotiate` - Validates a driver-supplied profile; reported features describe encoding support, not physical qualification.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..
- Slot 1, Offset 40: `encode_copy` - Encodes virtual CE copies and system-scope semaphore release. Validation precedes every output write.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4NV_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..

Typen
-----

- `R4NvDeviceProfile`: 48 Byte, Alignment 8. Exact live driver binding plus its pinned command/firmware profile.
- `R4NvFeatures`: 48 Byte, Alignment 8. Actual encoder limits; no rendering or hardware validation claim.
- `R4NvCopy`: 64 Byte, Alignment 8. GPU virtual operands supplied by the owning driver. Zero rows denotes a linear transfer; otherwise bytes per row.
- `R4NvDriverProfile`: 32 Byte, Alignment 4. Immutable driver protocol payload in GfxBackendProfile.data. Version 1, size 32, vendor 0x10de and actual allocated copy-engine class; reserved fields zero. Identity/revision are BACKEND_V1. Kernel-assigned adapter and generations come from the accompanying binding, never these bytes.

Besitzregeln
------------

- hardware: The library creates command words only. NVIDIA.R4D validates mappings, current generation, channel state and completion; only that driver submits or frees GPU resources.
- outputs: Inputs are immutable for the call. Output commands and written count must be separate from each other and request metadata. Rejection leaves both outputs unchanged.
- version: BACKEND_V1 is independent of R4GFX and the platform ABI. Optional consumers validate the library header and negotiate the actual driver profile; absent/incompatible backends keep software available.

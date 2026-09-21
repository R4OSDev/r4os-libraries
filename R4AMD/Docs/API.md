R4AMD Runtime-R4L API
=====================

AMD command encoding and rendering/media library. Only AMDGPU owns hardware; encoder capabilities are intersected with the active common backend.

INFO_V1
-------

Independent immutable library identity, append-only interface.

- ELF-Symbol: `r4amd_info_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x52344f53:0x414d4431`
- Tabellengroesse: 40 Byte

- Slot 0, Offset 32: `get_info` - Return source/build identity. Zero capabilities is deliberate until real implementation; source compatibility is not device admission.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: No retained memory, allocation, hardware access or shared mutable state..

BACKEND_V1
----------

AMD-only negotiation; separate from NVIDIA BACKEND_V1 even if individual payload sizes coincide.

- ELF-Symbol: `r4amd_backend_v1`
- ABI-Major: 1
- Revision: 2
- Interface-ID: `0x52344f53:0x414d4432`
- Tabellengroesse: 56 Byte

- Slot 0, Offset 32: `negotiate` - Validate the AMD-specific versioned protocol and report only implemented command capabilities. Zero features is a valid foundation result; it cannot select an accelerated provider.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure bounded negotiation; no device access, allocations or pointers retained..
- Slot 1, Offset 40: `encode_copy` - Bounded SDMA4.1 packets into disjoint caller memory; failure changes neither commands nor written count. No fence or device access is implied.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..
- Slot 2, Offset 48: `encode_fill` - Bounded SDMA4.1 packets into disjoint caller memory; failure changes neither commands nor written count. No fence or device access is implied.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..

Typen
-----

- `R4AmdInfo`: 32 Byte, Alignment 4. Fixed ABI1 source/build identity, not a measured hardware profile.
- `R4AmdDriverProfile`: 32 Byte, Alignment 4. Opaque AMD payload in common GfxBackendProfile; tagged by this BACKEND_V1 interface ID, profile revision 1.
- `R4AmdDeviceProfile`: 56 Byte, Alignment 8. Negotiation binds an AMD IP/command profile to one common device/reset epoch; memory generation remains a separate common owner field.
- `R4AmdFeatures`: 32 Byte, Alignment 4. A compatible profile is not an active GPU: effective operations are the intersection with actual common driver capabilities.
- `R4AmdCopy`: 72 Byte, Alignment 8. Fixed SDMA4.1 request; all reserved fields and unsupported modifiers must be zero. Validation precedes output writes.
- `R4AmdFill`: 32 Byte, Alignment 8. Fixed SDMA4.1 request; all reserved fields and unsupported modifiers must be zero. Validation precedes output writes.

Besitzregeln
------------

- hardware: Only AMDGPU.R4D owns hardware. The foundation interface touches no device.
- provider: Table pointers live for the loaded provider generation. No pointer is retained from the caller.

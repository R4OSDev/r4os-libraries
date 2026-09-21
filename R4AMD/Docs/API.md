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
- Revision: 3
- Interface-ID: `0x52344f53:0x414d4432`
- Tabellengroesse: 64 Byte

- Slot 0, Offset 32: `negotiate` - Validate the AMD-specific versioned protocol and report only implemented command capabilities. Zero features is a valid foundation result; it cannot select an accelerated provider.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure bounded negotiation; no device access, allocations or pointers retained..
- Slot 1, Offset 40: `encode_copy` - Bounded SDMA4.1 packets into disjoint caller memory; failure changes neither commands nor written count. No fence or device access is implied.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..
- Slot 2, Offset 48: `encode_fill` - Bounded SDMA4.1 packets into disjoint caller memory; failure changes neither commands nor written count. No fence or device access is implied.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..
- Slot 3, Offset 56: `encode_pm4_frame` - Emit 48 graphics or 32 compute PM4 dwords; disjoint buffers and all fields are validated before output writes. No allocation, retention, submission or hardware access.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Pure encoding into caller-owned output. No allocation, hardware access or retained pointers..

IMAGE_V1
--------

GFX9 source-backed image layout and immutable provider descriptors, separate from active driver operations.

- ELF-Symbol: `r4amd_image_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x52344f53:0x414d4433`
- Tabellengroesse: 72 Byte

- Slot 0, Offset 32: `calculate` - Calculate real GFX9 Addr2 surface and mip geometry. Outputs unchanged on failure; scratch may change. At most64KB scratch,15mips,64MB image. No retained allocations.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Caller-owned disjoint inputs, outputs and 16-byte-aligned workspace. No heap, globals, hardware I/O or retained pointers. Do not reuse workspace concurrently..
- Slot 1, Offset 40: `address` - Actual Addr2 coordinate calculation including tiled/mip/MSAA addressing.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Caller-owned disjoint inputs, outputs and 16-byte-aligned workspace. No heap, globals, hardware I/O or retained pointers. Do not reuse workspace concurrently..
- Slot 2, Offset 48: `metadata` - Reference-only DCC/HTILE geometry from Addr2. Never enables compression or accepts unknown metadata states.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Caller-owned disjoint inputs, outputs and 16-byte-aligned workspace. No heap, globals, hardware I/O or retained pointers. Do not reuse workspace concurrently..
- Slot 3, Offset 56: `import_image` - Recompute and validate BO import. Exact modifier/topology/epoch; insufficient or misaligned backing rejected. No BO retain or mapping: owner must retain it separately.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Caller-owned disjoint inputs, outputs and 16-byte-aligned workspace. No heap, globals, hardware I/O or retained pointers. Do not reuse workspace concurrently..
- Slot 4, Offset 64: `descriptors` - Recompute image layout before building uncompressed GFX9 texture/sampler/color resource descriptors; no caller-forged internal layout.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4AMD_STATUS`; Besitz: Caller-owned disjoint inputs, outputs and 16-byte-aligned workspace. No heap, globals, hardware I/O or retained pointers. Do not reuse workspace concurrently..

Typen
-----

- `R4AmdInfo`: 32 Byte, Alignment 4. Fixed ABI1 source/build identity, not a measured hardware profile.
- `R4AmdDriverProfile`: 32 Byte, Alignment 4. Opaque AMD payload in common GfxBackendProfile; tagged by this BACKEND_V1 interface ID, profile revision 1.
- `R4AmdDeviceProfile`: 56 Byte, Alignment 8. Negotiation binds an AMD IP/command profile to one common device/reset epoch; memory generation remains a separate common owner field.
- `R4AmdFeatures`: 32 Byte, Alignment 4. A compatible profile is not an active GPU: effective operations are the intersection with actual common driver capabilities.
- `R4AmdCopy`: 72 Byte, Alignment 8. Fixed SDMA4.1 request; all reserved fields and unsupported modifiers must be zero. Validation precedes output writes.
- `R4AmdFill`: 32 Byte, Alignment 8. Fixed SDMA4.1 request; all reserved fields and unsupported modifiers must be zero. Validation precedes output writes.
- `R4AmdPm4Frame`: 64 Byte, Alignment 8. Bounded GC9.1 outer ring frame: HDP, pipeline/cache barriers, VMID1 IB, EOP workaround and exact 64-bit fence. No device completion or shader/API capability is implied.
- `R4AmdImageRequest`: 80 Byte, Alignment 8. Immutable GFX9 image request. Measured GB_ADDR_CONFIG and external ASIC revision, never PCI revision. Dimensions <=16384, mips<=15, samples1/2/4/8, 64MB owner bound. No compression state is accepted.
- `R4AmdImageLayout`: 104 Byte, Alignment 8. Stable derived surface description. Pitch is bytes; mip records distinguish elements/pixels and macro-block/tail positions. No upstream pointers or C++ layouts cross the interface.
- `R4AmdMip`: 64 Byte, Alignment 8. One AddrLib mip record; pitch in elements. Caller supplies at most15 records.
- `R4AmdCoordinate`: 32 Byte, Alignment 4. Coordinates in format elements; bounded to the selected logical mip/slice/sample.
- `R4AmdImageAddress`: 24 Byte, Alignment 8. Actual coordinate-to-byte result.
- `R4AmdMetadata`: 72 Byte, Alignment 8. Reference-only DCC or HTILE geometry. Flags stay zero: transitions/initialization are not enabled and this is not a usable compressed image.
- `R4AmdImageImport`: 80 Byte, Alignment 8. Import from the common BO descriptor. Metadata state must be zero; adapter/epoch, alignment, offset, pitch, size and modifier must exactly support the derived image.
- `R4AmdImageView`: 96 Byte, Alignment 8. GFX9 texture/sampler and color target descriptor request. Caller retains VA/backing through the associated queue fence. Uncompressed views only; no command submission.
- `R4AmdImageDescriptors`: 120 Byte, Alignment 4. GFX9 source-derived resource words; color words ordered as documented in the API. Immutable data, no live rendering capability.
- `R4AmdArchitecture`: 64 Byte, Alignment 8. Measured AMD image profile in common backend properties (IMAGE_V1 identity, revision1). Flags/reserved zero; describes geometry, not render/present capability. ASIC revision is external, not PCI revision.

Besitzregeln
------------

- hardware: Only AMDGPU.R4D owns hardware. The foundation interface touches no device.
- provider: Table pointers live for the loaded provider generation. No pointer is retained from the caller.

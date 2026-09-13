R4GFX Runtime-R4L API
=====================

Userland-Grafikbibliothek: gepruefte lineare Layouts und Softwarezugriff auf caller-eigene CPU-Maps des gemeinsamen BO-Vertrags.

API_V1
------

Unabhaengiger R4GFX V1-Laufzeitvertrag.

- ELF-Symbol: `r4gfx_api_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x35393730:0x34584647`
- Tabellengroesse: 48 Byte

- Slot 0, Offset 32: `linear_layout` - Berechnet lineare XRGB8888-, ARGB8888- oder R8-Layouts mit gepruefter 64-Bit-Groesse.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Keine Allokation; Caller haelt die CPU-Map fuer den gesamten Aufruf..
- Slot 1, Offset 40: `fill_rect` - Validiert Bildspanne und Rechteck vor dem ersten Schreibzugriff; beruehrt kein Zeilenpadding.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Keine Allokation; Caller haelt die CPU-Map fuer den gesamten Aufruf..

RENDER_V1
---------

Independent bounded CPU 2D execution table. Existing API_V1 remains byte-for-byte compatible.

- ELF-Symbol: `r4gfx_render_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x52344f5352474658:0x52454e4445523147`
- Tabellengroesse: 48 Byte

- Slot 0, Offset 32: `capabilities` - Report the actual bounded software profile.
  Semantik: nonblocking, caller_serialized, reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Synchronous bounded CPU work; caller holds read/write maps and immutable input metadata. No allocation, I/O, wait, retained pointer or service hop..
- Slot 1, Offset 40: `execute_cpu` - Validate the complete ordered batch before the first pixel write, then execute fill, scaled blit and premultiplied source-over.
  Semantik: nonblocking, caller_serialized, reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Synchronous bounded CPU work; caller holds read/write maps and immutable input metadata. No allocation, I/O, wait, retained pointer or service hop..

DEVICE_V1
---------

Bounded per-caller graphics devices, resources and asynchronous copy lifetime. Independent of existing API_V1 and RENDER_V1.

- ELF-Symbol: `r4gfx_device_v1`
- ABI-Major: 1
- Revision: 3
- Interface-ID: `0x52344f5330373931:0x5234474658444556`
- Tabellengroesse: 160 Byte

- Slot 0, Offset 32: `storage_size` - Required zeroed caller storage bytes, aligned to 8; allocation occurs once outside the library.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 1, Offset 40: `device_open` - Initializes caller storage and negotiates an optional backend; software fallback remains available.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 2, Offset 48: `device_close` - Retryable close: cancel jobs, release only retired resources, retain unresolved backing; success invalidates the device handle.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 3, Offset 56: `device_info` - Reports the currently selected backend, feature limits and actual work counters.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 4, Offset 64: `device_refresh` - Revalidates the live backend binding, discards stale GPU state and preserves source resources.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 5, Offset 72: `resource_create` - Creates an image/sampler/pipeline resource. Repeated immutable source generations retain the existing import. Native creation may wait on the existing kernel allocation request outside frame execution. Failure leaves caller output unchanged; pending close failures remain tracked until device cleanup.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 6, Offset 80: `resource_retain` - Adds one logical resource reference without copying pixels or reimporting a BO.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 7, Offset 88: `resource_release` - Drops one logical reference; jobs independently retain their source and target until physical retirement.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 8, Offset 96: `resource_info` - Returns source provenance without borrowing a new CPU map.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 9, Offset 104: `render` - Resolves the complete bounded scene, maps each image once, validates all commands, renders and releases the CPU maps.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 10, Offset 112: `copy_submit` - Submits one ordered BO copy and retains both resources until actual fence retirement.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 11, Offset 120: `job_info` - Reads canonical completion and physical resource-retirement state without waiting.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 12, Offset 128: `job_cancel` - Requests cancellation; does not claim GPU quiescence or release referenced resources.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 13, Offset 136: `job_release` - Releases a retired fence and its resource references; returns busy while physical use remains.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 14, Offset 144: `copy_submit_ex` - Submits checked rows or linear bytes with exact upstream fences, preserving resources through physical completion. Different strides and native layouts use the common negotiated transport; unsupported opaque layouts never fall back to CPU address guessing.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..
- Slot 15, Offset 152: `job_fence` - Exports the exact canonical fence for dependencies without waiting. Job and backing remain owned by their original receipts; exporting neither completes nor releases work.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GFX_STATUS`; Besitz: Caller owns device storage and serializes all calls for it. Resource references and real queue fences define retained backing lifetime. Outputs never alias device storage or inputs..

Typen
-----

- `R4GfxLinearLayout`: 32 Byte, Alignment 8. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxCpuImage`: 40 Byte, Alignment 8. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxRect`: 16 Byte, Alignment 4. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxRenderCaps`: 48 Byte, Alignment 8. Fixed capability snapshot; no GPU or native display claim.
- `R4GfxCpuDraw`: 64 Byte, Alignment 4. Fixed ordered 2D command. Equal-size same-view blit supports memmove; other source/target aliases are rejected.
- `R4GfxCpuBatch`: 40 Byte, Alignment 8. Synchronous caller-owned batch. All metadata and CPU maps stay valid and exclusively bound until return; no allocation or retained pointer.
- `R4GfxCpuStats`: 32 Byte, Alignment 8. Only written after successful validation and execution; rejected batches preserve output and image bytes.
- `R4GfxDevice`: 16 Byte, Alignment 8. Caller-owned storage identity. Memory stays valid through successful close; first allocation must be zeroed. Reopening the same retained storage advances its generation.
- `R4GfxDeviceConfig`: 40 Byte, Alignment 8. Version 1; storage_size bytes aligned to 8, borrowed R4XStartContext for this caller. Preferred adapter zero selects automatically. software_only prevents native selection. Storage and outputs must not overlap input/start metadata.
- `R4GfxDeviceInfo`: 120 Byte, Alignment 8. Software render capabilities and separately negotiated native copy capabilities. Counters are actual work; direct imports do not count as uploads. Refresh changes GPU identity only, preserving portable sources.
- `R4GfxResource`: 32 Byte, Alignment 8. Opaque, nonwrapping resource identity local to one device storage generation. Retain/release are explicit; jobs hold independent internal references.
- `R4GfxResourceDesc`: 88 Byte, Alignment 8. Image, immutable sampler or 2D pipeline. Image source is a new system BO, pointer to canonical GfxBufferHandle, pointer to GuiSharedRasterLease, or explicitly borrowed CPU image. Image target flag permits writes; immutable rasters cannot be targets. Import forms derive image geometry from the canonical BO. Borrowed CPU bytes remain valid while any reference/job exists. Unused fields are zero. Native source4 instead points to R4GfxNativeImage with explicit deadline and requested layout; unused CPU image/source-generation fields stay zero.
- `R4GfxResourceInfo`: 112 Byte, Alignment 8. Source provenance and current logical reference count. Image addresses are exposed only for explicitly borrowed CPU sources; BO CPU mapping remains internal and transient.
- `R4GfxDraw`: 168 Byte, Alignment 8. Ordered 2D operation through immutable pipeline and sampler resources. Fill uses zero source/sampler/source_rect/opacity. Blit uses opacity 255; over uses premultiplied alpha.
- `R4GfxRenderBatch`: 24 Byte, Alignment 8. Borrowed array of R4GfxDraw. Reuses RENDER_V1 limits and all-before-write validation. No service IPC per draw; unavailable native operations use the shared CPU renderer.
- `R4GfxRenderStats`: 40 Byte, Alignment 8. Actual execution backend and byte counts. fallback is one only when the selected native device used software for unsupported drawing features.
- `R4GfxCopyRequest`: 96 Byte, Alignment 8. Asynchronous whole-range BO copy on the selected common queue. Borrowed CPU pointers are never submitted as GPU addresses. Serial queue ordering applies; explicit deadline uses the platform monotonic clock.
- `R4GfxJob`: 32 Byte, Alignment 8. Device-local copy-job identity. A terminal logical result is independent of physical resource retirement. Release requires actual resources_released.
- `R4GfxJobInfo`: 56 Byte, Alignment 8. Canonical queue phase/result/flags, including device_active/resources_held, and original fence identity. Backend reports where the job ran; a software completion is not a GPU completion.
- `R4GfxCopyFence`: 40 Byte, Alignment 8. Exact common GfxFence wire identity. Export adds no reference: keep the job until a dependency has been admitted. Canonical admission retains its own dependency; copying numbers alone never proves completion.
- `R4GfxCopyRequestEx`: 136 Byte, Alignment 8. Version1 exact-size input. Zero rows is a linear copy and requires zero pitches; otherwise copy.byte_length is bytes per row. Up to eight borrowed R4GfxCopyFence dependencies, zero address for zero count. The complete descriptor and identities are captured before admission; no pointer survives the call.
- `R4GfxNativeImage`: 32 Byte, Alignment 8. Copied native image allocation intent for source_create_native. source_address points to this payload; source_generation and ResourceDesc.image remain zero. The selected native adapter and memory generation bind allocation. Returned resource information exposes the actual pitch and byte length.

Besitzregeln
------------

- CPU-Map: fill_rect borgt nur die CPU-Adresse waehrend des Aufrufs. Der Caller haelt eine exklusive CPU-Schreibmap des gemeinsamen R4DRAW-BO-Vertrags und fuehrt danach unmap aus. Keine verborgene Kopie, GPU-Adresse oder VRAM-Lesung.
- Layout: Lineares RAM-Bild. Andere Modifier, GPU-Seitentabellen, Speicherallokation und Scanout bleiben bei ihren Besitzern.
- RENDER_V1 maps: R4GfxCpuImage addresses are caller-owned readable/writable CPU maps, never physical or GPU addresses. The caller holds exclusive target access, read access to sources, and immutable metadata until return. Different virtual mappings of the same backing must not be presented as independent images.
- RENDER_V1 execution: Commands execute in order with an explicit total-pixel budget. Whole rectangles must already be clipped by the caller. Images and output may not alias metadata. Complete validation precedes every write; no hidden frame copy, allocation, thread or graphics service.
- RENDER_V1 colors: Source-over uses premultiplied ARGB8888 and integer rounding; XRGB is opaque with zero stored padding byte. Blit converts XRGB/ARGB and scales with pixel-center nearest or bilinear filtering clamped to the source rectangle. R8 supports fill/blit, not source-over. Color space conversion remains a separate stage.
- device_storage: DEVICE_V1 storage belongs to one serialized caller. Keep its allocation, start context and imported R4Ls alive through successful device_close. No R4L-global allocator or context. Library outputs and original batch metadata never alias writable image bytes or internal storage.
- resource_retirement: Logical release and device change never prove GPU quiescence. Jobs retain their exact canonical fences and BO sources until actual resource retirement. Portable CPU/immutable raster sources remain reconstructable after backend reset. Driver mapping caches may retain bounded backing until confirmed eviction.

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

Typen
-----

- `R4GfxLinearLayout`: 32 Byte, Alignment 8. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxCpuImage`: 40 Byte, Alignment 8. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxRect`: 16 Byte, Alignment 4. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxRenderCaps`: 48 Byte, Alignment 8. Fixed capability snapshot; no GPU or native display claim.
- `R4GfxCpuDraw`: 64 Byte, Alignment 4. Fixed ordered 2D command. Equal-size same-view blit supports memmove; other source/target aliases are rejected.
- `R4GfxCpuBatch`: 40 Byte, Alignment 8. Synchronous caller-owned batch. All metadata and CPU maps stay valid and exclusively bound until return; no allocation or retained pointer.
- `R4GfxCpuStats`: 32 Byte, Alignment 8. Only written after successful validation and execution; rejected batches preserve output and image bytes.

Besitzregeln
------------

- CPU-Map: fill_rect borgt nur die CPU-Adresse waehrend des Aufrufs. Der Caller haelt eine exklusive CPU-Schreibmap des gemeinsamen R4DRAW-BO-Vertrags und fuehrt danach unmap aus. Keine verborgene Kopie, GPU-Adresse oder VRAM-Lesung.
- Layout: Lineares RAM-Bild. Andere Modifier, GPU-Seitentabellen, Speicherallokation und Scanout bleiben bei ihren Besitzern.
- RENDER_V1 maps: R4GfxCpuImage addresses are caller-owned readable/writable CPU maps, never physical or GPU addresses. The caller holds exclusive target access, read access to sources, and immutable metadata until return. Different virtual mappings of the same backing must not be presented as independent images.
- RENDER_V1 execution: Commands execute in order with an explicit total-pixel budget. Whole rectangles must already be clipped by the caller. Images and output may not alias metadata. Complete validation precedes every write; no hidden frame copy, allocation, thread or graphics service.
- RENDER_V1 colors: Source-over uses premultiplied ARGB8888 and integer rounding; XRGB is opaque with zero stored padding byte. Blit converts XRGB/ARGB and scales with pixel-center nearest or bilinear filtering clamped to the source rectangle. R8 supports fill/blit, not source-over. Color space conversion remains a separate stage.

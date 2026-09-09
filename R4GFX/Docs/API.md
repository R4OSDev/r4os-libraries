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

Typen
-----

- `R4GfxLinearLayout`: 32 Byte, Alignment 8. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxCpuImage`: 40 Byte, Alignment 8. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.
- `R4GfxRect`: 16 Byte, Alignment 4. Feste V1-Payload. Adressen sind ausschliesslich CPU-Maps.

Besitzregeln
------------

- CPU-Map: fill_rect borgt nur die CPU-Adresse waehrend des Aufrufs. Der Caller haelt eine exklusive CPU-Schreibmap des gemeinsamen R4DRAW-BO-Vertrags und fuehrt danach unmap aus. Keine verborgene Kopie, GPU-Adresse oder VRAM-Lesung.
- Layout: Lineares RAM-Bild. Andere Modifier, GPU-Seitentabellen, Speicherallokation und Scanout bleiben bei ihren Besitzern.

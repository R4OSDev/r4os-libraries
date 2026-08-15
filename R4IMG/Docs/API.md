R4IMG Runtime-R4L API
=====================

Unabhaengige Runtime-R4L fuer begrenztes PNG-, JPEG-, BMP- und SVG-Decoding sowie ARGB-Skalierung.

API_V1
------

Append-only V1-Tabelle fuer Bildprobe, Decoding, SVG-Rendering, Skalierung und Diagnose.

- ELF-Symbol: `r4img_api_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x315346a3a7ea4152:0x5233f7f0fb63b451`
- Tabellengroesse: 80 Byte

- Slot 0, Offset 32: `probe` - Erkennt Format und begrenzte intrinsische Dimensionen ohne Pixeldecoding.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4IMG_STATUS`; Besitz: Alle Pointer werden nur waehrend des Aufrufs verwendet..
- Slot 1, Offset 40: `scratch_bytes` - Berechnet die konservative Scratchobergrenze fuer einen Decodeaufruf.
  Semantik: nonblocking, thread_safe, reentrant; Fehlerdomaene `R4IMG_STATUS`; Besitz: Die Funktion allokiert und behaelt keinen Speicher..
- Slot 2, Offset 48: `decode` - Decodiert PNG, JPEG, BMP oder SVG in ARGB; SVG nutzt dabei Standardoptionen.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4IMG_STATUS`; Besitz: Eingabe, Pixel und Scratch bleiben caller-owned; die Library behaelt keinen Pointer..
- Slot 3, Offset 56: `decode_svg_at` - Rendert SVG in frei waehlbare begrenzte Zieldimensionen und ruft optionale C-ABI-Callbacks auf.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4IMG_STATUS`; Besitz: Alle Buffer und Callbackkontexte bleiben caller-owned und gelten nur fuer den Aufruf..
- Slot 4, Offset 64: `scale_composite` - Skaliert bilinear und komponiert Alpha gegen einen RGB-Hintergrund.
  Semantik: may_block, thread_safe, reentrant; Fehlerdomaene `R4IMG_STATUS`; Besitz: Quell- und Zielpuffer bleiben vollstaendig caller-owned..
- Slot 5, Offset 72: `decoder_diagnostic` - Liefert Scratch-Spitze und Allokationsfehler des letzten STB-Decodes.
  Semantik: nonblocking, caller_serialized, not_reentrant; Fehlerdomaene `R4IMG_STATUS`; Besitz: Die Ausgabe wird kopiert; es wird kein Pointer behalten..

Typen
-----

- `R4ImgInfo`: 16 Byte, Alignment 4. Festes Bildmetadatenlayout der V1-ABI.
- `R4ImgSvgOptions`: 56 Byte, Alignment 8. Festes Optionslayout; Callbacks und Kontexte gelten nur waehrend decode_svg_at.
- `R4ImgDecoderDiagnostic`: 16 Byte, Alignment 8. Festes Diagnoseergebnis der V1-ABI.

Besitzregeln
------------

- Caller-owned Buffer: Codierte Daten, Pixelpuffer und Scratchspeicher bleiben beim Caller; R4IMG verwendet sie nur waehrend des Aufrufs und allokiert nie ueber die ABI.
- Callback-Lebensdauer: SVG-Callbackadressen und ihre Kontexte muessen nur bis zur Rueckkehr von decode_svg_at gueltig bleiben und werden nicht gespeichert.
- Providergeneration: Die API-Tabelle und ihre Funktionspointer bleiben bis zum Ende der geladenen R4IMG-Providergeneration gueltig.
- Serialisierung: Rasterdecode und Decoderdiagnose muessen vom Caller serialisiert werden, weil der eingebettete STB-Adapter eine providerlokale Scratchdiagnose fuehrt.

R4FONT.R4L
============

R4FONT ist eine unabhaengige Runtime-R4L fuer validierte Schriftquellen. Sie
exportiert die versionierte Funktionstabelle `API_V1:1`; Implementierung,
Contract, Baseline, Zig-/C-Bindings sowie FreeType und Brotli liegen
vollstaendig in dieser Library-Einheit. Das Kern-SDK kennt keine
R4FONT-Typen oder Decoderquellen.

Unterstuetzt werden TTF, OpenType/CFF, WOFF, WOFF2 und SFNT-Collections mit
CMAP, Metriken, Kerning und deterministischer Alpha8-Rasterung. Quelle,
Decoderzustand, Rasterpuffer und alle Rekonstruktionsallokationen gehoeren
dem aufrufenden Prozess. Weder Kernel noch R4DRAW enthalten Parsercode oder
speichern dekodierte Webfonts.

Verbraucher deklarieren `IMPORT=R4FONT:API_V1:1` und binden
`Bindings/Zig/r4font.zig` beziehungsweise `Bindings/C/r4font.h` ein. Die
erzeugte Referenz steht in `Docs/API.md`; `zig build test` prueft Contract,
Provider, Decoder, FaceStore und echte Zig-/C-Verbraucher.

Build:

    Build.bat R4FONT test

Vendor- und Fixture-Provenienz lassen sich zusaetzlich aus dem
Repository-Root pruefen:

    python R4FONT/ThirdParty/r4font/Tools/verify_vendor.py --check
    python R4FONT/Tests/Tools/generate_minimal_fonts.py --check

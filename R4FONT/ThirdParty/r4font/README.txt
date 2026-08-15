R4FONT Drittanbieterbasis
===========================

R4FONT verwendet drei fest gepinnte Upstream-Bestandteile: FreeType, Brotli
und den von FreeType eingebetteten zlib-Teilbestand. `UPSTREAM.json` ist die
maschinenlesbare Herkunfts-, Versions-, Lizenz- und Patchwahrheit.

FreeType
--------

- Version: 2.14.3
- Kanonischer Upstream: https://gitlab.freedesktop.org/freetype/freetype.git
- Spiegel: https://github.com/freetype/freetype.git
- Tag: VER-2-14-3
- Annotiertes Tag-Objekt: c740f0fda4274d6ffd2e5b64a25b06ef69803a07
- Aufgeloester Quell-Commit: 0a0221a1347e2f1e07c395263540026e9a0aa7c7
- Lizenz: FreeType License oder GPLv2; R4OS verwendet die FreeType License.
- Lizenztexte: freetype/LICENSE.TXT, freetype/FTL.TXT,
  freetype/GPLv2.TXT

Der gepinnte Baum ist auf die in `UPSTREAM.json` aufgefuehrten Verzeichnisse
begrenzt. Der einzige R4OS-Patch liegt als
`Patches/freetype-2.14.3-r4font.patch` vor. Er gilt fuer den aufgeloesten
Quell-Commit, hat einen festgehaltenen Vorher-/Nachher-Hash und wird mit
deaktivierter Zeilenendenkonvertierung angewendet.

Brotli
------

- Version: 1.2.0
- Upstream: https://github.com/google/brotli
- Tag: v1.2.0
- Commit: 028fb5a23661f123017c060daa546b55cf4bde29
- Lizenz: MIT
- Lizenztext: brotli/LICENSE

Brotli wird ausschliesslich als begrenzter WOFF2-Decoder kompiliert.

zlib
----

- Version: 1.3.1, als Teilbestand des gepinnten FreeType-Baums
- Upstream: https://github.com/madler/zlib.git
- Tag: v1.3.1
- Annotiertes Tag-Objekt: 925af44f3cde53c6b076611c297850091b5dc7bb
- Aufgeloester Quell-Commit: 51b7f2abdade71cd9bb0e7a373ef2610ec6f9daf
- Lizenz: Zlib
- Lizenztext: ZLIB-LICENSE

`freetype/src/gzip/ftgzip.c` bindet fuer WOFF die sechs in
`UPSTREAM.json` genannten zlib-Quelldateien ein. FreeType leitet auch deren
Allokationen an das caller-owned `FT_Memory` weiter.

Quell- und Freestanding-Vertrag
-------------------------------

Die produktive FreeType-/Brotli-/Bridge-Quellliste liegt ausschliesslich im
lokalen `R4FONT/module.R4MF`. Der eigenstaendige
Hosttest-Build verwendet dieselben Quellen ueber die lokale Hilfsfunktion
`addHostDecoder`. Verbraucher importieren nur `R4FONT:API_V1:1` und kennen
den Fremdcode nicht.

Der Hostmodus nutzt die Host-C-Laufzeit nur fuer den Testprozess. Der
Produktivmodus kompiliert freestanding und ohne libc:

- `freestanding/` enthaelt die schmalen C-Header fuer die benoetigte
  Quelloberflaeche.
- `src/r4font_freestanding.c` implementiert genau die beim freestanding Link
  benoetigten Speicher-, String-, Sortier- und Abbruchprimitive.
- `src/r4font_system.c` verhindert FreeTypes unbenutzten System-Memory-Pfad.
- Das produktive R4FONT-Artefakt linkt diese Quellen freestanding und ohne
  Host-libc.

R4OS-Anpassungen
----------------

- `config/r4font_ftoption.h` deaktiviert Dateistreams, Environment-
  Properties, eingebetteten TrueType-Bytecode und nicht benoetigte Formate.
- `config/r4font_ftmodule.h` ist die geschlossene Modulliste.
- `freetype/src/sfnt/sfwoff2.c` bindet Brotli an dasselbe caller-owned
  `FT_Memory`, erzwingt vollstaendigen Ein- und Ausgabeverbrauch und begrenzt
  rekonstruierte SFNT-Daten auf 32 MB.
- `src/r4font_bridge.c` stellt den begrenzten C-Kern bereit.

R4FONT oeffnet nur vollstaendige, aufrufereigene Speicherabbilder. Es gibt
kein Datei-I/O, keinen Host-Fallback und keine Decoderallokation im Kernel
oder in R4DRAW. Alle Allokationen laufen ueber den vom R4OS-Verbraucher
gelieferten und hart begrenzten Allocator.

Reproduzierbare Pruefung
------------------------

`VENDOR.sha256` pinnt bytegenau alle vendorten FreeType-, Brotli-, zlib-,
Konfigurations-, Bridge-, Freestanding- und Patchdateien. Der Check prueft
ausserdem alle Lizenzhashes und spielt den lokalen FreeType-Patch rueckwaerts
ab; dessen Ergebnis muss wieder den gepinnten Upstream-Hash ergeben:

    python R4FONT/ThirdParty/r4font/Tools/verify_vendor.py --check

`--write` ist ausschliesslich fuer einen ausdruecklichen, geprueften
Vendor-Baselinewechsel vorgesehen. Danach muessen die Manifest-, Script- und
Patchhashes in `UPSTREAM.json` bewusst aktualisiert werden.

Abruf und Pruefung fuer R4OS: 2026-08-08

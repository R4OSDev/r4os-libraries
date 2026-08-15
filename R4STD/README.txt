R4STD.R4L
=========

R4STD ist eine unabhaengige Runtime-R4L fuer Text, R4S-Settings, Datum,
Zeitzonen und atomare Konfigurationsdateien. Contract, Baseline,
Implementierung, Zig-/C-Bindings und Tests gehoeren ausschliesslich zu dieser
Library-Einheit. Kernel, zentraler Plattform-Contract und Kern-SDK enthalten
keine fachliche R4STD-Implementierung.

Versionierte Interfaces:

- `R4STD:TEXT_V1:1`
- `R4STD:SETTINGS_V1:1`
- `R4STD:DATE_V1:1`
- `R4STD:TIME_V1:1`
- `R4STD:CONFIG_V1:1`

Eine Anwendung importiert nur die Interfaces, die sie wirklich verwendet,
bindet `Bindings/Zig/r4std.zig` beziehungsweise `Bindings/C/r4std.h` lokal
ein und initialisiert das Binding aus ihrem R4XStart-Kontext. `Query:1` bleibt
technische Modulidentitaet und ist kein produktiver R4STD-Funktionsimport.

Wichtige Pfade:

- Contract: `Contract/LibraryContract.json`
- Kompatibilitaetsbaseline: `Contract/LibraryContract.baseline.json`
- Implementierung: `Source/`
- Bindings: `Bindings/Zig/` und `Bindings/C/`
- generierte Referenz: `Docs/API.md`
- Tests: `Tests/`

CONFIG_V1 erhaelt die opake Adresse des caller-eigenen R4XStart-Kontexts pro
Aufruf und loest daraus R4SYS. R4STD behaelt weder diesen Kontext noch andere
uebergebene Pointer. Buffer und Zustandsobjekte bleiben beim Aufrufer.

Nicht hierher gehoeren Kernel-nahe Datei-/VM-/Thread-Primitives,
Netzwerkpolicy, Desktop-Hosting, Audio-Policy oder Entwicklungsdiagnose.

Build:

    Build.bat R4STD test

Der Repository-Starter loest SDK und Plattform-Contract aus `Settings.R4S`
auf. Der Library-Build prueft Contract, Implementierung, Bindings,
Runtime-Verhalten und das erzeugte R4L-Artefakt.

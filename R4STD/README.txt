R4STD.R4L
=========

R4STD is an independent Runtime-R4L for text, R4S settings, dates, time zones,
and atomic configuration files. Its contract, baseline, implementation, Zig
and C bindings, and tests belong entirely to this library. The kernel, central
platform Contract, and core SDK contain no R4STD implementation.

Versioned interfaces:

- R4STD:TEXT_V1:1
- R4STD:SETTINGS_V1:1
- R4STD:DATE_V1:1
- R4STD:TIME_V1:1
- R4STD:CONFIG_V1:1

Applications import only the interfaces they use and bind
Bindings/Zig/r4std.zig or Bindings/C/r4std.h. Query:1 is the technical module
identity, not a functional R4STD import.

Important paths:

- Contract: Contract/LibraryContract.json
- Compatibility baseline: Contract/LibraryContract.baseline.json
- Implementation: Source
- Bindings: Bindings/Zig and Bindings/C
- Generated reference: Docs/API.md
- Tests: Tests

CONFIG_V1 receives the opaque caller-owned R4XStart context per call and uses
it to resolve R4SYS. R4STD retains neither that context nor any other supplied
pointer. Buffers and state objects remain caller-owned.

The Zig binding also owns the shared desktop file-handler helpers. These are
compiled into their consumers and do not add a premature R4STD runtime ABI:

- `app_assoc` parses and writes APPASSOC entries for application, subsystem,
  and deliberately removed handlers.
- `file_handler` combines application defaults with the installed subsystem
  resolver and emits the stable subsystem launch request.
- `subsystem_runtime` loads the subsystem view solely from installed
  `MODULES.JSON`, keeps bounded 256 KiB probe storage, and performs the final
  host-file check. Metadata inspection precedes resolution; only an unknown or
  ambiguous result completes the content window through range reads. Access
  counters expose info calls, read calls, and bytes without retaining source
  data across a launch. ASSOC.R4S stores only stable subsystem and format IDs,
  never a copied host path or display name.

The shipped default maps `.BAS` to subsystem `r4os.basic` and format
`basic.qbasic-source`. Open With still lists the ordinary Notepad application
alongside the resolved subsystem host.

Build and test from the owning Repositories/Libraries directory:

    Windows: Build.bat R4STD test
    Linux:   ./Build.sh R4STD test


Konfigurationsspeicherung ab 0.78.63
-----------------------------------
R4STD0.2.2 behandelt nur R4SYS-Read -3 als fehlende Datei. Null Bytes
bezeichnen einen vorhandenen leeren Bestand. Zu grosse Dateien ergeben
config_error_buffer_too_small (-3); sonstige Lesefehler werden als neuer
config_error_read_failed (-9) gemeldet. Die bestehenden Fehlernummern und
Tabellenlayouts bleiben gleich; der Library-Contract wurde ausschliesslich
um diese Fehlerkonstante erweitert und kontrolliert neu generiert.

Einzelwerte werden erst nach erfolgreicher TMP-/BAK-Wiederherstellung aus
dem tatsaechlichen Zielinhalt komponiert. Unveraenderte Schluessel bleiben
erhalten. Nicht lesbare oder ungeeignete Zieldaten und nicht lesbare
Sicherungen stoppen den Vorgang vor Loeschen oder Schreiben. Ein gueltiges
TMP hat bei fehlendem Ziel Vorrang; sonst kann eine lesbare BAK verwendet
werden. Fehlgeschlagenes Umbenennen einer brauchbaren Sicherung behaelt sie.
Scheitern Publikation und Rueckbenennung, liefert saveDocument
error_recovery_failed; TMP und BAK bleiben fuer die Wiederherstellung stehen.
Es gibt keine bedingungslose Aussage, dass ein Rueckbau abgeschlossen sei.
Der Zig-Pfadvergleich ruft den kanonischen SDK-Helfer equalsIgnoreCase auf.

Nachweis: bestehender R4STD-Build mit47 Hosttests einschliesslich zweier
gebuendelter Fehler-/Wiederherstellungsfaelle und instanziiertem Binding-
Pfadvergleich; fuenf gezielte Hostfaelle fuer die betroffenen Oberflaechen und
REG; ein SMP4-Gastlauf mit privaten TMP/BAK-Daten, erhaltenem Fremdschluessel,
geaendertem COUNT, unveraenderter4097-Byte-Datei nach Groessenfehler und
vorhandener leerer Datei. Kein neuer kanonischer Testlauf angelegt.

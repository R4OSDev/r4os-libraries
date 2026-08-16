R4OS Runtime Libraries
======================

Dieses Repository enthaelt die offiziellen unabhaengigen Runtime-R4Ls:

- `R4STD` fuer Text, Settings, Datum, Zeit und Konfiguration
- `R4IMG` fuer Raster- und Vektorbildformate
- `R4FONT` fuer TTF, OpenType/CFF, WOFF, WOFF2 und Font-Rasterung

Jede Library besitzt ihren Contract, ihre Baseline, Implementierung,
versionierten Zig-/C-Bindings, Tests und Drittquellen in der eigenen Einheit.
Eine kompatible Libraryaenderung benoetigt keine Aenderung an Kernel,
Plattform-Contract oder Kern-SDK.

Pfade
-----

`Settings.R4S` mappt Workspace, Repositories, Contract, SDK, DevKit und Zig.
Relative Pfade sind die portable Voreinstellung; jeder Eintrag kann durch
einen anderen relativen oder absoluten Pfad ersetzt werden.

Build und Tests
---------------

Unter Windows:

    Build.bat
    Build.bat test
    Build.bat R4STD test
    Build.bat R4IMG test
    Build.bat R4FONT test

Unter Linux und macOS stehen dieselben Schritte ueber `Build.sh` bereit. Der
praktische 0.64-Umbau wird ausschliesslich auf Windows abgenommen.

Die Starter wenden die Settings vor der Zig-Paketaufloesung an. SDK und
Plattform-Contract sind im Paketbaum inhaltlich gepinnt; die gemappten lokalen
Checkouts werden als passende Entwicklungsvarianten verwendet.

Consumer-Bindings
-----------------

Das Rootpaket `r4os_libraries` stellt die Zig-Bindings als benannte Pfade
`r4std_zig_binding`, `r4img_zig_binding` und `r4font_zig_binding` bereit. Fuer
C-Verbraucher existieren entsprechend `r4std_c_include`, `r4img_c_include` und
`r4font_c_include`. Ein Modul pinnt dieses Paket und uebergibt nur den
benoetigten Pfad an den SDK-Manifestbuild; die Runtime-Implementierungen werden
dadurch weder eingebettet noch mit dem Verbraucher gekoppelt.

Fuer distributionseigene Hostgeneratoren exportiert das Rootpaket ausserdem
den formatreinen Pfad `r4font_format`. Das ist kein Runtime-Provider und keine
zweite R4FONT-API, sondern nur die gemeinsame Dateiformatdefinition fuer die
Erzeugung installierbarer `.R4F`-Systemfonts.

Herkunft und Transfergrenzen stehen in `PROVENANCE.txt`.

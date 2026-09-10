R4GFX 0.1.0
============
Generische Runtime-R4L fuer lineare Grafiklayouts und Softwarezugriff auf
caller-eigene CPU-Maps. Kein privater Allocator und kein GPU-Treiber.
Quelle, kanonischer Contract, Baseline, generierte C/Zig-Bindings und Tests
liegen in dieser Einheit. Implementierung ist originales Apache-2.0-Material.

Build ab Libraries-Root: Build.bat R4GFX test oder ./Build.sh R4GFX test.
Beide Starter nutzen Build.ps1/PowerShell 7 und Settings.R4S.
Consumer pinnen r4os_libraries und verwenden r4gfx_zig_binding bzw.
r4gfx_c_include; das Modul importiert R4GFX:API_V1:1.
API-Referenz: Docs/API.md. Systemvertrag: Docs/Drivers/GrafikPuffer07905.txt
im projektweiten Docs-Repository.

Seit 0.79.6 steht daneben Bindings/Zig/queue.zig als einkompilierter
Produzentenhelfer bereit (r4gfx_queue im Libraries-Build). Queue oeffnet den
ausgehandelten R4DRAW-Backendvertrag und uebermittelt copy/barrier mit
endlicher Deadline und expliziten Abhaengigkeiten. Handles und Backing
bleiben caller-eigen; es gibt keine versteckte Allokation oder Threadpool.
Die R4L-Implementierung und ihr eigener Vertrag bleiben bei 0.1.0.
Systemvertrag: Docs/Drivers/GrafikQueues07906.txt.

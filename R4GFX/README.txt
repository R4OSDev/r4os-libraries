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

The compiled Zig helpers `r4gfx_edid` and `r4gfx_outputs` add bounded EDID
base/CTA/DisplayID decoding and generation-consistent receiver reads through
R4DRAW ABI12. The caller owns storage; no I/O policy or allocator is hidden.
Bad extensions contribute no partial modes/audio. Missing blocks, unknown
metadata and nominal-only timings remain explicit. Only complete timings
can become programmable output modes. Supported DisplayID timing blocks
are type I (1.x) and VII (2.x); CVT/GTF synthesis, DSC, VRR and vendor-specific
policy are not implemented. License/provenance: ThirdParty/DisplayInfo/.
These helpers do not change the R4GFX 0.1.0 runtime artifact or its own ABI.

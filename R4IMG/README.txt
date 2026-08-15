R4IMG.R4L
==========

R4IMG ist die unabhaengige Runtime-R4L fuer Raster- und Vektorbildformate.
Die Library besitzt Implementierung, STB-Fremdcode, lokalen V1-Vertrag sowie
generierte Zig- und C-Bindings. Verbraucher importieren R4IMG:API_V1:1 und
rufen ausschliesslich die geladene Funktionstabelle auf. Pixelpuffer und
Scratchspeicher bleiben immer beim aufrufenden Prozess.

Aktueller Zielstand: PNG, JPEG und BMP sowie ein statischer, begrenzter
SVG-2-Teilbestand mit ARGB-Ausgabe, Alpha-Komposition, Seitenverhaeltnis,
Software-Rasterung und begrenzter Skalierung. SVG-Text und Linkregionen
werden ueber optionale Callbacks des Verbrauchers angebunden.

Build:

    Build.bat R4IMG test

Der Test umfasst Contract, Provider, echte Decoderpfade, Runtime-Tabelle und
einen eigenstaendigen C-Consumer.

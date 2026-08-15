stb_image
=========

R4IMG verwendet stb_image 2.30 aus dem offiziellen nothings/stb-Projekt fuer
PNG-, JPEG- und BMP-Dekodierung. Die unveraenderte Upstream-Datei
stb_image.h steht wahlweise unter Public Domain oder MIT-Lizenz; der volle
Lizenztext befindet sich am Ende der Datei.

Quelle: https://github.com/nothings/stb/blob/master/stb_image.h
Abruf fuer R4OS: 2026-08-05

r4img_stb.c begrenzt den Formatsatz und ersetzt dynamische C-Allokation durch
einen vom R4OS-Aufrufer bereitgestellten Scratch-Arena-Puffer.

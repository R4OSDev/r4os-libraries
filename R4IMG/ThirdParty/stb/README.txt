stb_image
=========

R4IMG uses stb_image 2.30 from the official nothings/stb project for PNG,
JPEG, and BMP decoding. R4OS selects the MIT option from the upstream
MIT/public-domain dual offer.

Source: https://github.com/nothings/stb/blob/master/stb_image.h
License: LICENSE-MIT and the license block at the end of stb_image.h
Retrieved for R4OS: 2026-08-05

r4img_stb.c restricts the format set and replaces dynamic C allocation with a
scratch arena supplied by the R4OS caller.

R4OS0.91.15 / R4IMG0.3.7 threads an explicit R4ImgArena pointer through
the allocating PNG/JPEG/BMP call graph. Every decode owns its context on
its stack and writes only to its caller's scratch and output. The upstream
image algorithms, format limits and license text are retained. The complete
ported header is built only through r4img_stb.c with its fixed format flags.
The public diagnostic publishes one atomic snapshot of the last completed
raster decode, shared across callers. The arena retains no caller pointers
after the function returns. Original source comparison and parallel decode
evidence: ExFiles/Reports/Fable091/0.91.15/.

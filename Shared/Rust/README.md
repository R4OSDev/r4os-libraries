# Library consumer helpers

Libraries 0.64.25 and SDK 0.64.78 expose the higher R4STD, R4IMG and R4FONT
helpers to Rust and C. The original Zig functions execute behind a generated,
fingerprinted boundary. Provider binaries and local ABI contracts are unchanged.

Rust projects select `r4os-library-helpers` from this directory and pass the
explicit `-LibraryHelpersRoot /selected/Libraries` to the SDK's
`Tools/Build-RustModule.ps1` (or its `.sh`/`.bat` starter). This also requires the
selected pinned `-ZigRoot`. Source files, native objects and dependency roots
are recorded in the normal build receipt. Component selection belongs to the
caller; the SDK does not create project pins or select versions for an IDE.

`standard`, `image` and `font` contain borrowed text/settings iterators,
bounded writers, typed codecs/date/time/config calls, caller-owned image
buffers and font resources. A font face borrows its decoder and source; the
decoder borrows its allocator/context. FNT/FON conversion returns owned bytes
which are freed through the same allocator. Text scalars, grapheme boundaries
and rendered glyph metrics remain separate. No normalization, shaping, BiDi or
display-width guarantee follows from a text length or boundary.

`raw` exposes the complete higher native operation boundary, including SVG
callbacks, color characterization/conversion, optional native JPEG, font
import/preview and the application face/raster cache. These operations remain
unsafe: callbacks and inputs must outlive retained views, native objects must
stay at their required address, cached glyph views must end before mutation,
and native resources require their original close/release acknowledgements.
Use the existing generated local binding crates for direct R4L table access;
those crates retain their own contracts and App loans.

C callers include `r4std_helpers.h`, `r4img_helpers.h` or `r4font_helpers.h`
from each owner's `Bindings/C`, plus `Shared/C/include`. Build the two optional
native helper objects from the selected SDK directory with its pinned Zig:

```
zig build --fork=/selected/Contract -Dlibrary-helpers-root=/selected/Libraries --prefix /output
```

Link `lib/r4libraries_helpers.o` and `lib/r4libraries_facades.o` along with the
normal SDK runtimes. The workspace SDK `Build.sh`/`Build.bat` starters also
accept this option and resolve their configured Contract automatically. C
retains the typed inline entries; Rust uses the identical exported bodies.
Opaque native storage uses `MaybeUninit`; never read padding or invent a Zig
slice, optional, union or allocator layout. `R4LibraryMemory` adapts explicit
allocation/free callbacks. `R4Library_colorClient` and `videoClient` resolve
the original optional provider contracts without guessing private layouts.

The generators are built with `-Dlibrary-helpers-generator-only=true` and
`-Dlibrary-helpers-rust-generator-only=true`, respectively, in addition to the
owner root. `write` and `check` preserve the checked-in projections. The first
tool takes the C-header and native-fingerprint output paths; the second takes
`Shared/Rust/src/raw.rs`. `Tools/Test-ConsumerHelpers.ps1` runs only the small
native C/Rust cases and five compiler ownership negatives. The reusable
`Shared/Tests/Consumer` performs real table calls in the guest; it is excluded
from images. No complete test environment needs archiving.

# Library consumer helpers

Libraries 0.64.26 and SDK 0.64.79 expose the higher R4STD, R4IMG, R4FONT,
R4GFX, R4ENC, R4VIDEO, R4ACO and R4NAK helpers to Rust and C. The original Zig functions execute behind a generated,
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

`graphics` adds receiver parsing and retained COLOR_V1 profiles; `media` adds
original NV12 row conversion, a synchronous Matroska sink and immutable builtin
SPIR-V words. `video` uses the original playback clock. A mux callback borrows
each byte slice only for that invocation; an accepted prefix remains written
after failure and the original failed writer cannot be replayed. A profile
copies its source, borrows the application/allocator, and closes before their
release. Apply profiles only to unpublished frames; discard a failed frame and
retain canonical SDR composition separately.

Output/mode/brightness/refresh/color admission, readback/transfer, playback,
compiler workers and disk-cache adapters are also fully available in `raw`.
These remain unsafe stateful owners, with the same precise jobs, generations,
borrowed bytes and real completion/release requirements as Zig. To initialize
a worker, use `R4Library_application` into its final native App storage, then
`R4AcoWorker_init`/`R4NakWorker_init`. Never cast a Rust SDK App to a Zig App.
Keep the native App, worker, request pointers, code and log storage at stable
addresses until `join` returns PRESENT. A missing join result retains ownership;
neither timeout nor cancel releases worker or buffer storage. Only fields
explicitly documented as concurrent may be accessed during a running job.
Other native contexts can be derived with `applicationSystem/applicationDraw`.

The R4AMD/R4NV/R4GL/R4VK public Zig bindings have no additional higher helpers.
Their existing generated C/Rust local contracts remain the consumer entry;
external OpenGL/Vulkan function-pointer and direct floating-point ABI
qualification belongs to the separate low-level profile work. Optional tables
still require actual presence, and CPU/compiler success admits no GPU job.
Declare each named import with the minimum revision required by the selected
binding; its interface ABI major is not the manifest minimum revision.

C callers include `r4std_helpers.h`, `r4img_helpers.h`, `r4font_helpers.h`,
`r4gfx_helpers.h`, `r4enc_helpers.h`, `r4video_helpers.h`, `r4aco_helpers.h`
or `r4nak_helpers.h`
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
Native error-set values use bounded exact error names, rather than private Zig
error integers. A returned error value (PRESENT) differs from an operation
failure (NATIVE_ERROR). Explicit slice alignment is checked, including ICC
storage; an empty slice does not authorize dereferencing its native pointer.

The generators are built with `-Dlibrary-helpers-generator-only=true` and
`-Dlibrary-helpers-rust-generator-only=true`, respectively, in addition to the
owner root. `write` and `check` preserve the checked-in projections. The first
tool takes the C-header and native-fingerprint output paths; the second takes
`Shared/Rust/src/raw.rs`. `Tools/Test-ConsumerHelpers.ps1` runs only the small
native C/Rust cases and five compiler ownership negatives. `-Media` adds the
existing recording owner oracles, aligned/error-value cases, C/Rust mux output
and two additional callback/profile lifetime negatives. The reusable
`Shared/Tests/Consumer` performs real table calls in the guest; it is excluded
from images. `Shared/Tests/MediaConsumer` performs real CPU ICC/VCGT table calls
and optional compiler availability, plus receiver/NV12/clock/shader checks.
With present compiler providers it exercises invalid-request worker rejection
and real join; the software image instead checks both unavailable initializers.
Both fixtures check final heap balance. No complete test environment needs archiving.

# R4GFX

R4GFX is the userland graphics library. Its runtime module owns CPU rendering;
R4DRAW owns shared buffers, queues and presentation. The compiled `Display/`
helpers parse receiver metadata and the Zig bindings expose queue/output helpers.
The Report keeps SCDC and low-rate scrambling separate; malformed extensions
contribute neither flag. Consumers decide link policy from a complete report.
These source helpers compile in their consumers, separately from R4GFX.R4L.

Build this unit with `../Build.sh R4GFX` on Linux or `..\Build.bat R4GFX` on
Windows. Both use the same PS7 build. Add `test` for the existing seven owner
and C/Zig conformance cases. No guest or benchmark runs automatically.

## Runtime interfaces

`module.R4MF` is authoritative. Module 0.1.1 exports two independent tables:

| Import | Behavior |
| --- | --- |
| `R4GFX:API_V1:1` | Checked linear layouts and rectangle fill; original table and payloads unchanged. |
| `R4GFX:RENDER_V1:1` | Capability query and ordered, bounded CPU 2D batches. |

Bindings and API documentation are generated from `Contract/LibraryContract.json`.
Use `ApiV1Client.init` or `RenderV1Client.init` with the app start context. The
generated clients check interface identity, revision, size and required slots.
The new renderer reports the software backend; it does not require R4NV.

## CPU batch ownership

Create/import shared BOs through R4DRAW and hold a write map for each target
and read access for each source until `execute_cpu` returns. Pass these CPU
addresses, pitches and extents as `R4GfxCpuImage`; physical/GPU addresses and
unmapped memory are invalid caller inputs. Input arrays and the batch must
remain immutable, and target access must be exclusive throughout the call.
No pointers, BOs or maps are retained by R4GFX.

The renderer validates every image and command, arithmetic, aliases and total
pixel budget before writing. Rejection leaves image bytes and output stats
unchanged. This is preflight atomicity, not rollback of memory faults or caller
lifetime violations. Pixel storage may not alias metadata or the output.
The caller must also exclude different virtual mappings of the same backing.

Use at most 64 images, 1024 commands and 16,777,216 destination pixels per
call, with an explicit `pixel_budget`. Whole rectangles must be clipped by
the caller; coordinates are unsigned and out-of-image areas are rejected.
Commands execute in array order. Empty rectangles do no pixel work.

| Operation | Inputs and behavior |
| --- | --- |
| Fill | Target rectangle and packed color. Source index, source rectangle, sampler and opacity must be zero. |
| Blit | Source/target rectangles, nearest or bilinear sampler; `opacity=255`, `color=0`. Supports scaling and XRGB/ARGB conversion. |
| Source-over | Same image geometry/samplers as blit; `opacity=0..255`, `color=0`. Premultiplied ARGB or opaque XRGB. |

All reserved fields and batch flags must be zero. R8 supports fill/blit only;
R8/color conversions are unsupported. XRGB reads as opaque and stores its
unused byte as zero. Filtering uses pixel centers and clamps to the source
rectangle. Color-space conversion is a separate stage. Equal-size, same-format
copies of identical views have memmove semantics, including overlapping rows.
Other overlapping source/target spans are rejected.

Capabilities report formats, operations, samplers, features and limits. Errors
distinguish invalid inputs, unsupported operations, overflow, work limits and
unsupported aliases. Unsupported work does not silently discard draws.
`R4GfxCpuStats` reports successful commands, destination pixels and logical
read/write bytes, including filter samples and destination reads for blending.
These counters do not measure memory-bus traffic, GPU time or presentation.

No allocation, upload, frame copy, thread, wait or service call is hidden inside
the renderer. Map release and presentation are separate caller actions.
`Repositories/Diagnostics/DisplayDiag/src/buffers.zig` is the executable client
example, including read leases surviving producer release and balanced teardown.

Device selection, persistent GPU resources, R4NV encoding and native dispatch
remain work in roadmap 0.79.17. A passing CPU scene does not qualify NVIDIA
rendering. Evidence and remaining work: `Docs/Drivers/GrafikRender07917.txt`.

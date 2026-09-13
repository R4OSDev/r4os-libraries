# R4GFX

R4GFX is the userland graphics library. Its runtime module owns render resources,
backend selection and CPU rendering;
R4DRAW owns shared buffers, queues and presentation. The compiled `Display/`
helpers parse receiver metadata and the Zig bindings expose queue/output helpers.
The Report keeps SCDC and low-rate scrambling separate; malformed extensions
contribute neither flag. Consumers decide link policy from a complete report.
These source helpers compile in their consumers, separately from R4GFX.R4L.

Build this unit with `../Build.sh R4GFX` on Linux or `..\Build.bat R4GFX` on
Windows. Both use the same PS7 build. Add `test` for the existing eight owner
and C/Zig conformance cases. No guest or benchmark runs automatically.

## Runtime interfaces

`module.R4MF` is authoritative. Module 0.1.3 exports three independent tables:

| Import | Behavior |
| --- | --- |
| `R4GFX:API_V1:1` | Checked linear layouts and rectangle fill; original table and payloads unchanged. |
| `R4GFX:RENDER_V1:1` | Capability query and ordered, bounded CPU 2D batches. |
| `R4GFX:DEVICE_V1:2` | Caller-owned devices, images/targets, samplers, pipelines, raster imports and canonical copy receipts. |

Bindings and API documentation are generated from `Contract/LibraryContract.json`.
Use `ApiV1Client.init` or `RenderV1Client.init` with the app start context. The
generated clients check interface identity, revision, size and required slots.
RENDER_V1 reports software rendering. DEVICE_V1 selects a compatible native copy
backend when the caller also imports `R4NV:BACKEND_V1:2:1`; a missing or incompatible
R4NV keeps software rendering and copying available.

## Device resources

Allocate `storage_size()` bytes at `device_storage_alignment`, zero the storage
before its first open, and pass the app start context to `device_open`. Serialize
calls for a device. Keep its storage, imported libraries and start context alive
until `device_close` succeeds; never move an open device. Device, resource and job
handles include owner/generation identity. Handles cannot survive freed storage.

There are at most 256 resources and 16 jobs per device. Create system-memory images,
import a canonical BO reference or immutable shared-raster lease, or borrow CPU
storage with an explicit source generation. Images also act as render targets when
`image_target` is set and writable access is allowed. Samplers and operation
pipelines are immutable resources. Retain/release is explicit; a job independently
holds its source and target until its exact receipt is physically retired.

Overlapping leases for the same immutable shared-raster generation reuse one BO
import. No upload or raster conversion occurs. Imported BO descriptors supply their
real geometry; borrowed CPU storage remains the caller's responsibility. `resource_info`
reports source kind/generation and canonical BO identity. Device counters distinguish
imports/imported bytes, successful CPU reads/writes and completed native copy bytes.
Upload bytes remain zero in this profile; these are logical costs, not bus measurements.

The kernel publishes a coherent opaque backend profile and exact device/reset binding.
R4NV validates its interface, command ABI, pinned RM release and Copy Engine class.
The generation must still open successfully through the common queue. `device_refresh`
changes the selected backend while preserving system images and immutable source
imports. Device-local imports affected by reset/change become `resource_invalidated`;
render/copy rejects them as stale, while information and release stay available.
The caller recreates those resources from retained sources; old GPU addresses are
never transferred to a new binding.

`render` resolves a whole resource batch through the same software 2D implementation
as RENDER_V1 and maps each distinct BO once. All primitive validation precedes pixel
writes. A failed physical unmap can still return busy after rendering; resources
remain tracked until release succeeds. Result metadata and input/storage ranges must
not alias. Native capabilities currently advertise copy only: unsupported drawing
uses this bounded CPU path and its result identifies the actual software backend.

`copy_submit` uses the canonical queue and returns a job, not synthetic completion.
Query/cancel/release preserve its original device/reset generation. An old queue stays
open until its last receipt is released. Cancellation/deadline alone never frees active
GPU resources. Close is retryable (`status_busy`); continue querying/releasing or retry
close while retaining storage. Opaque device-local images are not CPU shadows.

The Desktop batches fills through DEVICE_V1, flushes before other scene operations
and retains imported shared rasters with its active/staging frame leases. Its borrowed
scene target is released at each scene boundary. R4DRAW still handles presentation.
DISPLAYD `/BUFFERS` includes two dependent row copies and exact 16-pixel readback through
this interface, in addition to the original RENDER_V1 scene.

## Asynchronous copies

DEVICE_V1 revision 2 appends `copy_submit_ex` and `job_fence` to the original
table. Pass bytes per row, nonzero row count and the two pitches for geometric
copies; zero rows and zero pitches retain linear-byte semantics. Image-plane
pitches must match the canonical descriptor. Offsets are logical plane offsets,
including for opaque native images. Up to eight exact common fences can be
passed as dependencies. Submit the dependent work before releasing its upstream
job. The kernel retains admitted dependencies independently; exporting a fence
does not transfer ownership or complete the job. Query/release only after the
reported physical boundary; cancellation alone does not release resources.

R4NV revision 2 and the common backend operation mask negotiate linear, pitched
and blocklinear CE copies independently of software rendering. Unsupported row
copies between system BOs can use a cached software queue. Opaque/device-local
copies require a compatible native backend and never guess CPU addresses.
Queue device/reset generations and the driver's memory generation are distinct;
native imports must match the current memory epoch and are invalidated on reset.
System resources survive this change. Copy costs count transferred row bytes,
excluding pitch gaps. DISPLAYD /BUFFERS demonstrates two dependent 24-byte copies
with pitches 16/24/32 and a checked readback. Software evidence and physical
follow-up: `Docs/Drivers/GrafikCopy07918.txt` and `ExFiles/Reports/OssiGPU.txt` /18.

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

Native shader rendering and complete GPU Desktop composition belong to 0.79.19/20.
A passing CPU scene does not qualify NVIDIA hardware. Software evidence lives in
`Docs/Drivers/GrafikRender07917.txt`; physical follow-up remains in
`ExFiles/Reports/OssiGPU.txt`, section 0.79.17.

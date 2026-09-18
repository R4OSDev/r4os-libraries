# R4ENC

Independent encoder library introduced in 0.79.41. The generated
`ENCODE_V1:1` contract separates canonical input BOs/fences, stream timestamps,
explicit codec/rate capabilities, bounded queues and immutable bitstream
leases. It does not reuse the R4VIDEO decoder API.

Implemented software path:

- C/Zig contract and canonical graphics identity checks.
- BO admission with deduplicated imports, finite retained-memory accounting,
  borrowed producer fences, CPU I420/NV12 views and retryable cleanup.
- Queue/control bookkeeping with backpressure, exact lease identities, ordered
  completion, IDR after Abort and Close escalation over pending Drain/Abort.
- Pinned OpenH264 2.6.0 freestanding C++/x86 assembly build; CQP H.264
  Constrained Baseline 8-bit 4:2:0, IDR/P, checked Annex-B access units.
- Loadable R4ENC.R4L with all nine public calls, R4SYS memory/clock/TLS adapters
  and one bounded worker per encoder, charged through its exact join.

The public software runtime passed a short SMP4 guest run with real BOs,
I420/NV12 inputs, bounded backlog, held output leases, Abort/IDR, Close and
exact worker joins. Independent FFmpeg decoding verified two twelve-frame
320x192 sequences at QP18/QP36. This is not a throughput or NVENC proof.
The private NVENC session now owns bounded work/bitstream BOs, two opaque
reconstructed references, IDR/P sequencing and fresh status validation.
It uses Shared/Native/gpu_resources.zig, including exact physical retirement
after timeout. Its Ampere/Ada SDK-dispatch model passes within the existing
second component case; no input pixels or actual codec execution are modeled.
The private encodePrepared boundary requires fully padded NV12 in NVENC
16x16 tile storage; it does not accept or reinterpret generic block-linear BOs.
The public NVIDIA path now selects matching Ampere/Ada NVENC and GR classes
and uses this session through its existing bounded worker. It starts GPU work
only for accepted input, applies one deadline to preparation/encoding and
retires both engines before input/close acknowledgements. Abort resets the
reference chain. Explicit NVIDIA requests never silently select software.

The GR preparer samples retained NV12/I420 directly, including authenticated
block-linear textures, and writes edge-padded private16x16 NV12 storage. Only
shader/packet/command/status/bitstream BOs are CPU-mapped; no full-frame
readback or extra intermediate copy is required. Private layout qualification
and actual NVENC output remain physical follow-up. Native configuration is
CQP,8-bit BT.709 limited, transfer1 or sRGB13, default/left chroma, GOP<=65535; unsupported metadata,
layouts, generations or missing channels return explicit errors. Capability
queries describe this software profile, not a completed physical qualification.
The compiled recording_mux helper writes bounded append-only Matroska/H.264
with explicit packet durations. Twelve real encoder packets preserve variable
PTS/durations and decoded pixels through independent demux. The companion
recording_pixels helper converts immutable CPU sRGB snapshots to limited NV12
with left chroma and explicit transfer13; it has no resource or thread owner.
Desktop's Ctrl+Print Screen recorder owns activation, latest-frame selection,
explicit fallback, file rotation and the worker. Its SMP4 consumer run decoded
62 pictures independently and checked delayed/failed writes, modeled NVIDIA
loss, repeated recording, exact joins and restored BO/capture baselines.
Physical NVENC execution remains unqualified. CBR/VBR constants define requests; they do
not imply backend support.

Build the module from Libraries with `./Build.sh R4ENC -Doffline=true` (or
`Build.bat R4ENC -Doffline=true`). Source archives must already be cached for
offline builds. From Libraries, use `./Build.sh R4ENC test` or `Build.bat R4ENC test` for the two
short component cases. The ownership case also exercises BO cleanup and flow
control with modeled kernel replies. No new workspace gate is added.

`Tools/BuildNative.ps1` uses PowerShell 7, clang 19.1.7, NASM >=2.16 and the bundled
Zig math sources. `-Offline` requires the checksum-pinned archive. Both host
paths share the script; execution has so far been checked on Linux only.
OpenH264's global thread pool is unavailable; the caller-owned R4OS worker runs
a single-thread codec with actual CPU SIMD dispatch. C++ is closed to exceptions
and RTTI; `-fcheck-new` preserves the codec's null-allocation checks.

Source pins/license: `ThirdParty/Sources.json`, `ThirdParty/OpenH264-LICENSE.txt`.
Workspace findings and proof limits: `Docs/Drivers/Videoencoding07941.txt`.
Physical follow-up: `ExFiles/Reports/OssiGPU.txt`, section 0.79.41.

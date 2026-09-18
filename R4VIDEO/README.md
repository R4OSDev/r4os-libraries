# R4VIDEO

Independent compressed-video library and compiled media-host facade for roadmap 0.79.40.
VIDEO_V1 covers bounded input, decoded BO-plane leases, timestamps, reorder,
Drain/Flush/Close and explicit backend selection. `zig build test` combines
C/Zig ABI, canonical graphics identities and concurrent allocation budgets.

`Tools/BuildNative.ps1` builds pinned FFmpeg 9.0.1 for freestanding x86_64 with
PowerShell 7, clang 19.1.7, NASM >= 2.16 and bundled Zig. It generates immutable
CAVLC/H.274 tables with the original upstream initializers and uses FFmpeg's
constant CRC tables. Linux execution and Windows cross-compilation of these
generators were checked; the complete PowerShell build was run on Linux.
`-Offline` requires the checksum-verified archive. See ThirdParty/Sources.json.

The archive has 143 objects (132 upstream, four adapters, seven shared C
helpers), plus separately built shared Math/Scan archives. SIMD dispatch uses
actual CPUID/XCR0; AVX512 remains masked under the current SDK contract.
Native process settings, bounded allocation ownership, worker admission/join,
TLS cleanup and real R4SYS clocks are implemented and link with the codec.
The public R4VIDEO.R4L now executes all nine VIDEO_V1 slots in a four-vCPU
R4OS guest. It is built with `../Build.sh R4VIDEO -Doffline=true` (or the Windows
Build.bat starter). `IMAGE_SCOPE=slim` includes the module in normal profiles.

The private worker bridge admits progressive H.264 8-bit 4:2:0 Baseline/Main/
High, one slice group, up to level 5.1 and caller dimension limits. Buildhost
probes check 36 exact YUV frames, reorder/timestamps, held frames over Flush/
Close, errors and modeled calling-process settings. The SMP4 native guest
repeats the frame/lifetime/error checks with real threads and budgets. Its
surface probe verifies all three YUV planes in common R8 BOs, partial-allocation
cleanup and final BO/reference/map/byte baselines. The public guest additionally
checks copied input/backpressure, leases across Flush/Close, common consumer
fences, stale tokens, failed admission retries and independent decoder errors.
PublicPoolGuest additionally checks stable BO identities, initialized padding
and 64x48 -> 96x64 -> 64x48 with a held old-size image (39 reference frames in
total). Evidence is under ExFiles/Reference/GFX/0.79.40/Evidence; PublicApiGuest,
NativeGuest and NativeSurfaceGuest retain earlier checks.

Memory limits charge payloads, allocation metadata/alignment, decoder surfaces
and retained worker stack reservations. Shared code, fixed process/TLS records,
backing allocator caches and kernel bookkeeping are outside that accounting;
these limits do not promise a total physical-RAM ceiling. Allocation exhaustion
returns failure and failed realloc preserves data. Join failure cannot return
into FFmpeg teardown while a worker might remain alive.

Source/surface.zig owns software YUV output storage, queried BO descriptors
and transient mappings. A failed upload retains partial resources until close
succeeds. It copies Y/U/V without RGB conversion. Source/engine.zig owns bounded
packet/output queues, stream generations and leases. Reuse starts after the
exact consumer fence retires and Release acknowledges the return. Fitting BOs
keep their identity and budget charge; Flush/Close/error close unused cached
storage. Dimension changes replace the affected slot's old layout without
revoking other held images. Padding is initialized separately from active rows,
avoiding a redundant clear of every pixel before copying it.

FFmpeg's max_pixels guard uses its own STRIDE_ALIGN-rounded width; actual
SPS/get_buffer2 dimensions still obey the exact caller limits. This permits
valid widths such as96 pixels without confusing SIMD stride with coded size.

Runtime admission permits 1..16 decoder owners. Its thread_limit caps aggregate
decoder workers, including their coordinators; one fixed retirement worker is
additional and its stack/allocation remains memory-budgeted. Config.threads caps
each decoder at 1..16 workers (zero chooses min(runtime limit,16)); caps <=2 use
one coordinator and synchronous FFmpeg, higher caps allow up to cap-1 codec
threads. Close completion includes exact joins, then Destroy frees the owner.
Finish permanently closes the process-local runtime. Fixed tombstone metadata,
including its owner mutex, follows process lifetime for safe stale/idempotent calls.

H.264 profile zero resolves to Baseline; Main/High require explicit selection.
Only progressive 8-bit 4:2:0 is admitted. Unsupported codecs/profiles/devices
return UNSUPPORTED without implicit substitution;
a media owner can explicitly open the software backend. Errors from asynchronous
FFmpeg admission wake the coordinator even if no further packet arrives.

R4GFX now provides CPU and native YUV composition through COLOR_V1:4.
The compiled media host and corresponding-source staging are described below. CUDA/NVDECODE are not dependencies. Source pins stay in
ThirdParty/Sources.json; implementation status belongs in this README.

`Port/FFmpegNvdec.patch` registers a private hardware pixel format and H.264
callback implementation. `Port/nvdec.c` maps parsed SPS/PPS, raster scaling
matrices, short/long references and original escaped slice NALs to the private
`nvdec.h` worker interface. FFmpeg retains parsing and display-order output;
the worker callbacks own GPU work. The hardware path uses a single coordinator
and never selects software implicitly after a callback failure.

Each opaque hardware image has an AVBuffer reference. The callback table is
copied at open and into each image; its external owner must outlive every
received frame, including held frames after codec_close. Partial allocation,
begin/slice/end errors abort once and release once. Only successful end marks
an image available; the GPU implementation must check its native fence AND
NVDEC picture status before returning success. CPU data planes are absent.

The SMP4 NvdecBridge fixture runs the real native FFmpeg callbacks through
R4NV's picture/slice encoder, with a model replacing GPU image ownership. It
checks 36 metadata/reorder frames, held references over Flush/Close, copied
callback tables, four failure stages and exact budget teardown. The same
changed R4VIDEO module also passes the existing 39-frame public software
probe. This is not GPU decode evidence. Evidence: GFX/0.79.40/Evidence/NvdecBridge.

Source/gpu_resources.zig now owns native NV12 allocations, coherent system
uploads/status, VRAM scratch, acknowledged GPU VA bindings and engine-8 queue
submissions. Architecture/epoch admission covers GA10x (C7B0) and Ada (C9B0);
the driver separately validates an offered NVDEC instance/class. No GR template
is required. All method addresses must fit 40 bits; an out-of-range RM allocation
is retired and rejected. Image layouts come from actual BO descriptors, including
the uncompressed blocklinear modifier and aligned chroma offset. GPU memory and
system upload allocations remain charged through their exact retirement ACK.

Source/gpu_decoder.zig connects these resources to the real FFmpeg callbacks and
R4NV's H.264 encoder. Seventeen coloc slots track DPB membership independently
of up to 48 image owners. Reordered references preserve their physical slot;
an output held by a consumer keeps its BO while its old coloc slot is reused.
Each job retains all indirect BO/VA resources, resets the picture status and
checks the coherent result after queue completion. Missing/error status produces
no frame. A partial allocation or timed-out job remains reachable for cleanup.

VIDEO_V1 now admits that NVIDIA path and publishes two NV12 planes borrowing
the same canonical BO, with normal timestamps, crop and color metadata. The
coordinator retains the received AVFrame through the consumer fence AND public
Release acknowledgement. Flush/Close do not revoke held images. Hardware uses
one coordinator; no FFmpeg frame threads or mandatory CPU color conversion.
Storage geometry changes require an empty DPB; held consumer images survive.
At most 36,864 macroblocks are admitted, so not every 4096x4096 combination is
valid. Further codecs, interlace, noncoherent mappings and unknown layouts are
not enabled. Physical decode/pixel validation remains in OssiGPU.txt.

Evidence/GpuOwner records the focused owner cases (delayed MAP/retirement,
timeouts, budgets, DPB-slot reorder/reuse, held old-size images and missing/bad
picture status). The public SMP4 fixture runs the actual R4VIDEO.R4L, FFmpeg
and GPU owner with modeled GPU replies: 36 Baseline/Main/High metadata/reorder
frames, held images through Flush/Close and delayed Release acknowledgement,
plus a rejected picture status and complete teardown. The same module passes
the existing 39 exact software frames. No GPU pixel or performance claim is
made; no additional permanent test group was added.

## Media host

`Bindings/Zig/playback.zig` is an optional compiled consumer facade, exported
as the package path `r4video_playback`; import `r4os` and `r4gfx_binding` into
that module. It uses actual VIDEO_V1, R4GFX COLOR_V1:4 / DEVICE_V1:10 and the
ordinary App-Audio/AUDSVC path. It is independent of any particular player UI.
The caller retains demux, audio decoding, file I/O/seek and desktop presentation.

Open the VIDEO runtime and graphics device outside paint callbacks, then
`Session.init` with explicit codec/color/budget settings and optional PCM owner.
Call `send` with complete access units and the current stream generation;
AGAIN/BUSY accepts no input. Feed bounded S16LE PCM with its sample-derived PTS
and audio epoch. Pump `step` from the event loop, using `pendingFrame` metadata
to choose the current crop/viewport and an available CPU or GPU output target.
Only `target_accepted` borrows that target. Each returned `Output` ends its
composition use; present it through the existing desktop/swapchain host only
when `display` is true. The caller owns the output storage and its subsequent
presentation lifetime. Three independent slots permit old/new-size overlap.

Sources use canonical BOs. Native composition retains frame loans throughout
BUSY preparation, GPU completion and physical job retirement. The R4GFX job
owns its fence; VIDEO receives an empty receipt only after that job is released.
CPU composition permits explicit system-linear maps only and retains partial
maps until unmap succeeds. Unknown modifiers never become implicit CPU reads.
ColorPolicy supplies explicit defaults for unspecified metadata and luminance;
unsupported signaled values remain errors. COLOR opacity is0..65535 on both
CPU and GPU, with full precision retained by native float vertex attributes.

One monotonic, pause-corrected clock schedules video and PCM; decode speed and
audio acceptance do not change it. App-Audio currently has no audible sample
cursor. The audio owner uses a10ms staging/lead bound and one service call per
step (SDK `AudioStream.writeOnce`); partial replies preserve their exact prefix.
Late audio/video is trimmed or dropped, never accelerated to catch up. Audio
absence/failure is reported as degraded while video time continues unchanged.
An uncertain timed-out write closes its stream instead of replaying samples.
Actual device latency and long-term A/V drift still require physical measurement.

`seek` and `pause` flush the decoder and close/discard queued audio. While the
seek handshake is pending, old outputs are retired without display and no new
packets enter. On `Step.reposition_ns`, seek the source to a preceding random-
access point and call `repositioned`; decoded preroll is skipped on the media
timeline. `resumePlaying` restarts the paused clock. PCM after seek uses the new
audio epoch. New stream dimensions/color are obtained from `pendingFrame`;
old composition targets remain held independently until returned.

Drain preserves reordered output. Close keeps pumping until all compositions,
VIDEO release acknowledgements, decoder destruction and audio close complete.
A definitively invalidated service connection ends the local audio close;
BUSY and uncertain replies keep it pending. Service death cannot hold the
session in an endless close loop.
Only then may the caller finish the VIDEO runtime, close the graphics device
and unload providers. A deadline reports failure but never frees live GPU data.
Unsupported NVIDIA admission may select the explicitly allowed software backend;
an asynchronous decoder/device failure requires closing this session and opening
a new software session at a source random-access point. No packet is silently
retried in another backend. A failed old device and its owners remain loaded
until their physical cleanup completes.

Existing owner cases cover clocks, partial audio responses, seek/close replies,
CPU map retention, native BUSY, separate GPU retirement and decoder errors. SMP4
executes the actual public modules:12 complete baseline frames and8 post-seek
frames (half opacity), plus one96x64 frame, all compared pixelwise to a scalar
BT.709/BT.1886 FP16 reference. First probe failures were its incorrect generic
success code and its three-frame expectation for a one-frame resize fixture.
This proves software integration, not native GPU pixels or audible A/V sync.

## Distribution and rebuilding

Every normal image contains `R4OS/SOURCES/R4VIDEO/R4VIDEO-SOURCE.tar.gz` and its
SHA256 manifest alongside the replaceable library. `Tools/PackageSources.ps1`
packages the matching module identity, original FFmpeg archive, all port patches
and R4VIDEO/SDK/contract/native-helper sources needed for a complete rebuild.
Full distribution terms and replacement steps are in `R4VIDEO-NOTICES.txt`;
FFmpeg retains LGPL-2.1-or-later. Consumers dynamically import this R4L.

On a Windows or Linux host, extract the package and provide PowerShell7,
clang19.1.7, NASM>=2.16, git, tar and a complete Zig0.16.0 installation under
`<DevKit>/Toolchains/Zig`. Run the packaged
`Repositories/Libraries/R4VIDEO/Tools/RebuildSources.ps1 -DevKitDirectory <DevKit>`
with PowerShell. The supplied FFmpeg archive allows an offline source rebuild
and relink. Replace `C:\R4OS\LIBS\R4VIDEO.R4L` after consumers stop or on reboot;
no signature or modification lock prevents using a compatible rebuilt module.

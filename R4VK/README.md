# R4VK native Vulkan provider

Roadmap 0.79.35 completes the native Vulkan resource/queue software integration.
R4VK 0.1.7 provides Mesa's CPU runtime and NVK devices, memory/VA, descriptions,
commands and submit/sync adapters through the standard ICD bootstrap.
`IMAGE_SCOPE=slim` installs the module in every normal image. Without an
admitted NVIDIA backend, Vulkan enumerates no device and the existing
firmware-framebuffer renderer continues to work. This is not a software
Vulkan renderer. Physical GPU qualification remains in OssiGPU.txt.
The selected provider remains pinned Mesa NVK/NIL/NAK with R4OS resource
contracts; NVIDIA.R4D remains the sole hardware owner.

Build from the Libraries root with `./Build.sh R4VK` or `Build.bat R4VK`.
`-Doffline=true` requires cached source archives. `Tools/Build.ps1` resolves
the mapped workspace, obtains a verified R4NAK build receipt, prepares Mesa
and shader helpers, builds native C/NIL, and publishes matching archives to
the Zig build. `Artifacts/Native/R4VK/<host>` holds checked native caches;
no temporary fixture path is a build dependency. Windows execution remains
unchecked. Required host tools are described below and in R4NAK/README.md.

Applications import `R4VK:VULKAN_V1:1` through the normal R4M loader. Generated
C/Zig bindings validate the library table. Its `open` call receives the
immutable R4SYS/R4DRAW/R4DEV table addresses and returns the standard ICD
negotiation, instance-proc and physical-device-proc entrypoints. Vulkan then
uses its ordinary x86_64 C ABI. Opening creates no Vulkan object and does not
claim GPU availability. Invalid descriptors leave the output unchanged;
repeat opens with the same boot tables are idempotent. Keep the imported
library generation alive while using its functions or objects. Contract and
API details: `Contract/LibraryContract.json` and `Docs/API.md`.

The normal build runs one generated C/Zig ABI conformance case. The independent
C consumer used for integration links no Mesa/NVK code; all Vulkan calls enter
the canonical R4VK.R4L. See the current scoped result in
`Docs/Drivers/GrafikVulkan07935.json` in the workspace Docs repository.
Full source notices accompany the artifact in `ThirdParty/NOTICES.txt`.

Native capability queries reject external memory handles consistently:
buffer queries retain the requested compatible handle type but expose no
import/export bits; image, fence and semaphore queries likewise promise no
missing transport. The one queue per logical device admits only MEDIUM global
priority. Vulkan's two required relative priority levels give no cross-device
scheduling guarantee. Sparse,
placed-map, external-FD, DRM and calibrated GPU time remain unavailable.
The native physical-device API is 1.3 because GPU timestamps are unavailable;
Vulkan 1.4 requires timestampComputeAndGraphics. Instance API 1.4 and explicit
extensions such as host-image-copy remain usable. The earlier priority=1
profile was invalid: Vulkan's required minimum is 2, regardless of global
priority support. See the normative Required Limits and Queue Priority sections
in the archived Khronos specification and GrafikVulkan07935.json / nvk_limits.
The 0.79.36 shader-object checkpoint enables EXT_shader_object. Both linked
and independent SPIR-V stages run through isolated frontend jobs, retain
serialized NIR/CPU sampler data through backend compilation, and release
every owner on success or failure. Vulkan objects and GPU upload stay on the
caller. A public SMP4 consumer covers VS/FS creation, binary round-trips,
incompatible binaries, partial outputs, callback OOM rollback and a specialized
compute shader's command submission. GPU execution is modeled, not measured.
See Docs/Drivers/GrafikVulkan07936.txt/.json. R4VK 0.1.5 also enables
EXT_device_generated_commands: its initialization/processing builders and
the KHR_copy_memory_indirect helper now use isolated NIR/NAK jobs. CPU stride
and QMD requirements are published only after successful compilation; uploads
and callback allocations stay on the caller. Public SMP4 checks cover explicit
and implicit compute preprocessing, shader execution sets, graphics layout
tokens, callback rollback, indirect copies and modeled submission. Indirect
memory-to-image copy remains unsupported. R4VK 0.1.6 enables KHR_pipeline_library,
EXT_graphics_pipeline_library and KHR_pipeline_binary. Four-part graphics
libraries, fast/LTO linking, retained NIR and compiled binary round-trips use
the same native compiler/cache owners. Binary imports preserve failure codes;
compute feedback starts with no cache hit. Shared shader upload checks device
status even when a retained heap block avoids native allocation. Public SMP4 checks cover short
exports, partial callback OOM, graphics draws after library destruction,
specialized compute submission and binary import after device loss. GPU pixels
and values remain unverified. Binary retrieval from a persistent driver cache
is unavailable; pipelineBinaryInternalCache and its control properties are false.
R4VK 0.1.7 reserves complete native binding pages for image planes and aligns
the D32S8 stencil-copy plane consistently. Public requirements include padding
before later planes/zcull, preventing an out-of-bounds native image binding.
Precompiled shader validation includes task/mesh stages and preserves errors
instead of reporting all frontend payload-transfer failures as host OOM.
A scoped SMP4 scene compiles all graphics stages, records indexed textured
draws with depth/stencil/blend through legacy/dynamic rendering and generated
commands, then reads the target from a storage-image compute shader. The model
checks selected NVIDIA command encoding, native resource coverage and cleanup;
it does not execute GPU instructions or verify pixel/compute results.
Resolve, whole-scope budgets, concurrency and feature/failure admission remain open.

The public C consumer verifies these queries and negative CreateDevice results.
Original host-image-copy code works on the explicitly host-visible RAM type:
RGBA8 and BC1 mip/layer subregions round-trip through real NIL tiling with
row padding preserved. This CPU data comparison does not execute a GPU copy.
An actual kernel-broker reset with modeled GPU quiescence makes the old Vulkan
device report device-lost for WaitIdle/allocation; a new instance/device then
works. Software admission reuses the matching resource/sync/error proofs;
physical execution and Vulkan conformance are not implied.

Query-copy compute shaders and Blit/Resolve fragment shaders now build in
isolated CPU jobs; serialized NIR stays alive until compilation consumes it.
The common clear builder uses the same boundary, while NVK clears use its
original hardware commands. Public SMP4 command recording/submission covers
query copies (32/64-bit, availability), linear/color/integer/depth blits and
four-sample average/sample-zero resolves, each fresh and cached. This proves
compilation, uploads and modeled receipts, not GPU pixels or query results.

`Port/threading.zig` implements process-owned mutexes and conditions on the
R4SYS v19 notification tail (Kernel 0.1.183). An uncontended mutex uses atomic
state and current-thread identity; it performs no notification wait/wake.
`Port/threads_api.zig` exports the C11 subset used by Mesa, native joinable
workers and its monotonic condition interface. Kernel thread admission checks
executable sections of the program's exact imported library generations.
The shared port retains only the immutable boot-lifetime kernel table.

Every mutex, condition and once object must belong to one calling process.
Do not place these objects in shared R4L mutable globals. Once notifications are closed after initialization is published and all
waiters are notified. A waiter racing that close succeeds only after observing
the initialized state; the flag retains the closed, never-reused identity. Mesa global
state must be audited and adapted before integrating additional source units.
An unreportable void-API lifetime failure traps; it never silently continues.
UTC timed waits, detached threads and TLS are not implemented or stubbed.

`Port/runtime.zig` binds the combined port to R4SYS v20 (Kernel 0.1.184).
`Port/memory.zig` implements C allocation with one explicitly owned SDK Heap
per calling process, published through program_local_get/publish. Competing
initializers discard their own metadata region and use the published winner.
Regular allocations reuse SDK blocks; OOM returns null and failed realloc
preserves its input. Process retirement reclaims VM regions without requiring
library destructors. A shared library static supplies only the unique context
key, never a cached caller pointer. The selected source set follows these
process/worker owners; new Mesa globals and host APIs require their own audit.

`Port/time.zig` connects Mesa's private monotonic time/deadline helpers to
R4SYS. Deadline sleep uses the actual event-frequency ratio and rechecks the
monotonic clock after waking. This is not a POSIX clock or UTC implementation.
`Port/MesaRuntime.patch` selects this host timestamp path with `R4OS_VULKAN`,
omits external-FD fence/semaphore entrypoints and excludes DRM device IDs from
the private nvkmd layout. Those omissions require corresponding Vulkan
extensions to remain unadvertised in the future provider.

NVK and the common runtime use one private `vk_image` layout, including NIL's
modifier metadata and its invalid sentinel. This does not expose the DRM
modifier query or external-memory entrypoints. `Port/math.zig` supplies the
integer rounding required by Mesa's descriptor packing: ties away from zero,
independent of the FPU rounding mode, with x86 invalid/inexact flag semantics.
It also provides MXCSR-sensitive `lrint`, signed-bit-preserving `copysign`
and `frexp` decomposition for the full NIR/format path. The private C subset
includes allocation-free nested sorting and OOM-aware string duplication.

`Port/stdio.c` supports caller-owned, seekable output memory streams for Mesa
diagnostics. Growth failure preserves the buffer, position and ownership;
close publishes the buffer for the caller to free even after a write error.
Seek beyond the end allocates on the next write, which zero-fills the gap;
`SEEK_END` refers to the full buffer length. Explicit flush publishes the
smaller of position and length, following the [POSIX memory-stream contract](https://pubs.opengroup.org/onlinepubs/9799919799/functions/open_memstream.html).
This is a private Mesa subset, not a public libc: global `fflush(NULL)` and
closing console identities return an error. Filesystem streams and shared
stream registries are not provided. Mesa must serialize each individual stream.
The targeted Linux host probe checks these primitives with ASan/UBSan and
the floating-point boundaries with all four MXCSR rounding modes.

The complete selected NVK/Vulkan/NIR/format/push-diagnostic C source set now
compiles (512 translation units) and links with original NAK and native NIL.
The native device path excludes calibrated
timestamps, RMV and WSI dispatch; swapchain-image requests return unsupported
until the native WSI integration exists. Experimental NVX CUBIN imports are
excluded consistently with the native instance's disabled experimental flags.
The selected shader-job and resource-provider paths are integrated; native
WSI remains later roadmap work.

CPU capability/once state, GLSL interned types, shader-printf caches and NIR
diagnostic mutexes belong to the calling process. Generic C state publication
checks size/alignment and zeroes before publication. Instance lifetime owns
GLSL cache references; initial cache OOM fails construction. CPU instruction
facts come from CPUID/XCR0. Topology and affinity remain unknown; this selected
runtime must not use generic Mesa worker-pool scheduling based on those fields.

Private C errno and diagnostic buffers belong to an admitted compiler worker
call. Native options preserve upstream defaults; environment-driven shader
dump/replacement files are excluded. Assertion/abort on that worker fails its
job; outside it the failure traps. This is not general TLS or a filesystem.
Each commandbuffer owns its own OOM runout buffer. Generated helper printf
metadata is registered per process/job. Full graphics pipeline and optional
shader-object/generated-command integration continues in 0.79.36.

NVK's NIR-to-machine-code phase now uses an isolated CPU job. Original const
NIR serialization/deserialization gives the worker its own graph and interned
types. GLSL/printf caches and diagnostic mutexes are job-owned there; every C
allocation is tracked separately from Rust backing blocks. OOM/abort retires
the worker, and exact join precedes disposal of all remaining storage. The
borrowed device compiler is immutable. No GPU resource or callback-owned
Vulkan object is created inside this boundary. On success, ordinary shader
storage receives the code, constants and optional diagnostics before the job
is destroyed; upload then uses the existing caller-side rollback path.

Public compute pipelines also run SPIR-V translation, specialization and NIR
preprocessing in an isolated job. The original precompiled-shader wire format
crosses that boundary; Vulkan allocation callbacks, cache insertion and GPU
uploads remain outside it. The compute backend deserializes cached NIR inside
its own job, without creating a caller-owned intermediate graph. Frontend
warnings/errors are captured in bounded stack-owned storage and delivered to
Vulkan debug callbacks after join, including failure; truncation is reported.
The native builtin-NIR frontend likewise serializes/deserializes its types.
Graphics pipeline inputs now use the same serialized boundary described below;
shader objects and other builtin builders remain open.

A targeted SMP4 probe passes private-cache isolation, allocation overflow,
bounded C-heap exhaustion, abort while holding a private diagnostic mutex,
unchanged failed-owner output, and two real NAK compute compilations/uploads
with balanced cleanup. A subsequent public compute probe also passes a valid
SPIR-V storage-buffer shader with specialization, compile-required cache miss,
cache hits and export/import, frontend OOM/abort, translator error callbacks
and valid retry. Callback allocations and the final C heap balance. The GPU
peer models uploads and does not execute the machine code. Graphics linking,
shader objects, shader printf and Vulkan conformance are not established by
these checks.

Native pipeline-cache exports retain the standard Vulkan header and add a
versioned envelope with BLAKE3 record checksums. Import validates the entire
envelope before creating raw cache objects; incompatible initial data yields
an empty cache. Lazy typed deserialization preserves allocation/device errors
and keeps bytes for retry. NVK checks shader metadata and complete payload
extents before allocating/uploading; diagnostic string OOM remains an error.
Failed optional insertion retains only the caller's usable object, while
mandatory import and merge allocation failures unwind and return OOM. Short
exports contain complete records, and serialization diagnostics run after unlock.
The provider's cache identity includes the verified native sources, compiler
archives and build options; Tools/BuildNative.ps1 emits the required digest.
The targeted SMP4 cache probe passes corrupted/truncated inputs, import and
lazy-load OOM, full-table insertion/merge failure and retry, partial export
reuse and final zero C allocations. Its first failure exposed a string-reader
assertion after an earlier bounds error; blob reads now retain that error.

Compute meta copy/fill NIR builders now run as isolated CPU jobs. They publish
serialized bytes through a private native NIR-stage input, retained until
pipeline creation returns. Hashing consumes those bytes directly; the normal
isolated frontend reconstructs its graph. No GPU resource or Vulkan allocator
callback is created on the builder worker. Vulkan util sources/headers share
the same prepared private layout as runtime consumers.
The targeted SMP4 probe covers public descriptors/samplers, Fill/Copy/Update,
barriers, decoded compute launch methods, QueueSubmit2 binary/timeline chains,
fence timeout/completion/reset and command-pool reuse. Injected meta-builder
OOM/abort reaches EndCommandBuffer; retry succeeds and final allocation counts
balance. The backend models receipts without executing the GPU instructions.
The following image checkpoint extends this proof; final feature admission and installed packaging remain open.

Image command integration now includes RGBA8 graphics/compute and BC1/D32
copy-engine paths, mip/layer subregions and padded rows. The native meta NIR
builder is shared by copy/fill and rectangle stages; graphics pipeline inputs
also remain serialized until the backend job. Scalar tessellation state is
passed separately, without a caller-owned NIR graph. This does not establish
all geometry/tessellation, pipeline variants or shader-object paths.
Command buffers request their actual structure alignment; the image probe
exposed an aligned SSE store on an allocation previously requesting only eight
bytes. Meta cache initialization, keys and mandatory insertion now report OOM
and destroy unretained objects. Cache lookups capture object pointers while
holding the mutex, before another insertion can invalidate table entries.
Temporary compute-meta push descriptors are freed after their bytes have been
uploaded into command-owned memory, before restoring the caller state; the
second guest exposed their previous loss during final allocation accounting.
The bounded SMP4 probe checks decoded compute/draw/DMA commands, vertex OOM,
fragment abort, meta retention OOM/rehash/retry and final cleanup. Model
completion does not prove image contents or physical memory visibility.

`Tools/BuildNative.ps1 -CompilerRoot <native-NAK> -MesaRoot <prepared-Mesa>
-ShaderRoot <prepared-helpers> -OutputRoot <native-output>` now owns the native
C dispatch build. Paths resolve against the mapped workspace. It reuses the
NAK owner's ABI flags/source selection, validates preparation records and all
outputs, and compiles the selected 512 C units without fixture interceptors.
Source/header/tool hashes and compiler arguments determine the generated
`r4vk_build_identity`; `native.json` records the archive and object hashes.
An unchanged cache is verified, while damaged outputs are rejected.
One deterministically ordered combined archive member preserves weak Mesa
dispatch implementations; a response file avoids Windows command-line limits.
The Linux build, cache reuse/rejection and R4M link pass. Windows execution
remains unchecked. The R4VK module build links the
archive with matching native NAK/NIL and the R4VK Zig runtime. The archive
build alone does not grant Vulkan capabilities.

`Tools/Prepare.ps1 -OutputRoot <workspace-relative-or-absolute-output>` verifies
the existing pinned Mesa source manifest, creates private C/header overlays
and runs the original Vulkan/NVK/NIL table generators. Prepare the shared
Mesa toolchain through `R4NV/Tools/Compiler` first. The script does not download
sources, alter the pinned source tree or build a complete provider. Consumers
must compile the private NVK, Vulkan-runtime, compiler and util source/header
trees together, with `R4OS_VULKAN`
and the generated headers, so relative includes cannot bypass the port.

`Port/process_local.zig` publishes resident process-owned contexts for the
heap and loader state. `Port/loader.zig` implements ICD negotiation v1-v7,
rejects v0, and preserves the lowest negotiated version within one process.
Mesa's instance path uses the native enumerator in `Port/nvk_enumerate.c`.
It scans all bounded inventory slots, skips holes/incompatible devices and
publishes the complete list only after revalidating each captured incarnation.
Failure destroys all newly created devices; an inventory without eligible
NVIDIA hardware succeeds with an empty list. Missing platform tables remain
an initialization error. `Port/platform.zig` retains only immutable boot-time
table addresses. The verified native build supplies the required build digest.

The private NVK patch rejects external FD memory before GPU allocation,
removes its Linux-only entrypoints, rolls back failed internal map counts,
unlinks failed mapped allocations and destroys each retired BO's map mutex.
The canonical provider uses this construction and discovery path.

The private original `nvk_device.c` now checks the exact native backend's loss
state and marks the Vulkan device lost. Devices without execution queues do
not inspect a nonexistent shader-printf buffer. Native device initialization
omits DRM FDs and DRM sync-payload copying; ordinary native queue submission
remains the synchronization path. GPU timestamp queries explicitly return
unsupported without modifying output until the owner exposes that operation.
Failed device construction destroys initialized meta state, and a zero-queue
cache-allocation failure skips resource owners that were never initialized.
The targeted SMP4 integration now passes public device/queue construction,
first-allocation OOM, buffer map/binding, optimal image/view creation, idle and
balanced destruction. Internal streams use Mesa timelines backed by native
fences; direct NVKMD calls allocate/unwrap points before submitting and publish
only successful signals. Timeline OOM/retry and zero/completed waits pass.
A zero M2MF class denotes an absent engine and emits no legacy setup commands.
These checks use a modeled GPU peer with real kernel brokers, not GPU execution.
Further command/shader integration and broader constructor faults remain open.

`Port/Include/assert.h` follows C's NDEBUG and re-inclusion rules. The compiler
port's unconditional assertion macro is unsuitable for Mesa release structures
whose debug-only fields are absent. Assertions remain active in debug builds.

`Port/nvk_va.c` implements NVK's private VA allocation/bind/unbind/free operations
through the SDK's R4DRAW virtual-resource broker. Its context belongs to one
NVK device and requires that device's canonical BO-reference accessor. The
kernel takes its own BO loan; neither a caller pointer nor a C destructor is
retained in a driver. Non-sparse bindings may alias the same backing at several
addresses. Exact unbind waits for confirmed retirement. Free closes the parent
and requests ordered child cleanup, which may continue after C metadata is freed.

Finite operations use one native clock snapshot for the broker deadline and
the rounded wait duration. Failed allocation leaves the output unchanged;
timeout, stale epochs, malformed completion and uncertain cleanup set the
context's device-lost state. NVK device/queue status propagates this state.
R4DRAW36 plus explicit architecture revision3 IMAGE_LAYOUTS permits
uncompressed NVIDIA PTE kinds1..6 in system memory and VRAM. Kind travels in
the broker's opaque layout byte; the driver supplies matching RM depth/packing
attributes and requires exact allocation/map acknowledgements. Old backends
and kernels retain linear-only support. Compressed/unknown kinds, sparse/replay
VA, overlapping replacement and partial unbind remain unsupported.
The installed R4VK provider owns these backend components.

`Port/nvk_mem.c` owns native NVK memory through the common BO and native VRAM
brokers. Each allocation has its canonical BO reference and a bound VA range;
failure unwinds in reverse order. Kernel loans retain backing through late
VA retirement. Internal and client CPU mappings share one persistent kernel
lease while NVK retains its own internal map count. Persistent mapping requires
R4DRAW's optional `gfx_buffer_map_persistent` tail (v33, Kernel 0.1.189).
It holds write-back system RAM without excluding device/queue use. The caller
must synchronize actual CPU/GPU accesses; this lease is not a GPU barrier.

Mappable or explicitly coherent LOCAL memory uses GART. Explicit VRAM allocations never silently
change location, and CPU VRAM/BAR maps, external memory, fixed maps and overmap
are unsupported. Host coherence is accepted only from architecture-properties
revision 2's explicit system-memory capability: native x86_64 WB RAM, cached
RM registration and acknowledged snooped/GPU-uncached maps. Revision 1 and
revision 2 without that bit remain noncoherent; mismatched versions or unknown
flags fail without output mutation. Coherent explicit VRAM remains unsupported.
Noncoherent maps use Mesa's actual cache operations. Admitted devices require
explicit host coherence; memory types expose RAM and VRAM without a BAR heap
or unsupported budget telemetry. Memory and VA contexts share one atomic
device-lost state and outlive their NVK objects; the kernel never retains their C addresses or destructors.

`Port/nvk_device.c` reads NVIDIA's architecture facts through the optional
R4DRAW v34 backend-properties slot (Kernel 0.1.190, NVIDIA 0.1.130). It validates
the exact backend/memory generation, protocol and supported chip identities
before constructing Mesa's `nv_device_info`. PCI identity, active GPC/TPC counts,
VRAM and VA limits come from the driver's captured/acknowledged records. Shader
geometry uses the pinned SM86/89 definitions; CPU cache granularity comes from
CPUID. Errors preserve output, and stale epochs report device-lost.

The kernel copies one immutable bounded payload per backend incarnation,
authenticates the publishing driver and invalidates it on reset. Old backends
without properties remain usable through their original interface. The native
driver publishes these facts after CE startup, independently of display registration
(NVIDIA 0.1.131). Provider admission validates these records. Architecture
classes describe hardware methods, not admitted command queues. No BAR mapping,
transfer queue, 2D/M2MF, ZCULL or Vulkan qualification is inferred. Host coherence
uses the explicit native mapping-policy capability above, not GPU class IDs.

`Port/nvk_resource_device.c` creates native `nvkmd_pdev` and `nvkmd_dev` objects
for an exact backend incarnation. Mesa's original dispatch/list/refcount code
reaches the R4OS memory/VA adapters through their device operations. Creation
and resource allocation revalidate the binding; a missing former incarnation
sets sticky device-lost instead of selecting a replacement. Logical devices
have separate memory lists and loss state. They retain their physical owner;
memory and standalone VA objects retain their logical owner through destruction.
Final C cleanup may precede resident broker retirement without leaving caller
pointers in the kernel. Partial construction preserves output and unwinds.

The original NVK physical-device constructor now has a native entry receiving
an exact R4OS backend and the immutable platform tables. `Port/nvk_physical.c`
revalidates the captured NVKMD owner and describes two heaps: non-mappable
device-local VRAM, and cached/coherent system memory. System capacity comes
from R4DEV total physical RAM minus the application reserve, rounded to the
backend binding alignment; allocation budgets still apply independently.
One graphics/compute/transfer queue is exposed by the resource description,
with medium priority and no sparse or timestamp-query claim. Native filtering
removes FD/DRM, placed mapping, capture/replay, sparse, calibrated timestamps,
memory-budget telemetry and HDR metadata that lack native implementations.
The port does not inherit Linux NVK's conformance version.

The constructor is compiled in assertion/release modes. The final advertised
API/feature profile and complete logical-device integration remain open.
The targeted SMP4 fixture executes the original public CreateInstance and
DestroyInstance, complete physical-device construction and native enumeration
with real NAK/NIL, generated queries, OOM and partial-enumeration cleanup.
GPU facts remain modeled; VKPORT is a temporary test module, not an installed
R4VK provider or a complete logical VkDevice.
`Port/compiler.zig` gives the real Rust NAK compiler its own
process-owned arena, retained by the native physical device. Creation and
destruction run on joinable workers; Rust OOM/panic terminates that worker
without unwinding through C. The parent waits for exact retirement before
releasing storage. Failed owners cannot be reused, and separate owners can
run concurrently. The process registry contains active calls only; no caller
pointer lives in shared R4L BSS. Both outputs remain unchanged on create failure.

This adapter links the verified freestanding Rust NAK archive, not R4NAK's
job runtime or its complete C archive. Successful creation retains the actual
NAK object, and destruction normally calls its original Rust destructor. If
a destructor worker cannot start, the arena can release this compiler's CPU
allocations directly; the pinned object contains no external resources.
The arena records bounded diagnostics and uses the native process allocation
budget. Full shader jobs still require C/NIR global-state ownership, their
allocation/abort boundary, cancellation/deadlines and output lifetimes.
Those are not supplied by wrapping the physical-device constructor alone.
No successful replacement compiler or default build identity is provided.

`Tools/BuildNil.ps1 -CompilerRoot <R4NAK-cache> -MesaRoot <prepared-Mesa>
-OutputRoot <separate-output>` builds original freestanding NIL from the same
verified Mesa source. It checks the current NAK build inputs and archive,
matches Rust dependency object code against that archive, regenerates target
bindings, and records tool/input/output hashes in `nil.json`. It requires the
existing R4NAK preparation and `Tools/Prepare.ps1` outputs; no temporary helper
or host libc is part of this build. Verified unchanged outputs are reusable.

The two image constructors are private unchecked Rust entries. `Port/nil.c`
owns their native boundary: a separate short-lived compiler arena runs each
calculation on a joinable worker and publishes its local image only after
success. Original layout assertions become format rejection; worker/arena
OOM and initialization errors retain their distinct Vulkan results. NVK's
four construction sites propagate these results. No Rust unwind crosses C,
and an invalid image cannot poison a physical device's NAK compiler. Other
NIL descriptor/copy operations retain their original valid-input contracts.
This boundary runs at image construction, not per submitted frame.

Native image-format queries reject external handles, DRM tiling and sparse
flags with zeroed base properties. Calibrated-clock enumeration is excluded;
the native API version cannot be raised with Mesa's environment override.
Formatting uses the existing licensed stb_sprintf implementation; ordinary
C string operations are provided without the R4NAK job runtime.

Generated native entrypoints preserve weak ELF binding with default visibility.
R4XBuilder leaves only fully linked, verified ABS64 weak-undefined NULL pointers
unrelocated. Strong/local undefined targets, nonzero values/addends/pointers,
unlinked inputs and relaxed GOT relocations remain errors. Manifest-selected
R4M exports and the loader format are unchanged.

The original public NVK instance entrypoints use per-instance native defaults
from `Port/nvk_options.c`, matching the pinned baseline values. Linux DRIRC,
identity/experimental overrides and RMV/file tracing are excluded from this
policy. Instance failure unwinds copied application/engine names, creation
messengers and initialized mutexes; mutex OOM preserves its Vulkan error kind.

Original Mesa error/debug functions are linked to the process-owned C heap.
Creation callbacks are considered even in a release logging build; diagnostic
allocation failure cannot turn a returned Vulkan error into a NULL access.
`Port/console.zig`, `stdio.c` and `log.c` send unbuffered diagnostic output
through the current caller's R4SYS console. Formatting uses bounded streaming
scratch space without heap allocation. This supplies console streams only;
no filesystem FILE, caller stream handle or Linux environment is fabricated.

`Tools/Archive.ps1` preserves Mesa's required `link_whole` dispatch semantics.
`New-R4VKDispatchArchive` combines the explicit C object set into one archive
member through Zig LLD `-r --unique`, keeping same-named static sections
separate for final garbage collection. This retains weak-only generated
query implementations while excluding unrelated shader globals. Rust archives
retain normal selective extraction. Rebuilds replace the archive completely.
The public-instance SMP4 probe covers function lookup, allocation-failure
rollback, repeated/incomplete enumeration, physical properties and actual
creation/runtime debug callbacks with zero remaining C allocations.

`Port/nvk_submit.c` connects NVK contexts to the canonical native queue. It
translates GR/compute/copy engine bits, including NVK's copy-only upload
context through a GR channel with paired CE. Initial admission waits for an
actual fence; class IDs alone do not suffice. Push lists split at complete
method groups, preserve no-prefetch and use the R4NV packet contract.

Submissions retain all live bindings, including aliases after their original
BO object closes. The broker owns these loans independently of C metadata.
Because indirect GPU addressing prevents precise access discovery here,
device queues conservatively chain on genuine GPU fences. This matches the
currently serialized physical publisher and avoids spurious cross-queue
writer conflicts. Empty fence batches need no caller binding snapshot.
The retained device tail is explicitly released at logical device close.
No resource/submit mutex spans a GPU wait; failed allocation preserves the
buffered batch. Queue capacity applies bounded backpressure.

`Port/nvk_sync.c` supplies native binary events; Mesa's original timeline
implementation wraps their actual submitted points. Pending submission is
distinct from GPU completion. Dependencies pin their kernel handles while
being copied, completed points release public metadata, and reset/failure
propagates device-lost. Objects own their mutexes/conditions; no shared R4L
mutable cache or invented GPU completion is used. Native absolute waits use
R4SYS time; the POSIX MESA_VK_MAX_TIMEOUT debug override is excluded.

Legacy tiled-BO allocation, sparse-bind contexts and external handles remain
unsupported; uncompressed tiled images use the explicit VA kinds above;
GPU timestamps and usage telemetry have no native owner callback. BAR mapping,
sparse, compression and external-FD remain unadvertised. The provider filters
features and limits to the native adapter contract. It does not inherit
upstream Linux conformance; the published conformance version is zero.

`Tools/PrepareShaders.ps1 -OutputRoot <output>` builds the original Mesa CLC
and NIR binding generator in a private source tree. It generates the NVK
query and indirect-copy helpers as native C with unchanged SPIR-V/NIR data.
`Port/MesaGenerators.patch` exposes the complete immutable printf metadata
through an explicit accessor instead of a C++ global constructor/destructor.
The provider registers it in its process-owned compiler context.
These host tools are not linked into R4OS. The shared Mesa lock and
`Tools/ShaderTools.lock.json` pin dependencies; `shaders.json` records options,
input/tool/output hashes. Windows and Linux use the same PowerShell path;
only Linux execution has been checked. Host prerequisites include LLVM/Clang
19 development files, SPIRV-Tools and LLVM-SPIRV with matching pkg-config data
(Debian: llvm-19-dev, libclang-cpp19-dev, libllvmspirvlib-19-dev, spirv-tools).

Earlier bounded SMP4 proofs use temporary native C/R4L fixtures. Actual
Mesa/NVK resource, sync and timeline code uses real kernel
queues and brokers with explicitly modeled GPU/VA receipts. Diagnostic-only
fixture replacements preserve negative errors and Mesa's lost flag; they do
not complete work. This does not validate physical GPU execution or DMA.
Evidence and remaining integration work are recorded in
`Docs/Drivers/GrafikVulkan07935.txt/.json` in the workspace's Docs repository.
Physical GPU validation remains in `ExFiles/Reports/OssiGPU.txt`.

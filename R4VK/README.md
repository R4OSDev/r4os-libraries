# R4VK development state

Work for roadmap 0.79.35 is in progress. This directory currently provides
Mesa's native CPU runtime and NVK resource devices, memory/VA, hardware
descriptions and native submit/sync adapters. It does not yet install an
R4VK.R4L, ICD, Vulkan device or advertised Vulkan feature set.
The selected provider remains pinned Mesa NVK/NIL/NAK with R4OS resource
contracts; NVIDIA.R4D remains the sole hardware owner.

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
key, never a cached caller pointer. This does not yet audit or port all Mesa
global state, file APIs, Rust allocation or Vulkan callback allocation paths.

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

`Tools/Prepare.ps1 -OutputRoot <workspace-relative-or-absolute-output>` verifies
the existing pinned Mesa source manifest, creates private C/header overlays
and runs the original Vulkan/NVK/NIL table generators. Prepare the shared
Mesa toolchain through `R4NV/Tools/Compiler` first. The script does not download
sources, alter the pinned source tree or build a complete provider. Consumers
must compile the private NVK and Vulkan-runtime source/header trees together, with `R4OS_VULKAN`
and the generated headers, so relative includes cannot bypass the port.

`Port/process_local.zig` publishes resident process-owned contexts for the
heap and loader state. `Port/loader.zig` implements ICD negotiation v1-v7,
rejects v0, and preserves the lowest negotiated version within one process.
Mesa's instance path requires an explicit native enumerator: an absent backend
is an initialization error, and failed enumeration destroys partial devices
before retry. The future adapter backend and build digest remain required
external symbols; neither has a successful fallback definition.

The private NVK patch rejects external FD memory before GPU allocation,
removes its Linux-only entrypoints, rolls back failed internal map counts,
unlinks failed mapped allocations and destroys each retired BO's map mutex.
Full Vulkan device construction and discovery still require provider integration.

The private original `nvk_device.c` now checks the exact native backend's loss
state and marks the Vulkan device lost. Devices without execution queues do
not inspect a nonexistent shader-printf buffer. Native device initialization
omits DRM FDs and DRM sync-payload copying; ordinary native queue submission
remains the synchronization path. GPU timestamp queries explicitly return
unsupported without modifying output until the owner exposes that operation.
Failed device construction destroys initialized meta state, and a zero-queue
cache-allocation failure skips resource owners that were never initialized.
Full constructor/runtime integration and its fault coverage remain pending.

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
context's device-lost state. The final NVK device/queue must propagate this
state. R4DRAW36 plus explicit architecture revision3 IMAGE_LAYOUTS permits
uncompressed NVIDIA PTE kinds1..6 in system memory and VRAM. Kind travels in
the broker's opaque layout byte; the driver supplies matching RM depth/packing
attributes and requires exact allocation/map acknowledgements. Old backends
and kernels retain linear-only support. Compressed/unknown kinds, sparse/replay
VA, overlapping replacement and partial unbind remain unsupported.
This is one backend component, not an installed or complete Vulkan provider.

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
Noncoherent maps use Mesa's actual cache operations. Vulkan device admission, published memory types/budgets,
cache/barrier integration remain required. The private
memory and VA contexts share one atomic device-lost state and outlive their
NVK objects; the kernel never retains their C addresses or destructors.

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
(NVIDIA 0.1.131). Vulkan enumeration and device admission remain pending. Architecture
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

The constructor is compiled in assertion/release modes. The temporary SMP4
fixture executes original Mesa memory/queue queries and capability filtering;
complete constructor execution and the final advertised API/feature profile
remain open. In particular, NVK retains a NAK compiler across operations, while
the existing R4NAK archive allocates within an isolated compilation job. Its
allocator/abort boundary must be integrated before publishing Vulkan devices.
No successful replacement compiler or default build identity is provided.

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

Tiled memory, sparse-bind contexts and external handles remain unsupported;
GPU timestamps and usage telemetry have no native owner callback. BAR mapping,
sparse, compression, external-FD and public Vulkan capabilities remain unadvertised.
Public Vulkan admission, feature/limit reporting and full device/error/logging
integration remain required; these private adapters are not that admission.

`Tools/PrepareShaders.ps1 -OutputRoot <output>` builds the original Mesa CLC
and NIR binding generator in a private source tree. It generates the NVK
query and indirect-copy helpers as native C with unchanged SPIR-V/NIR data.
`Port/MesaGenerators.patch` exposes the complete immutable printf metadata
through an explicit accessor instead of a C++ global constructor/destructor.
The future provider must register it in its process-owned compiler context.
These host tools are not linked into R4OS. The shared Mesa lock and
`Tools/ShaderTools.lock.json` pin dependencies; `shaders.json` records options,
input/tool/output hashes. Windows and Linux use the same PowerShell path;
only Linux execution has been checked. Host prerequisites include LLVM/Clang
19 development files, SPIRV-Tools and LLVM-SPIRV with matching pkg-config data
(Debian: llvm-19-dev, libclang-cpp19-dev, libllvmspirvlib-19-dev, spirv-tools).

The bounded SMP4 proof uses a temporary native C/R4L fixture, not a Vulkan
provider. Actual Mesa/NVK resource, sync and timeline code uses real kernel
queues and brokers with explicitly modeled GPU/VA receipts. Diagnostic-only
fixture replacements preserve negative errors and Mesa's lost flag; they do
not complete work. This does not validate physical GPU execution or DMA.
Evidence and remaining integration work are recorded in
`Docs/Drivers/GrafikVulkan07935.txt/.json` in the workspace's Docs repository.
Physical GPU validation remains in `ExFiles/Reports/OssiGPU.txt`.

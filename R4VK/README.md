# R4VK development state

Work for roadmap 0.79.35 is in progress. This directory currently provides
Mesa's native CPU threading and process-owned memory transport. It does not yet install an R4VK.R4L,
ICD, Vulkan device, GPU submission path or advertised Vulkan feature set.
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
Memory allocation, CPU mappings, device discovery and submission still require
the complete R4OS backend.

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
state. Sparse/replay VA, nonzero PTE kinds, overlapping replacement and partial
unbind are explicitly unsupported. No corresponding features may be advertised.
This is one backend component, not an installed or complete Vulkan provider.

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

The bounded CPU proof uses a temporary native C/R4L fixture, not a Vulkan
provider. Modeled enumeration and memory failures exercise actual Mesa/NVK
list, map and refcount code; they do not validate real GPU discovery or DMA. Evidence and remaining integration work are recorded in
`Docs/Drivers/GrafikVulkan07935.txt/.json` in the workspace's Docs repository.
Physical GPU validation remains in `ExFiles/Reports/OssiGPU.txt`.

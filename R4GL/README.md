# R4GL

Native Mesa EGL/OpenGL runtime for R4OS. The initial software profile uses
softpipe without LLVM/JIT and works without a native GPU backend.
It currently negotiates EGL 1.5 and OpenGL 3.3 Core. Version 0.1.15 also
connects Zink directly to the native R4VK ICD. Its pbuffer and native window profiles
have passed GLSL drawing submission, EGL fences, resize and buffer retirement
with modeled NVIDIA and AMD Picasso devices. Physical GPU pixels remain unqualified.

Build from the workspace with `Repositories/Libraries/Build.sh R4GL`
(Windows: `Repositories\Libraries\Build.bat R4GL`). Add `-Doffline=true`
to require cached source archives. Shared PS7 orchestration derives paths
from Libraries/Settings.R4S. Dependencies: pinned Clang/LLVM 19.1.7, the
workspace Zig toolchain, Python 3 with Mako/PyYAML/packaging, Bison, Flex,
glslangValidator, Git and tar; online source acquisition also uses curl.
The software build needs no host Rust compiler or Meson installation.

`Tools/NativeInputs.json` owns the native unit/flag selection;
`Generators.json` owns the ordered upstream generator calls. The shared
Mesa source lock and ordered `Port` patches identify the source. Sources,
generated files and archives live below the configured artifact root.
Build receipts verify input and output hashes before cache reuse. The C++
and shared math/scanner sources are pinned separately. Backend admission uses
the actual Vulkan features and limits, independently of archive contents.

Import `R4GL:EGL_V1:1` and the R4SYS/R4DRAW/R4DEV platform groups. Call
`open` with the actual application startup context, then resolve standard
EGL/GL commands through the returned resolver. C consumers include
`Bindings/C/r4gl_api.h`; Zig consumers use the generated `r4gl.zig` binding.
Use standard API queries and context negotiation for supported capabilities.
`EGL_DEFAULT_DISPLAY` selects the opened process profile. Native window handles
encode the application's WINSVC window ID; pbuffer rendering is also supported.
EGL configs advertise swap intervals 0..1 only when a current output reports
synchronized FIFO presentation. Otherwise they advertise 0..0; the firmware
framebuffer does not promise VSync. When synchronized configs are offered,
additional 0..0 configs remain available for unsynchronized window targets.
Choose a compatible config for the window; creating a synchronized surface
on an incompatible output fails with `EGL_BAD_MATCH`. Intervals are clamped
by EGL to the selected config's limits. The default is 1 where supported.

Interval 0 selects MAILBOX when available, otherwise FIFO without a timing
promise. Interval 1 requires the exact output lifetime's synchronization
capability and selects FIFO. A change takes effect on the next swap; already
queued FIFO frames drain before the old chain closes. Outstanding consumer
loans keep their fence metadata and storage until release. A transient timeout
retains that state for retry. Losing synchronization rejects interval-1 posting;
the app can select 0 or recreate a compatible surface. No synthetic VBlank or
extra pixel copy is introduced. Evidence/EGLSwapIntervals covers the native
admission and chain transitions with controlled host responses, and the real
SMP4 firmware fallback. Physical VSync remains in OssiGPU/0.79.39.

For sRGB window/pbuffer attachments, request `EGL_GL_COLORSPACE_SRGB` and
use `glEnable(GL_FRAMEBUFFER_SRGB)` for linear shader output. EGL's default
linear surface remains linear even when the GL switch is enabled. The window
transport presents the stored SDR bytes without a second encoding pass;
alpha remains linear. Surface queries and GL attachment encoding agree after
rebinding and resizing. Evidence/EGLColorCore covers actual pixel values,
shader blending, core platform/image/sync calls, 64-bit attribute rejection
and window resource retirement in SMP4. This is focused software evidence,
not a full conformance certification. The core fence API requires EGL 1.5;
`eglCreateSync64KHR` independently requires the unadvertised CL extension.

`EGL_KHR_fence_sync` and `EGL_KHR_wait_sync` use Gallium fences from the
actual GL command stream. Softpipe completes rendering synchronously.
Client waits, server waits, status queries and deletion share resource
ownership; deleting a handle defers storage release until active calls return.
Fences retain their display backend and survive destruction of their creating
context. Reusable syncs and OpenCL event interop are not advertised.

The EGLImage frontend exports GL 2D textures, cube faces, 3D slices and
renderbuffers, and imports them through Mesa's GL image commands. Consumers
retain storage after the EGLImage handle is destroyed. Native metadata tracks
image siblings and detaches shared storage on respecification; framebuffer
and sampler views carry the selected mip level and layer. Focused software
probes cover these paths, including independent contexts and same-size
respecification. Structural changes clone distinct shared allocations before
publishing new storage; ordinary subimage writes and complete mipmap generation
keep sharing. Incomplete mipmap generation detaches siblings, and renderbuffer
exports use an atomic claim. Uploads, readback, copies and clears share physical
level/layer addressing, including immutable views of imported storage. Exports
and renderbuffer imports preserve the view's format. Focused SMP4 probes cover
five image/view families and RGBA8/R32UI reinterpretation. Imports acquire and
validate storage before replacing the old image; a rejected import preserves
its contents and mutability. Native image shape is independent of its backing
allocation. Surface resources use the final EGL reference callback, including
outstanding dispatcher loans after handle deletion. Evidence/EGLImageImport
covers these cases. Before exporting mutable storage, compatible defined mips
share a complete allocation that stays stable across BaseLevel/MaxLevel changes.
An existing complete allocation is reused. Evidence/EGLImageLevels covers both
range changes, inactive mip exports and a non-power-of-two root. These focused
proofs do not claim complete EGLImage conformance.

AMD Picasso uses the same profile-1 Zink/R4VK path with the RADV provider.
R4GL does not require a fabricated Vulkan border-color-swizzle extension:
when it is absent, Vulkan sampler views retain identity component mappings
and NIR applies the final GL mapping per stage and sampler binding. Float and
integer constants, sampler arrays and gathers retain their types and texel
order. Rebinding changes the shader key. Bindless textures are not offered
on this fallback because their handles have no fixed per-binding key.
Missing native stipple modes select Zink's existing geometry/fragment shader
lowering when the actual geometry and sample-shading features support it.
R4VK 0.1.21 pools small private AMD allocations and retains closed byte extents
until all submissions using their native root have completed. The native
32-root-binding limit remains unchanged. See AMDEGL08026.txt/.json in Docs.

Choose profile 0 for software rendering, or profile 1 for Zink pbuffer/window rendering. Profile 1 additionally requires the application's ordinary
`R4VK:VULKAN_V1:1` import; keep both library generations loaded through GL
cleanup. `open` creates no GPU device. `eglInitialize` checks the real Vulkan
baseline and reports `EGL_NOT_INITIALIZED` if it cannot create a suitable
backend. Failed initialization can be retried. The process profile is immutable;
there is no implicit switch to software after selecting Zink. Profile 0 remains
usable without an R4VK import.

The Zink path uses native ICD dispatch and process-owned instance/device caches.
It has no host Vulkan loader or installed layers and does not read host drirc.
GL up to 3.3 Core is currently offered. Native window configs additionally
require the real swapchain/mutable-format extensions and R4VK window entrypoint.
The private Kopper platform copies the application and WINSVC identity; it uses
R4VK's existing surface API and canonical GPU buffers. Zink interval 1 requires
both a synchronized output and the private R4VK queue-drain entrypoint. Config
discovery includes additional outputs; each window still checks its exact target. Evidence/EGLZinkBootstrap records the admission/cleanup proof without a
GPU, software shader pixels, and a separate actual Zink/R4VK context on controlled
GA106 metadata. The model does not execute GPU drawing or validate image output.
Evidence/EGLZinkDraw additionally covers actual GLSL330 compilation, pbuffer
drawing submission through NVK/NAK, EGL fence completion and the exact buffer
balance before process exit. Native command/resource packets are validated by
the model, which acknowledges completion without executing GPU instructions.
There is no GPU pixel or physical completion proof. A C11 barrier lifetime bug
in Mesa queue retirement was fixed by destroying the barrier only after all
worker callbacks complete; parallel work and native lifetime checks remain.
Evidence/EGLZinkWindow covers an sRGB native window, three presentations,
resize, a consumer loan surviving EGL teardown, and the exact initial buffer
balance before process exit. The last two frames do not call glFinish: the
frontend flushes pending vertices, marks the image for presentation and submits
the batch before presenting. GPU synchronization uses the presentation semaphore,
without an unconditional CPU wait in eglSwapBuffers. QueuePresent's synchronous
result is reported to EGL. A separate no-GPU run preserves admission failure,
explicit profile selection and Softpipe shader pixels.
Evidence/EGLZinkSwap qualifies native intervals with the real WINSVC and a modeled
synchronized output: FIFO timeout preserves both queued frames and order; retry
can change to MAILBOX, then back to FIFO. Loss of the output timing capability
rejects synchronized swaps before making a presentation semaphore; interval 0
can retry the still-owned image. An already acquired image is presented under
the old policy, then the replacement applies to the next image. The private
R4VK drain uses a one-second queue-wait deadline; an in-flight bounded service
RPC may finish afterwards. It does not wait for scanout or consumer-held images. Consumer loans and full buffer retirement
remain correct across teardown. No extra pixel copy or synthetic VBlank is used.
Device loss preserves the original drawable ownership for normal retirement;
Zink must not dereference a failed replacement allocation on a lost device.
Evidence/EGLZinkDeviceLoss resets the real kernel backend generation with a live
context, pending draw and consumer-held image. Repeated swaps report
EGL_CONTEXT_LOST, teardown returns the exact initial buffer balance, and the
consumer can return its retained image after EGL destruction. The GPU is modeled;
physical reset/recovery is still in OssiGPU.

Evidence/EGLDesktop completes the ordinary Desktop integration with the public
[triangle example](Examples/README.md): actual Softpipe pixels in a decorated
window, borderless fullscreen, exact geometry restoration and runtime finish in
SMP4/1 GB without NVIDIA. Desktop retires its last image when the producer closes
the chain, including occluded windows; reader, mapping and fence ownership still
follow the acknowledged Return path. The [capability record](Docs/Capabilities.md)
separates software pixels from native model declarations and physical evidence.

Softpipe allocates each full texture cache with its actual sampler view. Bound
stage/slot copies borrow that cache; rebinding invalidates stale texels and the
last view reference releases mappings, texture references and cache storage.
Allocation failure is returned through sampler-view creation. This removes about
192 MB of unused eager caches per context without shrinking cache capacity,
texture limits or raising the process budget. Evidence/EGLSoftpipeMemory measures
four usable contexts in SMP4/1 GB with the ordinary 512-MB desktop budget, and
checks shared sampling, rebind, texture updates, deletion and software pixels.

Before an application-created rendering thread returns, call `release_thread`.
Before `finish`, stop/join application rendering threads, destroy contexts and
surfaces, and terminate displays. A busy finish retains retirement ownership
and can be retried. A completed finish closes this process's runtime permanently.
See [the generated ABI contract](Docs/API.md) for exact lifetime/error rules.

Mesa and libc++ retain their original licenses. Full texts and source/header
provenance are in `ThirdParty`; shared math/scanner notices remain with their
owners under `Shared/Native`. The distribution carries the same notice bundle.

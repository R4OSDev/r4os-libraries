# R4NV

R4NV owns bounded NVIDIA command encoding and fixed shader artifacts. It never
opens registers or submits GPU work. NVIDIA.R4D owns address spaces, allocation,
channels, completion and resource retirement. Encoding support does not qualify
a physical GPU or imply that its native driver bootstrap is implemented.

`BACKEND_V1` revision 3 is a 64-byte table for copy negotiation, linear/pitched
and tiled command encoding, and image layouts. Generated C/Zig bindings check
the interface. Optional consumers can use `IMPORT=R4NV:BACKEND_V1:3:1` and keep
software rendering when the library is unavailable or incompatible.

Native queue packets use `R4NvNativeSubmitHeader` (32 bytes), followed by exactly
`push_count` `R4NvNativePush` records (16 bytes each). Version 1 admits at most
510 pushes and flags `incomplete`/`no_prefetch`. Engine mask bit1 requires graphics;
bits2/4 additionally request instantiated compute/copy objects. The first job
fixes the queue's engine set; subsequent jobs may request subsets. Unknown bits,
missing classes or an unpaired copy engine fail before GPU publication.
The final push must be complete. Every referenced BO/VA, including command
storage, must be retained through the common native resource list. Completion
is a GPU drain and ordered semaphore, not command fetch; Vulkan resource/cache
barriers remain in the stream. These wire types add no R4L slots or revisions;
NVIDIA.R4D decides actual support from its live resources.

`Source/copy.zig` is shared by the R4L and the driver's compiled binding:

| Copy class | Encoding scope |
| --- | --- |
| C5B5 | Linear, pitched and blocklinear; packed 16-bit x/y origins. |
| C6B5, C7B5 | Linear, pitched and blocklinear; separate 32-bit x/y origins. |
| C9B5, CAB5 | Linear and pitched; tiled operations require a future explicit kind/BPP contract. |

Command addresses remain 40-bit and copy operands 49-bit. Transfers and their
final system-scope semaphore release use the selected class's PLC control.
Allocation extents, aliasing and every operand are checked before publication.
At most 37 command words are written. Callers provide output storage and retain
GPU resources themselves; a rejected call leaves output and count unchanged.

`SHADER_V1` revision 1 is a separate 56-byte metadata/cache table. The keyed
cache admits exactly C597/SM75, C797/SM86, C997/SM89 or CD97/SM120. Every target
has seven fixed programs with its original NVIDIA header. Class and shader
model must agree with the measured driver profile. The legacy unkeyed metadata
entry continues to describe SM86. See `Docs/API.md` for the unchanged ABI.

A cache binds driver build, device/reset identity, graphics class, compiler,
RM/command/shader/resource ABI, formats and complete pipeline-state digest.
It contains a 384-byte prefix, header and code within the 16384-byte ABI limit.
Loading checks exact metadata, header, code and hash; stale or corrupt entries
return `status_cache_miss`. No GPU address is cached. Reset requires fresh
resident resources, regardless of a CPU cache hit.

The [host compiler](Tools/Compiler/README.md) builds pinned Mesa 26.2.2 NIR/NAK.
`-ShaderModel 75|86|89|120` selects one target (default 86). Reproducible outputs
include machine code, header, NIR and assembly. `EmitRuntime.ps1` verifies and
imports those outputs. `Tools/RenderState/Generate.ps1` derives class-specific
state from the pinned original headers. Normal module builds embed the checked
files and do not run or download a compiler. Complete upstream notices remain
with source/generated files and the host tool's Legal directory.

Build with `../Build.sh R4NV` or `..\Build.bat R4NV`. The existing `test` step
covers C/Zig conformance, commands, target separation, byte caches and rejection.
The driver tests retain independent original-header fixtures. The C7B5 release
fixture correction and all four compiler/state profiles are recorded under
`ExFiles/Reference/GFX/0.79.33`.
Physical qualification follows `ExFiles/Reports/OssiGPU.txt`; native Windows
compiler execution and runtime compiler integration remain in 0.79.34.

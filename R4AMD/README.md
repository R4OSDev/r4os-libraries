# R4AMD

R4AMD 0.1.5 owns AMD image geometry, descriptors and command encoders.
`INFO_V1:1` and `BACKEND_V1:3` retain their layouts and slots; `IMAGE_V1:1`
provides stateless image layout, address, metadata, import and descriptor
calls. `RENDER_V1:1` adds six actual ACO shader profiles and transactional
GFX9 pipeline/direct/indexed draw encoding.
AMDGPU.R4D owns devices and publishes measured architecture and memory
versions through the common graphics backend properties.

The R4L links all sixteen original Mesa 26.2.2 AddrLib translation units,
including factory dependencies, plus three private R4OS C++ bridges. Runtime
admission is limited to Picasso 1002:15D8 / GC9.1. No AddrLib or C++ type
crosses the fixed Zig/C interface. Each call constructs and destroys AddrLib
in disjoint caller scratch (16-byte aligned, at most 64 KB). No heap, TLS,
OS allocator, exceptions or RTTI is required. The pure-virtual failure
helper traps; memory operations use the compiler runtime. Outputs are
unchanged on errors.

Images support bounded linear/tiled surfaces, mips, arrays, volumes, MSAA,
selected color/depth/BC formats and real Addr2 coordinate calculations.
Size, pitch, alignment and topology are checked before import. GFX9 texture,
sampler and color state follows original Mesa descriptors and generated
register masks. DCC/HTILE queries describe geometry only: compression stays
disabled and unknown/compressed modifiers cannot be imported as linear.
Scanout admission uses the DCN1 32-bit standard-swizzle restrictions.
See workspace Docs/Drivers/AMDImageLayouts08012.txt for limits and units.

Source/copy.zig and Source/pm4.zig remain shared with AMDGPU. They emit
bounded SDMA linear/row/fill commands and GC9.1 PM4 frames, with exact fences
and the GFX9 EOP workaround. Encoder flags 27 do not advertise tiled copies,
render execution, Vulkan, media or a compute-language runtime. The separate
render owner provides one color target, vertex pulling, sampling, blending,
depth/stencil and bounded raster state. Native GPU capabilities require
confirmed driver prerequisites; physical laptop validation is in 0.80.39.

The shared driver provider translates up to sixteen common render commands
into genuine PM4 plus 4 KB of job parameters. R8 text masks, premultiplied
alpha, nearest/bilinear scaling, affine grids and the common color program
use immutable shaders and retained native BOs. NV12, P010 and YUV420P use
integer plane fetches, explicit range/matrix/transfer conversion and a
504-byte native queue description. The canonical queue uses BACKEND_V1's
profile identity/revision 1; this is separate from the R4L table revision.
Linear aligned video planes are supported; tiled YUV, compressed images,
dual-source blending, MRT and arbitrary Vulkan pipelines are not advertised.

Source/Shaders and Source/Generated/Shaders preserve GLSL, SPIR-V, genuine
R4ACO machine code and reproducibility hashes. Tools/Shaders.ps1 validates
them during each native build. Its explicit `-Write` mode regenerates with
glslang 15.2.0 and the pinned R4ACO offline compiler, twice per profile.
AMDGPU statically links the same image/render archive through the SDK's
Zig R4D NATIVE_ARCHIVE path; no loaded R4L is required in driver startup.

Build with ./Build.sh R4AMD or Build.bat R4AMD from Libraries. Both use
PowerShell 7 and workspace-relative Settings.R4S paths. The normal build
checks source/patch hashes, compiles the genuine C++ closure, creates
runtime/host archives, checks C/Zig ABI conformance and exercises the linked
library on the host. Linux uses ELF; Windows also builds COFF objects for
host tests. The Windows path is implemented but not yet tested.

Clang/LLVM 19.1.7, Python 3 and configured Zig 0.16.0 headers are required.
Shared/Native/BuildPortability.ps1 isolates output by module/host/version
under Artifacts/Native. portability.json records object hashes and inputs;
the native archive manifest records archive hashes. No prepared NAK/NVK
source or cache is reused. DISPLAYD /AMDIMAGE checks the loaded R4L on the
CPU, including C++ vtables/relocations, without GPU access. `/AMDRENDER`
checks loaded shader bytes, native pipeline/draw calls and failure output
integrity. IMAGE_SCOPE=none
keeps the provider out of ordinary profiles until its consumers are ready.

ThirdParty/Sources.json pins 73 original files and the release patch
avoiding unused POSIX signal.h when DEBUG=0. Original bytes stay unchanged.
Adapted Mesa code retains MIT notices; original R4OS code is Apache-2.0.
Tools/ExportLegal.ps1 exports all compiled AddrLib and image/encoder notices
plus the complete MIT grant to the distribution.

The 0.80.23 contract additionally defines the 240-byte R4AmdDeviceFacts,
32-byte R4AmdNativeSubmit and 16-byte R4AmdNativeIb wire types. Existing
types, interface layouts and the R4AMD 0.1.5 runtime are unchanged. Backend
properties revision 2 is distinct from the IMAGE_V1 library revision and
retains the 64-byte R4AmdArchitecture prefix. Native driver profile/commands
keep revision 1 and distinguish PM4 from legacy YUV by exact payload length.

The 0.80.25 additive R4AmdDeviceFactsV3 type has a 256-byte wire layout: the
unchanged 240-byte facts prefix plus timestamp clock in kHz (zero if unknown),
native root-binding capacity and maximum backing bytes including SMEM padding.
Backend-properties revision 3 is separate from every function-table revision.
No existing type or runtime slot changes; the R4AMD artifact remains 0.1.5.

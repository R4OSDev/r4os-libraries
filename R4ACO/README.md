# R4ACO

R4ACO 0.1.1 is the CPU shader compiler for the fixed Picasso GFX9 profile.
It links the real Mesa 26.2.2 SPIR-V frontend, NIR and ACO into R4ACO.R4L.
`INFO_V1:1` reports CPU compilation; `COMPILER_V1:1` compiles and serializes
shader caches. Physical device access belongs to AMDGPU.R4D.

Build from Libraries with `./Build.sh R4ACO` or `Build.bat R4ACO`. Shared
PowerShell 7 orchestration reads the workspace Settings.R4S. It requires
Clang/LLVM 19.1.7, the bundled Zig 0.16.0 libc++ headers/sources, Python 3,
Mako and PyYAML. Tools/Build.ps1 verifies 620 unchanged Mesa files, the ordered
job-isolation patch and pinned runtime sources before generating and linking
373 compiler units plus 18 runtime/bridge units. Shared native math and scan
archives are separate dependencies. No ELF startup constructors are required.

Each compile runs in an exclusive, disposable worker with caller allocation,
clock, cancellation and retirement callbacks. Allocation graphs and emulated
TLS belong to the job. OOM, deadline and compiler abort release that graph
before terminating the worker; callers retain all storage until join.
Bindings/Zig/worker.zig supplies the R4SYS integration and atomic file-cache
helpers. Prepare shaders before rendering; never compile or join in a frame.

Native resource ABI 1 supports vertex pulling through buffers, one fragment
color output, compute, static shared memory, 16 buffer bindings and 256 bytes
of push constants. Stages are vertex 0, fragment 4 and compute 5, wave64.
The target is PCI 1002:15D8 with separately confirmed external ASIC revision
0x41..0x48. Texture/image operations and broader Vulkan shader semantics
belong to subsequent renderer/RADV integration and are rejected here.
Returned ACO symbols retain upstream semantics; constant-data offsets are
already resolved. GPU resource allocation and register encoding belong to
R4AMD and AMDGPU.

Caches bind original SPIR-V, compiler/toolchain identity, device/revision,
resource/command/driver ABI, pipeline and memory/reset epochs. Corruption
returns a cache miss. The compiler never accepts a caller-supplied compiler
identity and never reads environment-selected replacement shaders.

Normal Linux builds run real CPU compilation and failure/cache tests plus
C/Zig ABI conformance. Windows builds the same freestanding ELF runtime and
host ABI check; its CPU integration runs through the SMP4 guest probe.
`DISPLAYD /AMDCOMPILER` tests the loaded module, real R4SYS workers/clock,
five shader fixtures, OOM recovery and actual atomic cache files.
Tests/Fixtures and Tools/ShaderFixtures.json preserve self-authored GLSL and
SPIR-V identities. Original GPU ISA is checked independently with LLVM's
gfx902 disassembler. None of these CPU checks executes an AMD GPU.

Sources and licenses are pinned in ThirdParty/Sources.json and
Tools/CppSources.json. Tools/ExportLegal.ps1 collects original notices,
libc++, stb and shared math/scan terms for distribution.
`IMAGE_SCOPE=none` remains until package integration. Further details are in
Docs/Drivers/AMDShaderCompiler08013.txt in the workspace and Docs/API.md here.

Original R4OS code: Apache License 2.0. Third-party material retains its
own license; see the repository THIRD_PARTY_NOTICES.md.

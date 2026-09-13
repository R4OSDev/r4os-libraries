# R4NV

R4NV owns NVIDIA command encoding in the Libraries repository. `BACKEND_V1`
negotiates a driver profile and produces bounded Copy Engine commands.
It neither accesses GPU registers nor submits work. NVIDIA.R4D owns address
spaces, mappings, channels, completion and resource retirement.

`Source/copy.zig` is the single implementation used by both the runtime
library and the driver's compiled binding. It covers C6B5/C7B5 virtual linear,
pitched and blocklinear copies, with a system-scope semaphore release. The implementation
comes from the existing R4OS encoder based on NVIDIA 570.144; all upstream
notices remain in that file and `ThirdParty/Nvidia/LICENSES.txt`.

The 56-byte `BACKEND_V1` revision 2 interface is independent of R4GFX and the platform
ABI. Generated C/Zig bindings validate its header, identity and functions.
Consumers may declare `IMPORT=R4NV:BACKEND_V1:2:1` and retain software when
the library is absent or incompatible. This optional import requires the
module-loader support introduced during 0.79.17.

Negotiation requires the actual driver's adapter and device/reset generations,
NVIDIA vendor, copy class, command ABI 1 and pinned RM release 570.144.
Successful negotiation describes supported encoding; it is no GPU hardware
qualification. Rendering and shaders are not advertised by this interface.

Callers own request/output storage and serialize any associated GPU resource
use themselves. Rejected encoding leaves command memory and count unchanged;
commands must not overlap the request or the returned count. No state, heap,
thread, service, callback or pointer is retained by a call.

Build through `../Build.sh R4NV` or `..\Build.bat R4NV`. The `test` step runs
the module boundary case and generated C/Zig conformance. The NVIDIA driver's
existing copy cases retain the independent original-header command vectors.

Revision 2 appends `encode_copy_layout`; existing structures and methods retain
their layout. A block operand supplies a 512-byte-aligned plane base, byte width,
height, byte x/row y and log2 GOB height 0..5. Canonical allocation/plane validation
belongs to NVIDIA.R4D. Depth is one, compression/remapping are disabled. The
encoder checks complete physical spans and aliases before writing at most 37
words. The legacy linear/pitched method still needs at most 19 words.

The existing provider case compares both C6B5/C7B5 37-word streams and GPFIFO
entries with independent original-header vectors. The 312-byte test-only fixture
is reproducible from Original-Layout.c and its pinned source archive under
ExFiles/Reference/GFX/Nvidia/0.79.18/copy-20260913. No fixture or host tiling emulator
is executed in R4NV.R4L. Physical GPU qualification remains in OssiGPU.txt /18.

The optional [host compiler](Tools/Compiler/README.md) builds pinned Mesa
26.2.2 NIR/NAK and reproducibly generates SM86 rectangle, texture, solid and
sRGB-transfer shaders. Its source lock, small standalone build patch and
readable shader sources are separate from the runtime library. It performs
no GPU access. `EmitRuntime.ps1` verifies its recorded outputs and generates
the fixed programs under `Source/Generated/Shaders`; normal module builds
embed those programs without invoking the compiler.

`SHADER_V1` revision 1 is a separate 56-byte table for fixed-program metadata
and executable byte caches. The five SM86/AMPERE_B programs include their
original 128-byte NVIDIA headers and 1904 total machine-code bytes. A cache
binds the current driver build, GPU identity, graphics class, RM/command/
shader/resource ABI, formats, compiler identity and complete pipeline-state
digest. Callers obtain the key from their actual driver/renderer. A matching
key is not evidence that the device has been qualified.

The version-1 cache is at most 1152 bytes: a 384-byte prefix followed by code.
Its little-endian prefix contains the version/length/profile, compiler ID,
120-byte key, metadata, NVIDIA header and SHA-256 over all other bytes. Reading
requires exact key, compiler, metadata, header, code and checksum matches;
incompatible or damaged data returns `status_cache_miss` without changing the
output. Unsupported current hardware/ABI returns `status_unsupported`.
Writes also preserve output and count on rejection. Buffers and output/key
structures must not overlap. The view borrows byte-aligned ranges in the
caller's immutable input until it is copied or uploaded; R4NV retains nothing.

The cache contains no GPU addresses. The renderer must still validate or
recreate resident shader/pipeline resources after a device/reset generation
change. Native allocation, descriptors, pipeline submission, dynamic R4OS
compilation and native Windows verification remain work in 0.79.19/0.79.34.
The existing provider case checks all fixed programs, every byte/truncation
of the largest cache, identity changes, recomputed corrupt headers and rejected
output preservation. DISPLAYD /BUFFERS exercises this table through the real
module loader with a synthetic device key; it performs no NVIDIA rendering.

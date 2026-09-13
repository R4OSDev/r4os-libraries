# R4NV

R4NV owns NVIDIA command encoding in the Libraries repository. `BACKEND_V1`
negotiates a driver profile and produces bounded Copy Engine commands.
It neither accesses GPU registers nor submits work. NVIDIA.R4D owns address
spaces, mappings, channels, completion and resource retirement.

`Source/copy.zig` is the single implementation used by both the runtime
library and the driver's compiled binding. It covers C6B5/C7B5 virtual linear
and pitched copies, with a system-scope semaphore release. The implementation
comes from the existing R4OS encoder based on NVIDIA 570.144; all upstream
notices remain in that file and `ThirdParty/Nvidia/LICENSES.txt`.

The 48-byte `BACKEND_V1` interface is independent of R4GFX and the platform
ABI. Generated C/Zig bindings validate its header, identity and functions.
Consumers may declare `IMPORT=R4NV:BACKEND_V1:1:1` and retain software when
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

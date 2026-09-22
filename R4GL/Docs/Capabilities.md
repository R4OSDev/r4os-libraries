# R4GL capability record — 0.80.26

Applications query EGL configs, GL context versions and extensions from the
selected backend. Archive contents or GPU PCI identity alone enable no feature.
The initial target is EGL 1.5 / OpenGL 3.3 Core; this is not CTS certification.

| Profile | Runtime declaration | Focused evidence | Remaining physical work |
| --- | --- | --- | --- |
| 0: Mesa Softpipe, no LLVM/JIT | EGL 1.5, GL 3.3 Core, 189 GL extensions in the recorded context | Real shader/sRGB/blending/image pixels, contexts/threads, four contexts at 1 GB; complete Desktop window/fullscreen/restore/close | No NVIDIA prerequisite; firmware scanout has no VSync promise |
| 1: Mesa Zink → native R4VK/NVK | EGL 1.5, GL 3.3 Core / GLSL 3.30, 215 GL extensions on the GA106 model; GL 4.6 context rejected | Vulkan admission, shader submission, window/pbuffer, resize, FIFO/MAILBOX transitions, fences and device-loss retirement | GPU pixel correctness, actual execution/scanout, timing, hotplug and reset recovery |
| 1: Mesa Zink → native R4VK/RADV | EGL 1.5, GL 3.3 Core / GLSL 3.30 on the Picasso model; GL 4.6 follows 0.80.27 | Actual GLSL/Zink/RADV/ACO submission, textures/FBOs, per-binding component mapping, stipple shaders, window/pbuffer, resize, FIFO/MAILBOX and complete BO retirement | Physical AMD drawing, scanout/VSync and reset qualification in 0.80.39 |

R4GL 0.1.15 implements missing GFX9 border-color swizzle through identity
Vulkan views and per-binding NIR mapping; Vulkan does not advertise the absent
extension. Bindless textures are disabled for this path. Missing native line
stipple modes use the existing Zink geometry/fragment lowering. R4VK 0.1.21
retains pooled byte extents until every submission using their root completes.
The 32-binding limit remains finite. Focused AMD evidence is in
`Docs/Drivers/AMDEGL08026.txt` and `.json` in the workspace's Docs repository.

The lists record runtime declarations, not 189/215 individually passed extension
tests. Mesa derives them from backend capabilities; Zink additionally checks the
native Vulkan features/limits and required entrypoints. The native model executes
no GPU instructions. Its extension list must never be presented as physical GPU
qualification. A different real adapter may expose a different list.

The final capture advertises no POSIX-fd/Win32 external-memory or semaphore
interop, OpenCL-event sync, or native-fence-fd extensions. The exposed EGL image,
colorspace, context and fence paths have the focused owner/software evidence
listed in README. Surface availability and swap intervals additionally require
the exact window/output lifetime. A native profile failure does not silently
select software; the application chooses profile 0 in a new runtime/process.

Full lists, artifact hashes, captures and check inputs:
`ExFiles/Reference/GFX/0.79.39/Evidence/EGLDesktop` (workspace).
NVIDIA physical follow-up: `ExFiles/Reports/OssiGPU.txt`, section 0.79.39.
AMD physical follow-up: roadmap 0.80.39.

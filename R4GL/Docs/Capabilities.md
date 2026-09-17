# R4GL capability record — 0.79.39

Applications query EGL configs, GL context versions and extensions from the
selected backend. Archive contents or GPU PCI identity alone enable no feature.
The initial target is EGL 1.5 / OpenGL 3.3 Core; this is not CTS certification.

| Profile | Runtime declaration | Focused evidence | Remaining physical work |
| --- | --- | --- | --- |
| 0: Mesa Softpipe, no LLVM/JIT | EGL 1.5, GL 3.3 Core, 189 GL extensions in the recorded context | Real shader/sRGB/blending/image pixels, contexts/threads, four contexts at 1 GB; complete Desktop window/fullscreen/restore/close | No NVIDIA prerequisite; firmware scanout has no VSync promise |
| 1: Mesa Zink → native R4VK/NVK | EGL 1.5, GL 3.3 Core / GLSL 3.30, 215 GL extensions on the GA106 model; GL 4.6 context rejected | Vulkan admission, shader submission, window/pbuffer, resize, FIFO/MAILBOX transitions, fences and device-loss retirement | GPU pixel correctness, actual execution/scanout, timing, hotplug and reset recovery |

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
Physical follow-up: `ExFiles/Reports/OssiGPU.txt`, section 0.79.39.

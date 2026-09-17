R4GL Runtime-R4L API
====================

Native EGL/OpenGL bootstrap and process lifecycle. Mesa owns GL/EGL semantics; R4OS owns presentation and resources.

EGL_V1
------

Process binding for native EGL profiles. This interface version is independent of EGL/GL versions.

- ELF-Symbol: `r4gl_egl_v1`
- ABI-Major: 1
- Revision: 1
- Interface-ID: `0x314c4734534f:0x314c4745523448`
- Tabellengroesse: 56 Byte

- Slot 0, Offset 32: `open` - Bind the actual application startup context and immutable kernel tables. Requires R4SYS23 and R4DRAW/R4DEV imports; Zink additionally requires the application import R4VK:VULKAN_V1:1. No EGL context or device is created. The selected profile is immutable; repeated matching opens are idempotent until finish begins.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GL`; Besitz: Process-owned runtime. Keep this R4L generation loaded until all GL/EGL calls, objects and thread cleanup have finished..
- Slot 1, Offset 40: `release_thread` - After the thread stops using GL/EGL, run its language TLS destructors, EGL unbinding and raw TLS retirement. Call before an application-created thread returns. Library-created C11 workers do this automatically.
  Semantik: may_block, owner_thread, not_reentrant; Fehlerdomaene `R4GL`; Besitz: Process-owned runtime. Keep this R4L generation loaded until all GL/EGL calls, objects and thread cleanup have finished..
- Slot 2, Offset 48: `finish` - After joining application GL threads, releasing their TLS, destroying all GL/EGL objects and terminating displays, close worker admission, drain/join window retirement, run process finalizers and close native streams/options. Busy retains ownership for retry; no API reentry except finish/release_thread once called. Closed is idempotent; reopening requires a new process.
  Semantik: may_block, caller_serialized, not_reentrant; Fehlerdomaene `R4GL`; Besitz: Process-owned runtime. Keep this R4L generation loaded until all GL/EGL calls, objects and thread cleanup have finished..

Typen
-----

- `R4GlRuntime`: 24 Byte, Alignment 8. Caller startup descriptor. R4GL retains its own process snapshot, not the descriptor or a stack Bundle.
- `R4GlLoader`: 16 Byte, Alignment 8. Resolve standard API commands; use eglQueryString/glGetString and context creation for supported versions/extensions. A resolved symbol alone does not admit a feature.

Besitzregeln
------------

- threads: Mutable Mesa state belongs to the calling process and exact thread generation. EGL context currentness and sharing follow EGL rules. Application-created threads explicitly release_thread before returning; callers serialize open/finish and quiesce GL/EGL before finish.
- presentation: EGL_DEFAULT_DISPLAY uses the selected native profile. Softpipe window handles encode the creating application WINSVC window ID. Zink currently admits pbuffers only; native Vulkan window integration remains pending. Buffers/fences use R4DRAW and WINSVC; no host window, Linux FD or GPU handle is fabricated.
- fatal: An unrecoverable native runtime failure terminates the calling process through R4SYS program_exit. It does not run foreign callbacks in kernel cleanup. Ordinary EGL/GL errors remain standard error returns.
- profile: Softpipe without LLVM/JIT: EGL 1.5, up to GL 3.3 Core, output-qualified swap intervals 0..1 with firmware fallback 0. Zink: an initial GL 3.3 pbuffer path over the imported R4VK ICD, admitted only after its actual Vulkan features/limits pass. Native Zink windows and positive rendering qualification remain roadmap work. No-device is EGL_NOT_INITIALIZED and permits another initialize attempt; profiles never switch implicitly.

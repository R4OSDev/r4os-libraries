# OpenGL triangle

`Triangle.zig` is a regular hosted GUI application using R4GL's public EGL
loader. It draws a GLSL 330 Core triangle, uses the complete client size, and
requests borderless fullscreen through `r4os.window_mode`. Press **F** to
switch modes; **Escape** restores the decorated window or closes it.

Use the file as `SOURCE` of an SDK R4X manifest with `ENTRY_MODE=app` and
`APP_CLASS=gui`. Import `R4SYS:Query:1`, `R4DESK:Query:1`, `R4DRAW:Query:1`,
`R4DEV:Query:1`, `R4GL:EGL_V1:1`, and `R4VK:VULKAN_V1:1`; bind `r4gl` to
`R4GL/Bindings/Zig/r4gl.zig`. Launch the resulting R4X from Desktop.
It is an example source, not a separately installed application or test gate.

Software rendering is the default. `/ZINK` explicitly selects the native
Vulkan backend and fails if its requirements are unavailable. Both use swap
interval zero; fullscreen does not change monitor timing or promise VSync.

An optional observer passed to `run` receives renderer/version/extensions and
logical client geometry and EGL framebuffer dimensions. Framebuffer dimensions
may differ on scaled outputs; viewport sizes always come from EGL. With an observer, the example also checks the center pixel
before swapping. The regular entry point omits these diagnostic readbacks.

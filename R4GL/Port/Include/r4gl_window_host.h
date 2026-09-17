/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4GL_WINDOW_HOST_H
#define R4GL_WINDOW_HOST_H
#include <r4os/r4draw.h>
#include "r4gl_egl.h"
bool r4gl_native_application(R4XStartContext *, R4Draw *);
int32_t r4gl_window_query(const R4XStartContext *, uint32_t, const R4WindowGraphicsSurface *, R4WindowGraphicsReply *);
bool r4gl_window_request(const R4XStartContext *, const R4WindowGraphicsRequest *, R4WindowGraphicsReply *);
bool r4gl_window_service_dead(const R4XStartContext *, const R4ProgramProcessHandle *);
void r4gl_window_wait(const R4XStartContext *, const R4ProgramProcessHandle *, uint64_t, uint64_t);
uint64_t r4gl_native_now(void);
/* NULL config enumerates display admission; an exact window config checks
 * its current output identity and synchronized FIFO capability. */
int32_t r4gl_window_swap_limit(const R4XStartContext *, const R4WindowGraphicsConfig *);
/* Called after all EGL users stopped. Failure retains outstanding retirement;
 * a deadline is not evidence that another process stopped reading. */
bool r4gl_window_finish(uint64_t deadline_ns);
#endif

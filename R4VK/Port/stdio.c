/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4nak_libc.h"
#include "../../R4NAK/ThirdParty/stb/stb_sprintf.h"

/* Only console streams are provided here. These immutable identities never
 * retain an application's output handle; R4SYS resolves the current caller. */
struct r4nak_file { unsigned console; };
static struct r4nak_file out_stream = {1}, err_stream = {2};
FILE *stdout = &out_stream;
FILE *stderr = &err_stream;
extern int32_t r4vk_console_write(const char *, uint32_t);

static bool is_console(FILE *file) { return file == stdout || file == stderr; }
static size_t write_console(const char *data, size_t bytes)
{
   size_t written = 0;
   while (written < bytes) {
      uint32_t chunk = bytes - written > INT_MAX ? INT_MAX : bytes - written;
      int32_t result = r4vk_console_write(data + written, chunk);
      if (result <= 0 || (uint32_t)result > chunk) break;
      written += result;
   }
   return written;
}
struct print_context { char buffer[STB_SPRINTF_MIN]; bool failed; };
static char *print_chunk(const char *bytes, void *user, int count)
{
   struct print_context *ctx = user;
   if (write_console(bytes, count) != (size_t)count) {
      ctx->failed = true;
      return NULL;
   }
   return ctx->buffer;
}
int vfprintf(FILE *file, const char *format, va_list args)
{
   if (!is_console(file)) return EOF;
   struct print_context ctx = {0};
   int result = stbsp_vsprintfcb(print_chunk, &ctx, ctx.buffer, format, args);
   return ctx.failed ? EOF : result;
}
int fprintf(FILE *file, const char *format, ...)
{
   va_list args;
   va_start(args, format);
   int result = vfprintf(file, format, args);
   va_end(args);
   return result;
}
int vprintf(const char *format, va_list args) { return vfprintf(stdout, format, args); }
int printf(const char *format, ...)
{
   va_list args;
   va_start(args, format);
   int result = vprintf(format, args);
   va_end(args);
   return result;
}
size_t fwrite(const void *data, size_t size, size_t count, FILE *file)
{
   if (!is_console(file) || !size || count > SIZE_MAX / size) return 0;
   return write_console(data, size * count) / size;
}
int fputs(const char *text, FILE *file)
{
   if (!is_console(file)) return EOF;
   size_t bytes = strlen(text);
   return write_console(text, bytes) == bytes ? 0 : EOF;
}
int fputc(int value, FILE *file)
{
   unsigned char byte = value;
   return fwrite(&byte, 1, 1, file) == 1 ? byte : EOF;
}
int putchar(int value) { return fputc(value, stdout); }
int puts(const char *text) { return fputs(text, stdout) == EOF ? EOF : fputc('\n', stdout); }
/* Writes are synchronous and unbuffered. No filesystem FILE is fabricated. */
int fflush(FILE *file) { return !file || is_console(file) ? 0 : EOF; }

_Noreturn void r4nak_port_assert(const char *condition, const char *file, int line)
{
   fprintf(stderr, "R4VK assertion: %s (%s:%d)\n", condition, file, line);
   __builtin_trap();
}

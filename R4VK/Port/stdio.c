/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4nak_libc.h"
#include "../../R4NAK/ThirdParty/stb/stb_sprintf.h"

/* Console identities are immutable and never retain an application's output
 * handle. Memory streams belong to their caller; Mesa serializes each stream.
 * No host filesystem FILE or shared-library list of caller buffers is used. */
struct r4nak_file {
   unsigned console;
   char *bytes;
   size_t position, length, capacity;
   char **out_bytes;
   size_t *out_length;
   bool failed;
};
static struct r4nak_file out_stream = {.console = 1}, err_stream = {.console = 2};
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
struct print_context { char buffer[STB_SPRINTF_MIN]; FILE *file; bool failed; };
static char *print_chunk(const char *bytes, void *user, int count)
{
   struct print_context *ctx = user;
   if (fwrite(bytes, 1, count, ctx->file) != (size_t)count) {
      ctx->failed = true;
      return NULL;
   }
   return ctx->buffer;
}
int vfprintf(FILE *file, const char *format, va_list args)
{
   if (!file) return EOF;
   struct print_context ctx = {.file = file};
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
   if (!file || !size || !count) return 0;
   if (count > SIZE_MAX / size) {
      if (!is_console(file)) file->failed = true;
      return 0;
   }
   const size_t bytes = size * count;
   if (is_console(file)) return write_console(data, bytes) / size;
   if (bytes > (size_t)LONG_MAX - file->position) {
      file->failed = true;
      return 0;
   }
   const size_t end = file->position + bytes;
   if (end + 1 > file->capacity) {
      size_t capacity = file->capacity <= SIZE_MAX / 2 ? file->capacity * 2 : end + 1;
      if (capacity < end + 1) capacity = end + 1;
      char *replacement = realloc(file->bytes, capacity);
      if (!replacement) {
         file->failed = true;
         return 0;
      }
      file->bytes = replacement;
      file->capacity = capacity;
   }
   if (file->position > file->length)
      memset(file->bytes + file->length, 0, file->position - file->length);
   memcpy(file->bytes + file->position, data, bytes);
   file->position = end;
   if (end > file->length) file->length = end;
   file->bytes[file->length] = 0;
   return count;
}
int fputs(const char *text, FILE *file)
{
   size_t bytes = strlen(text);
   return fwrite(text, 1, bytes, file) == bytes ? 0 : EOF;
}
int fputc(int value, FILE *file)
{
   unsigned char byte = value;
   return fwrite(&byte, 1, 1, file) == 1 ? byte : EOF;
}
int putchar(int value) { return fputc(value, stdout); }
int puts(const char *text) { return fputs(text, stdout) == EOF ? EOF : fputc('\n', stdout); }
FILE *open_memstream(char **bytes, size_t *length)
{
   if (!bytes || !length) return NULL;
   FILE *file = calloc(1, sizeof(*file));
   if (!file) return NULL;
   file->bytes = malloc(1);
   if (!file->bytes) { free(file); return NULL; }
   file->bytes[0] = 0;
   file->capacity = 1;
   file->out_bytes = bytes;
   file->out_length = length;
   *bytes = file->bytes;
   *length = 0;
   return file;
}
int fflush(FILE *file)
{
   /* Mesa flushes explicit streams. Global flushing is not a supported entry
    * in this private C subset and must not report success for unflushed data. */
   if (!file) return EOF;
   if (is_console(file)) return 0;
   *file->out_bytes = file->bytes;
   *file->out_length = file->position < file->length ? file->position : file->length;
   return file->failed ? EOF : 0;
}
int fclose(FILE *file)
{
   if (!file || is_console(file)) return EOF;
   int result = fflush(file);
   /* The caller owns the published buffer even after a failed write. */
   free(file);
   return result;
}
int ferror(FILE *file) { return file && !is_console(file) && file->failed; }
long ftell(FILE *file)
{
   return file && !is_console(file) && file->position <= LONG_MAX ? (long)file->position : -1;
}
int fseek(FILE *file, long offset, int origin)
{
   if (!file || is_console(file) || origin < SEEK_SET || origin > SEEK_END) return -1;
   /* SEEK_END uses the full buffer length. Seeking beyond it does not allocate;
    * the next write zero-fills the gap (POSIX permits both choices). */
   size_t base = origin == SEEK_SET ? 0 : origin == SEEK_CUR ? file->position : file->length;
   size_t magnitude = offset < 0 ? (size_t)(-(offset + 1)) + 1 : (size_t)offset;
   if (offset < 0 ? magnitude > base : magnitude > (size_t)LONG_MAX - base) return -1;
   file->position = offset < 0 ? base - magnitude : base + magnitude;
   return 0;
}

_Noreturn void r4nak_port_assert(const char *condition, const char *file, int line)
{
   fprintf(stderr, "R4VK assertion: %s (%s:%d)\n", condition, file, line);
   __builtin_trap();
}

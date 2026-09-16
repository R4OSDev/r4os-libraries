/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4nak_libc.h"

size_t strlen(const char *text) { const char *end = text; while (*end) end++; return (size_t)(end - text); }
size_t strnlen(const char *text, size_t limit) { size_t n = 0; while (n < limit && text[n]) n++; return n; }
int strcmp(const char *a, const char *b) { while (*a && *a == *b) { a++; b++; } return (unsigned char)*a - (unsigned char)*b; }
int strncmp(const char *a, const char *b, size_t n) { while (n && *a && *a == *b) { a++; b++; n--; } return n ? (unsigned char)*a - (unsigned char)*b : 0; }
char *strchr(const char *text, int value) { do { if ((unsigned char)*text == (unsigned char)value) return (char *)text; } while (*text++); return NULL; }
char *strstr(const char *text, const char *part) { size_t n = strlen(part); for (; *text; text++) if (!strncmp(text, part, n)) return (char *)text; return n ? NULL : (char *)text; }
int tolower(int c) { return c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c; }
int strcasecmp(const char *a, const char *b) { while (*a && tolower((unsigned char)*a) == tolower((unsigned char)*b)) { a++; b++; } return tolower((unsigned char)*a) - tolower((unsigned char)*b); }
char *strcpy(char *out, const char *in) { char *p = out; while ((*p++ = *in++)) {} return out; }
char *strncpy(char *out, const char *in, size_t n) { size_t i = 0; while (i < n && in[i]) { out[i] = in[i]; i++; } while (i < n) out[i++] = 0; return out; }
char *strcat(char *out, const char *in) { strcpy(out + strlen(out), in); return out; }
size_t strcspn(const char *text, const char *set) { size_t n = 0; while (text[n] && !strchr(set, text[n])) n++; return n; }
char *strpbrk(const char *text, const char *set) { for (; *text; text++) if (strchr(set, *text)) return (char *)text; return NULL; }
void *memchr(const void *bytes, int value, size_t n) { const unsigned char *p = bytes; for (size_t i = 0; i < n; i++) if (p[i] == (unsigned char)value) return (void *)(p + i); return NULL; }
char *strndup(const char *text, size_t limit)
{
   size_t n = strnlen(text, limit);
   if (n == SIZE_MAX) return NULL;
   char *out = malloc(n + 1);
   if (!out) return NULL;
   memcpy(out, text, n);
   out[n] = 0;
   return out;
}
char *strdup(const char *text) { return strndup(text, SIZE_MAX); }
int abs(int value) { return value < 0 ? -value : value; }
long long llabs(long long value) { return value < 0 ? -value : value; }
int atoi(const char *text)
{
   while (*text == ' ' || (*text >= '\t' && *text <= '\r')) text++;
   bool negative = *text == '-';
   if (*text == '-' || *text == '+') text++;
   unsigned value = 0, limit = negative ? (unsigned)INT_MAX + 1 : INT_MAX;
   while (*text >= '0' && *text <= '9') {
      unsigned digit = (unsigned)(*text++ - '0');
      if (value > (limit - digit) / 10) return negative ? INT_MIN : INT_MAX;
      value = value * 10 + digit;
   }
   return negative ? (value == (unsigned)INT_MAX + 1 ? INT_MIN : -(int)value) : (int)value;
}

/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4nak_libc.h"

size_t strlen(const char *text) { const char *end = text; while (*end) end++; return (size_t)(end - text); }
int strcmp(const char *a, const char *b) { while (*a && *a == *b) { a++; b++; } return (unsigned char)*a - (unsigned char)*b; }
int strncmp(const char *a, const char *b, size_t n) { while (n && *a && *a == *b) { a++; b++; n--; } return n ? (unsigned char)*a - (unsigned char)*b : 0; }
char *strchr(const char *text, int value) { do { if ((unsigned char)*text == (unsigned char)value) return (char *)text; } while (*text++); return NULL; }
char *strstr(const char *text, const char *part) { size_t n = strlen(part); for (; *text; text++) if (!strncmp(text, part, n)) return (char *)text; return n ? NULL : (char *)text; }
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

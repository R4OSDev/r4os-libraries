/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4nak_libc.h"
extern int *r4vk_compiler_errno(void);

/* The selected provider uses strtoull for SPIR-V debug hashes, on the admitted
 * compiler worker. Its error cell belongs to that call, not shared R4L BSS. */
unsigned long long strtoull(const char *text, char **end, int base)
{
   if (base && (base < 2 || base > 36)) {
      *r4vk_compiler_errno() = EINVAL;
      if (end) *end = (char *)text;
      return 0;
   }
   const char *at = text;
   while (*at == ' ' || (*at >= '\t' && *at <= '\r')) at++;
   bool negative = *at == '-';
   if (*at == '-' || *at == '+') at++;
   if ((!base || base == 16) && at[0] == '0' && (at[1] == 'x' || at[1] == 'X')) {
      unsigned digit = (unsigned char)at[2];
      if ((digit >= '0' && digit <= '9') || (digit >= 'a' && digit <= 'f') || (digit >= 'A' && digit <= 'F')) {
         at += 2; base = 16;
      }
   }
   if (!base) base = *at == '0' ? 8 : 10;
   const char *first = at;
   uint64_t value = 0;
   bool overflow = false;
   for (;; at++) {
      unsigned ch = (unsigned char)*at;
      unsigned digit = ch >= '0' && ch <= '9' ? ch - '0' : ch >= 'a' && ch <= 'z' ? ch - 'a' + 10 : ch >= 'A' && ch <= 'Z' ? ch - 'A' + 10 : 36;
      if (digit >= (unsigned)base) break;
      if (value > (UINT64_MAX - digit) / (unsigned)base) overflow = true;
      else value = value * (unsigned)base + digit;
   }
   if (end) *end = (char *)(at == first ? text : at);
   if (overflow) { *r4vk_compiler_errno() = ERANGE; return UINT64_MAX; }
   return negative ? UINT64_C(0) - value : value;
}

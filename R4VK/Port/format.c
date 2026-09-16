/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4nak_libc.h"
#define STB_SPRINTF_IMPLEMENTATION
#define STB_SPRINTF_NOUNALIGNED
#include "../../R4NAK/ThirdParty/stb/stb_sprintf.h"

int vsnprintf(char *out, size_t capacity, const char *format, va_list args)
{
   return stbsp_vsnprintf(out, capacity > INT_MAX ? INT_MAX : (int)capacity,
                         format, args);
}
int snprintf(char *out, size_t capacity, const char *format, ...)
{
   va_list args;
   va_start(args, format);
   int count = vsnprintf(out, capacity, format, args);
   va_end(args);
   return count;
}

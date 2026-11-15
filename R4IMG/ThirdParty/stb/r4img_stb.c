#include <stddef.h>
#include <stdint.h>
#include <stdatomic.h>

typedef struct R4ImgArenaHeader {
    size_t size;
    size_t previous_used;
} R4ImgArenaHeader;

/* Each decode owns its allocator context on its own stack. Only the
 * completed diagnostic value is shared, published as one atomic snapshot. */
typedef struct R4ImgArena {
    unsigned char *base;
    size_t capacity;
    size_t used;
    size_t peak;
    int failed;
} R4ImgArena;

static _Atomic uint64_t r4img_last_diagnostic;

static void *r4img_memcpy(void *destination, const void *source, size_t length) {
    unsigned char *out = (unsigned char *)destination;
    const unsigned char *in = (const unsigned char *)source;
    size_t index;
    for (index = 0; index < length; ++index) out[index] = in[index];
    return destination;
}

static void *r4img_memmove(void *destination, const void *source, size_t length) {
    unsigned char *out = (unsigned char *)destination;
    const unsigned char *in = (const unsigned char *)source;
    size_t index;
    if (out <= in) {
        for (index = 0; index < length; ++index) out[index] = in[index];
    } else {
        for (index = length; index > 0; --index) out[index - 1] = in[index - 1];
    }
    return destination;
}

static void *r4img_memset(void *destination, int value, size_t length) {
    unsigned char *out = (unsigned char *)destination;
    size_t index;
    for (index = 0; index < length; ++index) out[index] = (unsigned char)value;
    return destination;
}

static int r4img_memcmp(const void *left, const void *right, size_t length) {
    const unsigned char *a = (const unsigned char *)left;
    const unsigned char *b = (const unsigned char *)right;
    size_t index;
    for (index = 0; index < length; ++index) {
        if (a[index] != b[index]) return a[index] < b[index] ? -1 : 1;
    }
    return 0;
}

static int r4img_abs(int value) {
    return value < 0 ? -value : value;
}

static void r4img_arena_reset(R4ImgArena *arena, unsigned char *memory, size_t capacity) {
    uintptr_t raw = (uintptr_t)memory;
    uintptr_t aligned = (raw + 15u) & ~(uintptr_t)15u;
    size_t skipped = (size_t)(aligned - raw);
    if (skipped > capacity) {
        arena->base = memory;
        arena->capacity = 0;
        arena->used = 0;
        arena->peak = 0;
        arena->failed = 1;
        return;
    }
    arena->base = (unsigned char *)aligned;
    arena->capacity = capacity - skipped;
    arena->used = 0;
    arena->peak = 0;
    arena->failed = 0;
}

static void *r4img_arena_alloc(R4ImgArena *arena, size_t size) {
    size_t start = (arena->used + sizeof(R4ImgArenaHeader) + 15u) & ~(size_t)15u;
    R4ImgArenaHeader *header;
    if (size == 0) size = 1;
    if (start > arena->capacity || size > arena->capacity - start) {
        arena->failed = 1;
        return (void *)0;
    }
    header = (R4ImgArenaHeader *)(arena->base + start - sizeof(R4ImgArenaHeader));
    header->size = size;
    header->previous_used = arena->used;
    arena->used = start + size;
    if (arena->used > arena->peak) arena->peak = arena->used;
    return arena->base + start;
}

static void *r4img_arena_realloc(R4ImgArena *arena, void *pointer, size_t old_size, size_t new_size) {
    void *replacement;
    size_t copy_size;
    size_t start;
    R4ImgArenaHeader *header;
    if (pointer == (void *)0) return r4img_arena_alloc(arena, new_size);
    start = (size_t)((unsigned char *)pointer - arena->base);
    header = (R4ImgArenaHeader *)((unsigned char *)pointer - sizeof(R4ImgArenaHeader));
    if (old_size == 0) {
        old_size = header->size;
    }
    if (start <= arena->capacity && header->size <= arena->capacity - start &&
        start + header->size == arena->used && new_size <= arena->capacity - start) {
        header->size = new_size;
        arena->used = start + new_size;
        if (arena->used > arena->peak) arena->peak = arena->used;
        return pointer;
    }
    replacement = r4img_arena_alloc(arena, new_size);
    if (replacement == (void *)0) return (void *)0;
    copy_size = old_size < new_size ? old_size : new_size;
    r4img_memcpy(replacement, pointer, copy_size);
    return replacement;
}

static void r4img_arena_free(R4ImgArena *arena, void *pointer) {
    size_t start;
    R4ImgArenaHeader *header;
    if (pointer == (void *)0) return;
    start = (size_t)((unsigned char *)pointer - arena->base);
    if (start > arena->capacity) return;
    header = (R4ImgArenaHeader *)((unsigned char *)pointer - sizeof(R4ImgArenaHeader));
    if (header->size <= arena->capacity - start && start + header->size == arena->used) {
        arena->used = header->previous_used;
    }
}

#define memcpy r4img_memcpy
#define memmove r4img_memmove
#define memset r4img_memset
#define memcmp r4img_memcmp
#define abs r4img_abs
#define STBI_MALLOC(size) r4img_arena_alloc(arena, size)
#define STBI_REALLOC_SIZED(pointer, old_size, new_size) r4img_arena_realloc(arena, pointer, old_size, new_size)
#define STBI_FREE(pointer) r4img_arena_free(arena, pointer)
#define STBI_ASSERT(condition) ((void)0)
#define STBI_NO_STDIO
#define STBI_NO_LINEAR
#define STBI_NO_HDR
#define STBI_NO_SIMD
#define STBI_NO_FAILURE_STRINGS
#define STBI_ONLY_JPEG
#define STBI_ONLY_PNG
#define STBI_ONLY_BMP
#define STBI_MAX_DIMENSIONS 4096
#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void r4img_stbi_diagnostic(size_t *peak, int *failed) {
    uint64_t value = atomic_load_explicit(&r4img_last_diagnostic, memory_order_acquire);
    *peak = (size_t)(value >> 1);
    *failed = (int)(value & 1u);
}

static void r4img_publish_diagnostic(const R4ImgArena *arena) {
    uint64_t value = ((uint64_t)arena->peak << 1) | (uint64_t)(arena->failed != 0);
    atomic_store_explicit(&r4img_last_diagnostic, value, memory_order_release);
}

static int r4img_stbi_decode_arena(R4ImgArena *arena,
    const unsigned char *bytes,
    size_t length,
    unsigned char *scratch,
    size_t scratch_length,
    uint32_t *pixels,
    size_t pixel_capacity,
    int *width,
    int *height,
    int *channels
) {
    stbi_uc *rgba;
    size_t count;
    size_t index;
    if (bytes == (const unsigned char *)0 || length == 0 || length > 0x7fffffffu ||
        scratch == (unsigned char *)0 || pixels == (uint32_t *)0) return 0;
    r4img_arena_reset(arena, scratch, scratch_length);
    rgba = stbi_load_from_memory(arena, bytes, (int)length, width, height, channels, STBI_rgb_alpha);
    if (rgba == (stbi_uc *)0 || *width <= 0 || *height <= 0) return 0;
    count = (size_t)*width * (size_t)*height;
    if ((size_t)*width != 0 && count / (size_t)*width != (size_t)*height) return 0;
    if (count > pixel_capacity) return 0;
    for (index = 0; index < count; ++index) {
        const unsigned char red = rgba[index * 4u + 0u];
        const unsigned char green = rgba[index * 4u + 1u];
        const unsigned char blue = rgba[index * 4u + 2u];
        const unsigned char alpha = rgba[index * 4u + 3u];
        pixels[index] = ((uint32_t)alpha << 24) | ((uint32_t)red << 16) |
            ((uint32_t)green << 8) | (uint32_t)blue;
    }
    return 1;
}

/* Same per-call bounded arena as the established8-bit decoder.
 * Preserve all16 source bits;8-bit channels expand exactly by257. Alpha is
 * straight, full-range and linear. No transfer or color-profile conversion. */
static int r4img_stbi_decode16_arena(R4ImgArena *arena, const unsigned char *bytes, size_t length,
    unsigned char *scratch, size_t scratch_length, uint16_t *pixels,
    size_t pixel_capacity, int *width, int *height, int *channels)
{
    stbi_us *rgba;
    size_t count;
    if (!bytes || !length || length > 0x7fffffffu || !scratch || !pixels) return 0;
    r4img_arena_reset(arena, scratch, scratch_length);
    rgba = stbi_load_16_from_memory(arena, bytes, (int)length, width, height, channels, STBI_rgb_alpha);
    if (!rgba || *width <= 0 || *height <= 0) return 0;
    count = (size_t)*width * (size_t)*height;
    if (count / (size_t)*width != (size_t)*height || count > pixel_capacity) return 0;
    r4img_memcpy(pixels, rgba, count * 4u * sizeof(uint16_t));
    return 1;
}

int r4img_stbi_decode(const unsigned char *bytes, size_t length,
    unsigned char *scratch, size_t scratch_length, uint32_t *pixels,
    size_t pixel_capacity, int *width, int *height, int *channels)
{
    R4ImgArena arena = {0};
    int result = r4img_stbi_decode_arena(&arena, bytes, length, scratch,
        scratch_length, pixels, pixel_capacity, width, height, channels);
    r4img_publish_diagnostic(&arena);
    return result;
}

int r4img_stbi_decode16(const unsigned char *bytes, size_t length,
    unsigned char *scratch, size_t scratch_length, uint16_t *pixels,
    size_t pixel_capacity, int *width, int *height, int *channels)
{
    R4ImgArena arena = {0};
    int result = r4img_stbi_decode16_arena(&arena, bytes, length, scratch,
        scratch_length, pixels, pixel_capacity, width, height, channels);
    r4img_publish_diagnostic(&arena);
    return result;
}

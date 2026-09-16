/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4VK_NVK_DEVICE_H
#define R4VK_NVK_DEVICE_H
#include "nv_device_info.h"
#include <r4os/r4draw.h>
#include <vulkan/vulkan_core.h>

/* Hardware description only. The eventual pdev/queue builder must separately
 * admit implemented execution, synchronization and image-layout operations.
 * No API version, queue family, Vulkan feature or conformance claim is made. */
struct r4vk_nvk_architecture {
   struct nv_device_info info;
   R4GfxBackendBinding binding;
   uint64_t memory_generation, va_start, va_end;
   uint32_t bind_alignment;
};
VkResult r4vk_nvk_query_architecture(const R4Draw *draw,
                                    const R4GfxBackendInfo *backend,
                                    struct r4vk_nvk_architecture *out);
#endif

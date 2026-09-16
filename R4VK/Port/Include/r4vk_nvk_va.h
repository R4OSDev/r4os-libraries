/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4VK_NVK_VA_H
#define R4VK_NVK_VA_H

#include "nvkmd/nvkmd.h"
#include <r4os/r4draw.h>

/* Private NVK adapter, not a public library ABI. One context belongs to one
 * nvkmd_dev and outlives its VA objects. The memory owner supplies a borrowed
 * canonical reference; the kernel obtains its own loan before start returns.
 * dev->va_start/end and pdev->bind_align_B must contain actual backend limits.
 * No Linux FD or RM token crosses this interface. */
struct r4vk_nvk_va_context {
   struct nvkmd_dev *dev;
   R4Draw draw;
   uint32_t adapter_id;
   uint64_t memory_generation;
   uint32_t lost; /* atomic, shared by this device's resource calls */
   VkResult (*reference)(struct nvkmd_mem *mem, R4GfxBufferReference *out);
};

VkResult r4vk_nvk_va_context_init(struct r4vk_nvk_va_context *context,
                                 struct nvkmd_dev *dev, const R4Draw *draw,
                                 uint32_t adapter, uint64_t generation,
                                 VkResult (*reference)(struct nvkmd_mem *,
                                                       R4GfxBufferReference *));
bool r4vk_nvk_va_device_lost(const struct r4vk_nvk_va_context *context);
VkResult r4vk_nvk_alloc_va(struct r4vk_nvk_va_context *context,
                          struct vk_object_base *log_obj,
                          enum nvkmd_va_flags flags, uint8_t pte_kind,
                          uint64_t size_B, uint64_t align_B,
                          uint64_t fixed_addr, struct nvkmd_va **out);

#endif

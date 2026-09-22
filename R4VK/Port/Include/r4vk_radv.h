/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4VK_RADV_H
#define R4VK_RADV_H
#include "ac_gpu_info.h"
#include "r4vk_provider.h"
#include <r4amd.h>

/* Native facts are separate from all NVK and libdrm private layouts. */
struct r4vk_radv_architecture {
   struct radeon_info info;
   R4GfxBackendInfo backend;
   R4AmdDeviceFacts facts;
   uint64_t system_heap_bytes;
};
VkResult r4vk_radv_query_architecture(const R4Draw *, const R4Dev *,
   const R4GfxBackendInfo *, struct r4vk_radv_architecture *);
struct radeon_winsys;
struct vk_sync_type;
struct radv_physical_device;
struct vk_device;
VkResult r4vk_radv_device_winsys(const struct radv_physical_device *, struct vk_device *, struct radeon_winsys **);
VkResult r4vk_radv_create_winsys(const R4Draw *, const R4Dev *,
   const struct r4vk_radv_architecture *, struct radeon_winsys **);
struct radv_instance;
VkResult r4vk_radv_physical_create(struct radv_instance *, const R4Draw *, const R4Dev *,
   const struct r4vk_radv_architecture *, struct vk_physical_device **);
void r4vk_radv_filter_physical(struct radv_physical_device *);
extern const struct vk_sync_type r4vk_radv_sync_type;
extern const struct r4vk_provider r4vk_radv_provider;
#endif

/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4VK_NATIVE_WSI_H
#define R4VK_NATIVE_WSI_H
#include "../../Bindings/C/r4vk_wsi.h"
#include <r4os/r4draw.h>
struct vk_instance;
struct nvk_physical_device;
struct r4vk_surface {
   struct vk_instance *instance;
   const R4XStartContext *application;
   R4WindowGraphicsSurface identity;
};
int32_t r4vk_window_query(const R4XStartContext *application, uint32_t window_id,
   const R4WindowGraphicsSurface *expected, R4WindowGraphicsReply *reply);
VKAPI_ATTR VkResult VKAPI_CALL r4vkCreateWindowSurface(VkInstance instance,
   const R4VkWindowSurfaceCreateInfo *info, const VkAllocationCallbacks *allocator,
   VkSurfaceKHR *surface);
#endif

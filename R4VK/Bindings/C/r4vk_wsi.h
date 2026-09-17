/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4VK_WSI_H
#define R4VK_WSI_H
#include <r4os/r4l.h>
#include <vulkan/vulkan_core.h>

/* Private R4VK entrypoint, obtained from its instance-proc loader with a
 * live instance that enabled VK_KHR_surface. This is not a registered
 * Vulkan extension and allocates no VkStructureType or extension number.
 * application is the calling program's original R4XStart context; its
 * lifetime must include the surface's lifetime. window_id comes from the
 * normal Desktop API. WINSVC authenticates the calling process generation.
 * VK_NOT_READY means Desktop has not published a compatible window yet.
 * Destroy a successful result with vkDestroySurfaceKHR. */
#define R4VK_WINDOW_SURFACE_ENTRYPOINT "r4vkCreateWindowSurface"
#define R4VK_WINDOW_SURFACE_VERSION 1u
typedef struct R4VkWindowSurfaceCreateInfo {
    uint32_t version;
    uint32_t size;
    const R4XStartContext *application;
    uint32_t window_id;
    uint32_t reserved;
} R4VkWindowSurfaceCreateInfo;
typedef VkResult (VKAPI_PTR *PFN_r4vkCreateWindowSurface)(
    VkInstance instance, const R4VkWindowSurfaceCreateInfo *info,
    const VkAllocationCallbacks *allocator, VkSurfaceKHR *surface);

#endif

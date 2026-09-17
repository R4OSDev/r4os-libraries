/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4vk_wsi.h"
#include "r4vk_nvk_device.h"
#include "nvk_entrypoints.h"
#include "nvk_format.h"
#include "nvk_image.h"
#include "nvk_physical_device.h"
#include "vk_alloc.h"
#include "vk_instance.h"
#include <r4gfx.h>

static struct r4vk_surface *surface_from_handle(VkSurfaceKHR handle)
{
   return (struct r4vk_surface *)(uintptr_t)handle;
}

VKAPI_ATTR VkResult VKAPI_CALL
r4vkCreateWindowSurface(VkInstance handle, const R4VkWindowSurfaceCreateInfo *info,
   const VkAllocationCallbacks *allocator, VkSurfaceKHR *out)
{
   if (out) *out = VK_NULL_HANDLE;
   if (!handle || !info || !out || info->version != R4VK_WINDOW_SURFACE_VERSION ||
       info->size != sizeof(*info) || !info->application || !info->window_id || info->reserved)
      return VK_ERROR_INITIALIZATION_FAILED;
   VK_FROM_HANDLE(vk_instance, instance, handle);
   if (!instance->enabled_extensions.KHR_surface) return VK_ERROR_EXTENSION_NOT_PRESENT;
   R4WindowGraphicsReply reply;
   int32_t status = r4vk_window_query(info->application, info->window_id, NULL, &reply);
   if (status == R4OS_WINDOW_GRAPHICS_UNAVAILABLE || status == R4OS_WINDOW_GRAPHICS_NOT_READY)
      return VK_NOT_READY;
   if (status != R4OS_WINDOW_GRAPHICS_OK) return VK_ERROR_SURFACE_LOST_KHR;
   struct r4vk_surface *surface = vk_zalloc2(&instance->alloc, allocator,
      sizeof(*surface), 8, VK_SYSTEM_ALLOCATION_SCOPE_OBJECT);
   if (!surface) return VK_ERROR_OUT_OF_HOST_MEMORY;
   *surface = (struct r4vk_surface) {
      .instance = instance, .application = info->application, .identity = reply.surface,
   };
   *out = (VkSurfaceKHR)(uintptr_t)surface;
   return VK_SUCCESS;
}

VKAPI_ATTR void VKAPI_CALL
nvk_DestroySurfaceKHR(VkInstance handle, VkSurfaceKHR surface,
                     const VkAllocationCallbacks *allocator)
{
   if (!surface) return;
   VK_FROM_HANDLE(vk_instance, instance, handle);
   /* The surface owns no display, imported BO or service publication. */
   vk_free2(&instance->alloc, allocator, surface_from_handle(surface));
}

static VkImageUsageFlags format_usage(const struct nvk_physical_device *pdev, VkFormat format)
{
   /* Swapchain imports use an uncompressed linear BO. Query the exact NIL
    * modifier instead of advertising arbitrary optimal-tiled image features. */
   VkFormatFeatureFlags2 f = nvk_get_image_format_features(pdev, format,
      VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT, 0);
   VkImageUsageFlags usage = 0;
   if (f & VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT)
      usage |= VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT;
   if (f & VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT) usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
   if (f & VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT) usage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
   if (f & VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT) usage |= VK_IMAGE_USAGE_SAMPLED_BIT;
   if (f & VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT) usage |= VK_IMAGE_USAGE_STORAGE_BIT;
   return usage;
}

static void add_format(struct r4vk_surface_caps *caps, VkFormat format,
                      VkImageUsageFlags usage, VkCompositeAlphaFlagsKHR alpha)
{
   if (!(usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT)) return;
   for (uint32_t i = 0; i < caps->format_count; i++) {
      if (caps->formats[i].format == format) { caps->alpha[i] |= alpha; return; }
   }
   const uint32_t i = caps->format_count++;
   assert(i < ARRAY_SIZE(caps->formats));
   caps->formats[i] = (VkSurfaceFormatKHR){format, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
   caps->alpha[i] = alpha;
   caps->usage &= usage;
}

static VkCompositeAlphaFlagsKHR native_alpha(const R4WindowGraphicsFormat *entry)
{
   if (entry->reserved) return 0;
   R4GfxColorDescription color;
   memcpy(&color, entry->color, sizeof(color));
   VkCompositeAlphaFlagsKHR alpha;
   if (entry->format == R4OS_GFX_BUFFER_FORMAT_XRGB8888 && color.alpha == R4GFX_COLOR_ALPHA_OPAQUE)
      alpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
   else if (entry->format == R4OS_GFX_BUFFER_FORMAT_ARGB8888 && color.alpha == R4GFX_COLOR_ALPHA_ELECTRICAL)
      alpha = VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR;
   else return 0;
   const R4GfxColorDescription expected = {
      .version = 1, .size = sizeof(expected), .primaries = R4GFX_COLOR_PRIMARIES_SRGB,
      .transfer = R4GFX_COLOR_TRANSFER_SRGB, .range = R4GFX_COLOR_RANGE_FULL,
      .alpha = color.alpha, .precision = R4GFX_COLOR_PRECISION_UNORM8,
      .reference_white = 1000000, .peak = 1000000,
   };
   return memcmp(&expected, &color, sizeof(color)) ? 0 : alpha;
}

uint32_t r4vk_surface_format(const R4WindowGraphicsConfig *config,
   VkFormat format, VkColorSpaceKHR space, VkCompositeAlphaFlagBitsKHR alpha)
{
   if ((format != VK_FORMAT_B8G8R8A8_UNORM && format != VK_FORMAT_B8G8R8A8_SRGB) ||
       space != VK_COLOR_SPACE_SRGB_NONLINEAR_KHR || !alpha) return UINT32_MAX;
   for (uint32_t i = 0; i < config->format_count; i++)
      if (native_alpha(&config->formats[i]) == alpha) return i;
   return UINT32_MAX;
}

VkResult r4vk_surface_snapshot(struct nvk_physical_device *pdev, VkSurfaceKHR handle,
                         struct r4vk_surface_caps *caps)
{
   *caps = (struct r4vk_surface_caps){0};
   struct r4vk_surface *surface = surface_from_handle(handle);
   if (!surface || surface->instance != pdev->vk.instance) return VK_ERROR_SURFACE_LOST_KHR;
   R4WindowGraphicsReply reply;
   if (r4vk_window_query(surface->application, surface->identity.window_id,
                        &surface->identity, &reply) != R4OS_WINDOW_GRAPHICS_OK)
      return VK_ERROR_SURFACE_LOST_KHR;
   const R4WindowGraphicsConfig *config = &reply.config;
   if (config->version != 1 || config->size != sizeof(*config) || !config->revision ||
       !config->width || !config->height || config->reserved ||
       config->format_count > ARRAY_SIZE(config->formats) || !config->format_count ||
       config->min_images < 2 || config->max_images < config->min_images || config->max_images > 3 ||
       !(config->present_modes & R4OS_WINDOW_GRAPHICS_FIFO) ||
       config->present_modes & ~(R4OS_WINDOW_GRAPHICS_FIFO | R4OS_WINDOW_GRAPHICS_MAILBOX) ||
       config->flags & ~R4OS_WINDOW_GRAPHICS_VISIBLE || !config->display_generation ||
       !config->output.connector_id || !config->output.connection_generation ||
       config->output.adapter_id != config->backend.binding.adapter_id ||
       config->output.device_generation != config->backend.binding.device_generation)
      return VK_ERROR_SURFACE_LOST_KHR;
   caps->config = *config;
   struct r4vk_nvk_architecture facts;
   if (r4vk_nvk_query_pdev_architecture(pdev->nvkmd, &facts) != VK_SUCCESS)
      return VK_ERROR_SURFACE_LOST_KHR;
   if (memcmp(&facts.binding, &config->backend.binding, sizeof(facts.binding)) ||
       facts.memory_generation != config->backend.memory_generation ||
       config->width > pdev->vk.properties.maxImageDimension2D ||
       config->height > pdev->vk.properties.maxImageDimension2D)
      return VK_SUCCESS; /* Another adapter/incarnation is not this surface's owner. */

   caps->usage = ~0u;
   for (uint32_t i = 0; i < config->format_count; i++) {
      const R4WindowGraphicsFormat *entry = &config->formats[i];
      if (entry->reserved) continue;
      /* Admit only byte-identical color contracts with an implemented Vulkan
       * color-space mapping. FP16/HDR remains in the shared compositor but is
       * not silently relabelled as a Vulkan extended color space. */
      const VkCompositeAlphaFlagsKHR alpha = native_alpha(entry);
      if (!alpha) continue;
      add_format(caps, VK_FORMAT_B8G8R8A8_UNORM, format_usage(pdev, VK_FORMAT_B8G8R8A8_UNORM), alpha);
      add_format(caps, VK_FORMAT_B8G8R8A8_SRGB, format_usage(pdev, VK_FORMAT_B8G8R8A8_SRGB), alpha);
   }
   caps->common_alpha = ~0u;
   for (uint32_t i = 0; i < caps->format_count; i++) caps->common_alpha &= caps->alpha[i];
   caps->supported = caps->format_count && caps->common_alpha &&
                     (caps->usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);
   return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL
nvk_GetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice handle, uint32_t family,
   VkSurfaceKHR surface, VkBool32 *supported)
{
   VK_FROM_HANDLE(nvk_physical_device, pdev, handle);
   *supported = false;
   struct r4vk_surface_caps caps;
   VkResult result = r4vk_surface_snapshot(pdev, surface, &caps);
   if (result == VK_SUCCESS && family < pdev->queue_family_count &&
       (pdev->queue_families[family].queue_flags & VK_QUEUE_GRAPHICS_BIT))
      *supported = caps.supported;
   return result;
}

VKAPI_ATTR VkResult VKAPI_CALL
nvk_GetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice handle,
   VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR *out)
{
   VK_FROM_HANDLE(nvk_physical_device, pdev, handle);
   struct r4vk_surface_caps caps;
   VkResult result = r4vk_surface_snapshot(pdev, surface, &caps);
   if (result != VK_SUCCESS) return result;
   if (!caps.supported) return VK_ERROR_SURFACE_LOST_KHR;
   VkExtent2D extent = {caps.config.width, caps.config.height};
   *out = (VkSurfaceCapabilitiesKHR) {
      .minImageCount = caps.config.min_images, .maxImageCount = caps.config.max_images,
      .currentExtent = extent, .minImageExtent = extent, .maxImageExtent = extent,
      .maxImageArrayLayers = 1, .supportedTransforms = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR,
      .currentTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR,
      .supportedCompositeAlpha = caps.common_alpha, .supportedUsageFlags = caps.usage,
   };
   return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL
nvk_GetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice handle,
   VkSurfaceKHR surface, uint32_t *count, VkSurfaceFormatKHR *out)
{
   VK_FROM_HANDLE(nvk_physical_device, pdev, handle);
   struct r4vk_surface_caps caps;
   VkResult result = r4vk_surface_snapshot(pdev, surface, &caps);
   if (result != VK_SUCCESS) return result;
   if (!caps.supported) return VK_ERROR_SURFACE_LOST_KHR;
   if (!out) { *count = caps.format_count; return VK_SUCCESS; }
   uint32_t copied = MIN2(*count, caps.format_count);
   memcpy(out, caps.formats, copied * sizeof(*out));
   *count = copied;
   return copied < caps.format_count ? VK_INCOMPLETE : VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL
nvk_GetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice handle,
   VkSurfaceKHR surface, uint32_t *count, VkPresentModeKHR *out)
{
   VK_FROM_HANDLE(nvk_physical_device, pdev, handle);
   struct r4vk_surface_caps caps;
   VkResult result = r4vk_surface_snapshot(pdev, surface, &caps);
   if (result != VK_SUCCESS) return result;
   if (!caps.supported) return VK_ERROR_SURFACE_LOST_KHR;
   const VkPresentModeKHR modes[] = {VK_PRESENT_MODE_FIFO_KHR, VK_PRESENT_MODE_MAILBOX_KHR};
   const uint32_t available = caps.config.present_modes & R4OS_WINDOW_GRAPHICS_MAILBOX ? 2 : 1;
   if (!out) { *count = available; return VK_SUCCESS; }
   const uint32_t copied = MIN2(*count, available);
   memcpy(out, modes, copied * sizeof(*out));
   *count = copied;
   return copied < available ? VK_INCOMPLETE : VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL
nvk_GetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice handle,
   const VkPhysicalDeviceSurfaceInfo2KHR *info, VkSurfaceCapabilities2KHR *out)
{
   return nvk_GetPhysicalDeviceSurfaceCapabilitiesKHR(handle, info->surface, &out->surfaceCapabilities);
}

VKAPI_ATTR VkResult VKAPI_CALL
nvk_GetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice handle,
   const VkPhysicalDeviceSurfaceInfo2KHR *info, uint32_t *count, VkSurfaceFormat2KHR *out)
{
   /* One snapshot serves both enumeration and copy, including changing size
    * or visibility. Preserve the caller's sType/pNext on each output entry. */
   VK_FROM_HANDLE(nvk_physical_device, pdev, handle);
   struct r4vk_surface_caps caps;
   VkResult result = r4vk_surface_snapshot(pdev, info->surface, &caps);
   if (result != VK_SUCCESS) return result;
   if (!caps.supported) return VK_ERROR_SURFACE_LOST_KHR;
   if (!out) { *count = caps.format_count; return VK_SUCCESS; }
   const uint32_t copied = MIN2(*count, caps.format_count);
   for (uint32_t i = 0; i < copied; i++) out[i].surfaceFormat = caps.formats[i];
   *count = copied;
   return copied < caps.format_count ? VK_INCOMPLETE : VK_SUCCESS;
}

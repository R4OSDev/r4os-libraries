/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#ifndef R4VK_NVK_WSI_IMAGE_H
#define R4VK_NVK_WSI_IMAGE_H
#include <stdbool.h>
#include <r4os/r4draw.h>
#include <vulkan/vulkan_core.h>

/* Private WSI-owned pair. The caller keeps VkDevice and its allocator alive
 * and destroys the image before its memory, after outstanding use retires.
 * The source BO reference stays owned by its caller. No public extension,
 * surface, presentation right or display capability is created here. */
struct r4vk_nvk_wsi_image {
   VkImage image;
   VkDeviceMemory memory;
   R4GfxBufferDescriptor descriptor;
};
/* Uses Mesa's generated Vulkan compatibility classes. Only creation flags
 * implemented by the native WSI are accepted; format lists remain caller-owned. */
VkResult r4vk_wsi_validate_formats(VkFormat base, VkSwapchainCreateFlagsKHR flags,
                                  const VkImageFormatListCreateInfo *formats);
bool r4vk_wsi_equal_formats(const VkImageFormatListCreateInfo *a,
                            const VkImageFormatListCreateInfo *b);
VkResult r4vk_nvk_import_wsi_image(VkDevice device,
                                  const R4GfxBufferHandle *source,
                                  VkFormat format, VkImageUsageFlags usage,
                                  VkImageCreateFlags flags,
                                  const VkImageFormatListCreateInfo *formats,
                                  const VkAllocationCallbacks *allocator,
                                  struct r4vk_nvk_wsi_image *out);
void r4vk_nvk_finish_wsi_image(VkDevice device,
                              const VkAllocationCallbacks *allocator,
                              struct r4vk_nvk_wsi_image *image);
#endif

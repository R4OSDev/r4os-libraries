/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4vk_nvk_physical.h"
#include "nvk_physical_device.h"
#include "vk_instance.h"
#include "util/list.h"

VkResult r4vk_nvk_enumerate_with_tables(struct vk_instance *instance,
   const R4Draw *draw, const R4Dev *devices)
{
   if (!instance || !draw || !devices ||
       !list_is_empty(&instance->physical_devices.list))
      return VK_ERROR_INITIALIZATION_FAILED;
   struct list_head created;
   list_inithead(&created);
   VkResult result = VK_SUCCESS;
   for (uint32_t index = 0; index < R4OS_GFX_QUEUE_BACKEND_CAPACITY; index++) {
      R4GfxBackendInfo backend;
      int32_t status = r4draw_gfx_queue_backend_info(draw, index, &backend);
      if (status == 0) continue; /* Vacant slots do not end the inventory. */
      if (status != 1) { result = VK_ERROR_INITIALIZATION_FAILED; goto fail; }
      struct vk_physical_device *device = NULL;
      result = nvk_create_r4os_physical_device(instance, draw, devices,
                                              &backend, &device);
      if (result == VK_ERROR_INCOMPATIBLE_DRIVER) continue;
      if (result != VK_SUCCESS) goto fail;
      list_addtail(&device->link, &created);
   }
   /* Construction may sleep. Revalidate every admitted incarnation before
    * publishing any device, so a reset cannot leave a partial success list. */
   list_for_each_entry(struct vk_physical_device, device, &created, link) {
      struct nvk_physical_device *nvk =
         container_of(device, struct nvk_physical_device, vk);
      struct r4vk_nvk_architecture facts;
      result = r4vk_nvk_query_pdev_architecture(nvk->nvkmd, &facts);
      if (result != VK_SUCCESS) goto fail;
   }
   list_for_each_entry_safe(struct vk_physical_device, device, &created, link) {
      list_del(&device->link);
      list_addtail(&device->link, &instance->physical_devices.list);
   }
   return VK_SUCCESS; /* An inventory with no eligible NVIDIA is valid. */
fail:
   list_for_each_entry_safe(struct vk_physical_device, device, &created, link) {
      list_del(&device->link);
      nvk_physical_device_destroy(device);
   }
   return result;
}

VkResult r4vk_nvk_enumerate_physical_devices(struct vk_instance *instance)
{
   R4Draw draw;
   R4Dev devices;
   if (r4vk_get_graphics_tables(&draw, &devices) != 1)
      return VK_ERROR_INITIALIZATION_FAILED;
   return r4vk_nvk_enumerate_with_tables(instance, &draw, &devices);
}

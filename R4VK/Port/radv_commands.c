/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0 */
#include "r4vk_radv_winsys.h"

/* Bounded recording storage. Overflow invalidates the whole command buffer;
 * the existing storage is then a sink for subsequent bounded emit blocks. */
#define RECORD_DWORDS (1u << 20)
#define MAX_IB_DWORDS (RECORD_DWORDS - 8)
#define NOP 0xffff1000u
static struct r4vk_radv_cs *native(struct ac_cmdbuf *cs) { return container_of(cs, struct r4vk_radv_cs, base); }
static enum radeon_bo_domain domain(const struct radeon_winsys *ws) { (void)ws; return RADEON_DOMAIN_GTT; }
static struct ac_cmdbuf *create_cs(struct radeon_winsys *base, enum amd_ip_type engine, bool secondary)
{
   (void)secondary;
   if (engine != AMD_IP_GFX && engine != AMD_IP_COMPUTE) return NULL;
   struct r4vk_radv_ws *ws = (struct r4vk_radv_ws *)base;
   if (r4vk_radv_is_lost(ws)) return NULL;
   struct r4vk_radv_cs *cs = calloc(1, sizeof(*cs));
   if (!cs) return NULL;
   cs->base.buf = malloc(RECORD_DWORDS * sizeof(uint32_t));
   if (!cs->base.buf) { free(cs); return NULL; }
   cs->base.max_dw = MAX_IB_DWORDS;
   cs->ws = ws; cs->engine = engine; cs->result = VK_SUCCESS;
   r4vk_radv_ws_ref(ws);
   return &cs->base;
}
static void reset_cs(struct ac_cmdbuf *base)
{
   struct r4vk_radv_cs *cs = native(base);
   if (cs->buffer) cs->ws->base.buffer_destroy(&cs->ws->base, &cs->buffer->base);
   cs->buffer = NULL;
   base->max_dw = MAX_IB_DWORDS;
   base->cdw = base->reserved_dw = 0;
   base->context_roll = false;
   cs->result = VK_SUCCESS;
}
static void destroy_cs(struct ac_cmdbuf *base)
{
   struct r4vk_radv_cs *cs = native(base);
   reset_cs(base);
   free(base->buf);
   struct r4vk_radv_ws *ws = cs->ws;
   free(cs); r4vk_radv_ws_unref(ws);
}
static void grow(struct ac_cmdbuf *base, size_t needed)
{
   struct r4vk_radv_cs *cs = native(base);
   /* RADV requests bounded packet blocks. Secondary arrays are checked
    * separately before copying; never let an oversized block enter the sink. */
   if (needed > MAX_IB_DWORDS) {
      /* Preserve enough writable recording memory for the current emit block
       * even though finalization must report the command buffer overflow. */
      if (needed > UINT32_MAX - 8 || needed > SIZE_MAX / 4) abort();
      void *sink = realloc(base->buf, (needed + 8) * 4);
      if (!sink) abort();
      base->buf = sink;
      base->max_dw = needed;
   }
   cs->result = VK_ERROR_OUT_OF_DEVICE_MEMORY;
   base->cdw = base->reserved_dw = 0;
}
static void pad(struct ac_cmdbuf *base, unsigned leave)
{
   if (leave > 7 || base->cdw > MAX_IB_DWORDS) { native(base)->result = VK_ERROR_OUT_OF_DEVICE_MEMORY; return; }
   while ((base->cdw + leave) & 7) base->buf[base->cdw++] = NOP;
   base->reserved_dw = MAX2(base->reserved_dw, base->cdw);
}
static VkResult finalize(struct ac_cmdbuf *base)
{
   struct r4vk_radv_cs *cs = native(base);
   if (cs->result != VK_SUCCESS) return cs->result;
   if (cs->buffer) return VK_SUCCESS;
   if (!base->cdw) base->buf[base->cdw++] = NOP;
   pad(base, 0);
   if (base->cdw > MAX_IB_DWORDS) return cs->result = VK_ERROR_OUT_OF_DEVICE_MEMORY;
   struct radeon_winsys_bo *bo;
   cs->result = cs->ws->base.buffer_create(&cs->ws->base, base->cdw * 4u, 4096,
      RADEON_DOMAIN_GTT, RADEON_FLAG_CPU_ACCESS | RADEON_FLAG_NO_INTERPROCESS_SHARING,
      RADV_BO_PRIORITY_CS, 0, &bo);
   if (cs->result != VK_SUCCESS) return cs->result;
   void *mapped = cs->ws->base.buffer_map(&cs->ws->base, bo, false, NULL);
   if (!mapped) { cs->ws->base.buffer_destroy(&cs->ws->base, bo); return cs->result = VK_ERROR_MEMORY_MAP_FAILED; }
   memcpy(mapped, base->buf, base->cdw * 4u);
   cs->ws->base.buffer_unmap(&cs->ws->base, bo, false);
   cs->buffer = (struct r4vk_radv_bo *)bo;
   return cs->result;
}
static bool chain(struct ac_cmdbuf *a, struct ac_cmdbuf *b, bool pre) { (void)a; (void)b; (void)pre; return false; }
static void unchain(struct ac_cmdbuf *a) { (void)a; }
static void add(struct ac_cmdbuf *base, struct radeon_winsys_bo *bo)
{
   if (((struct r4vk_radv_bo *)bo)->ws != native(base)->ws) native(base)->result = VK_ERROR_DEVICE_LOST;
}
static void secondary(struct ac_cmdbuf *parent, struct ac_cmdbuf *child, bool ib2)
{
   (void)ib2;
   struct r4vk_radv_cs *p = native(parent), *c = native(child);
   if (p->result != VK_SUCCESS) return;
   if (c->result != VK_SUCCESS) { p->result = c->result; return; }
   if (p == c || p->ws != c->ws || p->engine != c->engine) { p->result = VK_ERROR_UNKNOWN; return; }
   if (child->cdw > MAX_IB_DWORDS - parent->cdw) { p->result = VK_ERROR_OUT_OF_DEVICE_MEMORY; return; }
   memcpy(parent->buf + parent->cdw, child->buf, child->cdw * 4u);
   parent->cdw += child->cdw;
   parent->reserved_dw = MAX2(parent->reserved_dw, parent->cdw);
}
static void execute_ib(struct ac_cmdbuf *base, struct radeon_winsys_bo *bo, uint64_t va, uint32_t dwords, bool predicate)
{
   struct r4vk_radv_cs *cs = native(base);
   if (cs->result != VK_SUCCESS) return;
   if (bo) { add(base, bo); va = bo->va; }
   if (cs->engine != AMD_IP_GFX || !va || (va & 31) || !dwords || dwords > MAX_IB_DWORDS ||
       base->cdw > MAX_IB_DWORDS - 4) { cs->result = VK_ERROR_FEATURE_NOT_PRESENT; return; }
   base->buf[base->cdw++] = 0xc0023f00u | predicate;
   base->buf[base->cdw++] = va;
   base->buf[base->cdw++] = va >> 32;
   base->buf[base->cdw++] = dwords;
   base->reserved_dw = MAX2(base->reserved_dw, base->cdw);
}
static void dgc(struct ac_cmdbuf *cs, uint64_t va, uint32_t count, uint64_t trailer, bool predicate)
{ (void)va; (void)count; (void)trailer; (void)predicate; native(cs)->result = VK_ERROR_FEATURE_NOT_PRESENT; }
static void dump(struct ac_cmdbuf *cs, FILE *f, const int *ids, int count, enum radv_cs_dump_type type)
{ (void)cs; (void)f; (void)ids; (void)count; (void)type; }
static void annotate(struct ac_cmdbuf *cs, const char *marker) { (void)cs; (void)marker; }
void r4vk_radv_command_init(struct radeon_winsys *ws)
{
   ws->cs_domain = domain; ws->cs_create = create_cs; ws->cs_destroy = destroy_cs;
   ws->cs_reset = reset_cs; ws->cs_chain = chain; ws->cs_unchain = unchain;
   ws->cs_finalize = finalize; ws->cs_grow = grow; ws->cs_pad = pad;
   ws->cs_add_buffer = add; ws->cs_execute_secondary = secondary; ws->cs_execute_ib = execute_ib;
   ws->cs_chain_dgc_ib = dgc; ws->cs_dump = dump; ws->cs_annotate = annotate;
}

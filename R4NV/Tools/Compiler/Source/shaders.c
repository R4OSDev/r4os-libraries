/* Copyright 2026 R4
 * SPDX-License-Identifier: Apache-2.0
 */
#include "shaders.h"
#include "nak.h"
#include "nir_builder.h"

/* R4NV graphics constant-buffer ABI 1. CBuf 0 reserves bytes 0..63:
 * 0..7 sample locations (u4/u4), 16..31 sample masks (u16),
 * 48..55 an optional printf address. These single-sample fixed shaders
 * do not issue printf or sample-table loads. CBuf 1 holds their texture. */
const struct nak_constant_offset_info nak_const_offsets_base = {
   .sample_info_cb = 0, .sample_locations_offset = 0,
   .sample_masks_offset = 16, .printf_cb = 0, .printf_buffer_offset = 48,
};
const struct nak_constant_offset_info nak_const_offsets_turing_graphics = {
   .sample_info_cb = 0, .sample_locations_offset = 0,
   .sample_masks_offset = 16, .printf_cb = 0, .printf_buffer_offset = 48,
};

static nir_variable *
varying(nir_builder *b, nir_variable_mode mode, const struct glsl_type *type,
        const char *name, unsigned location)
{
   nir_variable *var = nir_variable_create(b->shader, mode, type, name);
   var->data.location = location;
   var->data.interpolation = INTERP_MODE_NOPERSPECTIVE;
   return var;
}

static nir_def *
srgb_convert(nir_builder *b, nir_def *rgba, bool encode)
{
   /* RGB is premultiplied on both sides of the transfer function. Keep
    * transparent pixels zero and never divide by zero in either branch. */
   nir_def *a = nir_channel(b, rgba, 3);
   nir_def *safe_a = nir_bcsel(b, nir_fgt_imm(b, a, 0.0), a, nir_imm_float(b, 1.0));
   nir_def *rgb = nir_fsat(b, nir_fdiv(b, nir_channels(b, rgba, 7), safe_a));
   nir_def *low, *high, *limit;
   if (encode) {
      low = nir_fmul_imm(b, rgb, 12.92);
      high = nir_fadd_imm(b, nir_fmul_imm(b,
                nir_fpow(b, rgb, nir_imm_float(b, 1.0 / 2.4)), 1.055), -0.055);
      limit = nir_imm_float(b, 0.0031308);
   } else {
      low = nir_fmul_imm(b, rgb, 1.0 / 12.92);
      high = nir_fpow(b, nir_fmul_imm(b, nir_fadd_imm(b, rgb, 0.055),
                                      1.0 / 1.055), nir_imm_float(b, 2.4));
      limit = nir_imm_float(b, 0.04045);
   }
   rgb = nir_fmul(b, nir_bcsel(b, nir_fge(b, limit, rgb), low, high), a);
   return nir_vec4(b, nir_channel(b, rgb, 0), nir_channel(b, rgb, 1),
                     nir_channel(b, rgb, 2), a);
}

nir_shader *
r4nv_build_shader(enum r4nv_shader_profile profile,
                  const nir_shader_compiler_options *options)
{
   if (profile < R4NV_RECT_VERTEX || profile > R4NV_SOLID_VERTEX)
      return NULL;
   bool vertex = profile == R4NV_RECT_VERTEX || profile == R4NV_SOLID_VERTEX;
   nir_builder b = nir_builder_init_simple_shader(
      vertex ? MESA_SHADER_VERTEX : MESA_SHADER_FRAGMENT, options,
      "R4NV rectangle profile %u", profile);

   if (vertex) {
      nir_variable *position = varying(&b, nir_var_shader_in, glsl_vec4_type(),
                                      "clip_position", VERT_ATTRIB_GENERIC0);
      nir_variable *uv = varying(&b, nir_var_shader_in, glsl_vec2_type(),
                                "uv", VERT_ATTRIB_GENERIC1);
      nir_variable *tint = varying(&b, nir_var_shader_in, glsl_vec4_type(),
                                  "premultiplied_tint", VERT_ATTRIB_GENERIC2);
      nir_variable *out_position = varying(&b, nir_var_shader_out, glsl_vec4_type(),
                                          "position", VARYING_SLOT_POS);
      nir_variable *out_uv = varying(&b, nir_var_shader_out, glsl_vec2_type(),
                                    "uv", VARYING_SLOT_VAR0);
      nir_variable *out_tint = varying(&b, nir_var_shader_out, glsl_vec4_type(),
                                      "premultiplied_tint", VARYING_SLOT_VAR1);
      nir_store_var(&b, out_position, nir_load_var(&b, position), 0xf);
      /* Pair the solid VS with its actual FS input mask. Unconsumed UV
       * stores can hit an unallocated attribute on NVIDIA; no global SM
       * exception-mask override is needed for these statically linked pairs. */
      if (profile == R4NV_RECT_VERTEX)
         nir_store_var(&b, out_uv, nir_load_var(&b, uv), 3);
      nir_store_var(&b, out_tint, nir_load_var(&b, tint), 0xf);
   } else {
      nir_variable *tint = varying(&b, nir_var_shader_in, glsl_vec4_type(),
                                  "premultiplied_tint", VARYING_SLOT_VAR1);
      nir_def *color = nir_load_var(&b, tint);
      if (profile != R4NV_SOLID_FRAGMENT) {
         nir_variable *uv = varying(&b, nir_var_shader_in, glsl_vec2_type(),
                                    "uv", VARYING_SLOT_VAR0);
         /* CBuf 1, byte 0 is one combined TIC/TSC handle. NAK owns its
          * encoding; the renderer binds the matching descriptor tables.
          * CBuf 0 remains available for NAK's internal graphics constants. */
         nir_def *handle = nir_ldc_nv(&b, 1, 32, nir_imm_int(&b, 1),
                                      nir_imm_int(&b, 0), .align_mul = 4,
                                      .align_offset = 0);
         nir_tex_instr *tex = nir_tex_instr_create(b.shader, 3);
         tex->op = nir_texop_tex;
         tex->sampler_dim = GLSL_SAMPLER_DIM_2D;
         tex->dest_type = nir_type_float32;
         tex->coord_components = 2;
         tex->src[0] = (nir_tex_src) { .src_type = nir_tex_src_coord,
                                     .src = nir_src_for_ssa(nir_load_var(&b, uv)) };
         tex->src[1] = (nir_tex_src) { .src_type = nir_tex_src_texture_handle,
                                     .src = nir_src_for_ssa(handle) };
         tex->src[2] = (nir_tex_src) { .src_type = nir_tex_src_sampler_handle,
                                     .src = nir_src_for_ssa(handle) };
         nir_def_init(&tex->instr, &tex->def, 4, 32);
         nir_builder_instr_insert(&b, &tex->instr);
         nir_def *sample = &tex->def;
         if (profile == R4NV_SRGB_DECODE_FRAGMENT)
            sample = srgb_convert(&b, sample, false);
         color = nir_fmul(&b, sample, color);
         if (profile == R4NV_SRGB_ENCODE_FRAGMENT)
            color = srgb_convert(&b, color, true);
      }
      nir_variable *output = nir_variable_create(b.shader, nir_var_shader_out,
                                                 glsl_vec4_type(), "color");
      output->data.location = FRAG_RESULT_DATA0;
      nir_store_var(&b, output, color, 0xf);
   }
   nir_validate_shader(b.shader, "R4NV source shader");
   return b.shader;
}

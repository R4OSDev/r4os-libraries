/* Copyright 2026 R4. SPDX-License-Identifier: Apache-2.0
 * Encoder input packing, profile9. CBuf1: integer Y/U/V handles at0/4/8.
 * CBuf3:u4(format1NV12/3I420, plane0Y/1UV, destination byte pitch, width),
 * then u32 height. All remaining words zero. An R8 linear target receives
 * row-major16x16 byte tiles; the fragment coordinate denotes storage bytes,
 * not source pixels. Chroma keeps UV channel parity when replicating edges.
 * No filtering, color conversion, CPU pixels or producer-fence handling here.
 */
#ifndef R4NV_ENCODE_SHADER_H
#define R4NV_ENCODE_SHADER_H
static nir_def *r4e_uniform(nir_builder *b, unsigned offset)
{
   return nir_ldc_nv(b, 4, 32, nir_imm_int(b, 3), nir_imm_int(b, offset),
                     .align_mul = 16, .align_offset = 0);
}
static nir_def *r4e_texel(nir_builder *b, unsigned plane, nir_def *position)
{
   nir_def *handle = nir_ldc_nv(b, 1, 32, nir_imm_int(b, 1), nir_imm_int(b, plane * 4),
                               .align_mul = 4, .align_offset = 0);
   nir_tex_instr *tex = nir_tex_instr_create(b->shader, 3);
   tex->op = nir_texop_txf;
   tex->sampler_dim = GLSL_SAMPLER_DIM_2D;
   tex->dest_type = nir_type_uint32;
   tex->coord_components = 2;
   tex->src[0] = (nir_tex_src) { .src_type = nir_tex_src_coord, .src = nir_src_for_ssa(position) };
   tex->src[1] = (nir_tex_src) { .src_type = nir_tex_src_texture_handle, .src = nir_src_for_ssa(handle) };
   tex->src[2] = (nir_tex_src) { .src_type = nir_tex_src_lod, .src = nir_src_for_ssa(nir_imm_int(b, 0)) };
   nir_def_init(&tex->instr, &tex->def, 4, 32);
   nir_builder_instr_insert(b, &tex->instr);
   return &tex->def;
}
static nir_def *r4nv_encode_pack(nir_builder *b, nir_def *opacity)
{
   nir_def *head = r4e_uniform(b, 0), *tail = r4e_uniform(b, 16);
   nir_def *pitch = nir_channel(b, head, 2);
   nir_def *pixel = nir_f2u32(b, nir_channels(b, nir_load_frag_coord(b), 3));
   nir_def *byte = nir_iadd(b, nir_imul(b, nir_channel(b, pixel, 1), pitch), nir_channel(b, pixel, 0));
   nir_def *tile = nir_ushr_imm(b, byte, 8), *columns = nir_ushr_imm(b, pitch, 4);
   nir_def *tile_y = nir_udiv(b, tile, columns);
   nir_def *tile_x = nir_isub(b, tile, nir_imul(b, tile_y, columns));
   nir_def *x = nir_iadd(b, nir_ishl_imm(b, tile_x, 4), nir_iand_imm(b, byte, 15));
   nir_def *y = nir_iadd(b, nir_ishl_imm(b, tile_y, 4), nir_iand_imm(b, nir_ushr_imm(b, byte, 4), 15));
   nir_def *width = nir_channel(b, head, 3), *height = nir_channel(b, tail, 0);
   nir_push_if(b, nir_ieq_imm(b, nir_channel(b, head, 1), 0));
   nir_def *luma_pos = nir_vec2(b, nir_umin(b, x, nir_iadd_imm(b, width, -1)),
                                 nir_umin(b, y, nir_iadd_imm(b, height, -1)));
   nir_def *luma = nir_channel(b, r4e_texel(b, 0, luma_pos), 0);
   nir_push_else(b, NULL);
   nir_def *chroma_pos = nir_vec2(b,
      nir_umin(b, nir_ushr_imm(b, x, 1), nir_iadd_imm(b, nir_ushr_imm(b, width, 1), -1)),
      nir_umin(b, y, nir_iadd_imm(b, nir_ushr_imm(b, height, 1), -1)));
   nir_def *uv = r4e_texel(b, 1, chroma_pos);
   nir_push_if(b, nir_ieq_imm(b, nir_channel(b, head, 0), 3));
   nir_def *planar_v = nir_channel(b, r4e_texel(b, 2, chroma_pos), 0);
   nir_push_else(b, NULL);
   nir_def *paired_v = nir_channel(b, uv, 1);
   nir_pop_if(b, NULL);
   nir_def *v = nir_if_phi(b, planar_v, paired_v);
   nir_def *chroma = nir_bcsel(b, nir_ieq_imm(b, nir_iand_imm(b, x, 1), 0), nir_channel(b, uv, 0), v);
   nir_pop_if(b, NULL);
   nir_def *code = nir_if_phi(b, luma, chroma);
   nir_def *value = nir_fmul(b, nir_fmul_imm(b, nir_u2f32(b, code), 1.0 / 255.0), opacity);
   return nir_vec4(b, value, nir_imm_float(b, 0), nir_imm_float(b, 0), opacity);
}
#endif

#include <stdio.h>
#include "clc7b7.h"
#include "clc9b7.h"
#define FIELD_BIT(field) (1U << (0 ? field))
#define TABLE(N) {N##_VIDEO_ENCODER,N##_SET_IN_REF_PIC0_LUMA,N##_SET_IN_REF_PIC0_CHROMA,N##_SET_CONTROL_PARAMS,N##_EXECUTE, \
 N##_SET_PICTURE_INDEX,N##_SET_OUT_ENCRYPT_PARAMS,N##_SET_IN_RCDATA,N##_SET_IN_DRV_PIC_SETUP,N##_SET_IN_CEAHINTS_DATA,N##_SET_OUT_ENC_STATUS, \
 N##_SET_OUT_BITSTREAM,N##_SET_IOHISTORY,N##_SET_IO_RC_PROCESS,N##_SET_IN_COLOC_DATA,N##_SET_OUT_COLOC_DATA,N##_SET_OUT_REF_PIC_LUMA, \
 N##_SET_IN_CUR_PIC,N##_SET_IN_MEPRED_DATA,N##_SET_OUT_MEPRED_DATA,N##_SET_IN_CUR_PIC_CHROMA_U,N##_SET_IN_CUR_PIC_CHROMA_V, \
 N##_SET_IN_QP_MAP,N##_SET_OUT_REF_PIC_CHROMA, \
 N##_SET_CONTROL_PARAMS_CODEC_TYPE_H264 | FIELD_BIT(N##_SET_CONTROL_PARAMS_FORCE_OUT_PIC) | FIELD_BIT(N##_SET_CONTROL_PARAMS_FORCE_OUT_COL) | FIELD_BIT(N##_SET_CONTROL_PARAMS_SLICE_STAT_ON), \
 N##_SET_APPLICATION_ID,N##_SET_APPLICATION_ID_ID_NVENC_H264}
static const unsigned int methods[][27]={TABLE(NVC7B7),TABLE(NVC9B7)};
_Static_assert(sizeof(methods)==216,"method words");
int main(int argc,char **argv){if(argc!=2)return 1;FILE *f=fopen(argv[1],"wb");if(!f)return 2;int ok=fwrite(methods,1,sizeof methods,f)==sizeof methods; if(fclose(f))return 3;return ok?0:4;}

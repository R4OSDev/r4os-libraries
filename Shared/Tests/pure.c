#include <r4std_helpers.h>
#include <r4img_helpers.h>
#include <r4font_helpers.h>
int32_t r4libraries59_pure(void) {
    if(R4StdCodecMode_controls!=0 || R4StdCodecMode_pc_graphics!=1)return 12;
    const uint8_t text[]={'A',0xcc,0x88,'B'},invalid[]={'A',0xff};
    R4LibrariesSlot value=R4StdGrapheme_prefix(0,text,sizeof(text),2);
    if(value.status || value.flags!=R4LIBRARIES_PRESENT || value.bits)return 1;
    value=R4StdGrapheme_prefix(0,text,sizeof(text),3);
    if(value.status || value.bits!=3)return 2;
    value=R4StdGrapheme_prefix(0,invalid,sizeof(invalid),1);
    if(value.status || !(value.flags&R4LIBRARIES_NATIVE_ERROR))return 3;
    if(!R4LibrariesVerifyAbi(R4Libraries_ABI_FINGERPRINT^1))return 4;
    value=R4LibrariesConstruct(R4Libraries_ABI_FINGERPRINT^1,0,0,0,(void *)(uintptr_t)1);
    if(!value.status)return 5;
    R4StdGraphemeIterator it;R4StdGraphemeRange range;
    if(R4StdGraphemeIterator_create(&it,text,sizeof(text)).status)return 6;
    value=R4StdGraphemeIterator_next(0,&it,&range);
    if(value.flags!=R4LIBRARIES_PRESENT || R4StdGraphemeRange_get_end(&range).bits!=3)return 7;
    value=R4StdGraphemeIterator_next(0,&it,&range);
    if(value.flags!=R4LIBRARIES_PRESENT || R4StdGraphemeRange_get_end(&range).bits!=4)return 8;
    value=R4StdGraphemeIterator_next(0,&it,&range);
    if(value.flags || value.status)return 9;
    R4XStartContext invalid_start={0};
    R4LibraryColorClient color;
    R4Lib_R4VIDEO_Bindings_Zig_r4video_VideoV1Client video;
    value=R4Library_colorClient(0,&invalid_start,&color);
    if(value.status || !(value.flags&R4LIBRARIES_NATIVE_ERROR))return 10;
    value=R4Library_videoClient(0,&invalid_start,&video);
    return value.status || !(value.flags&R4LIBRARIES_NATIVE_ERROR) ? 11 : 0;
}

#include <r4gfx_helpers.h>
#include <r4enc_helpers.h>
#include <r4video_helpers.h>
#include <r4aco_helpers.h>
#include <r4nak_helpers.h>
#include <string.h>
int32_t r4libraries60_transport(void) {
    /* Only the initialized field is inspected; no resource owner is started. */
    R4GfxReadbackOwner readback;
    R4LibrariesSlot why={.ptr=(void *)"Busy",.length=4,.flags=R4LIBRARIES_PRESENT};
    R4LibrariesSlot value=R4GfxReadbackOwner_set_failure(&readback,why);
    if(value.status)return 1;
    value=R4GfxReadbackOwner_get_failure(&readback);
    if(value.status || value.flags!=R4LIBRARIES_PRESENT || value.length!=4 || memcmp(value.ptr,"Busy",4))return 2;
    /* Unknown error is rejected before touching any uninitialized owner data. */
    value=R4GfxReadbackOwner_cancel(0,&readback,(const uint8_t *)"InventedError",13);
    if(!value.status)return 3;
    R4GfxDisplayProfileOwner profile;_Alignas(16) uint8_t storage[32];
    value=R4GfxDisplayProfileOwner_set_storage(&profile,storage,sizeof(storage));
    if(value.status)return 4;
    value=R4GfxDisplayProfileOwner_set_storage(&profile,storage+1,1);
    if(!value.status)return 5;
    value=R4GfxDisplayProfileOwner_get_storage(&profile);
    if(value.status || value.ptr!=storage || value.length!=sizeof(storage))return 6;
    value=R4GfxDisplayProfileOwner_set_storage(&profile,0,0);
    if(value.status || R4GfxDisplayProfileOwner_get_storage(&profile).length)return 7;
    return 0;
}
struct Collect { uint8_t bytes[4096];uintptr_t length; };
static uint8_t collect(void *context,const uint8_t *bytes,uintptr_t length){
    struct Collect *c=context;if(length>sizeof(c->bytes)-c->length)return 0;
    memcpy(c->bytes+c->length,bytes,length);c->length+=length;return 1;
}
uint64_t r4libraries60_mux(const uint8_t *bytes,uintptr_t length){
    R4EncMuxWriter writer;R4MediaSink sink;struct Collect c={0};
    R4LibrariesSlot context={.ptr=&c,.flags=R4LIBRARIES_PRESENT};
    if(R4EncMuxWriter_create(&writer,64,64).status || R4MediaSink_from_fields(&sink,context,(uintptr_t)collect).status)return 0;
    R4LibrariesSlot value=R4Media_muxPacket(0,&writer,&sink,bytes,length,1,0,1);
    if(value.status || value.flags&R4LIBRARIES_NATIVE_ERROR || R4EncMuxWriter_get_frames(&writer).bits!=1)return 0;
    uint64_t hash=14695981039346656037ull;
    for(uintptr_t i=0;i<c.length;++i)hash=(hash^c.bytes[i])*1099511628211ull;
    return hash;
}

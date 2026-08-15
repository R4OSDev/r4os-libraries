#include <stddef.h>
#include <stdint.h>
#include <r4os/r4os.h>
#include "../../../Bindings/C/r4img.h"

int32_t r4_app_main(R4App *app) {
    uint8_t bmp[54] = {0};
    R4ImgApiV1Client images;
    R4ImgInfo info = {0};
    bmp[0] = 'B';
    bmp[1] = 'M';
    bmp[18] = 1;
    bmp[22] = 1;
    bmp[26] = 1;
    bmp[28] = 24;
    if (r4img_api_v1_init(app->context, &images) != R4L_BINDING_OK) return 41;
    if (r4img_probe(&images, bmp, sizeof(bmp), (const uint8_t *)"image/bmp", 9u, &info) != R4IMG_STATUS_OK) return 42;
    if (info.format != R4IMG_FORMAT_BMP || info.width != 1u || info.height != 1u) return 43;
    return 0;
}

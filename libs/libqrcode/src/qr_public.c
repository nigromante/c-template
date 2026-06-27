
#include "include/qr_public.h"
#include "include/qrcode.h"

int qr_2_png(QRCODE_PARAM *param) {

    wrap_png_load();
    png_api->png_create(param->file, param->pixsize, param->border);

    wrap_qr_load(png_api->set_size, png_api->set_pixel);

    wrap_qr_2_png(param->text);

    png_api->flush();
    png_api->finish();

    wrap_qr_free();
    wrap_png_free();

    return 0;
}

#define QR_WRAP_C
#include "include/qr_wrap.h"

#include "include/qrcode.h"
#include <qrencode.h>

#include <stdlib.h>
#include <string.h>

#define _PIXEL_(x, y) (qr_data->data[(y) * qr_data->width + (x)] & 1)

int wrap_qr_2_png(char *text) {

    QRcode *qr_data = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr_data == NULL) {
        return 1;
    }

    qr_api->png_set_size(qr_data->width, qr_data->width);

    for (int y = 0; y < qr_data->width; y++) {
        for (int x = 0; x < qr_data->width; x++) {
            int pixel = _PIXEL_(x, y);
            if (pixel) {
                qr_api->png_pixel_on(x, y);
            }
        }
    }

    QRcode_free(qr_data);
    return 0;
}

void wrap_qr_load(fn_set_size fn_size, fn_pixel_on fn_pixel) {
    qr_api = (QR_WRAP_DATA *)malloc(sizeof(QR_WRAP_DATA));
    memset(qr_api, 0x00, sizeof(QR_WRAP_DATA));
    qr_api->qr_create = &wrap_qr_2_png;
    qr_api->png_set_size = fn_size;
    qr_api->png_pixel_on = fn_pixel;
}

void wrap_qr_free() {
    free(qr_api);
    qr_api = NULL;
}

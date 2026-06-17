#include <stdlib.h>

#include "include/qr_public.h"
#include "include/qrcode.h"
#include "include/shared.h"

PUBLIC QRCODE *qrcode_init() {

    QRCODE *qrcodePtr = (QRCODE *)malloc(sizeof(QRCODE));

    qrcodePtr->qr2png = &qr_2_png;

    return qrcodePtr;
}

PUBLIC void qrcode_release(QRCODE **ptr) {
    free(*ptr);
    ptr = NULL;
}

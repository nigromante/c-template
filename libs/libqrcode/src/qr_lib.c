#include <stdlib.h>

#include "../include/shared.h"

#include "../export/qrcode.h"
#include "../include/qr_public.h"

PUBLIC QRCODE *qrcode_init() {

    QRCODE *qrcodePtr = (QRCODE *)malloc(sizeof(QRCODE));

    qrcodePtr->show = &qrshow;
    qrcodePtr->version = &qrversion;

    return qrcodePtr;
}

PUBLIC void qrcode_release(QRCODE **ptr) {
    free(*ptr);
    ptr = NULL;
}

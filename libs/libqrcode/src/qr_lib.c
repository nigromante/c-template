#include <stdlib.h>

#include "include/qr_public.h"
#include "include/qrcode.h"
#include "include/shared.h"

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

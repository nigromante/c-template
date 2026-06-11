#define LOADER_C

#include "include/libscall.h"

void loader_init() {
    qrcode = qrcode_init();

    logger = log_init();
    logger->Instance();
}

void loader_end() {
    qrcode_release(&qrcode);

    logger->Release();
    log_release(&logger);
}

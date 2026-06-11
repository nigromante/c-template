#define LOADER_C

#include "include/libscall.h"

void loader_init() {
    qrcode = qrcode_init();

    logger = log_init();

    vio = vio_init();
}

void loader_end() {
    qrcode_release(&qrcode);

    log_release(&logger);

    vio_release(&vio);
}

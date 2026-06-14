#define LOADER_C

#include "include/libscall.h"

__attribute__((constructor)) void loader_init() {

    qrcode = qrcode_init();
    logger = log_init();
    vio = vio_init();
}

__attribute__((destructor)) void loader_end() {

    qrcode_release(&qrcode);
    log_release(&logger);
    vio_release(&vio);
}

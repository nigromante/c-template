#include <stdlib.h>

#include "include/log.h"
#include "include/log_public.h"
#include "include/shared.h"

PUBLIC LOG *log_init() {

    LOG *qrcodePtr = (LOG *)malloc(sizeof(LOG));

    qrcodePtr->Write = &log_Write;
    qrcodePtr->AddListener = &log_AddListener;

    log_Instance();
    return qrcodePtr;
}

PUBLIC void log_release(LOG **ptr) {
    log_Release();

    free(*ptr);
    ptr = NULL;
}

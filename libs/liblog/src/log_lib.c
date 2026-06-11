#include <stdlib.h>

#include "include/log.h"
#include "include/log_public.h"
#include "include/shared.h"

PUBLIC LOG *log_init() {

    LOG *qrcodePtr = (LOG *)malloc(sizeof(LOG));

    qrcodePtr->Write = &log_Write;
    qrcodePtr->Instance = &log_Instance;
    qrcodePtr->Release = &log_Release;
    qrcodePtr->AddListener = &log_AddListener;

    return qrcodePtr;
}

PUBLIC void log_release(LOG **ptr) {
    free(*ptr);
    ptr = NULL;
}

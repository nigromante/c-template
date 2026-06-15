#include <stdlib.h>

#include "include/log.h"
#include "include/log_public.h"
#include "include/shared.h"

PUBLIC LOG *log_init() {

    LOG *qrcodePtr = (LOG *)malloc(sizeof(LOG));

    qrcodePtr->Info = &log_Info;
    qrcodePtr->Debug = &log_Debug;
    qrcodePtr->Warning = &log_Warning;
    qrcodePtr->Error = &log_Error;

    qrcodePtr->Send = &log_Send;

    qrcodePtr->AddListener = &log_AddListener;

    log_Instance();
    return qrcodePtr;
}

PUBLIC void log_release(LOG **ptr) {
    log_Release();

    free(*ptr);
    ptr = NULL;
}

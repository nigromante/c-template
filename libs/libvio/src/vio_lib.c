#include <stdlib.h>

#include "include/shared.h"
#include "include/vio.h"
#include "include/vio_public.h"

PUBLIC VIO *vio_init() {

    VIO *qrcodePtr = (VIO *)malloc(sizeof(VIO));

    qrcodePtr->print = &vio_print;

    return qrcodePtr;
}

PUBLIC void vio_release(VIO **ptr) {
    free(*ptr);
    ptr = NULL;
}

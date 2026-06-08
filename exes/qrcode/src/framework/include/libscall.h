#ifndef LIBSCALL_H
#define LIBSCALL_H

#ifndef NULL
#define NULL 0x00;
#endif

#include "libs/qrcode.h"
#include "libs/vio.h"

#ifdef MAIN_C
QRCODE *qrcode = NULL;
VIO *vio = NULL;
#else
extern QRCODE *qrcode;
extern VIO *vio;
#endif

#endif

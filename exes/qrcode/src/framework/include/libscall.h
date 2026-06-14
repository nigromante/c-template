#ifndef LIBSCALL_H
#define LIBSCALL_H

#ifndef NULL
#define NULL 0x00;
#endif

#include "libs/log.h"
#include "libs/qrcode.h"
#include "libs/vio.h"

#ifdef MAIN_C

QRCODE *qrcode = NULL;
LOG *logger = NULL;
VIO *vio = NULL;

#else

extern QRCODE *qrcode;
extern LOG *logger;
extern VIO *vio;

#endif

#endif

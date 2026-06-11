#ifndef LIBSCALL_H
#define LIBSCALL_H

#ifndef NULL
#define NULL 0x00;
#endif

#include "libs/log.h"
#include "libs/qrcode.h"

#ifdef MAIN_C
QRCODE *qrcode = NULL;
LOG *logger = NULL;
#else
extern QRCODE *qrcode;
extern LOG *logger;
#endif

#endif

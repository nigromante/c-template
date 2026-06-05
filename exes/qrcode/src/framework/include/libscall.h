#ifndef LIBSCALL_H
#define LIBSCALL_H

#ifndef NULL
#define NULL 0x00;
#endif

#include "libs/qrcode.h"

#ifdef MAIN_C
QRCODE *qrcode = NULL;
#else
extern QRCODE *qrcode;
#endif

#endif

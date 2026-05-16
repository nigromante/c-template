#ifndef INC_MAIN
#define INC_MAIN

#ifndef NULL
#define NULL 0x00;
#endif

#include "../include/qrcode.h"

#ifdef FILE_MAIN
QRCODE *qrcode = NULL;
#else
extern QRCODE *qrcode;
#endif

#include "../include/loader.h"
#include "../include/proc.h"

#endif

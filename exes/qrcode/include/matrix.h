#ifndef INC_MAIN
#define INC_MAIN

#ifndef NULL
#define NULL 0x00;
#endif

#include "libs/qrcode.h"

#ifdef FILE_MAIN
QRCODE *qrcode = NULL;
#else
extern QRCODE *qrcode;
#endif

int pmain(int argc, char **argv);

#include "framework/loader.h"

#endif

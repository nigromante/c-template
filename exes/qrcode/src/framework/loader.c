#define LOADER_C

#include "include/libscall.h"

void loader_init() { qrcode = qrcode_init(); }

void loader_end() { qrcode_release(&qrcode); }

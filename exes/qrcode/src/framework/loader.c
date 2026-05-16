#define FILE_INIT

#include "../../include/matrix.h"

void loader_init() { qrcode = qrcode_init(); }

void loader_end() { qrcode_release(&qrcode); }

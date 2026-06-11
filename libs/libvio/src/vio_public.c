#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIO_PUBLIC_C
#include "include/vio_public.h"

void vio_print(int level, char *format, ...) {
    char buffer[256];
    va_list args;

    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    printf("vio_print :: %d :: %s\n", level, buffer);
}

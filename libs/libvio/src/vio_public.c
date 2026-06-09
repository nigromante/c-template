#include <stdarg.h>
#include <stdio.h>

#include "include/vio_public.h"

void vio_print(const char *level, const char *format, ...) {
    char buffer[256];
    va_list args;

    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    printf("[%s] %s\n", level, buffer);
}

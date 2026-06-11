#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_PUBLIC_C
#include "include/log_public.h"

void log_Instance() {
    logger = (tLogger *)malloc(sizeof(tLogger));
    memset(logger, 0x00, sizeof(tLogger));
}

void log_Release() {
    free(logger);
    logger = 0x00;
}

void log_AddListener(fn _fn, int flag) {
    logger->lista[logger->total++] = _fn;
    return;
}

void log_Write(int level, char *format, ...) {
    char buffer[256];
    va_list args;

    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](level, buffer);
    }
}

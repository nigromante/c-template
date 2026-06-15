#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_PUBLIC_C
#include "include/log.h"
#include "include/log_public.h"

void log_Instance() {
    logger = (TLOGGER *)malloc(sizeof(TLOGGER));
    memset(logger, 0x00, sizeof(TLOGGER));
}

void log_Release() {
    free(logger);
    logger = 0x00;
}

void log_AddListener(fn _fn, int flag) {
    if (flag) {
        logger->lista[logger->total++] = _fn;
    }
    return;
}

void log_Write(int level, char *format, va_list args) {
    char buffer[1024];

    vsnprintf(buffer, sizeof(buffer), format, args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](level, buffer);
    }
}

void log_Info(char *fmt, ...) { _LOG_WRITE_(LOG_INFO, fmt); }

void log_Debug(char *fmt, ...) { _LOG_WRITE_(LOG_DEBUG, fmt); }

void log_Warning(char *fmt, ...) { _LOG_WRITE_(LOG_WARNING, fmt); }

void log_Error(char *fmt, ...) { _LOG_WRITE_(LOG_ERROR, fmt); }

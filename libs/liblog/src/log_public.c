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

void log_Write(int level, char *format, ...) {
    char buffer[1024];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](level, buffer);
    }
}

void log_Info(char *format, ...) {
    char buffer[1024];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](LOG_INFO, buffer);
    }
}

void log_Debug(char *format, ...) {
    char buffer[1024];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](LOG_DEBUG, buffer);
    }
}

void log_Warning(char *format, ...) {
    char buffer[1024];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](LOG_WARNING, buffer);
    }
}

void log_Error(char *format, ...) {
    char buffer[1024];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    for (int i = 0; i < logger->total; i++) {
        logger->lista[i](LOG_ERROR, buffer);
    }
}

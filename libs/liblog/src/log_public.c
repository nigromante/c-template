#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_PUBLIC_C
#include "include/log.h"
#include "include/log_data.h"
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

void log_Write(int level, char *buffer) { msg_push(level, buffer); }

void log_Send() {
    int level = 0;
    char *buffer = 0;

    if (msg_pop(&level, &buffer)) {

        for (int i = 0; i < logger->total; i++) {
            logger->lista[i](level, buffer);
        }
    }

    return;
}

void log_Info(char *fmt, ...) { _LOG_WRITE_(LOG_INFO, fmt); }

void log_Debug(char *fmt, ...) { _LOG_WRITE_(LOG_DEBUG, fmt); }

void log_Warning(char *fmt, ...) { _LOG_WRITE_(LOG_WARNING, fmt); }

void log_Error(char *fmt, ...) { _LOG_WRITE_(LOG_ERROR, fmt); }

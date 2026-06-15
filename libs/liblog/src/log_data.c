#define LOG_DATA_C
#include "include/log_data.h"
#include <stdio.h>
#include <string.h>

void msg_push(int level, char *buffer) {
    if (ldata_tail == NEXT(ldata_head)) {
        return;
    }
    logData[ldata_head].level = level;
    strcpy(logData[ldata_head].buffer, buffer);
    ldata_head = NEXT(ldata_head);
}

int msg_pop(int *level, char **buffer) {
    if (ldata_tail == ldata_head) {
        return 0;
    }
    *level = logData[ldata_tail].level;
    *buffer = logData[ldata_tail].buffer;
    ldata_tail = NEXT(ldata_tail);
    return 1;
}

void msg_trace() {
    int tail = ldata_tail;
    int head = ldata_head;

    int level = 0;
    char *buffer = 0;

    while (msg_pop(&level, &buffer)) {
        printf("\n [%d] [%s]", level, buffer);
    }
    // printf("\n");

    ldata_tail = tail;
    ldata_head = head;
}

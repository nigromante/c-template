#ifndef LOG_DATA_H
#define LOG_DATA_H

#define MAXLOG 20
#define NEXT(a) (((a) + 1) % MAXLOG)

typedef struct {
    int level;
    char buffer[1024];
} LOG_DATA;

#ifdef LOG_DATA_C
LOG_DATA logData[MAXLOG];
int ldata_head = 0;
int ldata_tail = 0;
#else
extern LOG_DATA logData[MAXLOG];
#endif

void msg_push(int level, char *buffer);
int msg_pop(int *level, char **buffer);
void msg_trace();
#endif

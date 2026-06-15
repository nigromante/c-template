#ifndef LOG_PUBLIC_H
#define LOG_PUBLIC_H

#define N 10

typedef void (*fn)(int, char *);

typedef struct {
    fn lista[N];
    int total;
} TLOGGER;

#ifdef LOG_PUBLIC_C
TLOGGER *logger;
#endif

void log_Instance();
void log_Release();
void log_AddListener(fn _fn, int flag);

void log_Debug(char *format, ...);
void log_Info(char *format, ...);
void log_Warning(char *format, ...);
void log_Error(char *format, ...);

#define _LOG_WRITE_(a, b)                                                                                                                                                                              \
    do {                                                                                                                                                                                               \
        char buffer[1024];                                                                                                                                                                             \
        va_list args;                                                                                                                                                                                  \
        va_start(args, (b));                                                                                                                                                                           \
        vsnprintf(buffer, sizeof(buffer), (b), args);                                                                                                                                                  \
        log_Write((a), buffer);                                                                                                                                                                        \
        va_end(args);                                                                                                                                                                                  \
    } while (0);
#endif

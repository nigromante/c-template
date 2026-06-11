#ifndef LOG_PUBLIC_H
#define LOG_PUBLIC_H

#define N 10

typedef void (*fn)(int, char *);

typedef struct {
    fn lista[N];
    int total;
} tLogger;

#ifdef LOG_PUBLIC_C
tLogger *logger;
#endif

void log_Write(int, char *format, ...);
void log_Instance();
void log_Release();
void log_AddListener(fn _fn);

#endif

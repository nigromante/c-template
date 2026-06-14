#ifndef LOG_H
#define LOG_H

typedef void (*fn)(int, char *);

typedef struct {

    void (*Write)(int, char *, ...);
    void (*Info)(char *, ...);
    void (*Debug)(char *, ...);
    void (*Warning)(char *, ...);
    void (*Error)(char *, ...);

    void (*AddListener)(fn _fn, int);

} LOG;

LOG *log_init();
void log_release(LOG **);

#define LOG_INFO 1
#define LOG_DEBUG 2
#define LOG_WARNING 4
#define LOG_ERROR 8

#endif

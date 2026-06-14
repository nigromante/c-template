#ifndef LOG_H
#define LOG_H

typedef void (*fn)(int, char *);

typedef struct {

    void (*Write)(int, char *, ...);
    void (*AddListener)(fn _fn, int);

} LOG;

LOG *log_init();
void log_release(LOG **);

#define LOG_DEBUG 1
#define LOG_WARNING 2
#define LOG_ERROR 4

#endif

#ifndef LOG_H
#define LOG_H

typedef void (*fn)(int, char *);

typedef struct {

    void (*Write)(int, char *, ...);
    void (*AddListener)(fn _fn, int);

} LOG;

LOG *log_init();
void log_release(LOG **);

#endif

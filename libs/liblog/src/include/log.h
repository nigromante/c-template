#ifndef LOG_H
#define LOG_H

typedef void (*fn)(int, char *);

typedef void (*fn_logger)(int, char *, ...);
typedef void (*fn_AddListener)(fn _fn);

typedef struct {

    fn_logger Write;
    fn_AddListener AddListener;

} LOG;

LOG *log_init();
void log_release(LOG **);

#endif

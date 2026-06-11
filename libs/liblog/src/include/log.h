#ifndef LOG_H
#define LOG_H

typedef void (*fn)(int, char *);

typedef void (*fn_logger)(int, char *, ...);
typedef void (*fn_loggerCreate)();
typedef void (*fn_loggerDelete)();
typedef void (*fn_loggerAddListener)(fn _fn);

typedef struct {

    fn_logger Write;
    fn_loggerCreate Instance;
    fn_loggerDelete Release;
    fn_loggerAddListener AddListener;

} LOG;

LOG *log_init();
void log_release(LOG **);

#endif

#ifndef ENV_H
#define ENV_H

#define LOG_DEBUG 1
#define LOG_WARNING 2
#define LOG_ERROR 4

typedef struct {
    int stdout;
    int mailer;
} ENV;

#ifdef ENV_C
ENV env;
#else
extern ENV env;
#endif

void env_init();

#endif

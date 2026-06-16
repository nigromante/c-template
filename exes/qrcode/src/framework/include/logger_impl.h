#ifndef LOGGER_IMPL_H
#define LOGGER_IMPL_H

typedef struct {
    int stdout;
    int mailer;
} LOG_ENV;

#ifdef LOGGER_IMPL_C

LOG_ENV log_env;

#else

extern LOG_ENV log_env;

#endif

void logger_init();

void log_stdout(int, char *);
void log_mailer(int, char *);

#endif

#ifndef LOGGER_H
#define LOGGER_H

#define LOG_DEBUG 1
#define LOG_WARNING 2
#define LOG_ERROR 4

typedef struct {
    int stdout;
    int mailer;
} LOG_ENV;

#ifdef LOGGER_C
LOG_ENV log_env;
#else
extern LOG_ENV log_env;
#endif

void logger_init();
void log_void();
void log_stdout(int level, char *buffer);
void log_mailer(int level, char *buffer);

#endif

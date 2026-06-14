#include <stdio.h>
#include <stdlib.h>

#define LOGGER_C
#include "include/logger.h"

void logger_init() {
    log_env.stdout = atoi(getenv("stdout"));
    log_env.mailer = atoi(getenv("mailer"));
}

void log_stdout(int level, char *buffer) {
    if (log_env.stdout & level) {
        printf("\n log_stdout :: %s\n", buffer);
    }
}

void log_mailer(int level, char *buffer) {
    if (log_env.mailer & level) {
        printf("\n log_mailer :: %s\n", buffer);
    }
}

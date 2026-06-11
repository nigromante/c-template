#include <stdio.h>

#include "include/env.h"

void log_void() {}

void log_stdout(int level, char *buffer) {
    env.stdout &level ? printf("\n log_stdout :: %s\n", buffer) : log_void();
    return;
}

void log_mailer(int level, char *buffer) {
    env.mailer &level ? printf("\n log_mailer :: %s\n", buffer) : log_void();
    return;
}

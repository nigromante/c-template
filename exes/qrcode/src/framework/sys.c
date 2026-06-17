#include <string.h>
#include <time.h>
#include <unistd.h>

void sleep_ms(long milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

void replace_char(char *str, char find, char replace) {
    while ((str = strchr(str, find)) != NULL) {
        *str = replace;
        str++; // Move to next character to prevent an infinite loop
    }
}

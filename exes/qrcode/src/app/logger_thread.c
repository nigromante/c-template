#define LOGGER_THREAD_C
#include "include/logger_thread.h"
#include "include/raylib_thread.h"
#include "include/terminal_thread.h"

#include "../framework/include/libscall.h"
#include <pthread.h>

void *fn_logger(void *args) {

    while (ff_terminal | ff_raylib) {
        logger->Send();
        sleep_ms(10);
    }

    pthread_exit(NULL);
}

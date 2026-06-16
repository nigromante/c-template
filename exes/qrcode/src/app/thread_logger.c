#define LOGGER_THREAD_C
#include "include/thread_logger.h"
#include "include/thread_raylib.h"
#include "include/thread_terminal.h"

#include "../framework/include/libscall.h"
#include <pthread.h>

void *fn_logger(void *args) {

    while (ff_terminal | ff_raylib) {
        logger->Send();
        sleep_ms(10);
    }

    pthread_exit(NULL);
}

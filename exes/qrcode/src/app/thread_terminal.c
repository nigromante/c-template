#define TERMINAL_THREAD_C
#include "include/thread_terminal.h"

#include "../framework/include/libscall.h"
#include <pthread.h>

void *fn_terminal(void *args) {

    vio->print("[ENTER] to finish program ...");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre  : [%s] ", "Julian Vidal A.");

    // getchar();
    ff_terminal = 0;

    pthread_exit(NULL);
}

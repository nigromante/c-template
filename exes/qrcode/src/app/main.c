#include <pthread.h>
#include <stdio.h>
#include <string.h>

#include "include/thread_logger.h"
#include "include/thread_raylib.h"
#include "include/thread_terminal.h"

#define MAIN_C
#include "../framework/include/libscall.h"

void initialize() {

    load_env(".env");

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);
}

int main(int argc, char **argv) {
    pthread_t pt_main;
    pthread_t pt_raylib;
    pthread_t pt_logger;

    initialize();

    char texto[256];
    strcpy(texto, argv[1]);
    replace_char(texto, '_', ' ');
    vio->print("texto : [%s] ", texto);

    pthread_create(&pt_logger, NULL, fn_logger, NULL);
    pthread_create(&pt_main, NULL, fn_terminal, texto);
    pthread_create(&pt_raylib, NULL, fn_raylib, texto);

    pthread_join(pt_main, NULL);
    pthread_join(pt_logger, NULL);
    pthread_join(pt_raylib, NULL);

    printf("\n");
    return 0;
}

// eof

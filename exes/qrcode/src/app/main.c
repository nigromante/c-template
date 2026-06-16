#include <pthread.h>
#include <stdio.h>

#include "include/logger_thread.h"
#include "include/raylib_thread.h"
#include "include/terminal_thread.h"

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

    char texto[] = "Julian Enrique Vidal Alarcon";
    vio->print("argv1 : [%s] ", argv[1]);

    pthread_create(&pt_logger, NULL, fn_logger, NULL);
    pthread_create(&pt_main, NULL, fn_terminal, NULL);
    pthread_create(&pt_raylib, NULL, fn_raylib, texto);

    pthread_join(pt_main, NULL);
    pthread_join(pt_logger, NULL);
    pthread_join(pt_raylib, NULL);

    printf("\n");
    return 0;
}

// eof

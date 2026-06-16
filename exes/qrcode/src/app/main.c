#include <pthread.h>
#include <stdio.h>

#define MAIN_C
#include "../framework/include/libscall.h"

#define TEXTO "Julian Vidal Alarcon"

int ff_main = 1;
extern int ff_raylib;
void *fn_raylib(void *args);

void initialize() {

    load_env(".env");

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);
}

void *fn_main(void *args) {

    vio->print("[ENTER] to finish program ...");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre ERROR : [%s] ", "Julian Vidal A.");

    getchar();
    ff_main = 0;

    pthread_exit(NULL);
}

void *fn_logger(void *args) {

    while (ff_main | ff_raylib) {
        logger->Send();
        sleep_ms(10);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t pt_main;
    pthread_t pt_raylib;
    pthread_t pt_logger;

    initialize();

    pthread_create(&pt_logger, NULL, fn_logger, NULL);
    pthread_create(&pt_main, NULL, fn_main, NULL);
    pthread_create(&pt_raylib, NULL, fn_raylib, NULL);

    pthread_join(pt_main, NULL);
    pthread_join(pt_logger, NULL);
    pthread_join(pt_raylib, NULL);

    printf("\n");
    return 0;
}

// eof

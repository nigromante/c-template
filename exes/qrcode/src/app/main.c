#include <pthread.h>
#include <stdio.h>

#define MAIN_C
#include "../framework/include/libscall.h"

int ff_main = 1;

void initialize() {

    load_env(".env");

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);
}

void *fn_main(void *args) {

    printf("[ENTER] to finish program ...\n");

    qrcode->version();
    qrcode->show("Julian Vidal Alarcon");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre ERROR : [%s] ", "Julian Vidal A.");

    vio->print(123, "[%s]", "test");

    getchar();
    ff_main = 0;

    pthread_exit(NULL);
}

void *fn_logger(void *args) {

    while (ff_main) {
        logger->Send();
        sleep_ms(10);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t pt_main;
    pthread_t pt_logger;

    initialize();

    pthread_create(&pt_logger, NULL, fn_logger, NULL);
    pthread_create(&pt_main, NULL, fn_main, NULL);

    pthread_join(pt_main, NULL);
    pthread_join(pt_logger, NULL);

    return 0;
}

// eof

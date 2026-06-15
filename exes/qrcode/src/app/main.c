#include <pthread.h>
#include <stdio.h>
#define MAIN_C
#include "../framework/include/libscall.h"

void initialize() {

    load_env(".env");

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);
}

void *fn_main(void *args) {
    qrcode->version();
    qrcode->show("Julian Vidal Alarcon");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre ERROR : [%s] ", "Julian Vidal A.");

    vio->print(123, "[%s]", "test");

    return NULL;
}

int main(int argc, char **argv) {
    pthread_t pt_main;

    initialize();

    pthread_create(&pt_main, NULL, fn_main, NULL);
    pthread_join(pt_main, NULL);

    return 0;
}

// eof

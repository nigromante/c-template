#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define MAIN_C
#include "../framework/include/libscall.h"

void sleep_ms(long milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

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

void *fn_logger(void *args) {

    while (1) {
        logger->Send();
        sleep_ms(100);
    }
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t pt_main;
    pthread_t pt_logger;

    initialize();

    pthread_create(&pt_main, NULL, fn_main, NULL);
    pthread_create(&pt_logger, NULL, fn_logger, NULL);

    pthread_join(pt_main, NULL);
    pthread_join(pt_logger, NULL);

    return 0;
}

// eof

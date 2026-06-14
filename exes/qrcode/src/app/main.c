#include <stdio.h>
#define MAIN_C
#include "../framework/include/libscall.h"

#include "include/env.h"
#include "include/logger.h"

int main(int argc, char **argv) {

    env_init();

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);

    qrcode->version();
    qrcode->show("Julian Vidal Alarcon");

    logger->Write(LOG_ERROR, "Nombre : [%s] ", "Julian Vidal A.");

    vio->print(123, "[%s]", "test");

    return 0;
}

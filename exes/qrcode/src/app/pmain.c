#include <stdio.h>

#include "../framework/include/libscall.h"

#define PMAIN_C
#include "include/env.h"
#include "include/logger.h"
// #include "include/pmain.h"

int pmain(int argc, char **argv) {

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

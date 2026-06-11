#include <stdio.h>

#include "../framework/include/libscall.h"

#define PMAIN_C
#include "include/env.h"
#include "include/logger.h"
#include "include/pmain.h"

int pmain(int argc, char **argv) {

    env_init();

    env.stdout ? logger->AddListener(log_stdout) : log_void();
    env.mailer ? logger->AddListener(log_mailer) : log_void();

    qrcode->version();

    qrcode->show("Julian Vidal Alarcon");

    logger->Write(LOG_ERROR, "Nombre : [%s] ", "Julian Vidal A.");

    return 0;
}

#include <stdio.h>
#define MAIN_C
#include "../framework/include/libscall.h"

void initialize() {

    load_env(".env");

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);
}

int main(int argc, char **argv) {

    initialize();

    qrcode->version();
    qrcode->show("Julian Vidal Alarcon");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre  : [%s] ", "Julian Vidal A.");

    vio->print(123, "[%s]", "test");

    return 0;
}

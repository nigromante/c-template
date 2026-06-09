#include "../framework/include/libscall.h"

#define PMAIN_C
#include "include/pmain.h"

int pmain(int argc, char **argv) {

    qrcode->version();

    qrcode->show("Julian Vidal Alarcon");

    vio->print("DEBUG", "Nombre : [%s] ", "Julian Vidal A.");

    return 0;
}

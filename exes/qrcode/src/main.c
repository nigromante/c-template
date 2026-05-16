#include "../include/qrcode.h"

int main(int argc, char **argv) {

    QRCODE *qrcode = qrcode_init();

    qrcode->version();

    qrcode->show("Julian Vidal Alarcon");

    qrcode_release(&qrcode);

    return 0;
}

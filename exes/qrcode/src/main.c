#include "../include/a.h"
#include "../include/qrcode.h"

int main(int argc, char **argv) {

    QRCODE *qrcode = qrcode_init();

    qrcode->version();

    qrcode->show("Julian Vidal Alarcon");

    fn();
    qrcode_release(&qrcode);
    return 0;
}

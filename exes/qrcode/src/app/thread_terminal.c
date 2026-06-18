#define TERMINAL_THREAD_C
#include "include/thread_terminal.h"

#include "../framework/include/libscall.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *fn_terminal(void *args) {
    char *texto = (char *)args;

    vio->print("[ENTER] to finish program ...");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre  : [%s] ", "Julian Vidal A.");

    QRCODE_PARAM param;
    strcpy(param.text, texto);

    int _border[] = {0, 1, 2, 3};
    int _pixsize[] = {1, 2, 4, 8, 12};
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 4; y++) {
            sprintf(param.file, "radio_nelson_%d_%d.png", _pixsize[x], _border[y]);
            param.border = _border[y];
            param.pixsize = _pixsize[x];
            param.pointsize = 1;
            qrcode->qr2png(&param);
        }
    }

    // getchar();
    ff_terminal = 0;

    pthread_exit(NULL);
}

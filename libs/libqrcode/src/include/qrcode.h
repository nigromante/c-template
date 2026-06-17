#ifndef QRCODE_H
#define QRCODE_H

typedef struct {

    int (*qr2png)(char *text, char *file);

} QRCODE;

QRCODE *qrcode_init();
void qrcode_release(QRCODE **);

int qr_2_png(char *text, char *file);

#endif

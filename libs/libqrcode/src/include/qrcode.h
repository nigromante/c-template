#ifndef QRCODE_H
#define QRCODE_H

typedef struct {
    char text[256];
    char file[256];
    int border;
    int pixsize;
    int pointsize;
} QRCODE_PARAM;

typedef struct {

    int (*qr2png)(QRCODE_PARAM *param);

} QRCODE;

QRCODE *qrcode_init();
void qrcode_release(QRCODE **);

int qr_2_png(QRCODE_PARAM *param);

#endif

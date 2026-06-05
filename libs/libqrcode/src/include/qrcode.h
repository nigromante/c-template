#ifndef QRCODE_H
#define QRCODE_H

typedef struct {
    void (*version)();
    int (*show)(char *);
} QRCODE;

QRCODE *qrcode_init();
void qrcode_release(QRCODE **);

#endif

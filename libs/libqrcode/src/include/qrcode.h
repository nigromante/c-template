#ifndef QRCODE_H
#define QRCODE_H

typedef struct {

    void (*version)();
    int (*show)(char *);

    int (*callback)(int, int, char *text, void (*p)(int, int, int, int, int));
} QRCODE;

QRCODE *qrcode_init();
void qrcode_release(QRCODE **);
int qrcallback(int, int, char *text, void (*p)(int, int, int, int, int));
#endif

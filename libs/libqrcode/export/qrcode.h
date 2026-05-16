#ifndef QRCODE_EXPORT
#define QRCODE_EXPORT

typedef struct {
    void (*version)();
    int (*show)(char *);
} QRCODE;

QRCODE *qrcode_init();
void qrcode_release(QRCODE **);

#endif

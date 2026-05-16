#ifndef INC_QRCODE
#define INC_QRCODE

typedef struct {
    void (*version)();
    int (*show)(char *);
} QRCODE;

QRCODE *qrcode_init();
void qrcode_release(QRCODE **);

#endif

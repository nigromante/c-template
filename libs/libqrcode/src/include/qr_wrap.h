#ifndef QR_WRAP_H
#define QR_WRAP_H

#ifndef NULL
#define NULL 0
#endif

typedef void (*fn_pixel_on)(int, int);
typedef void (*fn_set_size)(int, int);

typedef struct {
    fn_pixel_on png_pixel_on;
    fn_set_size png_set_size;
    int (*qr_create)(char *text);
} QR_WRAP_DATA;

#ifdef QR_WRAP_C
QR_WRAP_DATA *qr_api = NULL;
#else
extern QR_WRAP_DATA *qr_api;
#endif

int wrap_qr_2_png(char *text);
void wrap_qr_load(fn_set_size fn_size, fn_pixel_on fn_pixel);
void wrap_qr_free();

#endif

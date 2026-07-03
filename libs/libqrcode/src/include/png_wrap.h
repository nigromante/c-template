#ifndef PNG_WRAP_H
#define PNG_WRAP_H

#include <png.h>

#ifndef NULL
#define NULL 0
#endif

#define PIX_LEN 3

#define BORDER (png_api->border)
#define BORDER_FULL (2 * BORDER)

#define PIX_SIZE (png_api->pix_size)
#define _PIX_SIZE_ (PIX_SIZE * PIX_LEN)

#define WIDTH (png_api->width)

#define WIDTH_FULL (BORDER_FULL + WIDTH)

#define BUFF_SIZE (WIDTH_FULL * PIX_SIZE)
#define BUFF_SIZE_FULL (WIDTH_FULL * _PIX_SIZE_)

typedef struct {
    int (*png_create)(char *file, int pix_size, int border);
    void (*set_size)(int w, int h);
    void (*set_pixel)(int x, int y);
    void (*finish)();
    void (*flush)();

    png_structp png_ptr;
    png_infop info_ptr;
    FILE *fp;

    // Parametrics
    int pix_size;   // Size of a pixel in qr
    int border;     // border of qr - in pix_size
    int point_size; // point size to divide a pixel in qr

    // Input
    int width;
    int height;
    char *data;

    // Temp
    char *buffer;

} PNG_WRAP_DATA;

#ifdef PNG_WRAP_C
PNG_WRAP_DATA *png_api = NULL;
#else
extern PNG_WRAP_DATA *png_api;
#endif

void wrap_png_load();
void wrap_png_free();
int wrap_png_create(char *file, int pix_size, int border);
void wrap_png_set_size(int w, int h);
void wrap_png_set_pixel(int x, int y);
void wrap_png_finish();
void wrap_png_draw();
#endif

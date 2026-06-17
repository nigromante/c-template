#include <png.h>
#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/qr_public.h"

#define _PIXEL_(x, y) (qr_data->data[(y) * qr_data->width + (x)] & 1)

#define PIX_SIZE 8
#define SIZE (size)
#define WIDTH SIZE
#define HEIGHT SIZE

int qr_2_png(char *text, char *file) {

    QRcode *qr_data = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr_data == NULL) {
        return 1;
    }

    int size = qr_data->width;

    FILE *fp = fopen("qrcode.png", "wb");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    // 1. Initialize core write structure
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_ptr) {
        fclose(fp);
        return EXIT_FAILURE;
    }

    // 2. Initialize info structure
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, NULL);
        fclose(fp);
        return EXIT_FAILURE;
    }

    // 3. Set up error handling (required by libpng)
    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        return EXIT_FAILURE;
    }

    // 4. Set up standard C stream I/O
    png_init_io(png_ptr, fp);

    // 5. Write PNG header info (Width, Height, Bit Depth, Color Type)
    png_set_IHDR(png_ptr, info_ptr, (WIDTH + 2) * PIX_SIZE, (HEIGHT + 2) * PIX_SIZE,
                 8,                  // 8 bits per channel
                 PNG_COLOR_TYPE_RGB, // RGB channels (no alpha)
                 PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_ptr, info_ptr);

    // 6. Allocate memory for image pixels (3 bytes per pixel for RGB)

    // -------------------------------------------------
    int tt = 3 * WIDTH * PIX_SIZE * sizeof(png_byte) + 48;
    png_bytep row = malloc(tt);
    memset((void *)row, 0xff, tt);
    for (int i = 0; i < PIX_SIZE; i++) {
        png_write_row(png_ptr, row);
    }
    for (int y = 0; y < size; y++) {
        memset((void *)row, 0xff, tt);
        for (int x = 0; x < size; x++) {
            int pixel = _PIXEL_(x, y);
            if (pixel) {
                memset(row + 24 + (x * 24), 0, 24);
            }
        }
        for (int i = 0; i < PIX_SIZE; i++) {
            png_write_row(png_ptr, row);
        }
    }
    memset((void *)row, 0xff, tt);
    for (int i = 0; i < PIX_SIZE; i++) {
        png_write_row(png_ptr, row);
    }
    free(row);
    // -------------------------------------------------

    // 8. End write operation and clean up
    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);

    QRcode_free(qr_data);
    return 0;
}

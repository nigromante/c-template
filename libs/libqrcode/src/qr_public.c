#include <png.h>
#include <qrencode.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/qr_public.h"

#define _PIXEL_(x, y) (qr_data->data[(y) * qr_data->width + (x)] & 1)

#define PIX_SIZE 16

#define SIZE (size)
#define WIDTH SIZE
#define HEIGHT SIZE

#define BLANCO "\xff\xff\xff"
#define AMARILLO "\xff\xff\xd0"
#define AMARILLO2 "\xee\xee\x66"
#define NARANJA2 "\xff\xe0\x00"

#define NEGRO "\x00\x00\x00"
#define ROJO "\xaf\x00\x00"
#define VERDE "\x00\xaf\x00"
#define AZUL "\x00\x00\xaf"
#define NARANJA "\xdf\x7f\x00"

char pix_fg[5][3];
char pix_bg[5][3];

void pix_color_init() {
    memcpy(pix_fg[0], NEGRO, 3);
    memcpy(pix_fg[1], ROJO, 3);
    memcpy(pix_fg[2], VERDE, 3);
    memcpy(pix_fg[3], AZUL, 3);
    memcpy(pix_fg[4], NARANJA, 3);

    memcpy(pix_bg[0], BLANCO, 3);
    memcpy(pix_bg[1], AMARILLO, 3);
    memcpy(pix_bg[2], AMARILLO2, 3);
    memcpy(pix_bg[3], NARANJA2, 3);
}

void paint_pix(void *buffer) {
    for (int i = 0; i < PIX_SIZE; i++) {
        int r = rand() % 5;
        memcpy(buffer + i * 3, pix_fg[r], 3);
    }
}

void pix_clear_line(void *buffer, int size) {
    for (int i = 0; i < size * PIX_SIZE * 3; i += 3) {
        int r = rand() % 2;
        memcpy(buffer + i, pix_bg[r], 3);
    }
}

int qr_2_png(char *text, char *file) {

    pix_color_init();

    QRcode *qr_data = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qr_data == NULL) {
        return 1;
    }

    int size = qr_data->width;

    FILE *fp = fopen(file, "wb");
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
    int tt = 3 * WIDTH * PIX_SIZE * sizeof(png_byte) + (2 * PIX_SIZE * 3);
    png_bytep row = malloc(tt);

    for (int i = 0; i < PIX_SIZE; i++) {
        pix_clear_line(row, WIDTH + 2);
        png_write_row(png_ptr, row);
    }

    for (int y = 0; y < size; y++) {
        pix_clear_line(row, WIDTH + 2);

        for (int i = 0; i < PIX_SIZE; i++) {
            for (int x = 0; x < size; x++) {
                int pixel = _PIXEL_(x, y);
                if (pixel) {
                    paint_pix(row + 3 * PIX_SIZE + (x * 3 * PIX_SIZE));
                }
            }
            png_write_row(png_ptr, row);
        }
    }

    for (int i = 0; i < PIX_SIZE; i++) {
        pix_clear_line(row, WIDTH + 2);
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

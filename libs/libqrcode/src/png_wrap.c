#define PNG_WRAP_C
#include "include/png_wrap.h"
#include "include/png_colors.h"

#include <stdlib.h>
#include <string.h>

void wrap_png_load() {

    png_api = (PNG_WRAP_DATA *)malloc(sizeof(PNG_WRAP_DATA));
    memset(png_api, 0x00, sizeof(PNG_WRAP_DATA));

    png_api->png_create = wrap_png_create;
    png_api->set_size = wrap_png_set_size;
    png_api->set_pixel = wrap_png_set_pixel;
    png_api->finish = wrap_png_finish;
    png_api->flush = wrap_png_flush;

    pix_color_init();
}

void wrap_png_free() {
    free(png_api);
    return;
}

int wrap_png_create(char *file, int pix_size, int border) {

    png_api->pix_size = pix_size;
    png_api->border = border;

    png_api->fp = fopen(file, "wb");
    if (!png_api->fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    // Initialize core write structure
    png_api->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png_api->png_ptr) {
        fclose(png_api->fp);
        return EXIT_FAILURE;
    }

    // Initialize info structure
    png_api->info_ptr = png_create_info_struct(png_api->png_ptr);
    if (!png_api->info_ptr) {
        png_destroy_write_struct(&png_api->png_ptr, NULL);
        fclose(png_api->fp);
        return EXIT_FAILURE;
    }

    // Set up error handling (required by libpng)
    if (setjmp(png_jmpbuf(png_api->png_ptr))) {
        png_destroy_write_struct(&png_api->png_ptr, &png_api->info_ptr);
        fclose(png_api->fp);
        return EXIT_FAILURE;
    }

    // Set up standard C stream I/O
    png_init_io(png_api->png_ptr, png_api->fp);

    return 0;
}

void wrap_png_finish() {

    png_write_end(png_api->png_ptr, NULL);
    png_destroy_write_struct(&png_api->png_ptr, &png_api->info_ptr);
    fclose(png_api->fp);

    free(png_api->data);
    free(png_api->buffer);
}

void wrap_png_flush() {
    int r = 0;
    printf("buff_size : %d : pix_size %d : width_full : %d :  width : %d ", BUFF_SIZE, PIX_SIZE, WIDTH_FULL, png_api->width);

    // Prepare background
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int offset = (y + BORDER) * BUFF_SIZE_FULL + x * _PIX_SIZE_ + BORDER * _PIX_SIZE_;
            for (int j = 0; j < PIX_SIZE; j++) {
                r = rand() % 5;
                memcpy(png_api->buffer + offset + j * 3, pix_fg[r], 3);
            }
        }
    }

    // Draw qr
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (*(png_api->data + y * WIDTH + x) == 0) {
                int offset = (y + BORDER) * BUFF_SIZE_FULL + x * _PIX_SIZE_ + BORDER * _PIX_SIZE_;
                for (int j = 0; j < PIX_SIZE; j++) {
                    r = rand() % 4;
                    memcpy(png_api->buffer + offset + j * 3, pix_bg[r], 3);
                }
            }
        }
    }

    // Write 2 png
    for (int j = 0; j < BUFF_SIZE; j++) {
        for (int k = 0; k < PIX_SIZE; k++) {
            png_write_row(png_api->png_ptr, (png_bytep)png_api->buffer + BUFF_SIZE_FULL * j);
        }
    }
    return;
}

void wrap_png_set_size(int w, int h) {

    png_api->width = w;
    png_api->height = h;

    png_api->data = (char *)malloc(WIDTH * WIDTH);
    memset(png_api->data, 0x00, WIDTH * WIDTH);

    png_api->buffer = (char *)malloc(BUFF_SIZE * BUFF_SIZE_FULL);
    memset(png_api->buffer, 0xff, BUFF_SIZE * BUFF_SIZE_FULL);

    // 5. Write PNG header info (Width, Height, Bit Depth, Color Type)
    png_set_IHDR(png_api->png_ptr, png_api->info_ptr, WIDTH_FULL * PIX_SIZE, WIDTH_FULL * PIX_SIZE,
                 8,                  // 8 bits per channel
                 PNG_COLOR_TYPE_RGB, // RGB channels (no alpha)
                 PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_api->png_ptr, png_api->info_ptr);
}

void wrap_png_set_pixel(int x, int y) {
    *(png_api->data + WIDTH * y + x) = 1;
    return;
}

// eof

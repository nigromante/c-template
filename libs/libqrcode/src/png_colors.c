#define PNG_COLORS_C

#include "include/png_colors.h"
#include <string.h>

void pix_color_init() {
    memcpy(pix_fg[0], NEGRO, PIX_LEN);
    memcpy(pix_fg[1], ROJO, PIX_LEN);
    memcpy(pix_fg[2], VERDE, PIX_LEN);
    memcpy(pix_fg[3], AZUL, PIX_LEN);
    memcpy(pix_fg[4], NARANJA, PIX_LEN);

    memcpy(pix_bg[0], BLANCO, PIX_LEN);
    memcpy(pix_bg[1], AMARILLO, PIX_LEN);
    memcpy(pix_bg[2], AMARILLO2, PIX_LEN);
    memcpy(pix_bg[3], NARANJA2, PIX_LEN);

    memcpy(pix_ag[0], NEGRO, PIX_LEN);
    memcpy(pix_ag[1], ROJO, PIX_LEN);
    memcpy(pix_ag[2], VERDE, PIX_LEN);
    memcpy(pix_ag[3], AZUL, PIX_LEN);
    memcpy(pix_ag[4], NARANJA, PIX_LEN);
    memcpy(pix_ag[5], BLANCO, PIX_LEN);
    memcpy(pix_ag[6], AMARILLO, PIX_LEN);
    memcpy(pix_ag[7], AMARILLO2, PIX_LEN);
    memcpy(pix_ag[8], NARANJA2, PIX_LEN);
}

#ifndef PNG_COLORS_H
#define PNG_COLORS_H

#ifndef PIX_LEN
#define PIX_LEN 3
#endif

#define BLANCO "\xff\xff\xff"
#define AMARILLO "\xff\xff\xd0"
#define AMARILLO2 "\xfe\xfe\xe6"
#define NARANJA2 "\xff\xe0\xe0"

#define NEGRO "\x00\x00\x00"
#define ROJO "\xaf\x00\x00"
#define VERDE "\x00\xaf\x00"
#define AZUL "\x00\x00\xaf"
#define NARANJA "\xdf\x7f\x00"

#ifdef PNG_COLORS_C

char pix_fg[5][PIX_LEN];
char pix_bg[5][PIX_LEN];
char pix_ag[9][PIX_LEN];
#else

extern char pix_fg[5][PIX_LEN];
extern char pix_bg[5][PIX_LEN];
extern char pix_ag[9][PIX_LEN];

#endif

void pix_color_init();

#endif

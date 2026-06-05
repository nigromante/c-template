#include <qrencode.h>
#include <stdio.h>

#include "../include/qr_public.h"

void qrversion() { printf("\n qrcode : 1.0\n"); }

int qrshow(char *text) {
    QRcode *qrcode = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        printf("Failed to generate QR code\n");
        return 1;
    }

    // Example: Iterate through the modules and print to console
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            // Check the LSB of the data to see if the module is dark
            if (qrcode->data[y * qrcode->width + x] & 1) {
                printf("##"); // Black module
            } else {
                printf("  "); // White module
            }
        }
        printf("\n");
    }

    QRcode_free(qrcode);
    return 0;
}

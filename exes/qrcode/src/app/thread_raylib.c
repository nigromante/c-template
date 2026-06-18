#define RAYLIB_THREAD_C
#include "include/thread_raylib.h"
#include "raylib.h"
#include <pthread.h>
#include <string.h>

#include "../framework/include/libscall.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *fn_raylib(void *args) {
    char *texto = (char *)args;

    SetTraceLogLevel(LOG_NONE);
    InitWindow(960, 800, "QR Code");

    Texture2D background = LoadTexture("background.png");

    /*
    QRCODE_PARAM param;
    strcpy(param.text, texto);
    strcpy(param.file, "qrcode.png");
    param.border = 1;
    param.pixsize = 12;
    param.pointsize = 2;
    qrcode->qr2png(&param);
    */

    Texture2D qrpng = LoadTexture("qrcode.png");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);

        DrawText(texto, 40, 10, 20, RED);
        DrawTexture(qrpng, 40, 40, WHITE);

        EndDrawing();
    }

    UnloadTexture(qrpng);
    UnloadTexture(background);

    CloseWindow();

    ff_raylib = 0;
    pthread_exit(NULL);
}

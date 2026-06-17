#define RAYLIB_THREAD_C
#include "include/thread_raylib.h"
#include "raylib.h"
#include <pthread.h>

#include "../framework/include/libscall.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *fn_raylib(void *args) {
    char *texto = (char *)args;

    SetTraceLogLevel(LOG_NONE);
    InitWindow(800, 600, "QR Code");

    Texture2D background = LoadTexture("background.png");

    qrcode->qr2png(texto, "qrcode.png");
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

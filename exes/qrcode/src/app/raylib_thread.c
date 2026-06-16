#define RAYLIB_THREAD_C
#include "include/raylib_thread.h"
#include "raylib.h"
#include <pthread.h>

#include "../framework/include/libscall.h"

#define PIXEL 12

void fn_callback(int sx, int sy, int x, int y, int flag) {
    if (flag) {
        DrawRectangle(sx + x * PIXEL, sy + y * PIXEL, PIXEL, PIXEL, RED);
    }
}

void DrawQR(char *buffer, int x, int y) { qrcode->callback(x, y, buffer, fn_callback); }

void *fn_raylib(void *args) {
    char *texto = (char *)args;
    logger->Info("DrawQR [%s] ", texto);
    qrcode->show(texto);

    SetTraceLogLevel(LOG_NONE);
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "QR Code");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Texture2D background = LoadTexture("background.png");
        DrawTexture(background, 0, 0, WHITE);
        DrawText(texto, 40, 70, 20, RED);
        DrawQR(texto, 40, 100);

        EndDrawing();
    }

    CloseWindow();

    ff_raylib = 0;
    pthread_exit(NULL);
}

#define RAYLIB_THREAD_C
#include "include/thread_raylib.h"
#include "raylib.h"
#include <pthread.h>

#include "../framework/include/libscall.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#define PIXEL 12
void fn_callback(int sx, int sy, int x, int y, int flag) {
    if (flag) {
        DrawRectangle(sx + x * PIXEL, sy + y * PIXEL, PIXEL, PIXEL, DARKPURPLE);
    }
}

void DrawQR(char *buffer, int x, int y) { qrcode->callback(x, y, buffer, fn_callback); }

void *fn_raylib(void *args) {
    char *texto = (char *)args;
    // vio->print("DrawQR [%s] ", texto);
    // qrcode->show(texto);

    SetTraceLogLevel(LOG_NONE);
    // SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(800, 600, "QR Code");

    Texture2D background = LoadTexture("background.png");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        DrawText(texto, 40, 70, 20, RED);

        pthread_mutex_lock(&mutex);
        DrawQR(texto, 40, 100);
        pthread_mutex_unlock(&mutex);

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();

    ff_raylib = 0;
    pthread_exit(NULL);
}

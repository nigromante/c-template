#include "raylib.h"
#include <pthread.h>
#include <stdio.h>

#include "../framework/include/libscall.h"

#define TEXTO "Julian Vidal Alarcon"

int ff_raylib = 2;

void fn_callback(int sx, int sy, int x, int y, int flag) {
    if (flag) {
        DrawRectangle(sx + x * 10, sy + y * 10, 10, 10, RED);
    }
}
void DrawQR(char *buffer, int x, int y) { qrcode->callback(x, y, buffer, fn_callback); }

void *fn_raylib(void *args) {

    qrcode->show(TEXTO);

    SetTraceLogLevel(LOG_NONE);
    InitWindow(800, 450, "QR Code");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Texture2D background = LoadTexture("background.png");
        DrawTexture(background, 0, 0, WHITE);
        DrawText(TEXTO, 40, 70, 20, RED);
        DrawQR(TEXTO, 40, 100);

        EndDrawing();
    }

    CloseWindow();

    ff_raylib = 0;
    pthread_exit(NULL);
}

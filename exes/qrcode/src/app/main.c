#include "raylib.h"
#include <pthread.h>
#include <stdio.h>

#define MAIN_C
#include "../framework/include/libscall.h"

int ff_main = 1;
int ff_raylib = 2;

void initialize() {

    load_env(".env");

    logger_init();

    logger->AddListener(log_stdout, log_env.stdout);
    logger->AddListener(log_mailer, log_env.mailer);
}

void fn_callback(int sx, int sy, int x, int y, int flag) {
    if (flag) {
        DrawRectangle(sx + x * 10, sy + y * 10, 10, 10, RED);
    }
}
void DrawQR(char *buffer, int x, int y) {
    // qrcode->show(buffer);
    qrcode->callback(x, y, buffer, fn_callback);
}

void *fn_raylib(void *args) {
    logger->Info("Program : [%s] ", "qrcode");
    SetTraceLogLevel(LOG_NONE);
    InitWindow(800, 450, "QR Code");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Texture2D background = LoadTexture("background.png");
        DrawTexture(background, 0, 0, WHITE);
        DrawText("Julian Vidal Alarcon", 40, 70, 20, RED);
        DrawQR("Julian Vidal Alarcon", 40, 100);

        EndDrawing();
    }

    CloseWindow();

    ff_raylib = 0;
    pthread_exit(NULL);
}

void *fn_main(void *args) {

    printf("[ENTER] to finish program ...\n");

    logger->Info("Program : [%s] ", "qrcode");
    logger->Error("Nombre ERROR : [%s] ", "Julian Vidal A.");

    vio->print(123, "[%s]", "test");

    getchar();
    ff_main = 0;

    pthread_exit(NULL);
}

void *fn_logger(void *args) {

    while (ff_main | ff_raylib) {
        logger->Send();
        sleep_ms(10);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t pt_main;
    pthread_t pt_raylib;
    pthread_t pt_logger;

    initialize();

    pthread_create(&pt_logger, NULL, fn_logger, NULL);
    pthread_create(&pt_main, NULL, fn_main, NULL);
    pthread_create(&pt_raylib, NULL, fn_raylib, NULL);

    pthread_join(pt_main, NULL);
    pthread_join(pt_logger, NULL);
    pthread_join(pt_raylib, NULL);

    return 0;
}

// eof

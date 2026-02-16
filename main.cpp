#include "raylib.h"

int main()
{
    // Configuración inicial
    const int screenWidth = 1280;
    const int screenHeight = 720;
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Ajedrez!");
    SetTargetFPS(60);

    // Inicialización
    Texture2D tablero_foto = LoadTexture("assets/tablero.png");

    while (!WindowShouldClose()) {
        // 1- @s    Actualizar

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(tablero_foto, 100, 100, WHITE);
        EndDrawing();
    }

    UnloadTexture(tablero_foto);
    CloseWindow();
    return 0;
}

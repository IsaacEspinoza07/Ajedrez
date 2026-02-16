#include "raylib.h"
#include "texturas.hpp"

int main()
{
    // Configuración inicial
    const int screenWidth = 1280;
    const int screenHeight = 720;
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Ajedrez!");
    SetTargetFPS(60);

    // Inicialización
    GestionTexturas texturas;
    texturas.CargarTodo();

    while (!WindowShouldClose()) {
        // 1- Actualizar

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexturePro(texturas.tablero,
                       {0.0f, 0.0f, (float)texturas.tablero.width,
                        (float)texturas.tablero.height},
                       {340.0f, 60.0f, 600, 600}, {0, 0}, 0.0f, WHITE);
        EndDrawing();
    }

    texturas.LiberarTodo();
    CloseWindow();
    return 0;
}

#include "Tablero.hpp"
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

    Tablero tablero;

    while (!WindowShouldClose()) {
        // 1- Actualizar

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // Dibujado
        DrawTexturePro(texturas.tablero,
                       {0.0f, 0.0f, (float)texturas.tablero.width,
                        (float)texturas.tablero.height},
                       {340.0f, 60.0f, 600, 600}, {0, 0}, 0.0f, WHITE);
        DrawTexturePro(texturas.peonBlanco,
                       {0.0f, 0.0f, (float)texturas.peonBlanco.width,
                        (float)texturas.peonBlanco.height},
                       {0, 0, 70, 70}, {-381.3 - 64 * 7, -545 + 64 * 7}, 0.0f,
                       WHITE);
        tablero.Dibujar(texturas);
        EndDrawing();
    }

    texturas.LiberarTodo();
    CloseWindow();
    return 0;
}

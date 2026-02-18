#include "Gestor.hpp"
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
    Gestor gestor(&tablero);

    while (!WindowShouldClose()) {
        // 1- Actualizar

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dibujado
        tablero.Dibujar(texturas);

        EndDrawing();
    }

    texturas.LiberarTodo();
    CloseWindow();
    return 0;
}

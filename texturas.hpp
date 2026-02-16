#pragma once

#include "raylib.h"
struct GestionTexturas {

    // Primero las GestionTexturas
    Texture2D peonBlanco;
    Texture2D peonNegro;

    Texture2D torreBlanca;
    Texture2D torreNegra;

    Texture2D alfilBlanco;
    Texture2D alfilNegro;

    Texture2D caballoBlanco;
    Texture2D caballoNegro;

    Texture2D reinaBlanca;
    Texture2D reinaNegra;

    Texture2D reyBlanco;
    Texture2D reyNegro;

    Texture2D tablero;

    // Funciones para manipular las texturas
    void CargarTodo()
    {
        peonBlanco = LoadTexture("assets/peonBlanco.png");
        peonNegro = LoadTexture("assets/peonNegro.png");

        torreBlanca = LoadTexture("assets/torreBlanca.png");
        torreNegra = LoadTexture("assets/torreNegra.png");

        alfilBlanco = LoadTexture("assets/alfilBlanco.png");
        alfilNegro = LoadTexture("assets/alfilNegro.png");

        caballoBlanco = LoadTexture("assets/caballoBlanco.png");
        caballoNegro = LoadTexture("assets/caballoNegro.png");

        reinaBlanca = LoadTexture("assets/reinaBlanca.png");
        reinaNegra = LoadTexture("assets/reinaNegra.png");

        reyBlanco = LoadTexture("assets/reyBlanco.png");
        reyNegro = LoadTexture("assets/reyNegro.png");

        tablero = LoadTexture("assets/tablero.png");
    }

    void LiberarTodo()
    {
        UnloadTexture(peonBlanco);
        UnloadTexture(peonNegro);

        UnloadTexture(torreBlanca);
        UnloadTexture(torreNegra);

        UnloadTexture(alfilBlanco);
        UnloadTexture(alfilNegro);

        UnloadTexture(caballoBlanco);
        UnloadTexture(caballoNegro);

        UnloadTexture(reinaBlanca);
        UnloadTexture(reinaNegra);

        UnloadTexture(reyBlanco);
        UnloadTexture(reyNegro);

        UnloadTexture(tablero);
    }
};

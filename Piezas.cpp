#include "Piezas.hpp"
#include "Tablero.hpp"
#include "raylib.h"
#include "texturas.hpp"

// ************* DE PIEZA **************** //

void Pieza::CambiarPosicion(int nueva_fila, int nueva_col)
{
    this->coor_x = nueva_fila;
    this->coor_y = nueva_col;
}

float conversor_x(int x)
{
    return -381.3 - 64 * x;
}
float conversor_y(int y)
{
    return -100 - 64 * y;
}

Pieza::~Pieza()
{
}

bool Pieza::ObtenerColor()
{
    return color;
}
// **************************************** //

// ***************** PEON ***************** //
Peon::Peon(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = PEON;
    this->YaMovido = false; // intersa para el doble movimiento al inicio
}
void Peon::Dibujar(GestionTexturas &texturas)
{
    Texture2D aDibujar = (color == BLANCO) ? texturas.peonBlanco : texturas.peonNegro;

    DrawTexturePro(aDibujar, {0.0f, 0.0f, (float)aDibujar.width, (float)aDibujar.height},
                   {0, 0, 70, 70}, {conversor_x(this->coor_x), conversor_y(this->coor_y)}, 0.0f,
                   WHITE);
}

bool Peon::MovimientoPermitido(int nueva_x, int nueva_y, Tablero *tablero)
{
    // PEON BLANCO
    // Movimiento doble al inicio del turno

    // Movimiento no doble

    // Captura en diagonal

    // TODO: captura al paso

    // Si no paso nada de esto...
    return 0;
}

// ***************** TORRE ***************** //
Torre::Torre(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = TORRE;
    this->YaMovido = false;
}

void Torre::Dibujar(GestionTexturas &texturas)
{
    Texture2D aDibujar = (color == BLANCO) ? texturas.torreBlanca : texturas.torreNegra;

    DrawTexturePro(aDibujar, {0.0f, 0.0f, (float)aDibujar.width, (float)aDibujar.height},
                   {0, 0, 70, 70}, {conversor_x(this->coor_x), conversor_y(this->coor_y)}, 0.0f,
                   WHITE);
}

bool Torre::MovimientoPermitido(int x_nueva, int y_nueva, Tablero *tablero)
{
    return 1;
}

// ***************** ALFIL ***************** //
Alfil::Alfil(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = ALFIL;
    this->YaMovido = false;
}
void Alfil::Dibujar(GestionTexturas &texturas)
{
    Texture2D aDibujar = (color == BLANCO) ? texturas.alfilBlanco : texturas.alfilNegro;

    DrawTexturePro(aDibujar, {0.0f, 0.0f, (float)aDibujar.width, (float)aDibujar.height},
                   {0, 0, 70, 70}, {conversor_x(this->coor_x), conversor_y(this->coor_y)}, 0.0f,
                   WHITE);
}

bool Alfil::MovimientoPermitido(int x_nueva, int y_nueva, Tablero *tablero)
{
    return 1;
}

// ***************** CABALLO ***************** //
Caballo::Caballo(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = CABALLO;
    this->YaMovido = false;
}
void Caballo::Dibujar(GestionTexturas &texturas)
{
    Texture2D aDibujar = (color == BLANCO) ? texturas.caballoBlanco : texturas.caballoNegro;

    DrawTexturePro(aDibujar, {0.0f, 0.0f, (float)aDibujar.width, (float)aDibujar.height},
                   {0, 0, 70, 70}, {conversor_x(this->coor_x), conversor_y(this->coor_y)}, 0.0f,
                   WHITE);
}

bool Caballo::MovimientoPermitido(int x_nueva, int y_nueva, Tablero *tablero)
{
    return 1;
}

// ***************** REINA ***************** //
Reina::Reina(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = REINA;
    this->YaMovido = false;
}

void Reina::Dibujar(GestionTexturas &texturas)
{
    Texture2D aDibujar = (color == BLANCO) ? texturas.reinaBlanca : texturas.reinaNegra;

    DrawTexturePro(aDibujar, {0.0f, 0.0f, (float)aDibujar.width, (float)aDibujar.height},
                   {0, 0, 70, 70}, {conversor_x(this->coor_x), conversor_y(this->coor_y)}, 0.0f,
                   WHITE);
}

bool Reina::MovimientoPermitido(int x_nueva, int y_nueva, Tablero *tablero)
{
    return 1;
}

// ***************** REY ***************** //
Rey::Rey(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = REY;
    this->YaMovido = false;
}
void Rey::Dibujar(GestionTexturas &texturas)
{
    Texture2D aDibujar = (color == BLANCO) ? texturas.reyBlanco : texturas.reyNegro;

    DrawTexturePro(aDibujar, {0.0f, 0.0f, (float)aDibujar.width, (float)aDibujar.height},
                   {0, 0, 70, 70}, {conversor_x(this->coor_x), conversor_y(this->coor_y)}, 0.0f,
                   WHITE);
}

bool Rey::MovimientoPermitido(int x_nueva, int y_nueva, Tablero *tablero)
{
    return 1;
}

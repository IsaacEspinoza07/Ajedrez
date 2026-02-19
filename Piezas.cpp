#include "Piezas.hpp"
#include "Tablero.hpp"
#include "raylib.h"
#include "texturas.hpp"
#include <cmath>

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

bool Pieza::ObtenerYaMovido()
{
    return YaMovido;
}

void Pieza::AlternarYaMovido()
{
    this->YaMovido = !this->YaMovido;
}

int Pieza::ObtenerTipoPieza()
{
    return tipo;
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
    // Blanco (sube, -1) o Negro (baja, +1)
    int orientacion = (color == BLANCO) ? -1 : 1;

    // Movimiento simple (un paso nomás)
    if (nueva_x == coor_x && nueva_y == coor_y + orientacion) {
        return (tablero->tablero[nueva_y][nueva_x] == nullptr);
        // Si a donde me muevo NO hay pieza, regreso true.
    }

    // Movimiento incial doble
    if (nueva_x == coor_x && nueva_y == coor_y + (2 * orientacion) && !YaMovido) {
        bool camino_libre = (tablero->tablero[coor_y + orientacion][coor_x] ==
                             nullptr); // Si NO me salto nada, y...
        bool nuevaPos_libre = (tablero->tablero[nueva_y][nueva_x] ==
                               nullptr); // No capturo nada (porque es directamente enfrente)
        return camino_libre && nuevaPos_libre;
    }

    // Captura diagonal
    if ((nueva_x == coor_x + 1 || nueva_x == coor_x - 1) && nueva_y == coor_y + orientacion) {
        Pieza *piezaCapturada = tablero->tablero[nueva_y][nueva_x];
        return (piezaCapturada != nullptr && piezaCapturada->ObtenerColor() != color);
    }

    // TODO: Caputa al paso

    // Si no paso nada de esto...
    return false;
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

bool Torre::MovimientoPermitido(int nueva_x, int nueva_y, Tablero *tablero)
{
    bool Recto = (nueva_x == coor_x || nueva_y == coor_y);
    if (!Recto) {
        return false;
    }

    if (!tablero->CaminoLibre(coor_x, coor_y, nueva_x, nueva_y)) {
        return false;
    }

    return true;
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

bool Alfil::MovimientoPermitido(int nueva_x, int nueva_y, Tablero *tablero)
{

    // Si aumente tanto en X como en Y LO MISMO, es diagonal (obviamente)
    bool diagonal = (std::abs(nueva_x - coor_x) == std::abs(nueva_y - coor_y));

    if (!diagonal) {
        return false;
    }
    if (!tablero->CaminoLibre(coor_x, coor_y, nueva_x, nueva_y)) {
        return false;
    }

    return true;
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

bool Caballo::MovimientoPermitido(int nueva_x, int nueva_y, Tablero *tablero)
{
    // Movimiento vertical
    if ((std::abs(coor_y - nueva_y) == 2 && std::abs(coor_x - nueva_x) == 1)) {
        return true;
    }
    // Movimiento lateral
    if ((std::abs(coor_y - nueva_y) == 1 && std::abs(coor_x - nueva_x) == 2)) {
        return true;
    }

    return false;
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

bool Reina::MovimientoPermitido(int nueva_x, int nueva_y, Tablero *tablero)
{
    // Mezclar la Torre y el Alfil (lit copiar y pegar)
    bool Recto = (nueva_x == coor_x || nueva_y == coor_y);
    bool diagonal = (std::abs(nueva_x - coor_x) == std::abs(nueva_y - coor_y));

    if (!diagonal && !Recto) {
        return false;
    }
    if (!(tablero->CaminoLibre(coor_x, coor_y, nueva_x, nueva_y))) {
        return false;
    }
    return true;
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

bool Rey::MovimientoPermitido(int nueva_x, int nueva_y, Tablero *tablero)
{
    if ((std::abs(coor_x - nueva_x) == 1 && std::abs(coor_y - nueva_y) == 0) ||
        (std::abs(coor_x - nueva_x) == 0 && std::abs(coor_y - nueva_y) == 1) ||
        (std::abs(coor_x - nueva_x) == 1 && std::abs(coor_y - nueva_y) == 1)) {
        return true;
    }
    return false;
}

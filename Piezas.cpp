#include "Piezas.hpp"

Pieza::~Pieza() {}

// ***************** PEON ***************** //
Peon::Peon(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = PEON;
    this->YaMovido = false; // intersa para el doble movimiento al inicio
}
void Peon::Dibujar() {}
// ***************** TORRE ***************** //
Torre::Torre(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = TORRE;
    this->YaMovido = false;
}

void Torre::Dibujar() {}
// ***************** ALFIL ***************** //
Alfil::Alfil(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = ALFIL;
    this->YaMovido = false;
}
void Alfil::Dibujar() {}
// ***************** CABALLO ***************** //
Caballo::Caballo(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = CABALLO;
    this->YaMovido = false;
}
void Caballo::Dibujar() {}
// ***************** REINA ***************** //
Reina::Reina(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = REINA;
    this->YaMovido = false;
}

void Reina::Dibujar() {}
// ***************** REY ***************** //
Rey::Rey(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = REY;
    this->YaMovido = false;
}
void Rey::Dibujar() {}

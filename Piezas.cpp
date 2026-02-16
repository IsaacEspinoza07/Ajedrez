#include "Piezas.hpp"
// ***************** PEON ***************** //
Peon::Peon(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = PEON;
    this->YaMovido = false; // intersa para el doble movimiento al inicio
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
// ***************** ALFIL ***************** //
Alfil::Alfil(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = ALFIL;
    this->YaMovido = false;
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

// ***************** REINA ***************** //
Reina::Reina(bool color, int x, int y)
{
    this->color = color;
    this->coor_x = x;
    this->coor_y = y;
    this->tipo = REINA;
    this->YaMovido = false;
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

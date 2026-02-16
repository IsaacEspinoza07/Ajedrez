#pragma once

#include "Piezas.hpp"

enum { BLANCO = 0, NEGRO };
class Tablero
{
    Tablero();
    ~Tablero();

  public:
    Pieza *tablero[8][8];

    void Inicializar();
    void Dibujar();

  private:
    unsigned int turno;
};

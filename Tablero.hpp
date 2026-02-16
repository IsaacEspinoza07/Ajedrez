#pragma once

#include "Piezas.hpp"

enum TURNO { NINGUNO, BLANCO, NEGRO };
class Tablero
{
    Tablero();

  public:
    Pieza *tablero[8][8];

    void Inicializar();
    void Dibujar();

  private:
    TURNO turno;
};

#pragma once

#include "Piezas.hpp"
#include "texturas.hpp"

class Tablero
{
  public:
    Tablero();
    ~Tablero();

    Pieza *tablero[8][8];

    void Inicializar();
    void Dibujar(GestionTexturas &texturas);

  private:
    unsigned int turno;
};

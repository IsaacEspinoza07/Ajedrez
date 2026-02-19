#pragma once

#include "Piezas.hpp"
#include "texturas.hpp"

class Tablero {
public:
    Tablero();
    ~Tablero();

    Pieza *tablero[8][8];

    void Inicializar();
    void Dibujar(GestionTexturas &texturas);
    bool CaminoLibre(int x_inicial, int y_inicial, int x_final, int y_final);

private:
    unsigned int turno;
};

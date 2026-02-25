#pragma once

#include "Piezas.hpp"
#include "texturas.hpp"

class Tablero {
public:
    Tablero();
    ~Tablero();

    Pieza *ObtenerPieza(int renglon, int columna);
    void Inicializar();
    void Dibujar(GestionTexturas &texturas);
    bool CaminoLibre(int x_inicial, int y_inicial, int x_final, int y_final);
    void MoverPieza(int fila_pieza, int col_pieza, int nueva_fila, int nueva_col);

private:
    Pieza *tablero[8][8];
    void CapturarPieza(int nueva_fila, int nueva_col);
    unsigned int turno;
};

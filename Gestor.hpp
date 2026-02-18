#pragma once

#include "Piezas.hpp"
#include "Tablero.hpp"

enum class EstadoTurno { ESPERANDO_SELECCION, PIEZA_SELECCIONADA };

class Gestor {
public:
    Gestor(Tablero *tablero);
    void Actualizar();

private:
    Tablero *tablero;
    Pieza *piezaSeleccionada; // Puntero a la pieza que elijas
    int fila_seleccionada;    // coordenada-y
    int col_seleccionada;     // coordenada-x
    EstadoTurno estadoActual;
    Vector2 coorACasilla(int coor_x, int coor_y);
};

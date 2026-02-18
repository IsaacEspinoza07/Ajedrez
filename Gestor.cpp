#include "Gestor.hpp"
#include "raylib.h"

Gestor::Gestor(Tablero *tablero)
{
    this->tablero = tablero;
    this->estadoActual = EstadoTurno::ESPERANDO_SELECCION;
    this->piezaSeleccionada = nullptr;
}

Vector2 Gestor::coorACasilla(int mouse_x, int mouse_y)
{
    // Definimos el origen (esquina superior izquierda de la casilla a8)
    const float origenX = 385.0f;
    const float origenY = 107.0f;
    const float tamanoCasilla = 62.0f;

    // Calculamos la posición relativa al tablero
    float relX = (float)mouse_x - origenX;
    float relY = (float)mouse_y - origenY;

    // Obtenemos el índice de la matriz (0 a 7)
    int casillaX = (int)(relX / tamanoCasilla);
    int casillaY = (int)(relY / tamanoCasilla);

    // Validación: Si el clic está fuera de los límites 0-7, devolvemos -1
    if (casillaX < 0 || casillaX > 7 || casillaY < 0 || casillaY > 7) {
        return (Vector2){-1.0f, -1.0f};
    }

    return (Vector2){(float)casillaX, (float)casillaY};
}

void Gestor::Actualizar()
{
    // Detectar el mouse
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 coorMouse = GetMousePosition();
        Vector2 casilla = coorACasilla(coorMouse.x, coorMouse.y);

        // Damos click y estamos fuera del tablero
        if (casilla.x == -1) {
            estadoActual = EstadoTurno::ESPERANDO_SELECCION;
            piezaSeleccionada = nullptr;
            return;
        }

        int fila = casilla.y;
        int col = casilla.x;

        // Damos click
        if (estadoActual == EstadoTurno::ESPERANDO_SELECCION) {

            // Dimos click y HABIA una pieza. Si no, no hace nada.
            if (tablero->tablero[fila][col] != nullptr) { // Hay una pieza...
                piezaSeleccionada = tablero->tablero[fila][col];
                fila_seleccionada = fila;
                col_seleccionada = col;
                estadoActual = EstadoTurno::PIEZA_SELECCIONADA;
            }

        } else if (estadoActual == EstadoTurno::PIEZA_SELECCIONADA) {
            // TODO: Por aquí va la logica de los movimientos. Por ahora será mov-Libre.

            // Evitamos que mueva a la misma casilla
            if (fila == fila_seleccionada && col == col_seleccionada) {
                estadoActual = EstadoTurno::ESPERANDO_SELECCION;
                piezaSeleccionada = nullptr;
                return;
            }

            // Si habia algo, borro la memoria
            if (tablero->tablero[fila][col] != nullptr) {
                delete tablero->tablero[fila][col];
            }

            // Luego cambio la posición de la pieza movida:
            tablero->tablero[fila][col] = piezaSeleccionada; // Cambiar
            tablero->tablero[fila_seleccionada][col_seleccionada] = nullptr;

            piezaSeleccionada->CambiarPosicion(col, fila);
            piezaSeleccionada = nullptr;
            estadoActual = EstadoTurno::ESPERANDO_SELECCION;
        }
    }
}

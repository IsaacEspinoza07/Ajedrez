#include "Tablero.hpp"
#include "Piezas.hpp"

void Tablero::Inicializar()
{
    // Primero llenamos el tablero de NADA.
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            tablero[i][j] = nullptr;
        }
    }
    // Colocar cada pieza en su lugar
    // Lado negro (arriba)
    tablero[0][0] = new Torre(NEGRO, 0, 0);
    tablero[0][7] = new Torre(NEGRO, 0, 7);
    tablero[0][1] = new Caballo(NEGRO, 0, 1);
    tablero[0][6] = new Caballo(NEGRO, 0, 6);
    tablero[0][2] = new Alfil(NEGRO, 0, 2);
    tablero[0][5] = new Alfil(NEGRO, 0, 5);
    tablero[0][3] = new Reina(NEGRO, 0, 3);
    tablero[0][4] = new Rey(NEGRO, 0, 4);
    for (int i = 0; i < 8; ++i) {
        tablero[1][i] = new Peon(NEGRO, i, 1);
    }
    // Lado blanco (abajo)
    tablero[7][0] = new Torre(BLANCO, 7, 0);
    tablero[7][7] = new Torre(BLANCO, 7, 7);
    tablero[7][1] = new Caballo(BLANCO, 7, 1);
    tablero[7][6] = new Caballo(BLANCO, 7, 6);
    tablero[7][2] = new Alfil(BLANCO, 7, 2);
    tablero[7][5] = new Alfil(BLANCO, 7, 5);
    tablero[7][3] = new Reina(BLANCO, 7, 3);
    tablero[7][4] = new Rey(BLANCO, 7, 4);
    for (int i = 0; i < 8; ++i) {
        tablero[6][i] = new Peon(BLANCO, i, 6);
    }
}
// ****************************** //
Tablero::Tablero()
{
    Inicializar();
    Dibujar();
}
// ****************************** //
void Tablero::Dibujar() {}
// ****************************** //

Tablero::~Tablero()
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tablero[i][j] != nullptr) {
                delete tablero[i][j];
                tablero[i][j] = nullptr;
            }
        }
    }
}

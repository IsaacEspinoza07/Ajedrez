#include "Tablero.hpp"
#include "Piezas.hpp"
#include "texturas.hpp"

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
    tablero[0][7] = new Torre(NEGRO, 7, 0);
    tablero[0][1] = new Caballo(NEGRO, 1, 0);
    tablero[0][6] = new Caballo(NEGRO, 6, 0);
    tablero[0][2] = new Alfil(NEGRO, 2, 0);
    tablero[0][5] = new Alfil(NEGRO, 5, 0);
    tablero[0][3] = new Reina(NEGRO, 3, 0);
    tablero[0][4] = new Rey(NEGRO, 4, 0);
    for (int i = 0; i < 8; ++i) {
        tablero[1][i] = new Peon(NEGRO, i, 1);
    }
    // Lado blanco (abajo)
    tablero[7][0] = new Torre(BLANCO, 0, 7);
    tablero[7][7] = new Torre(BLANCO, 7, 7);
    tablero[7][1] = new Caballo(BLANCO, 1, 7);
    tablero[7][6] = new Caballo(BLANCO, 6, 7);
    tablero[7][2] = new Alfil(BLANCO, 2, 7);
    tablero[7][5] = new Alfil(BLANCO, 5, 7);
    tablero[7][3] = new Reina(BLANCO, 3, 7);
    tablero[7][4] = new Rey(BLANCO, 4, 7);
    for (int i = 0; i < 8; ++i) {
        tablero[6][i] = new Peon(BLANCO, i, 6);
    }
}
// ****************************** //

/*
bool Tablero::CaminoLibre(int x_inicial, int y_inicial, int x_final, int y_final, bool diagonal)
{
    return true;
}
*/

// ****************************** //
Tablero::Tablero()
{
    Inicializar();
}
// ****************************** //
void Tablero::Dibujar(GestionTexturas &texturas)
{
    DrawTexturePro(texturas.tablero,

                   {0.0f, 0.0f, (float)texturas.tablero.width,

                    (float)texturas.tablero.height},

                   {340.0f, 60.0f, 600, 600}, {0, 0}, 0.0f, WHITE);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tablero[i][j] != nullptr) {
                tablero[i][j]->Dibujar(texturas);
            }
        }
    }
}
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

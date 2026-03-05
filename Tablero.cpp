#include "Tablero.hpp"
#include "Piezas.hpp"
#include "texturas.hpp"
// #include <cmath>

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

bool Tablero::CaminoLibre(int x_inicial, int y_inicial, int x_final, int y_final)
{
    int diferencia_x = x_final - x_inicial;
    int diferencia_y = y_final - y_inicial;

    // Ver para donde voy a caminar( si en x, en y, o en ambos.)
    int paso_x, paso_y;
    if (diferencia_x == 0) {
        paso_x = 0;
    } else {
        if (diferencia_x > 0) {
            paso_x = 1;
        } else {
            paso_x = -1;
        }
    }
    if (diferencia_y == 0) {
        paso_y = 0;

    } else {
        if (diferencia_y > 0) {
            paso_y = 1;
        } else {
            paso_y = -1;
        }
    }

    // nos movemos al de enfrente pues no tiene caso revisar si mismo.
    int x_actual = x_inicial + paso_x;
    int y_actual = y_inicial + paso_y;

    // Ahora, recorremos!!!
    while (x_actual != x_final || y_actual != y_final) {
        if (tablero[y_actual][x_actual] != nullptr) { // Que NO estorbe nada...
            return false;
        }
        x_actual += paso_x;
        y_actual += paso_y;
    }
    return true; // Si acabamos y no estorbo nada...
}

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

// ****************************** //
Pieza *Tablero::ObtenerPieza(int renglon, int columna)
{
    return this->tablero[renglon][columna];
}

// ****************************** //
void Tablero::MoverPieza(int fila_pieza, int col_pieza, int nueva_fila, int nueva_col)
{
    // Capturar si hay pieza
    if (this->ObtenerPieza(nueva_fila, nueva_col) != nullptr) {
        CapturarPieza(nueva_fila, nueva_col);
    }
    // Cambiar el punterito
    this->tablero[nueva_fila][nueva_col] = this->tablero[fila_pieza][col_pieza];
    this->tablero[fila_pieza][col_pieza] = nullptr; // Limpiamos donde andabamos.

    this->tablero[nueva_fila][nueva_col]->CambiarPosicion(nueva_col, nueva_fila);
}

// ****************************** //
void Tablero::CapturarPieza(int nueva_fila, int nueva_col)
{
    delete this->tablero[nueva_fila][nueva_col];
    this->tablero[nueva_fila][nueva_col] = nullptr;
}

bool Tablero::EsJaque(bool color)
{
    int fila_rey, col_rey;

    // Buscamos donde esta el rey del color buscado. O(64), tonses no es pesado.
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (this->ObtenerPieza(i, j) != nullptr &&
                this->tablero[i][j]->ObtenerTipoPieza() == REY &&
                this->tablero[i][j]->ObtenerColor() == color) {

                fila_rey = i;
                col_rey = j;
                break;
            }
        }
    }
    // ====== VERIFICACION VERTICAL Y LATERAL ========
    // Primeor arriba
    for (int i = fila_rey - 1; i >= 0; --i) {
        Pieza *pAux = ObtenerPieza(i, col_rey); // Ayudara simplificando
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == TORRE)) {
                return true;
            }
            break; // No enconro nada.
        }
    }

    // Ahora abajo
    for (int i = fila_rey + 1; i <= 7; ++i) {
        Pieza *pAux = ObtenerPieza(i, col_rey);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == TORRE)) {
                return true;
            }
            break;
        }
    }

    // Checamos derecha
    for (int i = col_rey + 1; i <= 7; ++i) {
        Pieza *pAux = ObtenerPieza(fila_rey, i);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == TORRE)) {
                return true;
            }
            break;
        }
    }

    // Ahora izquierda
    for (int i = col_rey - 1; i >= 0; --i) {
        Pieza *pAux = ObtenerPieza(fila_rey, i);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == TORRE)) {
                return true;
            }
            break;
        }
    }

    //=====VERIFICACION DE DIAGONALES =======
    // Primero diagonal izq-superior
    int dx = col_rey - 1, dy = fila_rey - 1;
    while (dx >= 0 && dy >= 0) {
        Pieza *pAux = ObtenerPieza(dy, dx);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == ALFIL)) {
                return true;
            }
            break;
        }
        --dx;
        --dy;
    }

    // Diagonal izq-inferior
    dx = col_rey - 1;
    dy = fila_rey + 1;
    while (dx >= 0 && dy <= 7) {
        Pieza *pAux = ObtenerPieza(dy, dx);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == ALFIL)) {
                return true;
            }
            break;
        }
        --dx;
        ++dy;
    }

    // Diagonal der-superior
    dx = col_rey + 1;
    dy = fila_rey - 1;
    while (dx <= 7 && dy >= 0) {
        Pieza *pAux = ObtenerPieza(dy, dx);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == ALFIL)) {
                return true;
            }
            break;
        }
        ++dx;
        --dy;
    }
    // Diagonal der-inferior
    dx = col_rey + 1;
    dy = fila_rey + 1;
    while (dx <= 7 && dy <= 7) {
        Pieza *pAux = ObtenerPieza(dy, dx);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color &&
                (pAux->ObtenerTipoPieza() == REINA || pAux->ObtenerTipoPieza() == ALFIL)) {
                return true;
            }
            break;
        }
        ++dx;
        ++dy;
    }

    // Verificamos caballo
    // Primero checamos en L-arriba
    if (fila_rey - 2 >= 0 && col_rey - 1 >= 0) {
        Pieza *pAux = ObtenerPieza(fila_rey - 2, col_rey - 1);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }
    if (fila_rey - 2 >= 0 && col_rey + 1 <= 7) {
        Pieza *pAux = ObtenerPieza(fila_rey - 2, col_rey + 1);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }
    // Luego  checamos en L-abajo
    if (fila_rey + 2 <= 7 && col_rey - 1 >= 0) {
        Pieza *pAux = ObtenerPieza(fila_rey + 2, col_rey - 1);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }
    if (fila_rey + 2 <= 7 && col_rey + 1 <= 7) {
        Pieza *pAux = ObtenerPieza(fila_rey + 2, col_rey + 1);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }

    // Luego checamos L-izquierda
    if (col_rey - 2 >= 0 && fila_rey - 1 >= 0) {
        Pieza *pAux = ObtenerPieza(fila_rey - 1, col_rey - 2);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }
    if (col_rey - 2 >= 0 && fila_rey + 1 <= 7) {
        Pieza *pAux = ObtenerPieza(fila_rey + 1, col_rey - 2);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }

    // Por ultimo L-Derecha
    if (col_rey + 2 <= 7 && fila_rey - 1 >= 0) {
        Pieza *pAux = ObtenerPieza(fila_rey - 1, col_rey + 2);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }
    if (col_rey + 2 <= 7 && fila_rey + 1 <= 7) {
        Pieza *pAux = ObtenerPieza(fila_rey + 1, col_rey + 2);
        if (pAux != nullptr) {
            if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == CABALLO) {
                return true;
            }
        }
    }

    // Verificamos en su rango (peon)
    if (color == BLANCO) {
        if (fila_rey - 1 >= 0 && col_rey - 1 >= 0) { // arriba izquierda
            Pieza *pAux = ObtenerPieza(fila_rey - 1, col_rey - 1);
            if (pAux != nullptr) {
                if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == PEON) {
                    return true;
                }
            }
        }
        if (fila_rey - 1 >= 0 && col_rey + 1 <= 7) { // arriba derecha
            Pieza *pAux = ObtenerPieza(fila_rey - 1, col_rey + 1);
            if (pAux != nullptr) {
                if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == PEON) {
                    return true;
                }
            }
        }

    } else {                                         // Fue color negro...
        if (fila_rey + 1 <= 7 && col_rey - 1 >= 0) { // abajo izquierda
            Pieza *pAux = ObtenerPieza(fila_rey + 1, col_rey - 1);
            if (pAux != nullptr) {
                if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == PEON) {
                    return true;
                }
            }
        }
        if (fila_rey + 1 <= 7 && col_rey + 1 <= 7) { // abajo derecha
            Pieza *pAux = ObtenerPieza(fila_rey + 1, col_rey + 1);
            if (pAux != nullptr) {
                if (pAux->ObtenerColor() != color && pAux->ObtenerTipoPieza() == PEON) {
                    return true;
                }
            }
        }
    }

    return 0;
}

void Tablero::AlternarTurno()
{
    this->turno = (this->turno == BLANCO) ? NEGRO : BLANCO;
}

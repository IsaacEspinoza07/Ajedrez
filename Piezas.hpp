#pragma once

enum { PEON, TORRE, ALFIL, CABALLO, REINA, REY };
class Pieza
{
  public:
    virtual void dibujar();
    int Obtener_x();
    int Obtener_y();

  protected:
    bool color;        // 0: Blanco, 1: Negro
    int coor_x;        // coordenadas a lo largo.
    int coor_y;        // coordenadas a lo alto.
    bool YaMovido = 0; // 0: No se ha movido. 1: Ya fue movida.
};

// ******* PIEZAS ********* //

class Peon : public Pieza
{
  public:
  private:
};

class Torre : public Pieza
{
  public:
  private:
};

#pragma once

#include "texturas.hpp"
enum { PEON, TORRE, ALFIL, CABALLO, REINA, REY };
enum { BLANCO = 0, NEGRO };
class Pieza
{
  public:
    virtual void Dibujar(GestionTexturas &texturas) = 0;

    int Obtener_x();
    int Obtener_y();
    virtual ~Pieza();

  protected:
    bool color;        // 0: Blanco, 1: Negro
    int coor_x;        // coordenadas a lo largo.
    int coor_y;        // coordenadas a lo alto.
    bool YaMovido = 0; // 0: No se ha movido. 1: Ya fue movida.
    unsigned int tipo = 0;
};

// ******* PIEZAS ********* //
class Peon : public Pieza
{
  public:
    Peon(bool color, int x, int y);
    void Dibujar(GestionTexturas &texturas) override;

  private:
};

// ******************************* //
class Alfil : public Pieza
{
  public:
    Alfil(bool color, int x, int y);
    void Dibujar(GestionTexturas &texturas) override;

  private:
};

// ******************************* //
class Caballo : public Pieza
{
  public:
    Caballo(bool color, int x, int y);
    void Dibujar(GestionTexturas &texturas) override;

  private:
};

// ******************************* //
class Torre : public Pieza
{
  public:
    Torre(bool color, int x, int y);
    void Dibujar(GestionTexturas &texturas) override;

  private:
};

// ******************************* //
class Reina : public Pieza
{
  public:
    Reina(bool color, int x, int y);
    void Dibujar(GestionTexturas &texturas) override;

  private:
};

// ******************************* //
class Rey : public Pieza
{
  public:
    Rey(bool color, int x, int y);
    void Dibujar(GestionTexturas &texturas) override;

  private:
};

// *** FUNCION DE UTILIDAD *** //

float conversor_x(int x);
float conversor_y(int y);

//

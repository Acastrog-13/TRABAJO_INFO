#pragma once
#include "Pieza.h"
class Alfil :  public Pieza
{
public:
    Alfil(Vector2D pos, Color c = {}) : Pieza(pos, c) {}

    void dibuja();
    void mueve(Vector2D);
};

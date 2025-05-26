#pragma once
#include "Pieza.h"
class Rey :  public Pieza
{
    void dibuja();
public:
    Rey(Vector2D pos, Color c = {}) : Pieza(pos, c) {}

};

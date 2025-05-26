#pragma once
#include "Pieza.h"
class Rey :  public Pieza
{
public:
    Rey(Vector2D pos, Color c = {}) : Pieza(pos, c) {}
    
    void dibuja();
    void mueve(Vector2D);
};

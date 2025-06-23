#pragma once
#include "Pieza.h"

struct Dama : Pieza
{
    //constructor
    Dama(Posicion pos, Color  col) : Pieza("Dama", pos, col) {}

    //metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    void dibuja() override;
};

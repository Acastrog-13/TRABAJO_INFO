#pragma once
#include "Pieza.h"

struct Dama : Pieza
{
    //constructor
    Dama(Posicion pos, Color  col) : Pieza("Dama", pos, col) {}

    //metodos
    bool check(const Posicion& objetivo, const TablaInfo& info)const;
    void dibuja()const override;
};
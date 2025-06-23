#pragma once
#include "Pieza.h"

struct Rey : Pieza
{
    //Constructor
    Rey(Posicion pos, Color col) : Pieza("Rey", pos, col) {}

    //Metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    void dibuja() override;
};
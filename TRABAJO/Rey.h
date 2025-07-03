#pragma once
#include "Pieza.h"

struct Rey : Pieza
{
    bool enroque_posible=false;

    //Constructor
    Rey(Posicion pos, Color col) : Pieza("Rey", pos, col) {}

    //Metodos
    bool check(const Posicion& objetivo, const TablaInfo& info)const;
    void dibuja()const override;
};
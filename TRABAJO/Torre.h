#pragma once
#include "Pieza.h"


struct Torre : Pieza
{
    //Constructor
    Torre(Posicion pos, Color col) : Pieza("Torre", pos, col) {}

    //Metodos
    bool check(const Posicion& objetivo, const TablaInfo& info)const;
    void dibuja()const override;
};
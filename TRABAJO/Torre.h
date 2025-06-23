#pragma once
#include "Pieza.h"
#include"ETSIDI.h"
#include <iostream>


struct Torre : Pieza
{
    //Constructor
    Torre(Posicion pos, Color col) : Pieza("Torre", pos, col) {}

    //Metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    void dibuja() override;
};

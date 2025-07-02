#pragma once
#include "Pieza.h"


struct Peon : Pieza
{
    //constructor
    Peon(Posicion pos, Color col, bool mov=true) : Pieza("Peon", pos, col, mov){}

    //metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    bool check_recorrido(Posicion objetivo, const TablaInfo& info) override;
    void dibuja() override;
};
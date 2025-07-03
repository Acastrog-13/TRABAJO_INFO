#pragma once
#include "Pieza.h"


struct Peon : Pieza
{
    //constructor
    Peon(Posicion pos, Color col, bool mov=true) : Pieza("Peon", pos, col, mov){}

    //metodos
    bool check(const Posicion& objetivo, const TablaInfo& info)const;
    bool check_recorrido(const Posicion& objetivo, const TablaInfo& info)const override;
    void dibuja()const override;
};
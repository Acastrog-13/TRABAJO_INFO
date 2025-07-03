#pragma once
#include "Pieza.h"

struct Caballo : Pieza
{
    //constructor
    Caballo(Posicion pos, Color col) : Pieza("Caballo", pos, col) {}

    //metodos inline
    bool check_recorrido(const Posicion& objetivo, const TablaInfo& info)const override { return true; }

    //metodos
    bool check(const Posicion& objetivo, const TablaInfo& info)const;
    void dibuja()const override;
};
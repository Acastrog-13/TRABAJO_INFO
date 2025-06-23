#pragma once
#include "Pieza.h"

struct Caballo : Pieza
{
    //constructor
    Caballo(Posicion pos, Color col) : Pieza("Caballo", pos, col) {}

    //metodos inline
    bool check_recorrido(Posicion objetivo, const TablaInfo& info) override { return true; }

    //metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    void dibuja() override;
};



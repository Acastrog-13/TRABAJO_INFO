#pragma once
#include "Pieza.h"


struct Torre : Pieza
{
	//Constructor
    Torre(Posicion pos, Color col) : Pieza("Torre", pos, col) {}

    bool check (Posicion objetivo, const TablaInfo& info) {
        auto dif = pos - objetivo;
        if ((dif.col != 0) && (dif.fil != 0)) return false;
        return Pieza::check (objetivo, info);
    }
    //Metodos
    //void dibuja();
    //void mueve(Vector2D);
    //void set_jugadas() {}
};

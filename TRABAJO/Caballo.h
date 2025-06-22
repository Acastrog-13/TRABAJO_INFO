#pragma once
#include "Pieza.h"

struct Caballo : Pieza
{
	//Constructor
    Caballo(Posicion pos, Color col) : Pieza("Caballo", pos, col){}


    bool check(Posicion objetivo, const TablaInfo& info) {
        auto dif = objetivo - pos;
        if (((abs(dif.fil) == 2) && (abs(dif.col) == 1)) || ((abs(dif.col) == 2) && (abs(dif.fil) == 1)))
            return Pieza::check(objetivo, info);
        return false;
    }
    bool check_recorrido (Posicion objetivo, const TablaInfo& info) override { return true; }

    //Metodos
    //void dibuja();
    //void mueve(Vector2D);
};



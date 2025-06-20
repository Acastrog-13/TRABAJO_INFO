#pragma once
#include "Pieza.h"

struct Dama : Pieza
{
	//Constructor
    Dama(Posicion pos, Color  col) : Pieza("Dama", pos, col){}


    bool check(Posicion objetivo, const TablaInfo& info) {
        auto dif = pos - objetivo;
        if ((dif.col != 0) && (dif.fil != 0)&&
            (abs(pos.col-objetivo.col)!=abs(pos.fil-objetivo.fil))) return false;
        return Pieza::check (objetivo, info);
    }
    //Metodos
   // void dibuja();
    //void mueve(Vector2D);
};

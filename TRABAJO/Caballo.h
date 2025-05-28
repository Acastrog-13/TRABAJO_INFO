#pragma once
#include "Pieza.h"

struct Caballo : Pieza
{
	//Constructor
    Caballo(Colores c = {}, Vector2D pos={}) :
        Pieza(c, CABALLO, pos) {}



    //Metodos
    void dibuja();
    void mueve(Vector2D);
};



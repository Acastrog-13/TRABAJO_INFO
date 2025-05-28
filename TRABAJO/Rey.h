#pragma once
#include "Pieza.h"

struct Rey : Pieza
{
	//Constructor
    Rey(Colores c = {}, Vector2D pos={}) :
        Pieza(c, REY, pos) {}



    //Metodos
    void dibuja();
    void mueve(Vector2D);
};
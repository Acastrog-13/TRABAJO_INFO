#pragma once
#include "Pieza.h"

struct Dama : Pieza
{
	//Constructor
    Dama(Colores c = {}, Vector2D pos={}) :
        Pieza(c, DAMA, pos) {}



    //Metodos
    void dibuja();
    void mueve(Vector2D);
};

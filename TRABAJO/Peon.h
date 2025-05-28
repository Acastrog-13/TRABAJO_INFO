#pragma once
#include "Pieza.h"

struct Peon : Pieza
{
	//Constructor
    Peon(Colores c = {}, Vector2D pos={}) :
        Pieza(c, PEON, pos) {}



    //Metodos
    void dibuja();
    void mueve(Vector2D);
};
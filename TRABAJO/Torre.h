#pragma once
#include "Pieza.h"

struct Torre : Pieza
{
	//Constructor
    Torre(Colores c = {}, Vector2D pos={}) :
        Pieza(c, TORRE, pos) {}



    //Metodos
    void dibuja();
    void mueve(Vector2D);
    //std::vector<Jugadas*> calcular_jugadas(const Tablero&) const override;
};

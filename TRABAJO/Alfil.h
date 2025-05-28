#pragma once
#include "Pieza.h"

struct Alfil : Pieza{

    //Constructor
    Alfil(Colores c = {}, Vector2D pos={}) :
        Pieza(c, ALFIL, pos) {}



    //Metodos
    void dibuja();
    void mueve(Vector2D);
};

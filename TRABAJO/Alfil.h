#pragma once
#include "Pieza.h"

struct Alfil : Pieza{

    //Constructor
    Alfil(Posicion pos, Color col) : Pieza("Alfil", pos, col) {}

    bool check (Posicion objetivo, const TablaInfo& info) {
        if ((abs(pos.col - objetivo.col) != abs(pos.fil - objetivo.fil))) return false;
        return Pieza::check(objetivo, info);
    }


    //Metodos
  //  void dibuja();
    //void mueve(Vector2D);
};

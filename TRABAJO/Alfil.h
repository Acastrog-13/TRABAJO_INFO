#pragma once
#include "Pieza.h"

struct Alfil : Pieza {

    //constructor
    Alfil(Posicion pos, Color col) : Pieza("Alfil", pos, col) {}

    //metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    void dibuja() override;
};
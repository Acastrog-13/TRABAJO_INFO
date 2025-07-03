#pragma once
#include "Pieza.h"

struct Alfil : Pieza {

    //constructor
    Alfil(Posicion pos, Color col) : Pieza("Alfil", pos, col) {}

    //metodos
    bool check(const Posicion& objetivo, const TablaInfo& info)const;
    void dibuja()const override;
};
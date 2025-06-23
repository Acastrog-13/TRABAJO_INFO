#pragma once
#include "Pieza.h"

struct Peon : Pieza
{
    //atributos
    bool primer_mov = true;

    //constructor
    Peon(Posicion pos, Color col) :Pieza("Peon", pos, col) {}

    //metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    void dibuja() override;
};
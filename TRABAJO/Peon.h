#pragma once
#include "Pieza.h"


struct Peon : Pieza
{
    //atributos
    bool primer_mov;

    //constructor
    Peon(Posicion pos, Color col, bool p) : Pieza("Peon", pos, col), primer_mov(p) {}

    //metodos
    bool check(Posicion objetivo, const TablaInfo& info);
    bool check_recorrido(Posicion objetivo, const TablaInfo& info) override;
    void dibuja() override;
};
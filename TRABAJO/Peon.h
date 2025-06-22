#pragma once
#include "Pieza.h"

struct Peon : Pieza
{
    bool primer_mov = true;
    //Constructor
    Peon(Posicion pos, Color col) :Pieza ("Peon", pos, col) { }

    bool check(Posicion objetivo, const TablaInfo& info) {
        auto dif = objetivo - pos;
        if (color == BLANCAS) {
            if (primer_mov == true) if (dif.fil != 2 || dif.col != 0) return false;
            else if (primer_mov == false) if (dif.fil != 1 || dif.col != 0) return false;
            return Pieza::check (objetivo, info);
        }
        else if (color == NEGRAS) {
            if (primer_mov == true) if (dif.fil != -2 || dif.col != 0) return false;
            if (primer_mov == false) if (dif.fil != -1 || dif.col != 0) return false;
            return Pieza::check (objetivo, info);
        }
        return false;
    }

    //Metodos
    //void dibuja();
    //void mueve(Vector2D);
};
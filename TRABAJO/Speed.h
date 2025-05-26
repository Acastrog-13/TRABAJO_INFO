#pragma once
#include "Juego.h"
class Speed :   public Juego
{
public:
    Speed() : Juego(6, 5) { inicializa(); }

    void inicializa();
};


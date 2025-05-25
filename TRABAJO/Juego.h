#pragma once
#include "Tablero.h"

class Juego
{
	Tablero mitablero;

public:
	Juego() : mitablero(4,5) {}
	void dibuja();
};



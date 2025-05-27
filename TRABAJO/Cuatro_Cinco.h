#pragma once
#include "Tablero.h"

class Cuatro_Cinco final : public Tablero
{
public: 
	Cuatro_Cinco() : Tablero(5, 4) { inicializa(); }

	void inicializa();

};


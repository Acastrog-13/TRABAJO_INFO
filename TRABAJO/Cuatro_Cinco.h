#pragma once
#include "Juego.h"

class Cuatro_Cinco final : public Juego
{
public: 
	Cuatro_Cinco() : Juego(5, 4) { inicializa(); }

	void inicializa();

};


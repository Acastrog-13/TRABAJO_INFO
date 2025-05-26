#pragma once
#include "Pieza.h"
class Torre : public Pieza
{
public:
	Torre(Vector2D pos, Color c = {}) : Pieza(pos, c) {}
	
	void dibuja();
	void mueve(Vector2D);
};


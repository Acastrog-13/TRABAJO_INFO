#pragma once
#include "Pieza.h"
class Torre : public Pieza
{
	void dibuja();
public:
	Torre(Vector2D pos, Color c = {}) : Pieza(pos, c) {}

};


#pragma once
#include "Pieza.h"
class Peon : public Pieza
{
	void dibuja();
	void mueve();

public:
	Peon(Vector2D pos, Color c = {}) : Pieza(pos, c){}
};

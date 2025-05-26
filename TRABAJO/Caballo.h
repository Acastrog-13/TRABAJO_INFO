#pragma once
#include "Pieza.h"
class Caballo :  public Pieza
{
	void dibuja();
public:
	Caballo(Vector2D pos, Color c = {}) : Pieza(pos, c) {}

};



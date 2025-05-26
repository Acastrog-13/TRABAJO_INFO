#pragma once
#include "Pieza.h"
class Dama :  public Pieza
{
	void dibuja();
public:
	Dama(Vector2D pos, Color c = {}) : Pieza(pos, c) {}

};

#pragma once
#include "Pieza.h"
class Dama :  public Pieza
{
public:
	Dama(Vector2D pos, Color c = {}) : Pieza(pos, c) {}
	
	void dibuja();
	void mueve(Vector2D);
};

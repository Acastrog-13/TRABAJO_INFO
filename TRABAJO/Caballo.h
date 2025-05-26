#pragma once
#include "Pieza.h"
class Caballo :  public Pieza
{
public:
	Caballo(Vector2D pos, Color c = {}) : Pieza(pos, c) {}
	
	void dibuja();

};



#pragma once
#include "Pieza.h"
class Peon : public Pieza
{

public:
	Peon(Vector2D pos, Color c = {}) : Pieza(pos, c){}
	
	void dibuja();
	void mueve(Vector2D);

};

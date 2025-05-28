#pragma once
#include "Vector2D.h"
#include "Tablero.h"

class Coordinador
{
	enum Estado { INICIO, CUATRO_CINCO, SPEED,JAQUE_MATE, FIN } estado{};

public: 
	Tablero mitablero;

	void tecla_especial(unsigned char key);
	void tecla (unsigned char key);
	void mueve();
	void dibuja();

	void busca(Vector2D);
};


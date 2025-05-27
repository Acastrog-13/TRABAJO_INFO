#pragma once
#include "Cuatro_Cinco.h"
#include "Speed.h"
#include "Vector2D.h"

class Coordinador
{
	enum Estado { INICIO, CUATRO_CINCO, SPEED,JAQUE_MATE, FIN } estado{};
	Cuatro_Cinco juego45;
	Speed juegoS;

public: 
	void tecla_especial(unsigned char key);
	void tecla (unsigned char key);
	void mueve();
	void dibuja();

	void busca(Vector2D);
};


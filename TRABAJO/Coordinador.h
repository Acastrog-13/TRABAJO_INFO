#pragma once
#include "Juego.h"
class Coordinador
{
	enum Estado { INICIO, CUATRO_CINCO, SPEED } estado{};
	Juego juego;

public: 
	void tecla_especial(unsigned char key);
	void tecla (unsigned char key);
	void mueve();
	void dibuja();

};


#pragma once
#include <iostream>
#include "Tablero.h"
using namespace std;
extern Tablero mitablero;

class Coordinador
{
	enum Estado { INICIO, CUATRO_CINCO, SPEED, JAQUE_MATE, FIN } estado{};

	void inicializa_45();									//set de filas y columnas y piezas de 4x5
	void inicializa_S();									//set de filas y columnas y piezas de Speed

public:
	void dibuja();
	void tecla_especial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();

};
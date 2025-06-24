#pragma once
#include <iostream>

#include "Tablero.h"

using namespace std;

extern Tablero mitablero;
extern Clicks numero_click;

class Coordinador
{
	Estado estado;
	void inicializa_45();									//set de filas y columnas y piezas de 4x5
	void inicializa_S();									//set de filas y columnas y piezas de Speed

public:
	
	void OnTimer(int value);
	void dibuja();
	void tecla(unsigned char key);

};
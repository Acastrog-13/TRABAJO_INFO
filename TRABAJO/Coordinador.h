#pragma once
#include "Tablero.h"



extern Tablero mitablero;

class Coordinador
{
	Estado estado;
	void inicializa_45();									//set de filas y columnas y piezas de 4x5
	void inicializa_S();									//set de filas y columnas y piezas de Speed

public:
	
	void OnTimer(int value);
	void dibuja()const;
	void tecla(unsigned char key);

	friend class Tablero;
};
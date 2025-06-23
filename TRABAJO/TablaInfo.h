#pragma once
#include "Posicion.h"

struct TablaInfo
{
	//atributos
	const int filas = 0, columnas = 0;
	Color** data;

	//constructor
	TablaInfo(int f, int c) : filas{ f }, columnas{ c } {
		data[f][c];
	}

	//operator
	Color& operator () (int i, int j) { return data[i][j]; }
	Color operator () (const Posicion& p)const { return data[p.fil][p.col]; }
};
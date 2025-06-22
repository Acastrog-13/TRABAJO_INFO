#pragma once
#include "Posicion.h"

struct TablaInfo
{
	const int filas = 0, columnas = 0;
	Color** data;
	Color& operator () (int i, int j) { return data[i][j]; }
	Color operator () (const Posicion& p)const { return data[p.fil][p.col]; }
	TablaInfo (int f, int c) : filas{ f }, columnas{ c } {
		data[f][c];
	}
};


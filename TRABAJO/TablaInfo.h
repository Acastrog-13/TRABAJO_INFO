#pragma once
#include "Posicion.h"

struct TablaInfo
{
	//atributos
	const int filas = 0, columnas = 0;
	Color** data;

	//constructor
	TablaInfo(int c, int f) : filas{ f }, columnas{ c } {
		data = new Color * [columnas];
		for (int i = 0; i < columnas; ++i) {
			data[i] = new Color[filas];
			for (int j = 0; j < filas; ++j) {
				data[i][j] = NONE;
			}
		}
	}

	//destructor
	~TablaInfo() {
		for (int i = 0; i < columnas; ++i)
			delete[] data[i];
		delete[] data;
	}

	//operator
	Color& operator () (int i, int j) { return data[i - 1][j - 1]; }
	Color operator () (const Posicion& p)const { return data[p.col - 1][p.fil - 1]; }
};
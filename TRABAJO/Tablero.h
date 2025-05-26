#pragma once
#include "freeglut.h"
#include "Celda.h"
#include <vector>
using namespace std;

class Tablero
{
	int filas, columnas;
	vector <Celda> lista;

public:
	Tablero(int, int, double lado = { 10 });

	~Tablero() {
		lista.clear();
	}

	inline void dibuja() { for (auto p : lista) p.dibuja(); }
	Vector2D get_centro(Vector2D);
};



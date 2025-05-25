#pragma once
#include "freeglut.h"
#include "Celda.h"
#include <vector>
using namespace std;

class Tablero
{
	int filas{ 8 }, columnas{ 8 };
	vector <Celda> lista;

public:
	//Tablero() = default;
	Tablero(int, int, double lado = { 10 });
	inline void dibuja() { for (auto p : lista) p.dibuja(); }
};



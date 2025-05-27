#pragma once
#include "Vector2D.h"
#include "Color.h"

class Celda
{
	double lado;
	Color color;
	Vector2D limite1, limite2, pos_centro, nombre;

public: 
	Celda(Vector2D lim1, Vector2D lim2, Vector2D n, Color c, double l = 10) : 
		limite1{ lim1 }, limite2{ lim2 }, nombre{ n }, color{ c }, lado { l } {
		pos_centro = { (l / 2) + limite1.x, limite1.y + l / 2 };
	}

	Vector2D get_nombre() const{ return nombre; }
	Vector2D get_centro() const{ return pos_centro; }


	double get_lado() const{ return lado; }

	void dibuja();

	friend class Tablero;
};


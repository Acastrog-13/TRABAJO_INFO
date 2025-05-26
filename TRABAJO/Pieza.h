#pragma once
#include "Color.h"
#include "Vector2D.h"
class Pieza
{
protected:
	Color color{};
	Vector2D posicion{};

public:
	Pieza(Vector2D pos, Color c = {}) :posicion{ pos }, color{ c }{}
	Vector2D get_pos() { return posicion; }
	Color get_color() {	return color;}
	inline void set_posicion(Vector2D& pos) { posicion = pos; }
	inline void set_color(Color& c) { color = c; }
	
	virtual void dibuja() = 0;
	void dibuja(unsigned int glComun)const;

	virtual void mueve(Vector2D) = 0;
	
	friend class Movimientos;
};




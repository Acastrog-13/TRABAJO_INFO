#pragma once
#include"color.h"
#include"vector2d.h"

class Pieza
{
	Color color{ 255,255,255 };
	Vector2D posicion{};
public:
	void get_color();
	void get_pos();
	void set_color();
	void set_pos();
	virtual void dibuja()=0;
	virtual void mueve()=0;
};


#pragma once
#include "Vector2D.h"
#include "Color.h"
#include "freeglut.h"


class Pieza
{
protected:
	Colores color_p{}; //Colores posibles
	enum Tipo { NO_TIPO, PEON, TORRE, CABALLO, ALFIL, DAMA, REY } tipo_p{};//Tipos de pieza posibles
	Vector2D posicion{};

public:
	//Constructores
	Pieza(Colores c_p, Tipo t_p, Vector2D pos_p) :
		color_p{ c_p },
		tipo_p{ t_p },
		posicion{ pos_p }
	{}

	//Destructores


	//Metodos inline
	inline void set_posicion(Vector2D& pos) { posicion = pos; } //Asigna la posicion
	inline void set_color(Colores& c) { color_p = c; } //Asigna el color

	inline Vector2D get_pos()const { return posicion; } //Devuelve la posicion
	inline Colores get_color()const { return color_p; } //Desvuelve el color
	
	//Metodos
	virtual void dibuja() = 0;
	void dibuja(unsigned int)const;

	//virtual void mueve(Vector2D) = 0;
	
	friend class Movimientos;
};




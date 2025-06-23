#pragma once
#include <string>
#include "Posicion.h"
#include "TablaInfo.h"
#include "freeglut.h"
#include <iostream>

using namespace std;

class Pieza
{
protected:
	//atributos
	string nombre;
	Posicion pos{};
	Color color{};
	Pieza(const string& n, const Posicion& p, Color c) : nombre{ n }, pos{ p }, color{ c } {}

public:
	//movimientos
	virtual bool check(Posicion objetivo, const TablaInfo& info);
	virtual bool check_recorrido(Posicion objetivo, const TablaInfo& info);
	//comprueban si entre inicio y final no hay nadie entre medias y que la p_objetivo esta en el tablero

	//dibujo
	void dibuja(unsigned int glComun)const;						//dibuja cada pieza
	virtual void dibuja() = 0;									//png especifico de cada pieza


	//amistades
	friend class Tablero;
	friend class Coordinador;
};


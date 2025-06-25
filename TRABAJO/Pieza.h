#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "freeglut.h"
#include"ETSIDI.h"

#include "Posicion.h"
#include "TablaInfo.h"

using namespace std;

class Pieza
{
protected:
	//atributos
	string nombre;
	Posicion pos{};
	Color color{};
	vector <Posicion> jugadas_posibles, jugadas_ofensivas, jugadas_no_ofensivas;
	bool hay_seleccion = false;
	bool hay_amenaza = false;

	Pieza(const string& n, const Posicion& p, Color c) : nombre{ n }, pos{ p }, color{ c } {}

public:
	//movimientos
	virtual bool check(Posicion objetivo, const TablaInfo& info) = 0;
	virtual bool check_recorrido(Posicion objetivo, const TablaInfo& info);
	//comprueban si entre inicio y final no hay nadie entre medias y que la p_objetivo esta en el tablero

	//dibujo
	void dibuja(unsigned int glComun)const;						//dibuja cada pieza
	virtual void dibuja() = 0;									//png especifico de cada pieza
	void set_jugadas(TablaInfo);

	//amistades
	friend class Tablero;
	friend class Coordinador;
};

#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "freeglut.h"
#include"ETSIDI.h"

#include "Posicion.h"
#include "TablaInfo.h"

class Tablero; //lo pongo para evitar inclusiones cruzadas

using namespace std;

class Pieza
{
protected:
	//atributos
	string nombre;
	Posicion pos{};
	Color color{};
	bool primer_mov=true;
	vector <Posicion> jugadas_posibles{}, jugadas_ofensivas{}, jugadas_no_ofensivas{};
	bool hay_seleccion = false;
	bool hay_amenaza = false;

	Pieza(const string& n, const Posicion& p, Color c, bool p_mov = true) : 
		nombre{ n }, pos{ p }, color{ c }, primer_mov{p_mov} {}

public:
	//movimientos
	virtual bool check(Posicion objetivo, const TablaInfo& info) = 0;
	virtual bool check_recorrido(Posicion objetivo, const TablaInfo& info);
	//comprueban si entre inicio y final no hay nadie entre medias y que la p_objetivo esta en el tablero

	//dibujo
	void dibuja(unsigned int glComun)const;						//dibuja cada pieza
	virtual void dibuja() = 0;									//png especifico de cada pieza
	void set_jugadas(Tablero&);
	vector<Posicion>& set_amenazas(Tablero& tablero);
	void eliminar_jugada(Posicion);

	//amistades
	friend class Tablero;
	friend class Coordinador;
};

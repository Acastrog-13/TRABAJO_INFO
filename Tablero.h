#pragma once
#include <vector>

#include "Pieza.h"
#include "Posicion.h"
#include "TablaInfo.h"


using namespace std;

class Tablero
{
	int num = 0; //numero de piezas vivas
	const int max = 0;
	vector <Pieza*> lista;
	const int filas = 0, columnas = 0;

public:

	Tablero(int fil, int col, int max) : filas{ fil }, columnas{ col }, max{ max } {}

	Pieza* operator()(const Posicion&); //retorna una pieza o nullptr
	bool operator += (Pieza* p); //añade una pieza a la lista
	Pieza* operator () (int fil, int col) { return operator ()(Posicion(fil, col)); }

	TablaInfo get_ocupacion () {
		TablaInfo retorno(filas, columnas);
		for (int i = 0; i < num; i++) retorno ((lista[i]->pos).fil, (lista[i]->pos).col) = lista[i]->color;
		return retorno;
	}

	bool mueve (Posicion inicial, Posicion objetivo) {
		Pieza* p_in = (*this)(inicial);
		Pieza* p_fin = (*this) (objetivo);
		if (p_in == nullptr) return false;
		if (p_in->check (objetivo, get_ocupacion())) {
			if (p_fin == nullptr) {
				eliminar_pieza (p_fin);
				p_in->pos = objetivo;
			}
			else { p_in->pos = objetivo; }
			return true;
		}
		return false;
	}

	void eliminar_pieza (Pieza* p) {
		for (int i = 0; i < lista.size(); i++)
			if (lista[i] == p) {
				delete lista[i];
				lista.erase (lista.begin() + i);
				return;
			}
	}
	~Tablero() {
		for (int i = 0; i < num; i++) delete lista[i];
		lista.clear();
	}
};


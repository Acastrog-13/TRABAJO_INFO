#pragma once
#include <vector>
#include "Pieza.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Peon.h"
#include "Rey.h"
#include "Torre.h"
#include "Dama.h"
using std::vector;

class Lista_Piezas
{
	vector <Pieza*> lista;
	Color color;
public:
	Lista_Piezas(Color color) :color{ color } {}
	
	/*
	~Lista_Piezas() {
		for (auto p : lista) delete p;
		lista.clear();
	}
	*/

	Color get_color() { return color; }
	
	inline void agregar(Pieza* p) { lista.push_back(p); }

	/*void agregar_pieza(Peon* p, const Vector2D pos, const Color col);
	void agregar_pieza(Torre* p, const Vector2D pos, const Color col);
	void agregar_pieza(Alfil* p, const Vector2D pos, const Color col);
	void agregar_pieza(Caballo* p, const Vector2D pos, const Color col);
	void agregar_pieza(Dama* p, const Vector2D pos, const Color col);
	void agregar_pieza(Rey* p, const Vector2D pos, const Color col);*/

	void dibuja() { for (auto p : lista) p->dibuja(); }
	void mueve(int index, Vector2D posicion);
	
	int size() { return lista.size(); }

	void destruir_contenido();
	void eliminar(int index);
	void eliminar(Pieza* p);
};


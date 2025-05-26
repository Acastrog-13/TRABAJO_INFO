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
	
	~Lista_Piezas() {
		destruir_contenido();
	}
	

	Color get_color() { return color; }
	
	inline void agregar(Pieza* p) { lista.push_back(p); }
	inline int size() { return lista.size(); }
	
	void dibuja() { for (auto p : lista) p->dibuja(); }
	void mueve(int index, Vector2D posicion);
	

	void destruir_contenido();
	void eliminar(int index);
	void eliminar(Pieza* p);
};


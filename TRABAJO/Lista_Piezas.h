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
	//Atributos
	vector <Pieza*> lista;
	Colores color_piezas{};
public:
	//Contructores
	Lista_Piezas(Colores color) :color_piezas{ color } {}
	
	//Destructores
	~Lista_Piezas() {
		destruir_contenido();
	}
	
	//M�todos inline
	Colores get_color() const{ return color_piezas; }
	inline int size() const{ return (int)lista.size(); }
	inline void agregar(Pieza* p) { lista.push_back(p); }
	inline void dibuja() const { for (auto p : lista) p->dibuja(); }					//Dibuja todas las piezas de su lista

	//M�todos
	void mueve(int index, Vector2D posicion);
	int indice_pieza (Vector2D);                                     //Devuelve el indice de la pieza con su posicion

	//M�todos de eliminaci�n
	void destruir_contenido();										//Elimina las piezas de la lista y la limpia
	void eliminar(int index);										//Elimina la pieza de una posicion concreta
	void eliminar(Pieza* p);										//Busca una pieza y la elimina


	friend class Tablero;

};


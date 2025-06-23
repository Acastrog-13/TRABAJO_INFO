#pragma once
#include <vector>

#include "Posicion.h"
#include "TablaInfo.h"

#include "Pieza.h"
#include "Peon.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"
#include "Rey.h"


using namespace std;

class Tablero
{
	//atributos
	int num = 0; //numero de piezas vivas
	int max = 0;
	vector <Pieza*> lista;
	int filas = 0, columnas = 0;

public:
	//constructor
	Tablero(int fil = 0, int col = 0, int max = 0) : filas{ fil }, columnas{ col }, max{ max } {}

	//operator
	Pieza* operator()(const Posicion&);													//retorna una pieza o nullptr
	bool operator += (Pieza* p);														//añade una pieza a la lista
	Pieza* operator () (int fil, int col) { return operator ()(Posicion(fil, col)); }

	//metodos
	TablaInfo get_ocupacion();															//retorna una matriz FxC con NONE, BLANCAS, NEGRAS
	bool mueve(Posicion inicial, Posicion objetivo);									//retorna true si en p_inicial hay una pieza y entre p_inicial 
	//y p_objetivo no hay piezas entre medias. Si en p_objetivo hay una
	// pieza se la come y la borra de la lista y mueve la pieza deseada

	bool eliminar_pieza(Pieza* p);														//elimina una pieza de la lista y desplaza la lista
	void vaciar();																		//vacia el tablero de piezas
	void set(int f, int c, int m);

	//dibujo
	void dibuja();																		//dibuja las celdas y las piezas
	void dibuja_tablero();																//dibuja el tablero con for anidado de celdas
	void dibujarFondoCelda(const Posicion&, double, double,
		unsigned char, unsigned char, unsigned char);									//dibuja las celdas

	//destructor
	~Tablero() {
		vaciar();
	}

	//amistades
	friend class Coordinador;
};

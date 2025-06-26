#pragma once
#include <vector>

#include "Posicion.h"
#include "Tiempo.h"
#include "TablaInfo.h"

#include "Pieza.h"
#include "Peon.h"
#include "Dama.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Torre.h"
#include "Rey.h"
#include "Coordinador.h"

using namespace std;


extern Tiempo tiempo;
extern Tiempo contador_blancas;
extern Tiempo contador_negras;
extern Clicks numero_click;
extern Coordinador ajedrez;

class Tablero
{
	//atributos
	int num = 0; //numero de piezas vivas
	int max = 0;
	int filas = 0, columnas = 0;
	vector <Pieza*> lista;
	vector <Pieza*> piezas_jaque;
	vector <Posicion> brillos;
	Color turno = NONE;
	Posicion posicion_promocion;
	Color color_promocion;

public:
	//constructor
	Tablero(int col = 0, int fil = 0, int max = 0) : filas{ fil }, columnas{ col }, max{ max } {}

	Color get_turno() { return turno; }
	void set_t(Color t);																	//set turno, click y contadores

	void set(int, int, int);																//set filas, columnas y numero max de piezas
	void cambio_turno() { turno == BLANCAS ? turno = NEGRAS : turno = BLANCAS; }
	string get_modo() { return filas > 5 ? "45" : "S"; }

	//operator
	Pieza* operator()(const Posicion&);													//retorna una pieza o nullptr
	bool operator += (Pieza* p);														//añade una pieza a la lista
	Pieza* operator () (int col, int fil) { return operator ()(Posicion(col, fil)); }

	//metodos
	TablaInfo get_ocupacion();	
	bool mueve(Posicion inicial, Posicion objetivo);									//retorna true si en p_inicial hay una pieza y entre p_inicial 
	//y p_objetivo no hay piezas entre medias. Si en p_objetivo hay una
	// pieza se la come y la borra de la lista y mueve la pieza deseada


	void jaque(TablaInfo);																//actualiza el vector que se le pasa con las piezas que estan en jaque con el rey opuesto
	Posicion get_centro(double, double);
	bool eliminar_pieza(Pieza* p);														//elimina una pieza de la lista y desplaza la lista
	void vaciar();																		//vacia el tablero de piezas
	
	//dibujo
	void dibuja();																		//dibuja las celdas y las piezas

	void brillo_pieza(Posicion, bool);													//busca una pieza y la ilumina o la deja de iluminar, llama a busca_amenaza y marca_movimiento
	void brillo_amenazada(Pieza*, bool);												//ilumina las piezas amenazadas por sus movimientos
	void marca_movimiento(Pieza*);														//ilumina las celdas donde se puede mover
	void borra_brillo() { brillos.clear(); }

	//destructor
	~Tablero() {
		vaciar();
	}

	//amistades
	friend class Coordinador;
};
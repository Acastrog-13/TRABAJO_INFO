#pragma once
#include "Tiempo.h"

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

class Tablero
{
	//atributos
	int num = 0; //numero de piezas vivas
	int max = 0;
	int filas = 0, columnas = 0;
	vector <Pieza*> lista, piezas_blancas, piezas_negras;
	vector<Posicion> brillos;
	Color turno = NONE,
		color_promocion = NONE,
		ganador = NONE;
	Posicion posicion_promocion;
	Clicks numero_click = NON;
	Posicion celdaClickada1, celdaClickada2;

public:
	//constructor
	Tablero(int col = 0, int fil = 0, int max = 0) : filas{ fil }, columnas{ col }, max{ max } {}

	Color get_turno() { return turno; }
	void set_t(Color t);																	//set turno, click y contadores

	void set(int, int, int);																//set filas, columnas y numero max de piezas
	void cambio_turno();
	string get_modo() { return filas > 5 ? "45" : "S"; }
	Posicion get() { return Posicion(columnas, filas); }

	//operator
	Pieza* operator()(const Posicion&);														//retorna una pieza o nullptr
	bool operator += (Pieza* p);															//añade una pieza a la lista
	Pieza* operator () (int col, int fil) { return operator ()(Posicion(col, fil)); }

	//metodos
	TablaInfo get_ocupacion();																//crea una matriz columnasXfilas con los colores de las piezas
	Posicion get_centro(double, double);													//con el valor de un punto de una celda se busca el punto medio

	void set_jugadas();																		//crea las jugadas de todas las piezas
	void OnMouse(double, double);															//maneja los clicks del raton y mueve las piezas 
	void filtro_piezas (vector <Pieza*>& blancas, vector <Pieza*>& negras);					//Filta las piezas por colores

	bool check_mueve(Posicion inicial, Posicion objetivo);									//comprueba si la pieza se puede mover a la posicion deseada						
	bool mueve(Posicion inicial, Posicion objetivo);										//mueve la pieza si cumple los requisitos

	void promociona(Pieza*,Posicion);

	void comprobacion_jaque_mate();															//cambia el estado del coordinado a JAQUE_MATE si cumple los requisitos
	void comprobacion_tablas();																//cambia el estado del coordinado a TABLAS si cumple los requisitos

	Rey* busca_rey(const vector<Pieza*>&);													//retorna el rey de una lista de piezas
	bool jaque(Rey*, vector<Pieza*>&);														//jaque actual
	bool jaque(Rey*, vector<Pieza*>&, Posicion, Posicion);									//jaque futuro, comprueba jaque con un rey, una lista de piezas atacantes, posicion inicial y final. Si esta pieza se mueve aquí habra jaque?
	void jaque_mate(vector <Pieza*>&, vector<Pieza*>&);										

	void enroque(Rey*);
	Pieza* torre_enroque(const Rey*);
	Posicion pos_enroque(const Rey* rey);
	bool enroque_mueve(Pieza*, Posicion);

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
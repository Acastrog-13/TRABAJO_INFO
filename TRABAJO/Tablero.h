#pragma once
#include "freeglut.h"
#include "Celda.h"
#include <vector>
#include "Lista_Piezas.h"
using namespace std;

class Tablero
{
	//Atributos
	int filas{}, columnas{};
	vector <Celda> celdas;

	//Protected para que Cuatro_Cinco y Speed puedan cambiarlas
	Lista_Piezas piezas_negras{ Colores::NEGRA }, piezas_blancas{ Colores::BLANCA };

public:
	//Destructores
	~Tablero() {
		destruir_contenido();
	}

	//Métodos de inicialización
	void inicializa(int, int, double lado = { 10 });
	void inicializa45();
	void inicializaS();

	//Métodos 
	Vector2D get_centro (Vector2D) const;									//Devuelve el centro con el nombre de la celda
	Vector2D get_nombre(Vector2D) const;
	void dibuja() const;													//Dibuja las celdas y las piezas blancas y negras
	void destruir_contenido();
	int indice_pieza (Vector2D, Colores);

	//Métodos inline
	int size() const { return (int)celdas.size(); }							//Devuelve la cantidad de celdas en el tablero
	int get_columnas() const { return columnas; }
	int get_filas() const { return filas; }


	//Métodos para la agregacion de piezas
	void agregar_pieza(Peon*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Torre*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Alfil*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Caballo*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Dama*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Rey*, Lista_Piezas&, const Vector2D);

	//Amistades
	friend class Movimientos;
};


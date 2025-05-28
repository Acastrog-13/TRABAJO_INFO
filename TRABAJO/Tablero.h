#pragma once
#include "freeglut.h"
#include "Celda.h"
#include <vector>
#include "Lista_Piezas.h"
using namespace std;

class Tablero
{
	//Atributos
	int filas, columnas;
	vector <Celda> lista;

	//Protected para que Cuatro_Cinco y Speed puedan cambiarlas
protected:
	Lista_Piezas piezas_negras{ Colores::NEGRA }, piezas_blancas{ Colores::BLANCA };

public:
	//Constructores
	

	//Destructores
	~Tablero() {
		destruir_contenido();
	}



	//M�todos de inicializaci�n
	void inicializa(int, int, double lado = { 10 });
	void inicializa45();
	void inicializaS();

	//M�todos 
	Vector2D get_centro (Vector2D) const;									//Devuelve el centro con el nombre de la celda
	void dibuja() const;													//Dibuja las celdas y las piezas blancas y negras
	void destruir_contenido();

	//M�todos inline
	int size() const { return (int)lista.size(); }							//Devuelve la cantidad de celdas en el tablero
	int get_columnas() const { return columnas; }
	int get_filas() const { return filas; }


	//M�todos para la agregacion de piezas
	void agregar_pieza(Peon*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Torre*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Alfil*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Caballo*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Dama*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Rey*, Lista_Piezas&, const Vector2D);

	//Amistades
	friend class Movimientos;
};


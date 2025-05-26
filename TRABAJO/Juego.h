#pragma once
#include "Tablero.h"
#include "Lista_Piezas.h"

class Juego
{
	int filas, columnas;
protected:
	Tablero mitablero;
	Lista_Piezas piezas_negras, piezas_blancas;
public:
	Juego(int f, int c) : mitablero(f, c), filas{ f }, columnas{ c },
		piezas_negras({ 0,0,0 }), piezas_blancas({ 255,255,255 }) {
	}

	void dibuja();

	void agregar_pieza(Peon*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Torre*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Alfil*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Caballo*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Dama*, Lista_Piezas&, const Vector2D);
	void agregar_pieza(Rey*, Lista_Piezas&, const Vector2D);

	void juego_elimina();

	int get_columnas() const { return columnas; }
	int get_filas() const { return filas; }

	friend class Movimientos;
};

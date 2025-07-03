#pragma once

enum Color { NONE, BLANCAS, NEGRAS };
enum Clicks { NON, CERO, UNO };
enum Estado { INICIO, CUATRO_CINCO, SPEED, JAQUE_MATE, FIN_TIEMPO, OBSERVACION, PROMOCION, TABLAS };

struct Posicion
{
	int fil = 0, col = 0;

	//constructor
	Posicion(int col = 0, int fil = 0) : fil{ fil }, col{ col } {}

	//metodos
	bool check(const int &, const int &)const;					//verifica que la posicion esta dentro del tablero
	bool check(const Posicion &)const;

	//operadores
	bool operator ==(const Posicion&)const;					//verifica que la posicion es igual
	Posicion operator + (const Posicion&)const;				//suma posiciones
	Posicion operator - (const Posicion&)const;				//resta posiciones
};
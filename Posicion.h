#pragma once
enum Color {NONE, BLANCAS, NEGRAS};

struct Posicion
{
	char fil = 0, col = 0;
	
	//constructor
	Posicion(char fil = 0, char col = 0) : fil{fil}, col{col}{}

	//metodos
	bool check(int, int); //verifica que la posicion esta dentro del tablero

	//operadores
	bool operator==(const Posicion&)const; //verifica que la posicion es igual
	Posicion operator + (const Posicion&)const; //suma posiciones
	Posicion operator - (const Posicion&)const; //resta posiciones

};


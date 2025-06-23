#pragma once
#include <iostream>
#include "Tablero.h"
using namespace std;

class Coordinador
{
	Tablero mitablero;
	enum Estado { INICIO, CUATRO_CINCO, SPEED, JAQUE_MATE, FIN } estado{};

	void inicializa_45();									//set de filas y columnas y piezas de 4x5
	void inicializa_S();									//set de filas y columnas y piezas de Speed

public:
	void dibuja();
	void tecla_especial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();

};




inline void Coordinador::inicializa_45() {
	mitablero.set(5, 4, 10);
	mitablero += new Peon({ 2,4 }, BLANCAS);
	mitablero += new Torre({ 1,1 }, BLANCAS);
	mitablero += new Alfil({ 1,2 }, BLANCAS);
	mitablero += new Caballo({ 1,3 }, BLANCAS);
	mitablero += new Rey({ 1,4 }, BLANCAS);

	mitablero += new Peon({ 4,1 }, NEGRAS);
	mitablero += new Torre({ 5,4 }, NEGRAS);
	mitablero += new Alfil({ 5,3 }, NEGRAS);
	mitablero += new Caballo({ 5,2 }, NEGRAS);
	mitablero += new Rey({ 5,1 }, NEGRAS);
}

inline void Coordinador::inicializa_S() {
	mitablero.set(6, 5, 20);
	mitablero += new Torre({ 1,1 }, BLANCAS);
	mitablero += new Alfil({ 1,2 }, BLANCAS);
	mitablero += new Caballo({ 1,3 }, BLANCAS);
	mitablero += new Rey({ 1,4 }, BLANCAS);
	mitablero += new Dama({ 1,5 }, BLANCAS);
	for (int i = 1; i < 6; i++)
		mitablero += new Peon({ 2,i }, BLANCAS);

	mitablero += new Torre({ 6,5 }, NEGRAS);
	mitablero += new Alfil({ 6,4 }, NEGRAS);
	mitablero += new Caballo({ 6,3 }, NEGRAS);
	mitablero += new Rey({ 6,2 }, NEGRAS);
	mitablero += new Dama({ 6,1 }, NEGRAS);
	for (int i = 1; i < 6; i++)
		mitablero += new Peon({ 5,i }, NEGRAS);
}

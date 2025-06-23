#include "Coordinador.h"
#include "ETSIDI.h"

Tablero mitablero; 

void Coordinador::tecla(unsigned char key) {

	switch (estado) {
	case INICIO:
		if (key == '0') exit(0);
		if (key != '1' && key != '2') return;
		if (key == '1') {

			//se inicializa el juego 45
			inicializa_45();
			estado = CUATRO_CINCO;
			break;
		}
		if (key == '2') {
			//inicializa el juego speed
			inicializa_S();
			estado = SPEED;
			break;
		}

	case CUATRO_CINCO:
		dibuja();
		if (key == 'i' || key == 'I') {
			mitablero.vaciar();
			estado = INICIO;
			break;
		}


	case SPEED:
		dibuja();
		if (key == 'i' || key == 'I') {
			mitablero.vaciar();
			estado = INICIO;
			break;
		}
	}
}

void Coordinador::dibuja()
{
	switch (estado) {
	case INICIO:

		gluLookAt(40, 40, 130,
			40, 40, 0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 180, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("AJEDREZ", -5, 80);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSE TECLA -1- PARA JUGAR 4X5", -5, 60);
		ETSIDI::printxy("PULSE TECLA -2- PARA JUGAR SPEED", -5, 50);
		ETSIDI::printxy("PULSE TECLA -0- PARA SALIR", -5, 40);
		ETSIDI::printxy("PULSE TECLA -i- PARA VOLVER A INICIO", -5, 10);
		break;

	case CUATRO_CINCO:
		gluLookAt(2.5, 3, 8,
			2.5, 3, 0,
			0.0, 1.0, 0.0);
		mitablero.dibuja();

		break;

	case SPEED:
		gluLookAt(3, 3.5, 9,
			3, 3.5, 0,
			0.0, 1.0, 0.0);
		mitablero.dibuja();
		break;
	}
}



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

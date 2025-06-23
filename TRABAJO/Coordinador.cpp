#include "Coordinador.h"
#include "ETSIDI.h"


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


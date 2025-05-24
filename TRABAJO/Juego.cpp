#include "Juego.h"

int prueba;
void Juego::dibuja() {
	
	gluLookAt(40, 40, 130,
		40, 40, 0, 
		0.0, 1.0, 0.0); 
	
	mitablero.dibuja();
}


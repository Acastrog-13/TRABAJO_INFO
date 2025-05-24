#include "Juego.h"

void Juego::dibuja() {
	
	gluLookAt(40, 40, 130,
		40, 40, 0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA 
	
	mitablero.dibuja();

}
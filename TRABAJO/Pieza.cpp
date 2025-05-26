#include "Pieza.h"

void Pieza::dibuja() {

	glColor3ub(color.r, color.g, color.b);
	glTranslated(posicion.x, posicion.y, 0);
	glutSolidSphere(1.5, 20, 20);
	glTranslated(-posicion.x, -posicion.y, 0);

}
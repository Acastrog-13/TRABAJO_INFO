#include "Celda.h"

void Celda::dibuja() {
	glDisable(GL_LIGHTING);
	glColor3ub(color.r, color.g, color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 0);
	glVertex3d(limite2.x, limite2.y, 0);
	glVertex3d(limite2.x, limite2.y + lado, 0);
	glVertex3d(limite1.x, limite1.y + lado, 0);
	glEnd();
	glEnable(GL_LIGHTING);
}

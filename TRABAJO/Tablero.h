#pragma once
#include "freeglut.h"

class Tablero
{
	int filas{ 5 };
	int columnas{ 4 };

public:
	void dibuja() {
		unsigned char r, g, b;

		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				if (((j % 2) == 0 && (i % 2) == 0) || ((j % 2) == 1 && (i % 2) == 1)) 
					r = 0; g = 0; b = 0;

				else { r = 255; g = 255; b = 255; }
				glDisable(GL_LIGHTING);
				glBegin(GL_QUADS);
				glColor3ub(r, g, b);
				glVertex3f((j - 1) * 10, (i - 1) * 10, 0);
				glVertex3f(j * 10, (i - 1) * 10, 0.0f);
				glVertex3f(j * 10, i * 10, 0.0f);
				glVertex3f((j - 1) * 10, i * 10, 0.0f);
				glEnd();
				glEnable(GL_LIGHTING);
				
			}
	}
	

};


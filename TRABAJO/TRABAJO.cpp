#include <iostream>

#include "ETSIDI.h"
#include "freeglut.h"

#include "Tiempo.h"
#include "Coordinador.h"
#include "Tablero.h"

Coordinador ajedrez;
Tablero mitablero;

Clicks numero_click = NON;
Posicion celdaClickada1;
Posicion celdaClickada2;

Tiempo tiempo (1,15);

Tiempo contador_blancas = tiempo;
Tiempo contador_negras = tiempo;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouse(int button, int state, int x, int y);
void ScreenToWorld(int screenX, int screenY, double& worldX, double& worldY);


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Juego de Ajedrez");
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	glutDisplayFunc(OnDraw);
	glutMouseFunc(OnMouse);
	glutTimerFunc(1000, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);

	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	ajedrez.dibuja();

	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	ajedrez.tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	ajedrez.OnTimer(value);

	glutTimerFunc(1000, OnTimer, 0);
	glutPostRedisplay();
}

void OnMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		double worldX, worldY;

		ScreenToWorld(x, y, worldX, worldY);

		switch (numero_click) {
		case CERO:
			if (mitablero.get_turno() == NEGRAS) cout << "Turno de las negras" << endl;
			if (mitablero.get_turno() == BLANCAS) cout << "Turno de las blancas" << endl;

			cout << "Click uno" << endl;
			celdaClickada1 = mitablero.get_centro(worldX, worldY);

			if (mitablero.get_turno() == mitablero.get_ocupacion().operator()(celdaClickada1)) {
				cout << "Celda clickada1: " << celdaClickada1.fil << celdaClickada1.col << "\n" << endl;
				mitablero.brillo_pieza(celdaClickada1, true);
				numero_click = UNO;
			}
			else cout << "Click no permitido \n" << endl;
			break;

		case UNO:
			cout << "Click dos" << endl;
			celdaClickada2 = mitablero.get_centro((double)worldX, (double)worldY);
			cout << "Celda clickada2: " << celdaClickada2.fil << celdaClickada2.col << endl;
			cout << endl;
			if (mitablero.mueve(celdaClickada1, celdaClickada2)) {
				mitablero.cambio_turno();
				mitablero.brillo_pieza(celdaClickada2, false);
			}
			else {
				cout << "No permitido, no hay cambio de turno \n" << endl;
				mitablero.brillo_pieza(celdaClickada1, false);
			}
			numero_click = CERO;
			break;
		}

	}
}

void ScreenToWorld(int screenX, int screenY, double& worldX, double& worldY) {
	GLint viewport[4];
	GLdouble modelview[16], projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	winX = (float)screenX;
	winY = (float)(viewport[3] - screenY);
	glReadPixels(screenX, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	worldX = posX;
	worldY = posY;
}
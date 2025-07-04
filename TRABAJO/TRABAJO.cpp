#include "freeglut.h"
#include "Tablero.h"



Coordinador ajedrez;
Tablero mitablero;

Tiempo tiempo (10,30);

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

	glutMouseFunc(OnMouse);
	glutTimerFunc(1000, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutDisplayFunc(OnDraw);

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

		mitablero.OnMouse(worldX, worldY);
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
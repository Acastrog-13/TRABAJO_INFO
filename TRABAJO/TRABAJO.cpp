#include <iostream>
#include "ETSIDI.h"
#include "freeglut.h"
#include "Coordinador.h"
#include "Tablero.h"

Coordinador ajedrez; //centralizamos la información en este objeto
Tablero mitablero;

static Clicks numero_click = CERO;
static Posicion celdaClickada1;
static Posicion celdaClickada2;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnMouse(int button, int state, int x, int y);
void ScreenToWorld(int screenX, int screenY, int& worldX, int& worldY);


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Juego de Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouse);


	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	ajedrez.dibuja();




	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado

	ajedrez.tecla(key);

	//ajedrez.tecla_especial(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion


	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}


void ScreenToWorld(int screenX, int screenY, double& worldX, double& worldY) {
	GLint viewport[4];								//area de la pantalla en la que dibuja
	GLdouble modelview[16], projection[16];
	GLfloat winX, winY, winZ;						//coordenadas pantalla
	GLdouble posX, posY, posZ;						//coordenadas mundo

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);		//matriz que combina donde esta la camara y como estan los objetos
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	winX = (float)screenX;
	winY = (float)(viewport[3] - screenY);				//se "invierte" Y pq el origen en OpenGL esta abajo izq y en nuestro sistema arriba izq
	glReadPixels(screenX, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);//toma coordenadas de la pantalla y devuelve las del mundo 3D

	worldX = posX;								//copia las coord del mundo 3D en nuestros parametros de salida
	worldY = posY;
}



void OnMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		double worldX, worldY;

		ScreenToWorld(x, y, worldX, worldY);
		switch (numero_click) {
		case CERO:
			celdaClickada1 = mitablero.get_centro(worldX, worldY);
			cout << celdaClickada1.fil << celdaClickada1.col << endl;
			cout << mitablero.get_turno();
			if (mitablero.get_turno() == mitablero.get_ocupacion().operator()(celdaClickada1)) numero_click = UNO;
			break;

		case UNO:
			celdaClickada2 = mitablero.get_centro((double)worldX, (double)worldY);
			cout << mitablero.get_turno();
			if (mitablero.mueve(celdaClickada1, celdaClickada2)) mitablero.cambio_turno();
			cout << "No permitido" << endl;
			numero_click = CERO;
			break;
		}

	}

}


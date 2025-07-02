#include "Coordinador.h"
#include "ETSIDI.h"

static unsigned char rB = 255, gB = 255, bB = 255, rN = 50, gN = 50, bN = 50;
static bool primer_tick = true;

void DrawText(const char* text, float x, float y, unsigned char, unsigned char, unsigned char);
void DrawImage(const string& imagen, double x, double y, double ancho, double alto);

void Coordinador::tecla(unsigned char key) {

	switch (estado) {
	case INICIO:
		if (key == '0') exit(0);
		if (key == '1') {
			inicializa_45();								//llena el tablero de piezas 45 y lo pone 4x5
			mitablero.set_t(BLANCAS);					//pone el turno de las blancas e inicializa el contador y los clicks
			estado = CUATRO_CINCO;
		
		}
		if (key == '2') {
			inicializa_S();									//llena el tablero de piezas S y lo pone 5x6
			mitablero.set_t(BLANCAS);
			estado = SPEED;
		
		}
		break;

	case CUATRO_CINCO:
		dibuja();
		if (key == 'i' || key == 'I') {
			mitablero.vaciar();									//vacia las piezas del tablero
			mitablero.set_t(NONE);
			primer_tick = true;
			estado = INICIO;
		
		}
		if (key == '0') exit(0);
		break;

	case SPEED:
		dibuja();
		if (key == 'i' || key == 'I') {
			mitablero.vaciar();
			numero_click = NON;
			mitablero.set_t(NONE);
			primer_tick = true;
			estado = INICIO;
			
		}
		if (key == '0') exit(0);
		break;

	case FIN_TIEMPO:
		if (key == '0') exit(0);
		if (key == 'i') {
			estado = INICIO;
			mitablero.vaciar();
			
		}
		if (key == '1') {
			mitablero.set_t(NONE);  // desactiva el turno para que no se pueda jugar
			estado = OBSERVACION;
		
		}
		break;

	case OBSERVACION:
		if (key == '0') exit(0);
		if (key == 'i') {
			estado = INICIO;
			mitablero.vaciar();
		
		}
		break;

	case PROMOCION:
		if (key == 't') {
			cout << "Se promociona por una torre" << endl;
			mitablero.eliminar_pieza(mitablero(mitablero.posicion_promocion));
			mitablero += new Torre(mitablero.posicion_promocion, mitablero.color_promocion);
			estado = CUATRO_CINCO;

		}
		if (key == 'a') {
			cout << "Se promociona por un alfil" << endl;
			mitablero.eliminar_pieza(mitablero(mitablero.posicion_promocion));
			mitablero += new Alfil(mitablero.posicion_promocion, mitablero.color_promocion);
			estado = CUATRO_CINCO;
		
		}
		if (key == 'c') {
			cout << "Se promociona por un caballo" << endl;
			mitablero.eliminar_pieza(mitablero(mitablero.posicion_promocion));
			mitablero += new Caballo(mitablero.posicion_promocion, mitablero.color_promocion);
			estado = CUATRO_CINCO;
		
		}
		break;

	case JAQUE_MATE:
		if (key == 'i') estado = INICIO;
		if (key == '1') estado = OBSERVACION;
		if (key == '0') exit(0);
		
		break;
		
	}
}

void Coordinador::dibuja()
{
	char contador_b[15];
	char contador_n[15];

	sprintf_s(contador_b, sizeof(contador_b), "Blancas: %02u:%02u", contador_blancas.minutos, contador_blancas.segundos);
	sprintf_s(contador_n, sizeof(contador_n), "Negras: %02u:%02u", contador_negras.minutos, contador_negras.segundos);


	switch (estado) {
	case INICIO:

		gluLookAt(40, 40, 130,
			40, 40, 0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 180, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("AJEDREZ", -15, 80);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSE TECLA -1- PARA JUGAR 4X5", -15, 60);
		ETSIDI::printxy("PULSE TECLA -2- PARA JUGAR SPEED", -15, 50);
		ETSIDI::printxy("PULSE TECLA  0  EN CUALQUIER MOMENTO PARA SALIR", -15, 40);
		ETSIDI::printxy("PULSE TECLA  i  EN CUALQUIER MOMENTO PARA VOLVER A INICIO", -15, 10);
		break;

	case CUATRO_CINCO:
		gluLookAt(2.5, 3, 8,
			2.5, 3, 0,
			0.0, 1.0, 0.0);

		mitablero.dibuja();
		DrawText(contador_b, 10, 570, rB, gB, bB);
		DrawText(contador_n, 650, 570, rN, gN, bN);

		break;

	case SPEED:
		gluLookAt(3, 3.5, 9,
			3, 3.5, 0,
			0.0, 1.0, 0.0);

		mitablero.dibuja();
		DrawText(contador_b, 10, 570, rB, gB, bB);
		DrawText(contador_n, 650, 570, rN, gN, bN);

		break;


	case FIN_TIEMPO:
		gluLookAt(25, 25, 50,			//desde donde
			25, 25, 0,		//hacia donde
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 180, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		mitablero.ganador == NEGRAS ? ETSIDI::printxy("LAS PIEZAS BLANCAS SE HAN QUEDADO SIN TIEMPO", 4, 33) : ETSIDI::printxy("LAS PIEZAS NEGRAS SE HAN QUEDADO SIN TIEMPO", 4, 33);
		mitablero.ganador == NEGRAS ? ETSIDI::printxy("PARTIDA FINALIZADA. GANAN NEGRAS", 9, 30) : ETSIDI::printxy("PARTIDA FINALIZADA. GANAN BLANCAS", 9, 30);
		
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("PULSE  0  PARA CERRAR EL PROGRAMA.", 10, 25);
		ETSIDI::printxy("PULSE  i  PARA VOLVER A PANTALLA DE INICIO.", 10, 22);
		ETSIDI::printxy("PULSE 1 PARA OBSERVAR EL TABLERO.", 10, 19);
		break;

	case OBSERVACION:
		gluLookAt(2.5, 3.5, 10,
			2.5, 3.5, 0,
			0.0, 1.0, 0.0);

		mitablero.dibuja();

		DrawImage("imagenes/imagen_observacion.png", -1, 6, 2.0, 1);	//0.5,5.5

		break;
	case PROMOCION:
		gluLookAt(25, 25, 50,			//desde donde
			25, 25, 0,		//hacia donde
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 180, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("Hay promocion", 20, 33);
		ETSIDI::printxy("Elige pieza por la que quieres promocionar", 10, 30);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Pulse -A- para alfil", 19, 25);
		ETSIDI::printxy("Pulse -T- para torre", 19, 22);
		ETSIDI::printxy("Pulse -C- para caballo", 19, 19);

		break;
	case JAQUE_MATE:
		gluLookAt(25, 25, 50,			//desde donde
			25, 25, 0,		//hacia donde
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 180, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("JAQUE MATE", 15, 31);
		mitablero.ganador == NEGRAS ? ETSIDI::printxy("Ganan Las Negras", 13, 27) : ETSIDI::printxy("Ganan las Blancas", 13, 27);
	
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Pulse i para volver a inicio", 16, 22);
		ETSIDI::printxy("Pulse 1 para observacion", 16, 19);
		ETSIDI::printxy("Pulse 0 para salir", 16, 16);

		break;
	}

}

void Coordinador::OnTimer(int value) {		//desciende el contador y le cambia el color en cada tuno y en los ultimos segundos parpadea
	static bool parpadeo = false;

	if (primer_tick) primer_tick = false;
	else {
		if (mitablero.get_turno() == BLANCAS || mitablero.get_turno() == NEGRAS) {
			Tiempo& contador = (mitablero.get_turno() == BLANCAS) ? contador_blancas : contador_negras;
			unsigned char& r = (mitablero.get_turno() == BLANCAS) ? rB : rN;
			unsigned char& g = (mitablero.get_turno() == BLANCAS) ? gB : gN;
			unsigned char& b = (mitablero.get_turno() == BLANCAS) ? bB : bN;

			contador--;

			parpadeo = !parpadeo;

			bool parpadea = (contador <= Tiempo(0, 10));

			r = parpadea ? (parpadeo ? 255 : 255) : 255;
			g = parpadea ? (parpadeo ? 0 : 255) : 255;
			b = parpadea ? (parpadeo ? 0 : 255) : 255;

			if (mitablero.get_turno() == BLANCAS) rN = gN = bN = 50;
			else rB = gB = bB = 50;

			if (contador <= 0) {
				cout << "¡Fin del tiempo para las " << (mitablero.get_turno() == BLANCAS ? "blancas" : "negras") << "!" << endl;
				mitablero.ganador = mitablero.get_turno() == BLANCAS ? NEGRAS : BLANCAS;
				estado = FIN_TIEMPO;
			}
		}
		else {
			contador_negras = tiempo;
			contador_blancas = tiempo;
		}
	}
}

void Coordinador::inicializa_45() {
	mitablero.set(4, 5, 11);
	mitablero += new Peon({ 4, 2 }, BLANCAS);
	mitablero += new Torre({ 1,1 }, BLANCAS);
	mitablero += new Alfil({ 2,1 }, BLANCAS);
	mitablero += new Caballo({ 3,1 }, BLANCAS);
	mitablero += new Rey({ 4,1 }, BLANCAS);

	mitablero += new Peon({ 1,4 }, NEGRAS);
	mitablero += new Torre({ 4,5 }, NEGRAS);
	mitablero += new Alfil({ 3,5 }, NEGRAS);
	mitablero += new Caballo({ 2,5 }, NEGRAS);
	mitablero += new Rey({ 1,5 }, NEGRAS);

	mitablero.filtro_piezas(mitablero.piezas_blancas, mitablero.piezas_negras);
}

void Coordinador::inicializa_S() {
	mitablero.set(5, 6, 20);
	mitablero += new Torre({ 1,1 }, BLANCAS);
	mitablero += new Alfil({ 3,1 }, BLANCAS);
	mitablero += new Caballo({ 2,1 }, BLANCAS);
	mitablero += new Rey({ 4,1 }, BLANCAS);
	mitablero += new Dama({ 5,1 }, BLANCAS);
	for (int i = 1; i < 6; i++)
		mitablero += new Peon({ i,2 }, BLANCAS,false);

	mitablero += new Torre({ 5,6 }, NEGRAS);
	mitablero += new Alfil({ 3,6 }, NEGRAS);
	mitablero += new Caballo({ 4,6 }, NEGRAS);
	mitablero += new Rey({ 2,6 }, NEGRAS);
	mitablero += new Dama({ 1,6 }, NEGRAS);
	for (int i = 1; i < 6; i++)
		mitablero += new Peon({ i,5 }, NEGRAS,false);

	mitablero.filtro_piezas(mitablero.piezas_blancas, mitablero.piezas_negras);
}


void DrawText(const char* text, float x, float y, unsigned char r, unsigned char g, unsigned char b) {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	glColor3ub(r, g, b);

	glRasterPos2f(x, y);
	for (const char* c = text; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}

	glEnable(GL_LIGHTING);  // Vuelve a activar iluminación

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}


void DrawImage(const string& imagen, double x, double y, double ancho, double alto) {
	unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, glComun);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2f(1, 1); glVertex3d(x + ancho / 2, y - alto / 2, 0.1);
	glTexCoord2f(0, 1); glVertex3d(x - ancho / 2, y - alto / 2, 0.1);
	glTexCoord2f(0, 0); glVertex3d(x - ancho / 2, y + alto / 2, 0.1);
	glTexCoord2f(1, 0); glVertex3d(x + ancho / 2, y + alto / 2, 0.1);

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
#include "Pieza.h"

bool Pieza::check(Posicion objetivo, const TablaInfo& info) {
	if ((objetivo.col == pos.col) && (objetivo.fil == pos.fil)) return false;
	if (!objetivo.check(info.columnas, info.filas)) return false;
	return check_recorrido(objetivo, info);
}

bool Pieza::check_recorrido(Posicion objetivo, const TablaInfo& info) {
	Posicion dif = objetivo - pos,
		inc = Posicion((dif.col > 0 ? 1 : (dif.col < 0 ? -1 : 0)), (dif.fil > 0 ? 1 : (dif.fil < 0 ? -1 : 0))),
		npos = pos + inc;
	while (!(npos == objetivo)) {
		if (info(npos) != NONE) return false;
		npos = npos + inc;
	}
	return true;
}

void dibuja_brillo(Posicion pos) {
	int ancho = 1, alto = 1;
	unsigned char alpha, r, g, b;

	bool esOscura = ((pos.col + pos.fil) % 2 == 0);
	if (!esOscura) { r = 230; g = 230; b = 100; alpha = 153; }
	else { r = 230; g = 210; b = 140; alpha = 102; }

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glColor4ub(r, g, b, alpha);

	glBegin(GL_POLYGON);
	glVertex3d(pos.col + 0.5, pos.fil - 0.5, 0.001);
	glVertex3d(pos.col - 0.5, pos.fil - 0.5, 0.001);
	glVertex3d(pos.col - 0.5, pos.fil + 0.5, 0.001);
	glVertex3d(pos.col + 0.5, pos.fil + 0.5, 0.001);
	glEnd();

	glDisable(GL_BLEND);
}

void Pieza::dibuja(unsigned int glComun)const {
	double ancho = 1; 
	double alto = 1;
	
	if (hay_seleccion) dibuja_brillo(pos);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, glComun);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2f(1, 1); glVertex3d(pos.col + ancho / 2, pos.fil - alto / 2, 0.002);
	glTexCoord2f(0, 1); glVertex3d(pos.col - ancho / 2, pos.fil - alto / 2, 0.002);
	glTexCoord2f(0, 0); glVertex3d(pos.col - ancho / 2, pos.fil + alto / 2, 0.002);
	glTexCoord2f(1, 0); glVertex3d(pos.col + ancho / 2, pos.fil + alto / 2, 0.002);
	
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}


void Pieza::set_jugadas(TablaInfo info) {
	jugadas_ofensivas.clear();
	jugadas_posibles.clear();
	for (int c = 1; c <= info.columnas; c++)
		for (int f = 1; f <= info.filas; f++)
			if (check(Posicion(c, f), info)) {
				if (color == BLANCAS && info(Posicion(c, f)) == NEGRAS) jugadas_ofensivas.push_back(Posicion(c, f));
				if (color == NEGRAS && info(Posicion(c, f)) == BLANCAS) jugadas_ofensivas.push_back(Posicion(c, f));
				jugadas_posibles.push_back(Posicion(c, f));
			}
}
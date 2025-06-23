#include "Pieza.h"

bool Pieza::check(Posicion objetivo, const TablaInfo& info) {
	if ((objetivo.col == pos.col) && (objetivo.fil == pos.fil)) return false;
	if (!objetivo.check(info.columnas, info.filas)) return false;
	return check_recorrido(objetivo, info);
}

bool Pieza::check_recorrido(Posicion objetivo, const TablaInfo& info) {
	Posicion dif = objetivo - pos,
		inc = Posicion((dif.fil >= 0 ? 1 : (dif.fil < 0 ? -1 : 0)), (dif.col > 0 ? 1 : (dif.col < 0 ? -1 : 0))),
		npos = pos + inc;
	while (!(npos == objetivo)) {
		if (info(npos) != NONE) return false;
		npos = npos + inc;
	}
	return true;
}

void Pieza::dibuja(unsigned int glComun)const {
	double ancho = 1; //tamaño imagen
	double alto = 1;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, glComun);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2f(1, 1); glVertex3d(pos.col + ancho / 2, pos.fil - alto / 2, 0.1);
	glTexCoord2f(0, 1); glVertex3d(pos.col - ancho / 2, pos.fil - alto / 2, 0.1);
	glTexCoord2f(0, 0); glVertex3d(pos.col - ancho / 2, pos.fil + alto / 2, 0.1);
	glTexCoord2f(1, 0); glVertex3d(pos.col + ancho / 2, pos.fil + alto / 2, 0.1);

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}

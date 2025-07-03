#include "Pieza.h"
#include "Tablero.h"

void dibuja_brillo(Posicion pos, unsigned char alpha = 255, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, float lado = 1, double fondo = 0.001);

bool Pieza::check(const Posicion& objetivo, const TablaInfo& info)const {
	if (!objetivo.check(info.columnas, info.filas)) return false;
	if ((objetivo.col == pos.col) && (objetivo.fil == pos.fil)) return false;
	
	return check_recorrido(objetivo, info);
}

bool Pieza::check_recorrido(const Posicion &objetivo, const TablaInfo& info)const  {
	Posicion dif = objetivo - pos,
		inc = Posicion((dif.col > 0 ? 1 : (dif.col < 0 ? -1 : 0)), (dif.fil > 0 ? 1 : (dif.fil < 0 ? -1 : 0))),
		npos = pos + inc;
	while (!(npos == objetivo)) {
		if (!npos.check(info.columnas, info.filas))return false;
		if (info(npos) != NONE) return false;
		npos = npos + inc;
	}
	return true;
}

void Pieza::dibuja(const unsigned int &glComun)const {
	double ancho = 1; 
	double alto = 1;
	unsigned char r, g, b, alpha;
	bool esOscura = ((pos.col + pos.fil) % 2 == 0);
	
	if (hay_seleccion) {
		if (!esOscura) { r = 230; g = 230; b = 100; alpha = 153; }
		else { r = 230; g = 210; b = 140; alpha = 102; }
		dibuja_brillo(pos, alpha, r, g, b);
	}
	if (hay_amenaza) {
		alpha = 255;
		dibuja_brillo(pos, alpha, 255, 0, 0);
	}

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


void Pieza::set_jugadas(Tablero& tablero) {
	TablaInfo info = tablero.get_ocupacion();
	jugadas_ofensivas.clear();
	jugadas_posibles.clear();
	jugadas_no_ofensivas.clear();

	if (nombre == "Rey") {
		Rey* rey = dynamic_cast<Rey*>(this);
		if (rey) tablero.enroque(rey);
	}
	
	for (int c = 1; c <= info.columnas; c++)
		for (int f = 1; f <= info.filas; f++) {
			Posicion objetivo (c, f);
			if (pos.col > 0 && pos.fil > 0 && check(objetivo, info)) {
				if (color == BLANCAS && info(objetivo) == NEGRAS) { jugadas_ofensivas.push_back(objetivo); }
				else if (color == NEGRAS && info(objetivo) == BLANCAS) { jugadas_ofensivas.push_back(objetivo); }
				else { jugadas_no_ofensivas.push_back(objetivo); }
				jugadas_posibles.push_back(objetivo);
				if (tablero(objetivo) != nullptr && tablero.operator()(objetivo)->nombre == "Rey") eliminar_jugada(objetivo);
			}
		}
}

void Pieza::set_amenazas(const TablaInfo &info) {
	jugadas_ofensivas.clear();
	
	for (int c = 1; c <= info.columnas; c++)
		for (int f = 1; f <= info.filas; f++)
			if (pos.col > 0 && pos.fil > 0 && check(Posicion(c, f), info)) {
				if (color == BLANCAS && info(Posicion(c, f)) == NEGRAS) { jugadas_ofensivas.push_back(Posicion(c, f)); }
				else if (color == NEGRAS && info(Posicion(c, f)) == BLANCAS) { jugadas_ofensivas.push_back(Posicion(c, f)); }
		}
}

void Pieza::eliminar_jugada(Posicion jugada) {
	for (int i = 0; i < jugadas_posibles.size(); i++)
		if (jugadas_posibles[i] == jugada) {
			jugadas_posibles.erase(jugadas_posibles.begin() + i);
			i = (int)jugadas_posibles.size();
		}
	for (int i = 0; i < jugadas_ofensivas.size(); i++)
		if (jugadas_ofensivas[i] == jugada) {
			jugadas_ofensivas.erase(jugadas_ofensivas.begin() + i);
			i = (int)jugadas_ofensivas.size();
		}
	for (int i = 0; i < jugadas_no_ofensivas.size(); i++)
		if (jugadas_no_ofensivas[i] == jugada) {
			jugadas_no_ofensivas.erase(jugadas_no_ofensivas.begin() + i);
			i = (int)jugadas_no_ofensivas.size();
		}
	
}

void dibuja_brillo(Posicion pos, unsigned char alpha, unsigned char r, unsigned char g, unsigned char b, float lado, double fondo) {
	float ancho = lado, alto = lado;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glColor4ub(r, g, b, alpha);

	glBegin(GL_POLYGON);
	glVertex3d(pos.col + lado / 2, pos.fil - lado / 2, fondo);
	glVertex3d(pos.col - lado / 2, pos.fil - lado / 2, fondo);
	glVertex3d(pos.col - lado / 2, pos.fil + lado / 2, fondo);
	glVertex3d(pos.col + lado / 2, pos.fil + lado / 2, fondo);
	glEnd();

	glDisable(GL_BLEND);
}

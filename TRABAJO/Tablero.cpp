#include "Tablero.h"


void Tablero::set(int c, int f, int m) {
	filas = f;
	columnas = c;
	max = m;
}


Pieza* Tablero::operator()(const Posicion& pos) {
	for (int i = 0; i < num; i++)
		if (pos == (lista[i]->pos))
			return lista[i];
	return nullptr;
}

bool Tablero :: operator+= (Pieza* p) {
	if (((*this)(p->pos)) || (num == max)) {
		delete p;
		return false;
	}
	lista.push_back(p);
	num++;
	return true;
}

TablaInfo Tablero::get_ocupacion() {
	TablaInfo retorno(columnas, filas);
	for (int i = 0; i < num; i++) retorno((lista[i]->pos).col, (lista[i]->pos).fil) = lista[i]->color;
	return retorno;
}

bool Tablero::mueve(Posicion inicial, Posicion objetivo) {
	Pieza* p_in = (*this)(inicial);
	Pieza* p_fin = (*this) (objetivo);
	if (p_in == nullptr) return false;
	if (p_in->check(objetivo, get_ocupacion())) {
		if (p_fin != nullptr) {
			eliminar_pieza(p_fin);
			p_in->pos = objetivo;
		}
		else {
			p_in->pos = objetivo;
			if (p_in->nombre == "Peon") {
				Peon* p = (Peon*)p_in;
				p->primer_mov = false;
			}
		}
		return true;
	}
	return false;
}

Posicion Tablero::get_centro(double x, double y) {
	int aux1 = (int)(x + 0.5);
	int aux2 = (int)(y + 0.5);
	return Posicion(aux1, aux2);
}

bool Tablero::eliminar_pieza(Pieza* p) {
	for (int i = 0; i < lista.size(); i++)
		if (lista[i] == p) {
			delete lista[i];
			lista.erase(lista.begin() + i);
			num--;
			return true;
		}
	return false;
}

void Tablero::vaciar() {
	for (int i = 0; i < num; i++) delete lista[i];
	lista.clear();
	num = 0;
	turno = BLANCAS;
}

void Tablero::dibuja() {
	dibuja_tablero();
	for (int i = 0; i < num; i++) lista[i]->dibuja();
}

void Tablero::dibuja_tablero() {
	for (int f = 1; f <= filas; ++f) {
		for (int c = 1; c <= columnas; ++c) {
			Posicion pos;
			pos.fil = f;
			pos.col = c;
			int ancho = 1, alto = 1;
			// Alternar color tipo ajedrez
			bool esOscura = (f + c) % 2 == 0;

			if (esOscura)
				dibujarFondoCelda(pos, ancho, alto, 100, 140, 0); // gris
			else
				dibujarFondoCelda(pos, ancho, alto, 213, 186, 152); // blanco
		}
	}
}
void Tablero::dibujarFondoCelda(const Posicion& pos, double ancho, double alto, unsigned char r, unsigned char g, unsigned char b) {
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3ub(r, g, b); // color pasado como argumento

	glBegin(GL_POLYGON);
	glVertex3d(pos.col + ancho / 2, pos.fil - alto / 2, 0.09); // Z = 0.09 para que esté detrás
	glVertex3d(pos.col - ancho / 2, pos.fil - alto / 2, 0.09);
	glVertex3d(pos.col - ancho / 2, pos.fil + alto / 2, 0.09);
	glVertex3d(pos.col + ancho / 2, pos.fil + alto / 2, 0.09);
	glEnd();
}
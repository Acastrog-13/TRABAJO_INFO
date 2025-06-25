#include "Tablero.h"

void dibuja_tablero(int columnas, int filas);
void dibujarFondoCelda(const Posicion& pos, double ancho, double alto, unsigned char r, unsigned char g, unsigned char b);
extern void dibuja_brillo(Posicion pos, unsigned char alpha = 255, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, float lado = 1, double fondo = 0.001);

void Tablero::set_t(Color t) {
	for (auto p : lista) p->set_jugadas(get_ocupacion());
	turno = t;
	contador_blancas = contador_negras = tiempo;
	if (t != NONE) numero_click = CERO;
	else numero_click = NON;
}

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
	Color color = p_in->color;
	Pieza* p_fin = (*this) (objetivo);
	if (p_in == nullptr) return false;
	if (p_fin != nullptr && p_fin->nombre == "Rey") return false;
	if (p_in->check (objetivo, (get_ocupacion()))) {
		brillo_pieza(inicial, false);
		if (p_fin != nullptr) eliminar_pieza(p_fin);
		else {
			if (p_in->nombre == "Peon") {
				Peon* p = (Peon*)p_in;
				p->primer_mov = false;
			}
		}
		p_in->pos = objetivo;
		

		//¿Este for y jaque se deberian hacer despues de la promocion?
		for (int i = 0; i < num; i++) lista[i]->set_jugadas(get_ocupacion());
		jaque(get_ocupacion());

		//Evaluacion de si debe haber promocion y su ejecucion
		if (p_in->nombre == "Peon" && estado_tablero == CUATRO_CINCO)
			if ((p_in->color == NEGRAS && p_in->pos.fil == 1) || (p_in->color == BLANCAS && p_in->pos.fil == filas)) {
				cout << "Hay promocion" << endl;
				char pieza_nueva;
				bool opcion_ok = 0;
				
				do {
					cout << "Elige pieza para la promoción: (t) Torre, (a) Alfil, (c) Caballo: ";
					cin >> pieza_nueva;

					switch (pieza_nueva) {
					case 't':
						eliminar_pieza(p_in);
						cout << "Se ha pedido una torre" << endl;
						(*this) += new Torre({ objetivo.col, objetivo.fil }, color == NEGRAS ? NEGRAS : BLANCAS);
						opcion_ok = 1;
						break;
					case 'a':
						eliminar_pieza(p_in);
						cout << "Se ha pedido un alfil" << endl;
						(*this) += new Alfil({ objetivo.col, objetivo.fil }, color == NEGRAS ? NEGRAS : BLANCAS);
						opcion_ok = 1;
						break;
					case 'c':
						eliminar_pieza(p_in);
						cout << "Se ha pedido un caballo" << endl;
						(*this) += new Caballo({ objetivo.col, objetivo.fil }, color == NEGRAS ? NEGRAS : BLANCAS);
						opcion_ok = 1;
						break;
					default:
						cout << "Opción no válida. Pide de nuevo la pieza" << endl;
						opcion_ok = 0;
						break;
					}
				} while (opcion_ok == 0);
			}

		return true;
	}
	return false;
}

void Tablero::jaque(TablaInfo info) {
	piezas_jaque.clear();
	for (int i = 0; i < lista.size(); i++) 
		for (int j = 0; j < (lista[i]->jugadas_ofensivas).size(); j++) 
			if ((*this)(lista[i]->jugadas_ofensivas[j])->nombre == "Rey") {
				cout << "Hay Jaque" << endl;
				piezas_jaque.push_back(lista[i]);
			}
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
	for (auto p : lista) delete p;
	brillos.clear();
	lista.clear();
	num = 0;
	turno = BLANCAS;
}

void Tablero::dibuja() {
	dibuja_tablero(columnas, filas);
	for (auto b : brillos) dibuja_brillo(b, 255, 0, 255, 255, (float)0.1, 0.01);
	for (auto p : lista) p->dibuja();
}

void dibuja_tablero(int columnas, int filas) {
	for (int f = 1; f <= filas; ++f) {
		for (int c = 1; c <= columnas; ++c) {
			Posicion pos;
			pos.fil = f;
			pos.col = c;
			int ancho = 1, alto = 1;
			bool esOscura = (f + c) % 2 == 0;

			if (esOscura)
				dibujarFondoCelda(pos, ancho, alto, 100, 140, 0); 
			else
				dibujarFondoCelda(pos, ancho, alto, 213, 186, 152); 
		}
	}
}

void dibujarFondoCelda(const Posicion& pos, double ancho, double alto, unsigned char r, unsigned char g, unsigned char b) {
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3ub(r, g, b); 

	glBegin(GL_POLYGON);
	glVertex3d(pos.col + ancho / 2, pos.fil - alto / 2, 0); 
	glVertex3d(pos.col - ancho / 2, pos.fil - alto / 2, 0);
	glVertex3d(pos.col - ancho / 2, pos.fil + alto / 2, 0);
	glVertex3d(pos.col + ancho / 2, pos.fil + alto / 2, 0);
	glEnd();
}

void Tablero::brillo_pieza(Posicion pos, bool s) {
	Pieza* p = (*this)(pos);
	p->hay_seleccion = s;
	for (auto pieza : lista) pieza->hay_amenaza = false;
	brillo_amenazada(p, s);
	marca_movimiento(p);
}

void Tablero::brillo_amenazada(Pieza* p, bool s) {
	for (auto j : p->jugadas_ofensivas) 
		(*this)(j)->hay_amenaza = s;
}

void Tablero::marca_movimiento(Pieza* p) {
	for (auto j : p->jugadas_no_ofensivas)
		brillos.push_back(j);
}
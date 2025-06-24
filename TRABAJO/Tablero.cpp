#include "Tablero.h"

void Tablero::set_t(Color t) {
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
//Para que funcione la promocion he necesitado cambiar este operador a como se muestra debajo del comentado
/*bool Tablero :: operator+= (Pieza* p) {
	if (((*this)(p->pos)) || (num == max)) {
		delete p;
		return false;
	}
	lista.push_back(p);
	num++;
	return true;
}*/

bool Tablero :: operator+= (Pieza* p) {
	if (num == max) {
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
	if (p_fin != nullptr && p_fin->nombre == "Rey") return false;
	if (p_in->check (objetivo, (get_ocupacion()))) {
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
		if (p_in->nombre == "Peon") {
			if (p_in->color == NEGRAS && p_in->pos.fil == 1) {
				cout << "Promocion negras" << endl;
				char pieza_nueva;
				cout << "Elige pieza para la promoción: (t) Torre, (a) Alfil, (c) Caballo: ";
				cin >> pieza_nueva;

				switch (pieza_nueva) {
				case 't':
					cout << "Se ha pedido una torre" << endl;
					(*this) += new Torre({ p_in->pos.col, p_in->pos.fil }, NEGRAS);
					break;
				case 'a':
					cout << "Se ha pedido un alfil" << endl;
					(*this) += new Alfil({ p_in->pos.col, p_in->pos.fil }, NEGRAS);
					break;
				case 'c':
					cout << "Se ha pedido un caballo" << endl;
					(*this) += new Caballo({ p_in->pos.col, p_in->pos.fil }, NEGRAS);
					break;
				default:
					cout << "Opción no válida. Se promoverá a torre por defecto." << endl;
					(*this) += new Torre({ p_in->pos.col, p_in->pos.fil }, NEGRAS);
					break;
				}

				// Eliminar el peón después de añadir la nueva pieza
				eliminar_pieza(p_in);
			}
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
			bool esOscura = (f + c) % 2 == 0;

			if (esOscura)
				dibujarFondoCelda(pos, ancho, alto, 100, 140, 0); 
			else
				dibujarFondoCelda(pos, ancho, alto, 213, 186, 152); 
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


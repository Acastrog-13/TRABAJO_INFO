#include "Tablero.h"

void dibuja_tablero(int columnas, int filas);
void dibujarFondoCelda(const Posicion& pos, double ancho, double alto, unsigned char r, unsigned char g, unsigned char b);
extern void dibuja_brillo(Posicion pos, unsigned char alpha = 255, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, float lado = 1, double fondo = 0.001);

void Tablero::set_t(Color t) {
	for (auto p : lista) p->set_jugadas(*this);
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

Posicion Tablero::get_centro(double x, double y) {
	int aux1 = (int)(x + 0.5);
	int aux2 = (int)(y + 0.5);
	return Posicion(aux1, aux2);
}

bool Tablero::mueve(Posicion inicial, Posicion objetivo) {
	Pieza* p_in = (*this)(inicial);
	if (p_in == nullptr) return false;

	Pieza* p_fin = (*this) (objetivo);
	if (p_fin != nullptr && p_fin->nombre == "Rey") return false;

	brillo_pieza(inicial, false);

	//Movimiento normal
	if (p_in->check (objetivo, get_ocupacion())) {
		enroque_mueve(p_in, objetivo);

		if (p_fin != nullptr) eliminar_pieza(p_fin);

		//Cambio estado pieza
		p_in->pos = objetivo;
		p_in->primer_mov = false;

		//Evaluacion de si debe haber promocion y su ejecucion
		promociona(p_in, objetivo);

		//Actualiza las jugadas
		for (int i = 0; i < num; i++) lista[i]->set_jugadas(*this);
		jaque(get_ocupacion());

		return true;
	}
	return false;
}

void Tablero::promociona(Pieza* p_in, Posicion objetivo) {
	if (!(p_in->nombre == "Peon")) return;
	if (ajedrez.estado != CUATRO_CINCO) return;
	if ((p_in->color == NEGRAS && p_in->pos.fil == 1) || (p_in->color == BLANCAS && p_in->pos.fil == filas)) {
		ajedrez.estado = PROMOCION;
		color_promocion = p_in->color;
		posicion_promocion = objetivo;
		cout << "Hay promocion del peon " << (p_in->color == BLANCAS ? "blanco" : "negro") << endl;
	}
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

void Tablero::enroque(Rey* rey) {
	if (!rey) return;

    if (!rey->primer_mov) {
        rey->enroque_posible = false;
        return;
    }
	    
    if (!rey->check_recorrido(pos_enroque(rey), get_ocupacion())) {
        rey->enroque_posible = false;
        return;
    }

	if (torre_enroque(rey)) {
        cout << "Enroque posible" << endl;
        rey->jugadas_posibles.push_back(pos_enroque(rey));
        rey->jugadas_no_ofensivas.push_back(pos_enroque(rey));
        rey->enroque_posible = true;
    } 
	else rey->enroque_posible = false;
}

Posicion Tablero::pos_enroque(const Rey*rey) {
	return (rey->color == BLANCAS) ?
		Posicion(rey->pos.col - 2, rey->pos.fil) : Posicion(rey->pos.col + 2, rey->pos.fil);
}

Pieza* Tablero::torre_enroque(const Rey* rey) {    
    if (!rey) return nullptr;

    Posicion pos_torre = (rey->color == BLANCAS) ?
        Posicion(1, rey->pos.fil) : Posicion(columnas, rey->pos.fil);

    Pieza* p_torre = (*this)(pos_torre);
    if (!p_torre) return nullptr;

    if (p_torre->nombre != "Torre" || p_torre->color != rey->color) return nullptr;

    Torre* torre = dynamic_cast<Torre*>(p_torre);
    if (!torre) return nullptr;

    if (!torre->primer_mov) return nullptr;

    return torre;
}

bool Tablero::enroque_mueve(Pieza* p_in, Posicion objetivo) {
	if (!(p_in->nombre == "Rey")) return false;
	Rey* rey = dynamic_cast <Rey*>(p_in);
	Posicion pos_torre;
	if (rey->enroque_posible && objetivo == pos_enroque(rey)) {

		pos_torre = (rey->color == BLANCAS) ?
			Posicion(rey->pos.col - 1, rey->pos.fil) : Posicion(rey->pos.col + 1, rey->pos.fil);
				
		auto torre = torre_enroque(rey);
		if (torre == nullptr) return false;

		p_in->pos = pos_enroque(rey);
		torre->pos = pos_torre;
		p_in->primer_mov = false;
		torre->primer_mov = false;
		return true;
	}
	return false;
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
	if (p) p->hay_seleccion = s;
	for (auto pieza : lista) pieza->hay_amenaza = false;
	if (p) brillo_amenazada(p, s);
	if (p) marca_movimiento(p);
}

void Tablero::brillo_amenazada(Pieza* p, bool s) {
	if (!p) return;
	for (auto j : p->jugadas_ofensivas) {
		Pieza* objetivo = (*this) (j);
		if (objetivo) objetivo->hay_amenaza = s;
	}
}

void Tablero::marca_movimiento(Pieza* p) {
	if (!p) return;
	for (auto j : p->jugadas_no_ofensivas)
		brillos.push_back(j);
}
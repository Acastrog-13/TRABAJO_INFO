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
	for (int i = 0; i < num; i++) {
		if (lista[i]->pos.col == 0) continue;
		retorno((lista[i]->pos).col, (lista[i]->pos).fil) = lista[i]->color;
	}
	return retorno;
}

Posicion Tablero::get_centro(double x, double y) {
	int aux1 = (int)(x + 0.5);
	int aux2 = (int)(y + 0.5);
	return Posicion(aux1, aux2);
}

void Tablero::filtro_piezas (vector <Pieza*>& blancas, vector <Pieza*>& negras) {

	blancas.clear();
	negras.clear();

	for (auto pieza : lista) {
		if (pieza == nullptr) continue;
		if (pieza->color == BLANCAS) blancas.push_back(pieza);
		else if (pieza->color == NEGRAS) negras.push_back(pieza);
	}
}

bool Tablero::check_mueve(Posicion inicial, Posicion objetivo) {
	Pieza* p_in = (*this)(inicial);
	if (!p_in) return false;

	Pieza* p_fin = (*this)(objetivo);
	if (p_fin && p_fin->nombre == "Rey") return false;

	return p_in->check(objetivo, get_ocupacion());
}

bool Tablero::mueve(Posicion inicial, Posicion objetivo) {

	if (!check_mueve(inicial, objetivo)) return false;

	Pieza* p_in = (*this)(inicial);
	Pieza* p_fin = (*this)(objetivo);

	brillo_pieza(inicial, false);

	//Enroque
	enroque_mueve(p_in, objetivo);

	

	//Cambio estado pieza
	p_in->pos = objetivo;

	if (p_fin != nullptr) {
		p_fin->pos = Posicion(0, 0);
	}

	if ((turno == BLANCAS) && jaque(busca_rey(piezas_blancas), piezas_negras) ||
		(turno == NEGRAS) && jaque(busca_rey(piezas_negras), piezas_blancas)) {
		p_in->pos = inicial;
		if (p_fin != nullptr)p_fin->pos = objetivo;
		return false;
	}
	
	p_in->primer_mov = false;
	if (p_fin != nullptr) eliminar_pieza(p_fin);
	//Promocion
	promociona(p_in, objetivo);

	//Actualiza las jugadas
	filtro_piezas(piezas_blancas, piezas_negras);
	for (int i = 0; i < num; i++) lista[i]->set_jugadas(*this);

	//Comprueba el jaque ofensivo
	if ((turno == BLANCAS) && jaque(busca_rey(piezas_negras), piezas_blancas))
		cout << "Rey negro en jaque" << endl;
	else if ((turno == NEGRAS) && jaque(busca_rey(piezas_blancas), piezas_negras))
		cout << "Rey blanco en jaque" << endl;
		
		return true;
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

Rey* Tablero::busca_rey(const vector<Pieza*>& piezas) {
	
	for (auto p : piezas)
		if (p && p->nombre == "Rey") return (dynamic_cast<Rey*>(p));
	
	return nullptr;
}

bool Tablero::jaque(Rey*rey, vector<Pieza*>piezas) {
	for(auto pieza:piezas){	
		if (!pieza) continue;
		pieza->set_jugadas(*this);
		for (auto jugada : pieza->jugadas_ofensivas)
			if ((*this)(jugada)->nombre == "Rey") return true;
	}

	return false;
}

/*void Tablero::set_piezas_jaque(const Color color_rey, vector<Pieza*>& piezas_jaque) {
	for (auto pieza : lista){
		if (pieza == nullptr) continue;
		if (pieza->color == color_rey || pieza->color==NONE) continue;
		for (auto jugada : pieza->jugadas_ofensivas) {
			Pieza* p_ataca = (*this)(jugada);
			if (p_ataca==nullptr) continue;
			if (p_ataca->nombre == "Rey" && p_ataca->color != color_rey) {
				piezas_jaque.push_back(pieza);
				break;
			}
		}
	}
}*/

/*void Tablero::evitar_jaque(Rey*rey, const vector<Pieza*>& piezas_contrarias) {
	if (rey == nullptr) return;

	for (auto p : piezas_contrarias)
		if (p) p->set_jugadas(*this);

	auto i = rey->jugadas_posibles.begin();
	while (i != rey->jugadas_posibles.end()) {
		bool posible_jaque = false;

		for (auto p : piezas_contrarias){
			if (!p) continue;
			for (auto jugada : p->jugadas_posibles)
				if (*i == jugada) {
					posible_jaque = true;
					break;
				}
			if (posible_jaque) break;
		}

		if (posible_jaque)
			i = rey->jugadas_posibles.erase(i);

		else ++i;
	}
}*/

void Tablero::enroque(Rey* rey) {

	trayectoria_enroque.clear();

	if (!rey) return;

	if (!rey->primer_mov) {
		rey->enroque_posible = false;
		return;
	}

	Pieza* pieza_obstaculo = (*this)(pos_enroque(rey));
	if ((pieza_obstaculo != nullptr && pieza_obstaculo->color != NONE) || 
		!(rey->check_recorrido(pos_enroque(rey), get_ocupacion()))) {
		rey->enroque_posible = false;
		return;
	}

	int direccion = (rey->color == BLANCAS) ? -1 : 1;
	int col_rey = rey->pos.col;
	int col_enroque = pos_enroque(rey).col;

	for (int i = col_rey + direccion; i != col_enroque + direccion; i += direccion)
		trayectoria_enroque.push_back(Posicion(i, rey->pos.fil));

	vector<Pieza*> piezas_contrarias;
	piezas_contrarias = rey->color == BLANCAS ? piezas_negras : piezas_blancas;

	if (torre_enroque(rey)) {        
		rey->jugadas_posibles.push_back(pos_enroque(rey));
		rey->jugadas_no_ofensivas.push_back(pos_enroque(rey));
        rey->enroque_posible = true;
	}
	
	else rey->enroque_posible = false;

	if (rey->enroque_posible) cout << "Enroque posible" << endl;	
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
	if (rey == nullptr) return false;
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
			lista[i] = nullptr;
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
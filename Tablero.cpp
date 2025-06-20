#include "Tablero.h"

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
	lista[num++] = p;
}
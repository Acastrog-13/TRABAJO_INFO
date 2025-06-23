#include "Posicion.h"

bool Posicion::check(int f, int c) {
	if ((col < 1) || (col > c) || (fil < 1) || (fil > f)) return false;
}


Posicion Posicion::operator + (const Posicion& pos)const {
	return Posicion(fil + pos.fil, col + pos.col);
}

Posicion Posicion::operator - (const Posicion& pos)const {
	return Posicion(fil - pos.fil, col - pos.col);
}

bool Posicion :: operator == (const Posicion& pos)const {
	return ((pos.col == col) && (pos.fil == fil));

}
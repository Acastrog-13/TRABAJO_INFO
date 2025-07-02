#include "Posicion.h"

bool Posicion::check(int c, int f) {
	if ((col < 1) || (col > c) || (fil < 1) || (fil > f)) return false;
	return true;
}

bool Posicion::check(Posicion i) {
	return check(i.col, i.fil);
}

Posicion Posicion::operator + (const Posicion& pos)const {
	return Posicion(col + pos.col, fil + pos.fil);
}

Posicion Posicion::operator - (const Posicion& pos)const {
	return Posicion(col - pos.col, fil - pos.fil);
}

bool Posicion :: operator == (const Posicion& pos)const {
	return ((pos.col == col) && (pos.fil == fil));
}
#include "Posicion.h"

bool Posicion::check(const int& c, const int& f) const{
	if ((col < 1) || (col > c) || (fil < 1) || (fil > f)) return false;
	return true;
}

bool Posicion::check(const Posicion &i)const {
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
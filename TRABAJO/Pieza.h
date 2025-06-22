#pragma once
#include <string>
#include "Posicion.h"
#include "TablaInfo.h"

using namespace std;

class Pieza
{
protected:
	string nombre;
	Posicion pos{};
	Color color{};
	Pieza (const string& n, const Posicion& p, Color c) : nombre{ n }, pos{ p }, color{ c } {}

public:
	virtual bool check(Posicion objetivo, const TablaInfo& info) {
		if ((objetivo.col == pos.col) && (objetivo.fil == pos.fil)) return false;
		if (!objetivo.check(info.filas,info.columnas)) return false;
		return check_recorrido (objetivo, info);
	}
	virtual bool check_recorrido(Posicion objetivo, const TablaInfo& info) {
		Posicion dif = objetivo - pos,
			inc = Posicion ((dif.fil >= 0 ? 1 : (dif.fil < 0 ? -1 : 0)), (dif.col > 0 ? 1 : (dif.col < 0 ? -1 : 0))),
			npos = pos + inc;
		while (!(npos == objetivo)) {
			if (info(npos) != NONE) return false; 
			npos = npos + inc;
		}
		return true;
	}
	friend class Tablero;
};




#include "Tablero.h"

Tablero::Tablero(int f, int c, double lado) : filas{ f }, columnas{ c }{
	Color color{};
	int co, fi;
	for (double fila = 1.0; fila <= f; fila++)
		for (double colum = 1.0; colum <= c; colum++) {
			co = colum;
			fi = fila;
			if (((co % 2) == 0 && (fi % 2) == 0) || ((co % 2) == 1 && (fi % 2) == 1)) color = { 100,140, 0}; //celdas oscuras
			else color = { 213, 186, 152 }; //celdas claras
			lista.push_back(Celda({ (colum - 1) * lado, (fila - 1) * lado }, { (colum)*lado, (fila - 1) * lado }, { fila,colum }, color, lado));
		}

}

//retorna el centro del nombre de la celda que le pasas
Vector2D Tablero::get_centro(Vector2D n) {
	for (int i = 0; i < lista.size(); i++)
		if (lista[i].get_nombre() == n)
			return lista[i].get_centro();
	return{ -1,-1 };
}

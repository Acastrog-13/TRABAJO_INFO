#include "Tablero.h"

Tablero::Tablero(int f, int c, double lado) : filas{ f }, columnas{ c }, 
piezas_negras(Colores::NEGRA), piezas_blancas(Colores::BLANCA) {
	Color color{};
	int co, fi;
	for (double fila = 1.0; fila <= f; fila++)
		for (double colum = 1.0; colum <= c; colum++) {
			co = (int)colum;
			fi = (int)fila;
			if (((co % 2) == 0 && (fi % 2) == 0) || ((co % 2) == 1 && (fi % 2) == 1)) color = { 100,140, 0}; //celdas oscuras
			else color = { 213, 186, 152 }; //celdas claras
			lista.push_back(Celda({ (colum - 1) * lado, (fila - 1) * lado }, { (colum)*lado, (fila - 1) * lado }, { fila,colum }, color, lado));
		}

}

//retorna el centro del nombre de la celda que le pasas
Vector2D Tablero::get_centro(Vector2D n) const {
	for (int i = 0; i < lista.size(); i++)
		if (lista[i].get_nombre() == n)
			return lista[i].get_centro();
	return{ -1,-1 };
}

void Tablero::dibuja() const{
	gluLookAt(columnas * 5, filas * 5, 100,
		columnas * 5, filas * 5, 0,
		0.0, 1.0, 0.0);

	for (auto p : lista) p.dibuja(); 


	piezas_blancas.dibuja();
	piezas_negras.dibuja();
}

void Tablero::agregar_pieza(Peon* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Peon(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Torre* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Torre(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Alfil* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Alfil(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Caballo* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Caballo(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Dama* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Dama(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Rey* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Rey(l.get_color(),get_centro(celda)));
}


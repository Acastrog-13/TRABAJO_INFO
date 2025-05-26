#include "Juego.h"

void Juego::dibuja() {
	gluLookAt(columnas * 5, filas * 5, 100,
		columnas * 5, filas * 5, 0, 
		0.0, 1.0, 0.0);

	mitablero.dibuja();
	piezas_blancas.dibuja();
	piezas_negras.dibuja();
}

void Juego::agregar_pieza(Peon* p,Lista_Piezas &l, const Vector2D celda) {
	l.agregar(new Peon(mitablero.get_centro(celda),l.get_color()));
}
void Juego::agregar_pieza(Torre* p,Lista_Piezas &l, const Vector2D celda) {
	l.agregar(new Torre(mitablero.get_centro(celda),l.get_color()));
}
void Juego::agregar_pieza(Alfil* p,Lista_Piezas &l, const Vector2D celda) {
	l.agregar(new Alfil(mitablero.get_centro(celda),l.get_color()));
}
void Juego::agregar_pieza(Caballo* p,Lista_Piezas &l, const Vector2D celda) {
	l.agregar(new Caballo(mitablero.get_centro(celda),l.get_color()));
}
void Juego::agregar_pieza(Dama* p,Lista_Piezas &l, const Vector2D celda) {
	l.agregar(new Dama(mitablero.get_centro(celda),l.get_color()));
}
void Juego::agregar_pieza(Rey* p,Lista_Piezas &l, const Vector2D celda) {
	l.agregar(new Rey(mitablero.get_centro(celda),l.get_color()));
}


void Juego::juego_elimina() {
	piezas_blancas.destruir_contenido();
	piezas_negras.destruir_contenido();
	//falta lablero elimina
}
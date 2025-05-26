#include "Movimientos.h"
#include "tablero.h"

bool Movimientos::limite_tablero(int x, int y, const Juego& juego) {
    int col = juego.get_columnas();
    int fil = juego.get_filas();
    return x >= 0 && x < juego.get_columnas() * 10 && y >= 0 && y < juego.get_filas() * 10;
}

//bool Movimientos::limite_pieza(const Pieza& pieza, const Vector2D& destino, const Tablero& tablero){}
//hace falta declarar el movimiento de cada pieza para configurar que no salte sobre ninguna otra. 
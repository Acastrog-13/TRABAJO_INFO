#include "Movimientos.h"
#include "tablero.h"

bool Movimientos::limite_tablero(int x, int y, const Tablero& Tablero) {
    int col = Tablero.get_columnas();
    int fil = Tablero.get_filas();
    return x >= 0 && x < Tablero.get_columnas() * 10 && y >= 0 && y < Tablero.get_filas() * 10;
}

//hace falta declarar el movimiento de cada pieza para configurar que no salte sobre ninguna otra. 


//Mueve verticalmente hacia alante, no hacia atras
bool Movimientos::delante(Pieza& p, Vector2D nombre, Tablero& Tablero) {
    if (p.color == Color{255, 255, 255}) {
        if (p.posicion == Tablero.get_centro({nombre.x - 1, nombre.y })) {
            p.posicion = Tablero.get_centro(nombre);
            return true;
        }
    }
    else if (p.color == Color{ 0, 0, 0 }) {
        if (p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y })) {
            p.posicion = Tablero.get_centro(nombre);
            return true;
        }
    }
    return false;
}

//Mueve verticalmente hacia atras, no hacia alante
bool Movimientos::atras(Pieza& p, Vector2D nombre, Tablero& Tablero)
{
    if (p.color == Color{ 255, 255, 255 }) {
        if (p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y })) {
            p.posicion = Tablero.get_centro(nombre);
            return true;
        }
    }
    else if (p.color == Color{ 0,0,0 }) {
        if (p.posicion == Tablero.get_centro({ nombre.x - 1, nombre.y })) {
            p.posicion = Tablero.get_centro(nombre);
            return true;
        }
    }
    return false;
}

//Mueve horizontalmente a izq y dcha
bool Movimientos::horizontal(Pieza& p, Vector2D nombre, Tablero& Tablero)
{
    if ((p.posicion == Tablero.get_centro({ nombre.x, nombre.y - 1 })) || (p.posicion == Tablero.get_centro({ nombre.x, nombre.y + 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    return false;
}

//Mueve diagonalmente hacia alante izq y dcha
bool Movimientos::diag_alante(Pieza& p, Vector2D nombre, Tablero& Tablero)
{
    if (p.color == Color{ 255, 255, 255 } && 
        (p.posicion == Tablero.get_centro({nombre.x - 1, nombre.y - 1}) || 
            p.posicion == Tablero.get_centro({ nombre.x - 1, nombre.y + 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    if (p.color == Color{ 0, 0, 0 } && (p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y - 1 }) 
        || p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y + 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    return false;
}
//Mueve diagonalmente hacia atras izq y dcha
bool Movimientos::diag_atras(Pieza& p, Vector2D nombre, Tablero& Tablero)
{
    if (p.color == Color{ 255, 255, 255 } && (p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y - 1 })
        || p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y + 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    if (p.color == Color{ 0, 0, 0 } &&
        (p.posicion == Tablero.get_centro({ nombre.x - 1, nombre.y - 1 }) ||
            p.posicion == Tablero.get_centro({ nombre.x - 1, nombre.y + 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    return false;
}
//Mueve diagonalmente en L para el caballo
bool Movimientos::ele(Pieza& p, Vector2D nombre, Tablero& Tablero)
{
    if ((p.posicion == Tablero.get_centro({ nombre.x - 2, nombre.y + 1 }) ||
            p.posicion == Tablero.get_centro({ nombre.x - 2, nombre.y - 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    if ((p.posicion == Tablero.get_centro({ nombre.x - 1, nombre.y + 2 })
        || p.posicion == Tablero.get_centro({ nombre.x - 1, nombre.y - 2 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    if ((p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y + 2 })
        || p.posicion == Tablero.get_centro({ nombre.x + 1, nombre.y - 2 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    if ((p.posicion == Tablero.get_centro({ nombre.x + 2, nombre.y + 1 })
        || p.posicion == Tablero.get_centro({ nombre.x + 2, nombre.y - 1 }))) {
        p.posicion = Tablero.get_centro(nombre);
        return true;
    }
    return false;
}


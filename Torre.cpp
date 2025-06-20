#include "Torre.h"
#include"ETSIDI.h"
#include <iostream>

using namespace std;

/*
void Torre::dibuja() {
    string imagen = (color_p == Colores::NEGRA) ? "imagenes/torre_negra.png" : "imagenes/torre_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
*/
/*void Torre::mueve(Vector2D nombre_casilla_final) {

}*/


/*void Torre::set_jugadas() {
    vector <Vector2D> direcciones = { {0,1}, {1,0}, {0,-1},{-1,0} };
    for (auto dir : direcciones) {
        Vector2D pos_actual = posicion + dir;
        while (Movimientos::limite_tablero(pos_actual.x, pos_actual.y))
            do {
                jugadas_posibles.push_back(Vector2D(pos_actual));
                pos_actual = pos_actual + dir;
            } while (Movimientos::limite_pieza(*this, pos_actual - dir) && Movimientos::limite_tablero(pos_actual.x, pos_actual.y));
    }
}*/


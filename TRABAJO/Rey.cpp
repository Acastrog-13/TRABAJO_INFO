#include "Rey.h"
#include "Tablero.h"

using namespace std;

bool Rey::check(const Posicion& objetivo, const TablaInfo& info)const {
    auto dif = pos - objetivo;
    auto pos_enroque = (color == BLANCAS) ?
		Posicion(pos.col - 2, pos.fil) : Posicion(pos.col + 2, pos.fil);
    if (enroque_posible && objetivo == pos_enroque) return true;
    
    if ((abs(dif.col) == 1) && (dif.fil == 0) ||
        (abs(dif.fil) == 1) && (dif.col == 0) ||
        (abs(dif.fil) == 1) && (abs(dif.col) == 1))
        return Pieza::check(objetivo, info);
    

    return false;
}

void Rey::dibuja()const {
    string imagen = (color == NEGRAS) ? "imagenes/rey_negro.png" : "imagenes/rey_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
#include "Torre.h"

using namespace std;


bool Torre::check(const Posicion& objetivo, const TablaInfo& info)const {
    auto dif = pos - objetivo;
    if ((dif.col != 0) && (dif.fil != 0)) return false;
    return Pieza::check(objetivo, info);
}


void Torre::dibuja()const {
    string imagen = (color == NEGRAS) ? "imagenes/torre_negra.png" : "imagenes/torre_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
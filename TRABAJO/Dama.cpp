#include "Dama.h"

using namespace std;

bool Dama::check(const Posicion &objetivo, const TablaInfo& info)const {
    auto dif = pos - objetivo;
    if ((dif.col != 0) && (dif.fil != 0) &&
        (abs(pos.col - objetivo.col) != abs(pos.fil - objetivo.fil))) return false;
    return Pieza::check(objetivo, info);
}

void Dama::dibuja()const {
    string imagen = (color == NEGRAS) ? "imagenes/dama_negra.png" : "imagenes/dama_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
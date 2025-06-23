#include "Caballo.h"
#include"ETSIDI.h"

using namespace std;

bool Caballo::check(Posicion objetivo, const TablaInfo& info) {
    auto dif = objetivo - pos;
    if (((abs(dif.fil) == 2) && (abs(dif.col) == 1)) || ((abs(dif.col) == 2) && (abs(dif.fil) == 1)))
        return Pieza::check(objetivo, info);
    return false;
}

void Caballo::dibuja() {
    string imagen = (color == NEGRAS) ? "imagenes/caballo_negro.png" : "imagenes/caballo_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}

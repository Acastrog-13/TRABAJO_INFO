#include "Rey.h"

using namespace std;

bool Rey::check(Posicion objetivo, const TablaInfo& info) {
    auto dif = pos - objetivo;
    if ((abs(dif.col) == 1) && (dif.fil == 0) ||
        (abs(dif.fil) == 1) && (dif.col == 0) ||
        (abs(dif.fil) == 1) && (abs(dif.col) == 1))
        return Pieza::check(objetivo, info);
    return false;
}

void Rey::dibuja() {
    string imagen = (color == NEGRAS) ? "imagenes/rey_negro.png" : "imagenes/rey_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
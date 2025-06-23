#include "Dama.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;

bool Dama::check(Posicion objetivo, const TablaInfo& info) {
    auto dif = pos - objetivo;
    if ((dif.col != 0) && (dif.fil != 0) &&
        (abs(pos.col - objetivo.col) != abs(pos.fil - objetivo.fil))) return false;
    return Pieza::check(objetivo, info);
}

void Dama::dibuja() {
    string imagen = (color == NEGRAS) ? "imagenes/dama_negra.png" : "imagenes/dama_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
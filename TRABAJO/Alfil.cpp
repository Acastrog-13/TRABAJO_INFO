#include "Alfil.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;

bool Alfil::check(Posicion objetivo, const TablaInfo& info) {
    if ((abs(pos.col - objetivo.col) != abs(pos.fil - objetivo.fil))) return false;
    return Pieza::check(objetivo, info);
}

void Alfil::dibuja() {
    string imagen = (color == NEGRAS) ? "imagenes/alfil_negro.png" : "imagenes/alfil_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}


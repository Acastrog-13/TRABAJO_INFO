#include "Peon.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;

bool Peon::check(Posicion objetivo, const TablaInfo& info) {
    auto dif = objetivo - pos;
    if (color == BLANCAS) {
        if (primer_mov == true) if (dif.fil != 2 || dif.col != 0) return false;
        else if (primer_mov == false) if (dif.fil != 1 || dif.col != 0) return false;
        return Pieza::check(objetivo, info);
    }
    else if (color == NEGRAS) {
        if (primer_mov == true) if (dif.fil != -2 || dif.col != 0) return false;
        if (primer_mov == false) if (dif.fil != -1 || dif.col != 0) return false;
        return Pieza::check(objetivo, info);
    }
    return false;
}

void Peon::dibuja() {
    string imagen = (color == NEGRAS) ? "imagenes/peon_negro.png" : "imagenes/peon_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}

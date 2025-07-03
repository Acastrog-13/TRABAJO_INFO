#include "Alfil.h"

using namespace std;

bool Alfil::check(const Posicion& objetivo, const TablaInfo& info)const {
    if ((abs(pos.col - objetivo.col) != abs(pos.fil - objetivo.fil))) return false;
    return Pieza::check(objetivo, info);
}

void Alfil::dibuja()const {
    string imagen = (color == NEGRAS) ? "imagenes/alfil_negro.png" : "imagenes/alfil_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
#include "Peon.h"

using namespace std;

bool Peon::check(Posicion objetivo, const TablaInfo& info) {
    auto dif = objetivo - pos;
    if (color == BLANCAS) {
        if (primer_mov == true)
            if ((dif.fil != 2 && dif.fil != 1) || dif.col != 0) return false;
        if (primer_mov == false)
            if (dif.fil != 1 || (dif.col != 0 && dif.col != 1 && dif.col != -1)) return false;

        return Pieza::check(objetivo, info);
    }
    else if (color == NEGRAS) {
        if (primer_mov == true)
            if ((dif.fil != -2 && dif.fil != -1) || dif.col != 0) return false;
        if (primer_mov == false)
            if (dif.fil != -1 || (dif.col != 0 && dif.col != 1 && dif.col != -1)) return false;

        return Pieza::check(objetivo, info);
    }
    return false;
}

bool Peon::check_recorrido(Posicion objetivo, const TablaInfo& info) {
    if (info(objetivo) == NONE) {
        if ((objetivo - pos).col == 0) return Pieza::check_recorrido(objetivo, info);
        return false;
    }
    if (color == BLANCAS)
        if (objetivo == Posicion(pos.col + 1, pos.fil + 1) || objetivo == Posicion(pos.col - 1, pos.fil + 1)) return true;
    if (color == NEGRAS)
        if (objetivo == Posicion(pos.col + 1, pos.fil - 1) || objetivo == Posicion(pos.col - 1, pos.fil - 1)) return true;
    return false;
}

void Peon::dibuja() {
    string imagen = (color == NEGRAS) ? "imagenes/peon_negro.png" : "imagenes/peon_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}

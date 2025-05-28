#include "Torre.h"
#include"ETSIDI.h"
#include <iostream>

using namespace std;

void Torre::dibuja() {
    string imagen = (color_p == Colores::NEGRA) ? "imagenes/torre_negra.png" : "imagenes/torre_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
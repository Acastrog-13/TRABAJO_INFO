#include "Rey.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;

void Rey::dibuja() {
    string imagen = (color == Color{ 0, 0, 0 }) ? "imagenes/rey_negro.png" : "imagenes/rey_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
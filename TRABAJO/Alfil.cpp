#include "Alfil.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;

void Alfil::dibuja() {
    string imagen = (color == Color{ 0, 0, 0 }) ? "imagenes/alfil_negro.png" : "imagenes/alfil_blanco.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
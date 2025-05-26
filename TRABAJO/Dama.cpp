#include "Dama.h"
#include "ETSIDI.h"
#include <iostream>

using namespace std;

void Dama::dibuja() {
    string imagen = (color == Color{ 0, 0, 0 }) ? "imagenes/dama_negra.png" : "imagenes/dama_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);
}
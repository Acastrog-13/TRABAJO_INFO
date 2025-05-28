#include "Torre.h"
#include"ETSIDI.h"
#include <iostream>

using namespace std;

void Torre::dibuja() {
    string imagen = (color_p == Colores::NEGRA) ? "imagenes/torre_negra.png" : "imagenes/torre_blanca.png";

    unsigned int glComun = ETSIDI::getTexture(imagen.c_str()).id;

    Pieza::dibuja(glComun);

    
}

/* vector<Jugadas> Torre::calcular_jugadas(const Tablero & tablero) const {
        vector<Jugadas*> posibles;

        Vector2D direcciones[] = { {0,1}, {0,-1}, {1,0}, {-1,0} };    //Vector de direcciones de los movimientos posibles de la torre

        for (Vector2D dir : direcciones) {      //comprobamos que se puede desplazar en cada direccion
            Vector2D pos_actual = this->posicion + dir;

            while (Tablero::limite_tablero(pos_actual.x, pos_actual.y, tablero)) {

                // Creamos una jugada tentativa
                if (Movimientos::limite_pieza(*this, pos_actual, tablero)) {
                    // La posición final está libre o capturamos rival
                    posibles.push_back(new Jugadas(this->posicion, pos_actual));

                    // Si hay pieza enemiga, no puede saltar más allá
                    const Celda& celda = tablero.get_celda(pos_actual);
                    if (celda.tiene_pieza() && celda.get_pieza()->get_color() != this->color_p)
                        break;

                    // Avanzamos
                    pos_actual = pos_actual + dir;
                }
                else {
                    // La pieza propia bloquea el camino
                    break;
                }
            }
        }

        return posibles;
    }*/
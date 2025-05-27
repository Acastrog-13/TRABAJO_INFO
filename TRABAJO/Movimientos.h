#pragma once
#include"pieza.h"
#include"tablero.h"
#include"Tablero.h"

class Movimientos
{
public:
    static bool limite_tablero(int x, int y, const Tablero& Tablero);                                   //posicion final dentro de tablero
    static bool limite_pieza(const Pieza& pieza, const Vector2D& destino, const Tablero& tablero);  //la pieza movida no salta otras
    static bool pieza_anclada(const Pieza& pieza, const Tablero& tablero);                          //no se puede mover en otra direccion la pieza si está anclada
    static bool mueve_jaque(const Pieza& rey, const Vector2D & destino, const Tablero& tablero);    //el rey no se mueve a posicion de jaque

    static Vector2D mueve_temporal(Pieza& pieza, Vector2D&);
    static Vector2D mueve_definitivo(Pieza& pieza, Vector2D&);


   
    //suponemos interaccion, hay que hacerlo
    static bool rey_en_jaque();       

    //Tipos de movimientos
    static bool delante(Pieza &, Vector2D, Tablero&);
    static bool atras(Pieza&, Vector2D, Tablero&);
    static bool horizontal(Pieza&, Vector2D, Tablero&);
    static bool diag_alante(Pieza&, Vector2D, Tablero&);
    static bool diag_atras(Pieza&, Vector2D, Tablero&);
    static bool ele(Pieza&, Vector2D, Tablero&);

    


    //otras funciones especiales
    /*static bool puede_enrocar(const Rey& rey, const Tablero& tablero);
    static bool puede_promocionar(const Peon& peon);
    static bool puede_captura_al_paso(const Peon& peon, const Tablero& tablero);
*/
    friend class Tablero;
};


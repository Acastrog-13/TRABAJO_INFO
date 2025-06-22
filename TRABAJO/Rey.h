#pragma once
#include "Pieza.h"

struct Rey : Pieza
{
	//Constructor
   Rey (Posicion pos, Color col): Pieza("Rey", pos, col){}


   bool check (Posicion objetivo, const TablaInfo& info) {
       auto dif = pos - objetivo;
       if ((abs(dif.col) == 1) && (dif.fil == 0) ||
           (abs(dif.fil) == 1) && (dif.col == 0) ||
           (abs(dif.fil) == 1) && (abs(dif.col) == 1))
           return Pieza::check (objetivo, info);
       return false;      
   }


    //Metodos
   // void dibuja();
    //void mueve(Vector2D);
};
#include "Peon.h"
#include "Pieza.h"

Peon::Peon(float x, float y) {
    posicion.x = x;
    posicion.y = y;
}


Color Pieza::get_color() {
    return color;
}

Vector2D Pieza::get_pos() {
    return posicion;
}

void Pieza::set_color(Color c) {
    color = c;
}

void Pieza::set_pos(Vector2D pos) {
    posicion = pos;
}

void Peon::dibuja() {           //OJO ACTUALIZAR CUANDO ESTÉN LAS CELDAS HECHAS. 
    glColor3ub(r, g, b);                                           // Color blanco, por ejemplo
    glTranslatef(posicion.x, posicion.y, 0.0);                     // Ajusta posición
    glutSolidSphere(2.5, 20, 20);         // Dibuja la letra P
    glTranslatef(-posicion.x, -posicion.y, 0.0);
}
}
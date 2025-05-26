#include "Pieza.h"


void Pieza::dibuja(unsigned int glComun)const {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);


    glBindTexture(GL_TEXTURE_2D, glComun);

    glDisable(GL_LIGHTING);

    int ancho = 8;  // tamaño imagen
    int alto = 8;

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);

    glTexCoord2d(1, 1); glVertex3d(posicion.x + ancho / 2, posicion.y - alto / 2, 0.1);
    glTexCoord2d(0, 1); glVertex3d(posicion.x - ancho / 2, posicion.y - alto / 2, 0.1);
    glTexCoord2d(0, 0); glVertex3d(posicion.x - ancho / 2, posicion.y + alto / 2, 0.1);         //(0,1) superior izq y en sentido horario. 
    glTexCoord2d(1, 0); glVertex3d(posicion.x + ancho / 2, posicion.y + alto / 2, 0.1);         //struct matricial siendo (0,0) abajo izq

    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

}
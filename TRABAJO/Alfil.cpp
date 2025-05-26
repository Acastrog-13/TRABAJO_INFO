#include "Alfil.h"
#include "ETSIDI.h"
void Alfil::dibuja() {
    if (color == Color{0, 0, 0}) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_TEXTURE_2D);

        glRotatef(180, 0, 0, 1);

        glBindTexture(GL_TEXTURE_2D,
            ETSIDI::getTexture("imagenes/alfil_negro.png").id);
        glDisable(GL_LIGHTING);

        int ancho = 8;  // tamaño imagen
        int alto = 8;

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);

        glTexCoord2d(1, 0); glVertex3d(posicion.x + ancho / 2, posicion.y - alto / 2, 0.1);
        glTexCoord2d(0, 0); glVertex3d(posicion.x - ancho / 2, posicion.y - alto / 2, 0.1);
        glTexCoord2d(0, 1); glVertex3d(posicion.x - ancho / 2, posicion.y + alto / 2, 0.1);         //(0,1) superior izq y en sentido horario. 
        glTexCoord2d(1, 1); glVertex3d(posicion.x + ancho / 2, posicion.y + alto / 2, 0.1);         //struct matricial siendo (0,0) abajo izq

        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
    }
    else {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_TEXTURE_2D);

        glRotatef(180, 0, 0, 1);

        glBindTexture(GL_TEXTURE_2D,
            ETSIDI::getTexture("imagenes/alfil_blanco.png").id);
        glDisable(GL_LIGHTING);

        int ancho = 8;  //tamaño imagen
        int alto = 8;

        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);

        glTexCoord2d(1, 0); glVertex3d(posicion.x + ancho / 2, posicion.y - alto / 2, 0.1);
        glTexCoord2d(0, 0); glVertex3d(posicion.x - ancho / 2, posicion.y - alto / 2, 0.1);
        glTexCoord2d(0, 1); glVertex3d(posicion.x - ancho / 2, posicion.y + alto / 2, 0.1);         //(0,1) superior izq y en sentido horario. 
        glTexCoord2d(1, 1); glVertex3d(posicion.x + ancho / 2, posicion.y + alto / 2, 0.1);         //struct matricial siendo (0,0) abajo izq

        glEnd();

        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
    }
}
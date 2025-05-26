#include "Lista_Piezas.h"


void Lista_Piezas::destruir_contenido() {
	for (auto p : lista) delete p;
	lista.clear();
}

void Lista_Piezas::eliminar(int index) {
	if ((index < 0) || (index >= lista.size())) return;
	delete lista[index];
	lista.erase(lista.begin() + index);
}

void Lista_Piezas::eliminar(Pieza* p) {
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i] == p) {
			eliminar(i);
			return;
		}
	}
}

void Lista_Piezas::mueve(int index, Vector2D posicion) {
	if ((index < 0) || (index >= lista.size())) return;
	lista[index]->set_posicion(posicion);
}

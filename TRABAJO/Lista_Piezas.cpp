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
	for (int i = 0; i < lista.size(); i++)
		if (lista[i] == p) {
			eliminar(i);
			return;
		}
}

int Lista_Piezas::indice_pieza (Vector2D pos_celda){
	for (int i = 0; i < lista.size(); i++) {
		if (lista[i]->get_pos() == pos_celda) return i;
	}
	return -1;
}




#include "Tablero.h"

void Tablero::inicializa(int f, int c, double lado)
{
	filas={ f };
	columnas={ c };
	
	Color color{};
	for (double fila = 1.0; fila <= f; fila++)
		for (double colum = 1.0; colum <= c; colum++) {
			if ((((int)colum% 2) == 0 && ((int)fila% 2) == 0) || (((int)colum% 2) == 1 && ((int)fila% 2) == 1)) color = { 100,140, 0}; //celdas oscuras
			else color = { 213, 186, 152 }; //celdas claras
			celdas.push_back(Celda({ (colum - 1) * lado, (fila - 1) * lado }, { (colum)*lado, (fila - 1) * lado }, { fila,colum }, color, lado));
		}

}

//retorna el centro del nombre de la celda que le pasas
Vector2D Tablero::get_centro(Vector2D n) const {
	for (int i = 0; i < celdas.size(); i++)
		if (celdas[i].get_nombre() == n)
			return celdas[i].get_centro();
	return{ -1,-1 };
}

Vector2D Tablero::get_nombre(Vector2D pos) const {
	for (int i = 0; i < celdas.size(); i++) {
		if (pos.x > celdas[i].limite1.x &&
			pos.x <= celdas[i].limite2.x &&
			pos.y > celdas[i].limite1.y &&
			pos.y <= celdas[i].limite1.y + celdas[i].lado)
			return celdas[i].get_nombre();
	}
	return{ -1,-1 };
}

void Tablero::dibuja() const{
	gluLookAt(columnas * 5, filas * 5, 100,
		columnas * 5, filas * 5, 0,
		0.0, 1.0, 0.0);

	for (auto c : celdas) c.dibuja(); 


	piezas_blancas.dibuja();
	piezas_negras.dibuja();
}

void Tablero::destruir_contenido() {
	piezas_blancas.destruir_contenido();
	piezas_negras.destruir_contenido();
	celdas.clear();
}

int Tablero::indice_pieza (Vector2D nombre_celda, Colores c) {
	switch (c) {

	case Colores::BLANCA:
		return piezas_blancas.indice_pieza(get_centro(nombre_celda));
		break;
	
	case Colores::NEGRA:
		return piezas_negras.indice_pieza(get_centro(nombre_celda));
		break;
	}
}


void Tablero::agregar_pieza(Peon* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Peon(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Torre* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Torre(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Alfil* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Alfil(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Caballo* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Caballo(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Dama* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Dama(l.get_color(),get_centro(celda)));
}
void Tablero::agregar_pieza(Rey* p, Lista_Piezas& l, const Vector2D celda) {
	l.agregar(new Rey(l.get_color(),get_centro(celda)));
}


void Tablero::inicializa45()
{
	inicializa(5, 4);
		
	agregar_pieza((Torre*)nullptr, piezas_blancas, { 1,1 });
	agregar_pieza((Alfil*)nullptr, piezas_blancas, { 1,2 });
	agregar_pieza((Caballo*)nullptr, piezas_blancas, { 1,3 });
	agregar_pieza((Rey*)nullptr, piezas_blancas, { 1,4 });
	agregar_pieza((Peon*) nullptr, piezas_blancas, { 2,4 });

	agregar_pieza((Torre*)nullptr, piezas_negras, { 5,4 });
	agregar_pieza((Alfil*)nullptr, piezas_negras, { 5,3 });
	agregar_pieza((Caballo*)nullptr, piezas_negras, { 5,2 });
	agregar_pieza((Rey*)nullptr, piezas_negras, { 5,1 });
	agregar_pieza((Peon*) nullptr, piezas_negras, { 4,1 });

}

void Tablero::inicializaS()
{
	inicializa(6, 5);

	agregar_pieza((Torre*)nullptr, piezas_blancas, { 1,1 });
	agregar_pieza((Caballo*)nullptr, piezas_blancas, { 1,2 });
	agregar_pieza((Alfil*)nullptr, piezas_blancas, { 1,3 });
	agregar_pieza((Dama*)nullptr, piezas_blancas, { 1,4 });
	agregar_pieza((Rey*)nullptr, piezas_blancas, { 1,5 });
	for (double i = 1; i < 6; i++)
		agregar_pieza((Peon*)nullptr, piezas_blancas, { 2,i });

	agregar_pieza((Torre*)nullptr, piezas_negras, { 6,5 });
	agregar_pieza((Caballo*)nullptr, piezas_negras, { 6,4 });
	agregar_pieza((Alfil*)nullptr, piezas_negras, { 6,3 });
	agregar_pieza((Dama*)nullptr, piezas_negras, { 6,2 });
	agregar_pieza((Rey*)nullptr, piezas_negras, { 6,1 });
	for (double i = 5; i > 0; i--)
		agregar_pieza((Peon*)nullptr, piezas_negras, { 5,i });

}


/*void Tablero::recalcula_jugadas() {
	// Borra las jugadas anteriores
	for (auto j : jugadas_posibles) delete j;
	jugadas_posibles.clear();

	for (auto p : piezas) {
		std::vector<Jugadas*> jugadas_pieza = p->calcular_jugadas(tablero);
		jugadas_posibles.insert(jugadas_posibles.end(), jugadas_pieza.begin(), jugadas_pieza.end());
	}
}*/
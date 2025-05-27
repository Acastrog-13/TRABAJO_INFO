#include "Cuatro_Cinco.h"

void Cuatro_Cinco::inicializa()
{
	agregar_pieza((Peon*) nullptr, piezas_blancas, { 2,4 });
	agregar_pieza((Torre*)nullptr, piezas_blancas, { 1,1 });
	agregar_pieza((Alfil*)nullptr, piezas_blancas, { 1,2 });
	agregar_pieza((Caballo*)nullptr, piezas_blancas, { 1,3 });
	agregar_pieza((Rey*)nullptr, piezas_blancas, { 1,4 });

	agregar_pieza((Peon*) nullptr, piezas_negras, { 4,1 });
	agregar_pieza((Torre*)nullptr, piezas_negras, { 5,4 });
	agregar_pieza((Alfil*)nullptr, piezas_negras, { 5,3 });
	agregar_pieza((Caballo*)nullptr, piezas_negras, { 5,2 });
	agregar_pieza((Rey*)nullptr, piezas_negras, { 5,1 });

}
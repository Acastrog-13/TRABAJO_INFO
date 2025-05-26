#include "Speed.h"

void Speed::inicializa()
{

	agregar_pieza((Torre*)nullptr, piezas_blancas, { 1,1 });
	agregar_pieza((Caballo*)nullptr, piezas_blancas, { 1,2 });
	agregar_pieza((Alfil*)nullptr, piezas_blancas, { 1,3 });
	agregar_pieza((Dama*)nullptr, piezas_blancas, { 1,4 });
	agregar_pieza((Rey*)nullptr, piezas_blancas, { 1,5 });	
	for (double i=1;i<6;i++)
		agregar_pieza((Peon*)nullptr, piezas_blancas, { 2,i });

	agregar_pieza((Torre*)nullptr, piezas_negras, { 6,5 });
	agregar_pieza((Caballo*)nullptr, piezas_negras, { 6,4 });
	agregar_pieza((Alfil*)nullptr, piezas_negras, { 6,3 });
	agregar_pieza((Dama*)nullptr, piezas_negras, { 6,2 });
	agregar_pieza((Rey*)nullptr, piezas_negras, { 6,1 });	
	for (double i=1;i<6;i++)
		agregar_pieza((Peon*)nullptr, piezas_negras, { 5,i });

}
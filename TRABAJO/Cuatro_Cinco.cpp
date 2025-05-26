#include "Cuatro_Cinco.h"

void Cuatro_Cinco::inicializa()
{
	agregar_pieza((Peon*) nullptr, piezas_blancas, { 2,4});
	agregar_pieza((Torre*)nullptr, piezas_blancas, { 1,1 });
	agregar_pieza((Alfil*)nullptr, piezas_blancas, { 1,2 });
	agregar_pieza((Caballo*)nullptr, piezas_blancas, { 1,3 });
	agregar_pieza((Rey*)nullptr, piezas_blancas, { 1,4 });

	agregar_pieza((Peon*) nullptr, piezas_negras, { 4,1 });
	agregar_pieza((Torre*)nullptr, piezas_negras, { 5,4 });
	agregar_pieza((Alfil*)nullptr, piezas_negras, { 5,3 });
	agregar_pieza((Caballo*)nullptr, piezas_negras, { 5,2 });
	agregar_pieza((Rey*)nullptr, piezas_negras, { 5,1 });

	/*
	piezas_blancas.agregar(new Torre{ mitablero.get_centro({1,1}), piezas_blancas.get_color()});
	piezas_blancas.agregar(new Alfil{ mitablero.get_centro({1,2}), piezas_blancas.get_color() });
	piezas_blancas.agregar(new Caballo{mitablero.get_centro({1,3}), piezas_blancas.get_color()});
	piezas_blancas.agregar(new Rey{ mitablero.get_centro({1,4}), piezas_blancas.get_color() });
	piezas_blancas.agregar(new Peon{ mitablero.get_centro({2,4}), piezas_blancas.get_color() });

	piezas_negras.agregar(new Torre{ mitablero.get_centro({5,4}), piezas_negras.get_color() });
	piezas_negras.agregar(new Alfil{ mitablero.get_centro({5,3}), piezas_negras.get_color() });
	piezas_negras.agregar(new Caballo{ mitablero.get_centro({5,2}), piezas_negras.get_color() });
	piezas_negras.agregar(new Rey{ mitablero.get_centro({5,1}), piezas_negras.get_color() });
	piezas_negras.agregar(new Peon{ mitablero.get_centro({4,1}), piezas_negras.get_color() });

	*/
}


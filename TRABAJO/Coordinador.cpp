#include "Coordinador.h"

void Coordinador::dibuja()
{
	switch (estado) {
	case INICIO:
		gluLookAt(40, 40, 130,
			40, 40, 0,
			0.0, 1.0, 0.0);

	}
}
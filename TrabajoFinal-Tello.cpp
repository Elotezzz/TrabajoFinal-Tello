#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    int opc;
	const char* opciones[] = { "Crear Tablero", "Ver Tableros", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
    Menu menuPrincipal("TELLO", opciones, 5);
	do
	{
		opc = menuPrincipal.mostrarMenu();
		switch (opc)
		{
		case 0:



			break;
		case 1:



			break;
		case 2:



			break;
		case 3:



			break;
		case 4:



			break;
		}
	} while (opc != 4);
	return 0;
}
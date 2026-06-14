#include <iostream>
#include "Menu.h"
#include "Tablero.h"

using namespace std;

int main()
{
	int opc;

	Tablero tablero(10);
	string titulo, ID;


	const char* opciones[] = { "Crear Tablero", "Ver Tableros", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
    Menu menuPrincipal("TELLO", opciones, 5);
	do
	{
		opc = menuPrincipal.mostrarMenu();
		switch (opc)
		{
		case 0:
			cout << "=== Info Tablero ===\n";
			cout << "> Nombre del tablero: "; cin >> titulo;
			cout << "> ID del tablero: "; cin >> ID;
			tablero.insertar(titulo, ID);
			_getch();
			
			break;
		case 1:
			tablero.imprimir();
			_getch();

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
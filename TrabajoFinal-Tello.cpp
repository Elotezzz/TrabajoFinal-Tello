#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Menu.h"
#include "Tablero.h"

using namespace std;

int main()
{
	int opc;
	string titulo, ID;

	vector<string> Titulos;

	Tablero tablero(10);
	Listado listado;
	Tarjeta tarjeta;

	vector<string> opciones = { "Crear Tablero", "Ver Tableros", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
    Menu menuPrincipal("TELLO", opciones, 5);
	do
	{
		opc = menuPrincipal.mostrarMenu();
		switch (opc)
		{
		case 0: {
			cout << "=== Crear Tablero ===\n";
			cout << "> Nombre del tablero: "; cin >> titulo;
			Titulos.push_back(titulo);
			ID =  to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) 
				+ to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) 
				+ to_string(rand() % 8 + 1);
			tablero.insertar(titulo, ID);

			_getch();
			break;
			}
		case 1: {
			cout << "=== Tableros Creados ===\n";
			tablero.imprimir();

			_getch();
			break;
			}
		case 2: {
			Menu menuSeleccionEliminar("Eliminar Tablero", Titulos, Titulos.size());

			int opcEliminar = menuSeleccionEliminar.mostrarMenu();
			titulo = Titulos[opcEliminar];
			tablero.eliminar(titulo);

			break;
			}
		case 3: {
			cout << "=== Seleccionar Tablero ===\n";


			break;
			}
		case 4:
			cout << "Saliendo del programa Tello ...";
			Sleep(2000);
			break;
		}
	} while (opc != 4);
	return 0;
}
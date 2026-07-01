#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Menu.h"
#include "Tablero.h"

using namespace std;

void menuTarjeta(int opc, string titulo, string ID) {
	Tarjeta tarjeta;
}

void menuListado(int opc, string titulo, string ID) {
	Listado listado;
	vector<string> ListadoNew;

	vector<string> opciones = { "Crear Tablero", "Ver Tableros", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
}

int main()
{
	int opc;
	string titulo, ID;
	vector<string> TableroNew;
	Tablero tablero(10);

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
			TableroNew.push_back(titulo);
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
			Menu menuSeleccionEliminar("Eliminar Tablero", TableroNew, TableroNew.size());

			int opcEliminar = menuSeleccionEliminar.mostrarMenu();
			titulo = TableroNew[opcEliminar];
			tablero.eliminar(titulo);

			break;
			}
		case 3: {
			Menu menuSeleccion("Seleccionar Tablero", TableroNew, TableroNew.size());

			int opcSeleccion = menuSeleccion.mostrarMenu();
			titulo = TableroNew[opcSeleccion];
			// segundo menu no? 

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
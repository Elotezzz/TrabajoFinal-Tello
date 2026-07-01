#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Menu.h"
#include "Tablero.h"

using namespace std;

void menuTarjeta(string titulo) {
	int opc;
	Tarjeta tarjeta;

	vector<string> opcL = { "Crear Tarjeta", "Ver Tarjetas", "Eliminar Tarjeta", "Seleccionar Tarjeta", "Volver" };
	Menu menuListado(titulo, opcL, opcL.size());
	do
	{
		opc = menuListado.mostrarMenu();

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
}

void menuListado(string titulo, Tablero& tablero) {
	int opc;
	Listado listado;

	vector<string> opcT = { "Crear Lista", "Ver Listas", "Eliminar Lista", "Seleccionar Lista", "Volver" };
	Menu menuTablero(titulo, opcT, opcT.size());
	do
	{
		opc = menuTablero.mostrarMenu();

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
}

int main()
{
	int opc;
	string titulo, ID;
	vector<string> TableroNew = {"New File"};
	Tablero tablero(10);

	vector<string> opcM = { "Crear Tablero", "Ver Tableros", "Eliminar Tablero", "Seleccionar Tablero", "Salir" };
    Menu menuPrincipal("TELLO", opcM, opcM.size());
	do
	{
		opc = menuPrincipal.mostrarMenu();
		switch (opc)
		{
		case 0: {
			cout << "=== Crear Tablero ===\n";
			cout << "> Nombre del tablero: "; cin >> titulo;
			TableroNew.push_back(titulo);
			ID = to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1) 
				+ to_string(rand() % 8 + 1) + to_string(rand() % 8 + 1);
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
			if (TableroNew.size() != 0)
			{
				Menu menuSeleccionEliminar("Eliminar Tablero", TableroNew, TableroNew.size());

				int opcEliminar = menuSeleccionEliminar.mostrarMenu();
				if (opcEliminar == -1) break;
				titulo = TableroNew[opcEliminar];

				// Aqui mi tio claudio me ayudo para la logica del if y q al momento de borrar un tablero seguia apareciendo 
				// su nombre
				if (!tablero.buscar(titulo).empty()) {
					tablero.eliminar(titulo);
					TableroNew.erase(TableroNew.begin() + opcEliminar);
				}

				else {
					cout << "Tablero no encontrado";
					_getch();
				}
			}
			else
			{
				cout << "Contenido no valido, primero registre un tablero\n";
				_getch();
			}
			break;
			}
		case 3: {
			Menu menuSeleccion("Seleccionar Tablero", TableroNew, TableroNew.size());

			int opcSeleccion = menuSeleccion.mostrarMenu();
			if (opcSeleccion == -1) break;
			titulo = TableroNew[opcSeleccion];

			if (!tablero.buscar(titulo).empty()) 
				menuListado(titulo, tablero);
			else {
				cout << "Tablero no encontrado";
				_getch();
			}
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
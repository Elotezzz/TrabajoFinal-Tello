#include "Menu.h"

Menu::Menu(std::string titulo, std::vector<std::string> opciones, int cantidad) : titulo(titulo), opciones(opciones),
cntOpciones(cantidad), seleccion(0) {
}

// Analisis Big O - funcion mostrarMenu
int Menu::mostrarMenu() {
	char tecla;																	// 1
	while (true) {																// N
		system("cls");
		std::cout << "====== " << titulo << " ======\n";						// 1
		for (int i = 0; i < cntOpciones; i++) {									// 1 + (1+ 2 + 2) N
			if (seleccion == i) {												// 1
				std::cout << "> " << i + 1 << ". " << opciones[i] << "\n";		// 2
			}
			else {
				std::cout << "  " << i + 1 << ". " << opciones[i] << "\n";		// 2
			}
		}
		tecla = _getch();														// 1
		if (tecla == -32) {														// 1
			tecla = _getch();													// 1
			if (tecla == KEY_DOWN) {											// 1
				seleccion = (seleccion + 1) % cntOpciones;						// 3
			}
			else if (tecla == KEY_UP) {											// 1
				seleccion = (seleccion - 1 + cntOpciones) % cntOpciones;		// 3
			}
		}
		else if (tecla == KEY_ENTER) {											// 1
			return seleccion;													// 1
		}
		else if (tecla == KEY_ESCAPE) {
			return -1;
		}
	}
};
// Como podemos ver en total nos saldria que -> mostrarMenu = 1 + N + 2 + (5)N + 3 + 2 + 7 + 4 + 2
// En total seria							 -> mostrarMenu = 21 + N + 5N
//											 -> mostrar Menu = O(6N) -> O(N)
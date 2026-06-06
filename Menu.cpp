#include "Menu.h"

Menu::Menu(const char* titulo, const char* opciones[], int cantidad) : titulo(titulo), opciones(opciones),
cntOpciones(cantidad), seleccion(0) {
}

int Menu::mostrarMenu() {
	char tecla;
	while (true) {
		system("cls");
		std::cout << "====== " << titulo << " ======\n";
		for (int i = 0; i < cntOpciones; i++) {
			if (seleccion == i) {
				std::cout << "> " << i + 1 << ". " << opciones[i] << "\n";
			}
			else {
				std::cout << "  " << i + 1 << ". " << opciones[i] << "\n";
			}
		}
		tecla = _getch();
		if (tecla == -32) {
			tecla = _getch();
			if (tecla == KEY_DOWN) {
				seleccion = (seleccion + 1) % cntOpciones;
			}
			else if (tecla == KEY_UP) {
				seleccion = (seleccion - 1 + cntOpciones) % cntOpciones;
			}
		}
		else if (tecla == KEY_ENTER) {
			return seleccion;
		}
	}
};

#include "Tablero.h"

Tablero::Tablero() : ID(00000), titulo(""), tam(10), listado(new Listado) {
	tablaHash = new Lista[tam];
}
Tablero::Tablero(int ID, std::string titulo, int tam) : ID(ID), titulo(titulo), tam(tam), listado(new Listado) {
	tablaHash = new Lista[tam];
}
Tablero::Tablero(int tam) : ID(0), titulo(""), tam(tam), listado(nullptr) {
    tablaHash = new Lista[tam];
}
Tablero::~Tablero() {
    for (int i = 0; i < tam; i++) {
        tablaHash[i].limpiar();
    }
    delete[] tablaHash;
	delete[] listado;
}

int Tablero::funcionHash(const std::string& clave) {
	unsigned long h = 0;
	for (char c : clave) {
		h = h * 31 + c;
	}
	return h % tam;
}

void Tablero::insertar(const std::string& titulo, const std::string& ID) {
    int idx = funcionHash(titulo);
    tablaHash[idx].insertar(titulo, ID);
    std::cout << "  [guardado] " << titulo
        << " en tabla[" << idx << "]\n";
}
std::string Tablero::buscar(const std::string& titulo) {
    int idx = funcionHash(titulo);
    return tablaHash[idx].buscar(titulo);
}
bool Tablero::eliminar(const std::string& titulo) {
    int idx = funcionHash(titulo);
    return tablaHash[idx].eliminar(titulo);
}
void Tablero::imprimir() {
    std::cout << "\n--- Tableros ---\n";
    for (int i = 0; i < tam; i++) {
        if (!tablaHash[i].cabeza) continue;
        std::cout << "tabla[" << i << "]: ";
        tablaHash[i].imprimir();
        std::cout << "\n";
    }
    std::cout << "--------------\n";
}
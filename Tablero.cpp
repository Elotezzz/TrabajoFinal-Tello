#include "Tablero.h"

Tablero::Tablero() : ID(00000), titulo(""), tam(10), listado(new DoubleLinkedList<Listado>) {
	tablaHash = new Lista<std::string, std::string>[tam];
}
Tablero::Tablero(int ID, std::string titulo, int tam) : ID(ID), titulo(titulo), tam(tam), listado(new DoubleLinkedList<Listado>) {
	tablaHash = new Lista<std::string, std::string>[tam];
}
Tablero::Tablero(int tam) : ID(0), titulo(""), tam(tam), listado(nullptr) {
    tablaHash = new Lista<std::string, std::string>[tam];
}
Tablero::~Tablero() {
    for (int i = 0; i < tam; i++) {
        tablaHash[i].limpiar();
    }
    delete[] tablaHash;
	delete[] listado;
}

// Analisis Big O - funcion funcionHash
int Tablero::funcionHash(const std::string& clave) {
	unsigned long h = 0;                // 1
	for (char c : clave) {              // 2 + N
		h = h * 31 + c;                 // 3
	}
	return h % tam;                     // 1
}
// Como podemos ver en total nos saldria que -> funcionHash: 1 + 2 + N + 3 + 1
// En total seria                            -> funcionHash: 7 + N
//                                           -> funcionHash: O(N)

void Tablero::insertar(const std::string& titulo, const std::string& ID) {
    int idx = funcionHash(titulo);
    tablaHash[idx].insertar(titulo, ID);
    std::cout << "  [guardado] " << titulo << " en tabla [" << idx << "]\n";
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
        std::cout << "Tablero [" << i << "]: ";
        tablaHash[i].imprimir();
        std::cout << "\n";
    }
    std::cout << "--------------\n";
}
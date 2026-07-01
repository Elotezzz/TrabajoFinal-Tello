#include "Listado.h"

Listado::Listado() {
	ID = 00000;
	titulo = "";
	raizArbol = nullptr;
}
Listado::Listado(int ID, std::string titulo) {
	this->ID = ID;
	this->titulo = titulo;
	raizArbol = nullptr;
}

// Analisis Big O - funcion agregarTarjeta
void Listado::agregarTarjeta(Tarjeta* nuevaTarjeta) {
	if (nuevaTarjeta!=nullptr)                                                                                                          // 1
	{
		auto calcularFormula = [](int comentarios, int tareas) -> int {                                                                 // 3
			return comentarios + 2 * tareas;                                                                                            // 3
			};
		int prioridadCalculada = calcularFormula(nuevaTarjeta->getCantidadComentarios(),nuevaTarjeta->getCantidadTasksCompletadas());   // 3
		nuevaTarjeta->setPrioridad(prioridadCalculada);                                                                                 // 2
        raizArbol = Insertar(raizArbol, nuevaTarjeta);                                                                                  // log N
	}
}
// Como podemos ver en total nos saldria que -> agregarTarjeta = 1 + 6 + 5 + log(N)
// En total seria                            -> agregarTarjeta = 12 + log(N)
//                                           -> agregarTarjeta = O(log(N))

Listado::~Listado() {
	DestruirArbol(raizArbol);
	raizArbol = nullptr;
}
std::string Listado::getTitulo(){ return titulo; }
int Listado::partition(std::vector<Listado>& A, int low, int high)
{
    std::string pivot = A[high].getTitulo();
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        // <= (menor a mayor)
        // >= (mayor a menor)
        if (A[j].getTitulo() <= pivot)
        {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[high]);
    return i + 1;
}
void Listado::quickSort(std::vector<Listado>& A, int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}
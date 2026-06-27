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
void Listado::agregarTarjeta(Tarjeta* nuevaTarjeta) {
	if (nuevaTarjeta!=nullptr)
	{
		raizArbol = Insertar(raizArbol, nuevaTarjeta);
	}
}
Listado::~Listado() {
	DestruirArbol(raizArbol);
	raizArbol = nullptr;
}
std::string Listado::getTitulo() const { return titulo; }
int partition(std::vector<Listado>& A, int low, int high)
{
    std::string pivot = A[high].getTitulo();
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        // <= (menor a mayor)
        // >= (mayor a menor)
        if (A[j].getTitulo() >= pivot)
        {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[high]);
    return i + 1;
}
void quickSort(std::vector<Listado>& A, int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}
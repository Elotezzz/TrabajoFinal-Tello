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
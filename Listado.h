#pragma once
#include <iostream>
#include "DobleListaEnlazada-Listado.h"
#include "Tarjeta.h"
#include "ArbolAVL-Priority.h"

class Listado
{
private:
	int ID;
	std::string titulo;
	NodoAVL<Tarjeta>* raizArbol;
public:
	Listado();
	Listado(int ID, std::string titulo);
	~Listado();
	void agregarTarjeta(Tarjeta* tarjeta);
	NodoAVL<Tarjeta>* getRaizArbol() const {
		return raizArbol;
	}
	std::string getTitulo();	
	int partition(std::vector<Listado>& A, int low, int high);
	void quickSort(std::vector<Listado>& A, int low, int high);
};
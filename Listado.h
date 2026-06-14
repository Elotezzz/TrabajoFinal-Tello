#pragma once
#include <iostream>
#include "DobleListaEnlazada-Listado.h"
#include "Tarjeta.h"

class Listado
{
private:
	int ID;
	std::string titulo;
	Tarjeta* tarjeta;

public:
	Listado();
	Listado(int ID, std::string titulo);
	~Listado();
};
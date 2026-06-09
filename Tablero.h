#pragma once
#include <iostream>
#include "Listado.h"

class Tablero
{
private:
	int ID;
	std::string titulo;
	Listado* listado;

public:
	Tablero(int ID, std::string titulo);
	~Tablero();

};
#pragma once
#include <iostream>
#include "Tarjeta.h"

class Listado
{
private:
	int ID;
	std::string titulo;
	Tarjeta tarjeta;

public:
	Listado();
	~Listado();
};
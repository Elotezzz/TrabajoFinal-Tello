#pragma once
#include <iostream>
#include "FechaVencimiento.h"
#include "Checklist.h"
#include "Comentario.h"

class Tarjeta
{
private:
	int ID;
	std::string titulo;
	std::string descripcion;

public:
	Tarjeta();
	~Tarjeta();


};
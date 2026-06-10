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
	FechaVencimiento* fechaVencimiento;
	std::string descripcion;
	Checklist* checklist;
	Comentario* comentario;

public:
	Tarjeta();
	Tarjeta(int ID, std::string titulo, std::string descripcion);
	~Tarjeta();


};
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
	std::vector<Comentario*> comentarios;
	int prioridad;
public:
	Tarjeta();
	Tarjeta(int ID, std::string titulo, std::string descripcion);
	int getPrioridad() const {
		return prioridad;
	}
	void actualizarPrioridad() {
		int tareasCompletadas = (checklist != nullptr) ? checklist->getCantidadTasksCompletadas():0;
		prioridad = comentarios.size() + 2 * checklist->getCantidadTasksCompletadas();
	}
	~Tarjeta();
};
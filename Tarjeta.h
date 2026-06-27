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
	void setPrioridad(int prioridad) {
		this->prioridad = prioridad;
	}
	int getCantidadComentarios() const {
		return comentarios.size();
	}
	int getCantidadTasksCompletadas() const {
		return (checklist != nullptr) ? checklist->getCantidadTasksCompletadas() : 0;
	}
	~Tarjeta();
};
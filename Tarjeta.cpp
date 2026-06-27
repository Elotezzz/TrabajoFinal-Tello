#include "Tarjeta.h"

Tarjeta::Tarjeta() : ID(00000), titulo(""), fechaVencimiento(new FechaVencimiento), descripcion(""), checklist(new Checklist) {}
Tarjeta::Tarjeta(int ID, std::string titulo, std::string descripcion) : ID(ID), titulo(titulo), 
fechaVencimiento(new FechaVencimiento), descripcion(descripcion), checklist(new Checklist) {}
Tarjeta::~Tarjeta() {
	delete fechaVencimiento;
	delete checklist;
}
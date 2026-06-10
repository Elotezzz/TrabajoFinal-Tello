#include "Listado.h"

Listado::Listado() : ID(00000), titulo(""), tarjeta(new Tarjeta) {}
Listado::Listado(int ID, std::string titulo) : ID(ID), titulo(titulo), tarjeta(new Tarjeta) {}
Listado::~Listado() {}
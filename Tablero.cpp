#include "Tablero.h"

Tablero::Tablero() : ID(00000), titulo(""), listado(new Listado) {}
Tablero::Tablero(int ID, std::string titulo) : ID(ID), titulo(titulo), listado(new Listado) {}
Tablero::~Tablero() {}
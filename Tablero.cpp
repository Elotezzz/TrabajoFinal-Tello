#include "Tablero.h"

Tablero::Tablero(int ID, std::string titulo) : ID(ID), titulo(titulo), listado(new Listado) {}
Tablero::~Tablero() {}
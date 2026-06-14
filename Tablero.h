#pragma once
#include <iostream>
#include "Listado.h"
#include "TablaHash-Tablero.h"

class Tablero
{
private:
	//parte del tablero
	int ID;
	std::string titulo;
	Listado* listado;

	//parte de la tabla hash
	int tam;
	Lista* tablaHash;
    int funcionHash(const std::string& clave);

public:
	Tablero();
	Tablero(int ID, std::string titulo, int tam);
	Tablero(int tam);
	~Tablero();

    void insertar(const std::string& titulo, const std::string& ID);
	std::string buscar(const std::string& titulo);
	bool eliminar(const std::string& titulo);
	void imprimir();
};
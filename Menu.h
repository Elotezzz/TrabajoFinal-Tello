#pragma once
#include <conio.h>
#include <iostream>
#include <vector>

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_ENTER 13

class Menu
{
private:
	const char* titulo;
	std::vector<std::string> opciones;
	int cntOpciones;
	int seleccion;

public:
	Menu(const char* titulo, std::vector<std::string> opciones, int cntOpciones);
	int mostrarMenu();
};
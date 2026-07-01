#pragma once
#include <conio.h>
#include <iostream>
#include <vector>

#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_ENTER 13
#define KEY_ESCAPE 27

class Menu
{
private:
	std::string titulo;
	std::vector<std::string> opciones;
	int cntOpciones;
	int seleccion;

public:
	Menu(std::string titulo, std::vector<std::string> opciones, int cntOpciones);
	int mostrarMenu();
};
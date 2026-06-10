#pragma once
#include <iostream>

class Task
{
private:
	std::string text;
	bool completado;

public:
	Task();
	Task(std::string text, bool completado);
	~Task();


};
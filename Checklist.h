#pragma once
#include <iostream>
#include "Task.h"

class Checklist
{
private:
	int cantidadTasks;
	Task* task;

public:
	Checklist();
	Checklist(int cantidadTasks);
	~Checklist();

};
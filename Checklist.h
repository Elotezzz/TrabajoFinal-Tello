#pragma once
#include <iostream>
#include <vector>
#include "Task.h"

class Checklist
{
private:
	int cantidadTasks;
	std::vector<Task*> tasks;
public:
	Checklist();
	Checklist(int cantidadTasks);
	int getCantidadTasks();
	int getCantidadTasksCompletadas();
	void agregarTask(Task* task);
	void marcarTaskCompletada(const int index);
	void marcarTaskIncompleta(const int index);
	void mostrarTasksRecursivo(const int n) {
		if (n >= (int)tasks.size()) 
			return;
		std::cout << "Task " << n + 1 << ": " << tasks[n]->getText()
				<< " [" << (tasks[n]->getCompletado() ? "Completada" : "Incompleta") << "]" << std::endl;
		mostrarTasksRecursivo(n + 1);
	}
};
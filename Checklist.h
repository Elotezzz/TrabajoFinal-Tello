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
	int getCantidadTasks() const { return tasks.size(); }
	int getCantidadTasksCompletadas() const {
		int count = 0;
		for (const auto& task : tasks) {
			if (task->getCompletado()) {
				count++;
			}
		}
		return count;
	}
	void agregarTask(Task* task) {
		tasks.push_back(task);
		cantidadTasks++;
	}
	void marcarTaskCompletada(int index) {
		if (index >= 0 && index < tasks.size()) {
			tasks[index]->setCompletado(true);
		}
	}
	void marcarTaskIncompleta(int index) {
		if (index >= 0 && index < tasks.size()) {
			tasks[index]->setCompletado(false);
		}
	}
	void mostrarTasksRecursivo(int n) const {
		if (n >= (int)tasks.size()) 
			return;
		std::cout << "Task " << n + 1 << ": " << tasks[n]->getText()
				<< " [" << (tasks[n]->getCompletado() ? "Completada" : "Incompleta") << "]" << std::endl;
		mostrarTasksRecursivo(n + 1);
	}
	~Checklist();
};
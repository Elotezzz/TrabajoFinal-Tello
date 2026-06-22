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
	void mostrarTasks() const {
		for (int i = 0; i < tasks.size(); ++i) {
			std::cout << "Task " << i + 1 << ": " << tasks[i]->getText()
				<< " [" << (tasks[i]->getCompletado() ? "Completada" : "Incompleta") << "]" << std::endl;
		}
	}
	~Checklist();
};
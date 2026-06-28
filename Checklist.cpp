#include "Checklist.h"

Checklist::Checklist() : cantidadTasks(0) {}
Checklist::Checklist(int cantidadTasks) : cantidadTasks(cantidadTasks) {}
int Checklist::getCantidadTasks() { return tasks.size(); }
int Checklist::getCantidadTasksCompletadas() {
	int count = 0;
	for (const auto& task : tasks) {
		if (task->getCompletado()) {
			count++;
		}
	}
	return count;
}
void Checklist::agregarTask(Task* task) {
	tasks.push_back(task);
	cantidadTasks++;
}
void Checklist::marcarTaskCompletada(const int index) {
	if (index >= 0 && index < tasks.size()) {
		tasks[index]->setCompletado(true);
	}
}
void Checklist::marcarTaskIncompleta(const int index) {
	if (index >= 0 && index < tasks.size()) {
		tasks[index]->setCompletado(false);
	}
}

// Analisis Big O - funcion mostrarTasksRecursivo
void Checklist::mostrarTasksRecursivo(const int n) {
	if (n >= (int)tasks.size())																		// 2
		return;																						// 1
	std::cout << "Task " << n + 1 << ": " << tasks[n]->getText()									
		<< " [" << (tasks[n]->getCompletado() ? "Completada" : "Incompleta") << "]" << std::endl;	// 4
	mostrarTasksRecursivo(n + 1);																	// N
}
// Como podemos ver en total nos saldria que -> mostrarTasksRecursivo = 3 + 4 + N
// En total seria							 -> mostrarTasksRecursivo = 7 + N
//											 -> mostrarTasksRecursivo = O(N)
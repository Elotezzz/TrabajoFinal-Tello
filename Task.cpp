#include "Task.h"

Task::Task() : text(""), completado(false) {}
Task::Task(std::string text, bool completado) : text(text), completado(completado) {}
int cantidadTasksCompletadas(const std::vector<Task>& tareas)
{
    auto contar = [](const std::vector<Task>& tareas)
        {
            int contador = 0;
            for (const auto& tarea : tareas)
            {
                if (tarea.getCompletado()) {
                    contador++;
                }
            }
            return contador;
        };
    return contar(tareas);
}
Task::~Task() {}
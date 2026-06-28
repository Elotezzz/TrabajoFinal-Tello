#include "Task.h"

Task::Task() : text(""), completado(false) {}
Task::Task(std::string text, bool completado) : text(text), completado(completado) {}

// Analisis Big O - funcion cantidadTasksCompletadas
int cantidadTasksCompletadas(const std::vector<Task>& tasks)
{
    auto contar = [](const std::vector<Task>& tasks)           // 1
        {
            int contador = 0;                                   // 1
            for (const auto& tarea : tasks)                    // 1 + N
            {
                if (tarea.getCompletado()) {                    // 1
                    contador++;                                 // 2
                }
            }
            return contador;                                    // 1
        };
    return contar(tasks);                                      // 1
}
// Como podemos ver en total nos saldria que -> cantidadTasksCompletadas = 1 + 2 + N + 3 + 1 + 1
// En total seria                            -> cantidadTasksCompletadas = 8 + N
//                                           -> cantidadTasksCompletadas = O(N)
Task::~Task() {}
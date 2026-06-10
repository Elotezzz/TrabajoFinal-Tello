#include "Task.h"

Task::Task() : text(""), completado(false) {}
Task::Task(std::string text, bool completado) : text(text), completado(completado) {}
Task::~Task() {}
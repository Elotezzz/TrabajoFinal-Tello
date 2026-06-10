#include "Checklist.h"

Checklist::Checklist() : cantidadTasks(0), task(new Task) {}
Checklist::Checklist(int cantidadTasks) : cantidadTasks(cantidadTasks), task(new Task) {}
Checklist::~Checklist() {}
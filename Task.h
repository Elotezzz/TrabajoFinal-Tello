#pragma once
#include <iostream>
#include <vector>

class Task
{
private:
	std::string text;
	bool completado;
public:
	Task();
	Task(std::string text, bool completado);
	void setText(std::string text) { this->text = text; }
	void setCompletado(bool completado) { this->completado = completado; }
	std::string getText() const { return text; }
	bool getCompletado() const { return completado; }
	int cantidadTasksCompletadas(std::vector<Task>& tasks);
	~Task();
};
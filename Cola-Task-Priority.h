#pragma once
#include <iostream>

class Nodo {
public:
	int dato;
	Nodo* siguiente;
	Nodo(int valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

class Cola {
private:
	Nodo* frente;
	Nodo* final;
public:
	Cola() {
		frente = nullptr;
		final = nullptr;
	}
	void enqueue(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (final == nullptr) {
			frente = final = nuevo;
			return;
		}
		final->siguiente = nuevo;
		final = nuevo;
	}
	void dequeue() {
		if (frente == nullptr) return;
		Nodo* temp = frente;
		frente = frente->siguiente;
		if (frente == nullptr)
			final = nullptr;
		delete temp;
	}
	int front() {
		return frente ? frente->dato : -1;
	}
	bool isEmpty() {
		return frente == nullptr;
	}
};

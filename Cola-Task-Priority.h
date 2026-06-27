#pragma once
#include <iostream>

template <typename T>
class NodoCola {
public:
	T dato;
	NodoCola<T>* siguiente;
	NodoCola(T valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

template <typename T>
class Cola {
private:
	NodoCola<T>* frente;
	NodoCola<T>* final;
public:
	Cola() {
		frente = nullptr;
		final = nullptr;
	}
	void enqueue(T valor) {
		NodoCola<T>* nuevo = new NodoCola<T>(valor);
		if (final == nullptr) {
			frente = final = nuevo;
			return;
		}
		final->siguiente = nuevo;
		final = nuevo;
	}
	void dequeue() {
		if (frente == nullptr) return;
		NodoCola<T>* temp = frente;
		frente = frente->siguiente;
		if (frente == nullptr)
			final = nullptr;
		delete temp;
	}
	T front() {
		return frente ? frente->dato : T();
	}
	bool isEmpty() {
		return frente == nullptr;
	}
	~Cola() {
		while (!isEmpty()) {
			dequeue();
		}
	}
};
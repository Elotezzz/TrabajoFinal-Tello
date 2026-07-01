#pragma once
#include <iostream>

template <typename T>
class DoubleNode {
public:
	T data;
	DoubleNode<T>* next;
	DoubleNode<T>* prev;
	// Constructor
	DoubleNode(T& data) : data(data), next(nullptr), prev(nullptr) {}
	DoubleNode(T& data, DoubleNode<T>* next, DoubleNode<T>* prev) : data(data), next(next), prev(prev) {}
};

// Lista Enlazada
template <typename T>
class DoubleLinkedList {
private:
	DoubleNode<T>* head;
	int length;

	// Método privado que va a buscar un nodo en una posición en particular
	// posición comienza de 0, como los arreglos
	DoubleNode<T>* NodeAt(int pos) {
		if (pos >= length) {
			std::cout << "No existe posicion, debe ser menor al tamanio de la lista...\n";
			return nullptr;
		}
		// Buscar el nodo, usando la posición
		int index = 0;
		DoubleNode<T>* aux = head;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta ubicar el nodo
		// en la posición que está mandada como parámetro
		while (index < pos) {
			aux = aux->next;
			index++;
		}
		return aux;
	}

public:
	// Constructor
	DoubleLinkedList() : head(nullptr), length(0) {}
	// Destructor
	~DoubleLinkedList() {
		DoubleNode<T>* aux = head;
		DoubleNode<T>* aux2;
		// Este código hace que el puntero aux, salte de nodo en nodo hasta eliminar el último
		while (aux != nullptr) {
			aux2 = aux->next;
			delete aux;
			aux = aux2;
		}
	}

	void Print(bool reverse = false) {
		if (IsEmpty()) {
			std::cout << "La lista enlazada esta Vacia...\n";
			return;
		}
		DoubleNode<T>* aux;
		// aux = reverse ? NodeAt(length - 1) : head;
		if (reverse)
			aux = NodeAt(length - 1);
		else
			aux = head;
		while (aux != nullptr) {
			std::cout << aux->data << " ";
			// aux = reverse ? aux->prev : aux->next;
			if (reverse)
				aux = aux->prev;
			else
				aux = aux->next;
		}
		std::cout << std::endl;
	}

	// La longitud
	int Length() {
		return length;
	}

	// Es vacío
	bool IsEmpty() {
		return length == 0;
	}

	void AddFirst(T data) {
		DoubleNode<T>* node = new DoubleNode<T>(data);
		if (IsEmpty()) { // Cuando está vacío next y prev apuntan a nulo
			node->next = nullptr;
			node->prev = nullptr;
		}
		else {
			node->next = head;
			head->prev = node;
		}
		head = node;
		length++;
	}

	void AddPos(T data, int pos) {
		// Ubicamos la posición anterior
		if (pos == 0) // Agrego al inicio
			AddFirst(data);
		else
		{
			DoubleNode<T>* nodeBefore = NodeAt(pos - 1);
			if (nodeBefore == nullptr) {
				std::cout << "Error: AddPos no se puede ejecutar, posicion fuera de rango\n";
				return;
			}
			DoubleNode<T>* nodeAfter = nodeBefore->next;
			// El nodo nuevo apunta a la siguiente posición
			DoubleNode<T>* node = new DoubleNode<T>(data, nodeAfter, nodeBefore);
			// El nodo anterior apunta al nuevo nodo.
			nodeBefore->next = node;
			if (nodeAfter != nullptr)
				nodeAfter->prev = node;
			length++;
		}
	}

	void AddLast(T data) {
		DoubleNode<T>* node = new DoubleNode<T>(data);
		if (IsEmpty()) {
			head = node;
		}
		else {
			// Buscamos el último nodo y lo agregamos
			DoubleNode<T>* nodeLast = NodeAt(length - 1);
			nodeLast->next = node; // el anterior último apunta al nodo
			node->prev = nodeLast; // el nuevo nodo apunta al anterior
		}
		length++;
	}
	
	void ModifyFirst(T data) {
		DoubleNode<T>* currentNode = NodeAt(0);
		if (currentNode != nullptr) {
			currentNode->data = data;
		}
	}

	void ModifyPos(T data, int pos) {
		DoubleNode<T>* currentNode = NodeAt(pos);
		if (currentNode != nullptr) {
			currentNode->data = data;
		}
	}

	void ModifyLast(T data) {
		DoubleNode<T>* currentNode = NodeAt(length - 1);
		if (currentNode != nullptr) {
			currentNode->data = data;
		}
	}

	void RemoveFirst() {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		DoubleNode<T>* aux = head;
		head = head->next;
		delete aux;
		length--;
	}

	void RemovePos(int pos) {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		if (pos == 0) // Remuevo el inicio
			RemoveFirst();
		else {
			DoubleNode<T>* nodeBefore = NodeAt(pos - 1);
			DoubleNode<T>* nodeErase = NodeAt(pos);
			if (nodeBefore != nullptr && nodeErase != nullptr) {
				nodeBefore->next = nodeErase->next;
				// Podemos eliminar con tranquilidad el nodo elegido
				delete nodeErase;
				length--;
			}
		}
	}

	void RemoveLast() {
		if (IsEmpty()) {
			std::cout << "No se puede eliminar un nodo en una lista enlazada vacía\n";
			return;
		}
		if (length == 1) {
			DoubleNode<T>* aux = head;
			head = nullptr;
			delete aux;
			length--;
		}
		else {
			// Busca el penúltimo nodo, lo guardamos
			DoubleNode<T>* nodePreviousLast = NodeAt(length - 2);
			if (nodePreviousLast != nullptr) {
				// Penúltimo nodo apunte a nulo y hacemos que el último nodo
				// sea eliminado.
				DoubleNode<T>* nodeLast = nodePreviousLast->next;
				nodePreviousLast->next = nullptr;
				delete nodeLast;
				length--;
			}
		}
	}

	T GetFirst() {
		DoubleNode<T>* first = NodeAt(0);
		return first != nullptr ? first->data : T();
	}

	T GetPos(int pos) {
		DoubleNode<T>* node = NodeAt(pos);
		return node != nullptr ? node->data : T();
	}

	T GetLast() {
		DoubleNode<T>* last = NodeAt(length - 1);
		return last != nullptr ? last->data : T();
	}
	
};
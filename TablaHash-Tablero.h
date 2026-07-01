#pragma once
#include <iostream>

template <typename Clave, typename Valor>
struct NodoHash {
    Clave clave; //titulo
    Valor valor; //ID
    NodoHash<Clave, Valor>* siguiente;

    NodoHash(Clave c, Valor v) : clave(c), valor(v), siguiente(nullptr) {}
};

template <typename Clave, typename Valor>
struct Lista {
    NodoHash<Clave, Valor>* cabeza;

    Lista() : cabeza(nullptr) {}

    // Inserta al inicio o actualiza
    void insertar(const Clave& clave, const Valor& valor) {
        NodoHash<Clave, Valor>* actual = cabeza;
        while (actual) {
            if (actual->clave == clave) {
                actual->valor = valor;  // actualiza
                return;
            }
            actual = actual->siguiente;
        }
        // No existe -> inserta al inicio
        NodoHash<Clave, Valor>* nuevo = new NodoHash<Clave, Valor>(clave, valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Retorna el valor o "noEncontrado" si no existe
    Valor buscar(const Clave& clave, const Valor& noEncontrado = Valor()) {
        NodoHash<Clave, Valor>* actual = cabeza;
        while (actual) {
            if (actual->clave == clave)
                return actual->valor;
            actual = actual->siguiente;
        }
        return noEncontrado;
    }

    // Elimina un nodo por clave
    bool eliminar(const Clave& clave) {
        if (!cabeza) return false;

        if (cabeza->clave == clave) {
            NodoHash<Clave, Valor>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        NodoHash<Clave, Valor>* anterior = cabeza;
        while (anterior->siguiente) {
            if (anterior->siguiente->clave == clave) {
                NodoHash<Clave, Valor>* temp = anterior->siguiente;
                anterior->siguiente = temp->siguiente;
                delete temp;
                return true;
            }
            anterior = anterior->siguiente;
        }
        return false;
    }

    // Libera toda la lista
    void limpiar() {
        while (cabeza) {
            NodoHash<Clave, Valor>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    // Imprime los nodos de esta lista
    void imprimir() {
        NodoHash<Clave, Valor>* actual = cabeza;
        while (actual) {
            std::cout << "[" << actual->clave << " \t--> " << actual->valor << "] ";
            actual = actual->siguiente;
        }
    }
};
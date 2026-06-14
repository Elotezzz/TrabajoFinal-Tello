#pragma once
#include <iostream>

struct Nodo {
    std::string titulo;
    std::string ID;
    Nodo* siguiente;

    Nodo(std::string n, std::string c) : titulo(n), ID(c), siguiente(nullptr) {}
};

struct Lista {
    Nodo* cabeza;

    Lista() : cabeza(nullptr) {}

    // Inserta al inicio o actualiza
    void insertar(const std::string& titulo, const std::string& ID) {
        Nodo* actual = cabeza;
        // Busca si existe el titulo y lo actualiza
        while (actual) {
            if (actual->titulo == titulo) {
                actual->ID = ID;  // actualiza
                return;
            }
            actual = actual->siguiente;
        }
        //Si  No existe → inserta al inicio
        Nodo* nuevo = new Nodo(titulo, ID);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Retorna ID o mensaje de error
    std::string buscar(const std::string& titulo) {
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->titulo == titulo)
                return actual->ID;
            actual = actual->siguiente;
        }


        return "No encontrado";



    }

    // Elimina un nodo por titulo
    bool eliminar(const std::string& titulo) {
        if (!cabeza) return false;

        // Caso especial: es la cabeza
        if (cabeza->titulo == titulo) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        // Caso general: busca el nodo anterior
        Nodo* anterior = cabeza;
        while (anterior->siguiente) {
            if (anterior->siguiente->titulo == titulo) {
                Nodo* temp = anterior->siguiente;
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
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    // Imprime los nodos de esta lista
    void imprimir() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << "[" << actual->titulo << " --> " << actual->ID << "] ";
            actual = actual->siguiente;
        }
    }
};
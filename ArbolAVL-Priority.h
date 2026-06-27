#pragma once
#include <iostream>

template <typename T>
struct NodoAVL {
    T* dato;
    NodoAVL<T>* izquierda;
    NodoAVL<T>* derecha;
    int altura;   // altura del subárbol con raíz en este nodo (una hoja vale 1)

    NodoAVL(T* d) : dato(d), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

template <typename T>
void DestruirArbol(NodoAVL<T>* raiz) {
    if (raiz == nullptr) return;
    DestruirArbol(raiz->izquierda);
    DestruirArbol(raiz->derecha);
    delete raiz;
}

template <typename T>
void ImprimirSubarbol(NodoAVL<T>* nodo, const std::string& prefijo, bool esDerecha) {
    if (nodo == nullptr) return;
    ImprimirSubarbol(nodo->derecha, prefijo + (esDerecha ? "    " : "|   "), true);
    std::cout << prefijo << "|---" << nodo->dato << "\n";
    ImprimirSubarbol(nodo->izquierda, prefijo + (esDerecha ? "|   " : "    "), false);
}
template <typename T>
void ImprimirArbol(NodoAVL<T>* raiz) {
    if (raiz == nullptr) {
        std::cout << "Arbol vacio\n";
        return;
    }
    ImprimirSubarbol(raiz->derecha, "", true);
    std::cout << raiz->dato << "\n";
    ImprimirSubarbol(raiz->izquierda, "", false);
}

template <typename T>
int Altura(NodoAVL<T>* nodo) {
    return (nodo == nullptr) ? 0 : nodo->altura;
}

template <typename T>
void ActualizarAltura(NodoAVL<T>* nodo) {
    int hi = Altura(nodo->izquierda);
    int hd = Altura(nodo->derecha);
    nodo->altura = 1 + (hi > hd ? hi : hd);
}

template <typename T>
int FactorBalance(NodoAVL<T>* nodo) {
    if (nodo == nullptr) return 0;
    return Altura(nodo->derecha) - Altura(nodo->izquierda);
}

template <typename T>
NodoAVL<T>* RotarDerecha(NodoAVL<T>* b) {
    NodoAVL<T>* a = b->izquierda;
    NodoAVL<T>* T2 = a->derecha;
    a->derecha = b;
    b->izquierda = T2;
    ActualizarAltura(b);
    ActualizarAltura(a);
    return a;
}

template <typename T>
NodoAVL<T>* RotarIzquierda(NodoAVL<T>* a) {
    NodoAVL<T>* b = a->derecha;
    NodoAVL<T>* T2 = b->izquierda;
    b->izquierda = a;
    a->derecha = T2;
    ActualizarAltura(a);
    ActualizarAltura(b);
    return b;
}

template <typename T>
NodoAVL<T>* Rebalancear(NodoAVL<T>* nodo) {
    ActualizarAltura(nodo);
    int balance = FactorBalance(nodo);

    if (balance < -1) {                                // pesado a la izquierda
        if (FactorBalance(nodo->izquierda) > 0)         // caso LR
            nodo->izquierda = RotarIzquierda(nodo->izquierda);
        return RotarDerecha(nodo);                      // caso LL
    }
    if (balance > 1) {                                  // pesado a la derecha
        if (FactorBalance(nodo->derecha) < 0)           // caso RL
            nodo->derecha = RotarDerecha(nodo->derecha);
        return RotarIzquierda(nodo);                    // caso RR
    }
    return nodo;
}

template <typename T>
NodoAVL<T>* Insertar(NodoAVL<T>* raiz, T* nuevoDato) {
    if (raiz == nullptr) {
        return new NodoAVL<T>(nuevoDato);
    }
    if (nuevoDato->getPrioridad() < raiz->dato->getPrioridad()) {
        raiz->izquierda = Insertar(raiz->izquierda, nuevoDato);
    }
    else if (nuevoDato->getPrioridad() > raiz->dato->getPrioridad()) {
        raiz->derecha = Insertar(raiz->derecha, nuevoDato);
    }
    else {
        return raiz; // no se insertan repetidos
    }
    return Rebalancear(raiz);
}

template <typename T>
NodoAVL<T>* Buscar(NodoAVL<T>* raiz, int valor) {
    if (raiz == nullptr) return nullptr;
    if (raiz->dato->getPrioridad() == valor) return raiz;
    if (valor < raiz->dato->getPrioridad())
        return Buscar(raiz->izquierda, valor);
    else
        return Buscar(raiz->derecha, valor);
}

template <typename T>
NodoAVL<T>* minimo(NodoAVL<T>* raiz) {
    if (raiz == nullptr) return nullptr;
    NodoAVL<T>* actual = raiz;
    while (actual->izquierda != nullptr) actual = actual->izquierda;
    return actual;
}

template <typename T>
NodoAVL<T>* maximo(NodoAVL<T>* raiz) {
    if (raiz == nullptr) return nullptr;
    NodoAVL<T>* actual = raiz;
    while (actual->derecha != nullptr) actual = actual->derecha;
    return actual;
}
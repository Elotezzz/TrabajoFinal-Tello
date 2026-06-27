#include "ArbolAVL-Priority.h"

using namespace std;

// Esto permite destruir / sacar de memoria los nodos creados. Se comienza con los hijos y luego
// se elimina el nodo padre, para así evitar que se pierdan referencias.
void DestruirArbol(NodoAVL* raiz) {
    if (raiz == nullptr)
        return;
    // Se parece al postorder
    DestruirArbol(raiz->izquierda);
    DestruirArbol(raiz->derecha);
    delete raiz;
}

void ImprimirSubarbol(NodoAVL* nodo, const std::string& prefijo, bool esDerecha) {
    if (nodo == nullptr) return;

    // Subárbol derecho primero (se dibuja arriba)
    ImprimirSubarbol(nodo->derecha, prefijo + (esDerecha ? "    " : "|   "), true);

    // Nodo actual
    cout << prefijo << "|---" << nodo->tarjeta << "\n";

    // Subárbol izquierdo después (se dibuja abajo)
    ImprimirSubarbol(nodo->izquierda, prefijo + (esDerecha ? "|   " : "    "), false);
}

void ImprimirArbol(NodoAVL* raiz) {
    if (raiz == nullptr) {
        cout << "Arbol vacio\n";
        return;
    }
    ImprimirSubarbol(raiz->derecha, "", true);   // arriba
    cout << raiz->tarjeta << "\n";             // raíz inicial
    ImprimirSubarbol(raiz->izquierda, "", false); // abajo
}

// ---- NUEVO: utilidades de altura y balance para el AVL ----

// Lee la altura guardada en el nodo (O(1)). Un nullptr tiene altura 0.
int Altura(NodoAVL* nodo) {
    return (nodo == nullptr) ? 0 : nodo->altura;
}

// Recalcula y guarda la altura de un nodo a partir de la de sus hijos.
void ActualizarAltura(NodoAVL* nodo) {
    int hi = Altura(nodo->izquierda);
    int hd = Altura(nodo->derecha);
    nodo->altura = 1 + (hi > hd ? hi : hd);
}

// Factor de balance = altura(derecha) - altura(izquierda).
// Si está fuera del rango [-1, 1], el nodo está desbalanceado.
int FactorBalance(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return Altura(nodo->derecha) - Altura(nodo->izquierda);
}

// ---- NUEVO: rotaciones ----

NodoAVL* RotarDerecha(NodoAVL* b) {
    NodoAVL* a = b->izquierda;
    NodoAVL* T2 = a->derecha;

    a->derecha = b;
    b->izquierda = T2;

    ActualizarAltura(b);
    ActualizarAltura(a);
    return a;
}

NodoAVL* RotarIzquierda(NodoAVL* a) {
    NodoAVL* b = a->derecha;
    NodoAVL* T2 = b->izquierda;

    b->izquierda = a;
    a->derecha = T2;

    ActualizarAltura(a);
    ActualizarAltura(b);
    return b;
}

// ---- NUEVO: reequilibrio (concentra los 4 casos LL, RR, LR, RL) ----

NodoAVL* Rebalancear(NodoAVL* nodo) {
    ActualizarAltura(nodo);
    int balance = FactorBalance(nodo);

    // Pesado a la izquierda
    if (balance < -1) {
        if (FactorBalance(nodo->izquierda) > 0)        // caso LR
            nodo->izquierda = RotarIzquierda(nodo->izquierda);
        return RotarDerecha(nodo);                     // caso LL (y cierre del LR)
    }
    // Pesado a la derecha
    if (balance > 1) {
        if (FactorBalance(nodo->derecha) < 0)          // caso RL
            nodo->derecha = RotarDerecha(nodo->derecha);
        return RotarIzquierda(nodo);                   // caso RR (y cierre del RL)
    }
    return nodo;   // ya estaba balanceado
}

// ---- MODIFICADO: ahora reequilibra al volver de la recursión ----

NodoAVL* Insertar(NodoAVL* raiz, Tarjeta* nuevaTarjeta) {
    if (raiz == nullptr) {
        return new NodoAVL(nuevaTarjeta);
    }
    if (nuevaTarjeta->getPrioridad() < raiz->tarjeta->getPrioridad()) {
        raiz->izquierda = Insertar(raiz->izquierda, nuevaTarjeta);
    }
    else if (nuevaTarjeta->getPrioridad() > raiz->tarjeta->getPrioridad()) {
        raiz->derecha = Insertar(raiz->derecha, nuevaTarjeta);
    }
    else {
        // En este ejemplo no se inserta repetidos.
        return raiz;
    }
    return Rebalancear(raiz);   // ÚNICO cambio de fondo respecto al ABB
}

NodoAVL* Buscar(NodoAVL* raiz, int valor) {
    if (raiz == nullptr) {
        return nullptr;
    }
    if (raiz->tarjeta->getPrioridad() == valor) {
        return raiz;
    }
    if (valor < raiz->tarjeta->getPrioridad()) {
        return Buscar(raiz->izquierda, valor);
    }
    else {
        return Buscar(raiz->derecha, valor);
    }
}

NodoAVL* minimo(NodoAVL* raiz) {
    if (raiz == nullptr) return nullptr;
    NodoAVL* actual = raiz;
    while (actual->izquierda != nullptr)
        actual = actual->izquierda;
    return actual;
}

NodoAVL* maximo(NodoAVL* raiz) {
    if (raiz == nullptr) return nullptr;
    NodoAVL* actual = raiz;
    while (actual->derecha != nullptr)
        actual = actual->derecha;
    return actual;
}
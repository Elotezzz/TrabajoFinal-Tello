#pragma once
#include <iostream>
#include "Tarjeta.h"

struct NodoAVL {
    Tarjeta* tarjeta;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;   // NUEVO: altura del subárbol con raíz en este nodo (una hoja vale 1)

    NodoAVL(Tarjeta* t) : tarjeta(t), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

// Prototipos de las funciones (Declaraciones)
void DestruirArbol(NodoAVL* raiz);
void ImprimirSubarbol(NodoAVL* nodo, const std::string& prefijo, bool esDerecha);
void ImprimirArbol(NodoAVL* raiz);

// ---- NUEVO: utilidades de altura y balance para el AVL ----
int Altura(NodoAVL* nodo);
void ActualizarAltura(NodoAVL* nodo);
int FactorBalance(NodoAVL* nodo);

// ---- NUEVO: rotaciones ----
NodoAVL* RotarDerecha(NodoAVL* b);
NodoAVL* RotarIzquierda(NodoAVL* a);

// ---- NUEVO: reequilibrio (concentra los 4 casos LL, RR, LR, RL) ----
NodoAVL* Rebalancear(NodoAVL* nodo);

// ---- MODIFICADO: ahora reequilibra al volver de la recursión ----
NodoAVL* Insertar(NodoAVL* raiz, Tarjeta* nuevaTarjeta);
NodoAVL* Buscar(NodoAVL* raiz, int valor);
NodoAVL* minimo(NodoAVL* raiz);
NodoAVL* maximo(NodoAVL* raiz);
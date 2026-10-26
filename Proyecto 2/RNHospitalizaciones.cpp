#include "RNHospitalizaciones.h"
#include <iostream>

RNHospitalizaciones::RNHospitalizaciones() {
    raiz = nullptr;
}

void RNHospitalizaciones::rotarIzquierda(NodoHospitalizaciones*& raizArbol, NodoHospitalizaciones*& ptr) {
    NodoHospitalizaciones* ptr_der = ptr->der;
    ptr->der = ptr_der->izq;
    if (ptr->der != nullptr) {
        ptr->der->padre = ptr;
    }
    ptr_der->padre = ptr->padre;
    if (ptr->padre == nullptr) {
        raizArbol = ptr_der;
    }
    else {
        if (ptr == ptr->padre->izq) {
            ptr->padre->izq = ptr_der;
        }
        else {
            ptr->padre->der = ptr_der;
        }
    }
    ptr_der->izq = ptr;
    ptr->padre = ptr_der;
}

void RNHospitalizaciones::rotarDerecha(NodoHospitalizaciones*& raizArbol, NodoHospitalizaciones*& ptr) {
    NodoHospitalizaciones* ptr_izq = ptr->izq;
    ptr->izq = ptr_izq->der;
    if (ptr->izq != nullptr) {
        ptr->izq->padre = ptr;
    }
    ptr_izq->padre = ptr->padre;
    if (ptr->padre == nullptr) {
        raizArbol = ptr_izq;
    }
    else {
        if (ptr == ptr->padre->izq) {
            ptr->padre->izq = ptr_izq;
        }
        else {
            ptr->padre->der = ptr_izq;
        }
    }
    ptr_izq->der = ptr;
    ptr->padre = ptr_izq;
}

void RNHospitalizaciones::corregirInsercion(NodoHospitalizaciones*& raizArbol, NodoHospitalizaciones*& nodoActual) {
    NodoHospitalizaciones* padreNodo = nullptr;
    NodoHospitalizaciones* abueloNodo = nullptr;
    while ((nodoActual != raizArbol) && (nodoActual->color != NEGRO) && (nodoActual->padre->color == ROJO)) {
        padreNodo = nodoActual->padre;
        abueloNodo = nodoActual->padre->padre;
        if (padreNodo == abueloNodo->izq) {
            NodoHospitalizaciones* tioNodo = abueloNodo->der;
            if (tioNodo != nullptr && tioNodo->color == ROJO) {
                abueloNodo->color = ROJO;
                padreNodo->color = NEGRO;
                tioNodo->color = NEGRO;
                nodoActual = abueloNodo;
            }
            else {
                if (nodoActual == padreNodo->der) {
                    rotarIzquierda(raizArbol, padreNodo);
                    nodoActual = padreNodo;
                    padreNodo = nodoActual->padre;
                }
                rotarDerecha(raizArbol, abueloNodo);
                ColorNodo colorTemporal = padreNodo->color;
                padreNodo->color = abueloNodo->color;
                abueloNodo->color = colorTemporal;
                nodoActual = padreNodo;
            }
        }
        else {
            NodoHospitalizaciones* tioNodo = abueloNodo->izq;
            if (tioNodo != nullptr && tioNodo->color == ROJO) {
                abueloNodo->color = ROJO;
                padreNodo->color = NEGRO;
                tioNodo->color = NEGRO;
                nodoActual = abueloNodo;
            }
            else {
                if (nodoActual == padreNodo->izq) {
                    rotarDerecha(raizArbol, padreNodo);
                    nodoActual = padreNodo;
                    padreNodo = nodoActual->padre;
                }
                rotarIzquierda(raizArbol, abueloNodo);
                ColorNodo colorTemporal = padreNodo->color;
                padreNodo->color = abueloNodo->color;
                abueloNodo->color = colorTemporal;
                nodoActual = padreNodo;
            }
        }
    }
    raizArbol->color = NEGRO;
}

void RNHospitalizaciones::insertar(string clave, Hospitalizaciones dato) {
    NodoHospitalizaciones* nuevoNodo = new NodoHospitalizaciones(clave, dato);
    if (raiz == nullptr) {
        nuevoNodo->color = NEGRO;
        raiz = nuevoNodo;
        return;
    }
    NodoHospitalizaciones* nodoActual = raiz;
    NodoHospitalizaciones* padreNodo = nullptr;
    while (nodoActual != nullptr) {
        padreNodo = nodoActual;
        if (clave < nodoActual->clave) {
            nodoActual = nodoActual->izq;
        }
        else {
            if (clave > nodoActual->clave) {
                nodoActual = nodoActual->der;
            }
            else {
                cout << "Elemento repetido (Hospitalización): " << clave << endl;
                delete nuevoNodo;
                return;
            }
        }
    }
    nuevoNodo->padre = padreNodo;
    if (clave < padreNodo->clave) {
        padreNodo->izq = nuevoNodo;
    }
    else {
        padreNodo->der = nuevoNodo;
    }
    corregirInsercion(raiz, nuevoNodo);
}

NodoHospitalizaciones* RNHospitalizaciones::buscarRec(NodoHospitalizaciones* nodoActual, string clave) {
    if (nodoActual == nullptr || nodoActual->clave == clave) {
        return nodoActual;
    }
    if (clave < nodoActual->clave) {
        return buscarRec(nodoActual->izq, clave);
    }
    else {
        return buscarRec(nodoActual->der, clave);
    }
}

Hospitalizaciones* RNHospitalizaciones::buscar(string clave) {
    NodoHospitalizaciones* resultado = buscarRec(raiz, clave);
    if (resultado != nullptr) {
        return &(resultado->dato);
    }
    else {
        return nullptr;
    }
}
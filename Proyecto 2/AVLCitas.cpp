#include "AVLCitas.h"
#include <iostream>

AVLCitas::AVLCitas() {
    raiz = nullptr;
}

int AVLCitas::obtenerAltura(NodoCitas* nodo) {
    if (nodo != nullptr) {
        return nodo->altura;
    }
    else {
        return 0;
    }
}

int AVLCitas::obtenerBalance(NodoCitas* nodo) {
    if (nodo != nullptr) {
        return obtenerAltura(nodo->izq) - obtenerAltura(nodo->der);
    }
    else {
        return 0;
    }
}

int obtenerMaximo(int valorA, int valorB) {
    if (valorA > valorB) {
        return valorA;
    }
    else {
        return valorB;
    }
}

NodoCitas* AVLCitas::rotarDerecha(NodoCitas* nodoY) {
    NodoCitas* nodoX = nodoY->izq;
    NodoCitas* subArbolTemp = nodoX->der;
    nodoX->der = nodoY;
    nodoY->izq = subArbolTemp;
    nodoY->altura = obtenerMaximo(obtenerAltura(nodoY->izq), obtenerAltura(nodoY->der)) + 1;
    nodoX->altura = obtenerMaximo(obtenerAltura(nodoX->izq), obtenerAltura(nodoX->der)) + 1;
    return nodoX;
}

NodoCitas* AVLCitas::rotarIzquierda(NodoCitas* nodoX) {
    NodoCitas* nodoY = nodoX->der;
    NodoCitas* subArbolTemp = nodoY->izq;
    nodoY->izq = nodoX;
    nodoX->der = subArbolTemp;
    nodoX->altura = obtenerMaximo(obtenerAltura(nodoX->izq), obtenerAltura(nodoX->der)) + 1;
    nodoY->altura = obtenerMaximo(obtenerAltura(nodoY->izq), obtenerAltura(nodoY->der)) + 1;
    return nodoY;
}

NodoCitas* AVLCitas::insertarRec(NodoCitas* nodoActual, string clave, Citas dato) {
    if (nodoActual == nullptr) {
        return new NodoCitas(clave, dato);
    }
    if (clave < nodoActual->clave) {
        nodoActual->izq = insertarRec(nodoActual->izq, clave, dato);
    }
    else {
        if (clave > nodoActual->clave) {
            nodoActual->der = insertarRec(nodoActual->der, clave, dato);
        }
        else {
            cout << "Elemento repetido (Cita): " << clave << endl;
            return nodoActual;
        }
    }

    nodoActual->altura = 1 + obtenerMaximo(obtenerAltura(nodoActual->izq), obtenerAltura(nodoActual->der));
    int factorBalance = obtenerBalance(nodoActual);

    if (factorBalance > 1) {
        if (clave < nodoActual->izq->clave) {
            return rotarDerecha(nodoActual);
        }
        else {
            nodoActual->izq = rotarIzquierda(nodoActual->izq);
            return rotarDerecha(nodoActual);
        }
    }
    if (factorBalance < -1) {
        if (clave > nodoActual->der->clave) {
            return rotarIzquierda(nodoActual);
        }
        else {
            nodoActual->der = rotarDerecha(nodoActual->der);
            return rotarIzquierda(nodoActual);
        }
    }

    return nodoActual;
}

void AVLCitas::insertar(string clave, Citas dato) {
    raiz = insertarRec(raiz, clave, dato);
}

NodoCitas* AVLCitas::buscarRec(NodoCitas* nodoActual, string clave) {
    if (nodoActual == nullptr) {
        return nullptr;
    }
    if (nodoActual->clave == clave) {
        return nodoActual;
    }
    if (clave < nodoActual->clave) {
        return buscarRec(nodoActual->izq, clave);
    }
    else {
        return buscarRec(nodoActual->der, clave);
    }
}

Citas* AVLCitas::buscar(string clave) {
    NodoCitas* resultado = buscarRec(raiz, clave);
    if (resultado != nullptr) {
        return &(resultado->dato);
    }
    else {
        return nullptr;
    }
}
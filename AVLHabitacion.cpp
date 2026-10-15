#include "AVLHabitacion.h"

AVLHabitacion::AVLHabitacion() {
    raiz = nullptr;
}
int AVLHabitacion::obtenerAltura(NodoHabitacion* nodo) {
    if (nodo == nullptr)
        return 0;
    return nodo->altura;
}
int AVLHabitacion::calcularMaximo(int alturaIzquierda, int alturaDerecha) {
    if (alturaIzquierda > alturaDerecha) {
        return alturaIzquierda;
    }
    return alturaDerecha;
}
int AVLHabitacion::obtenerBalance(NodoHabitacion* nodo) {
    if (nodo == nullptr)
        return 0;
    return obtenerAltura(nodo->Hizq) - obtenerAltura(nodo->Hder);
}
NodoHabitacion* AVLHabitacion::rotacionDerecha(NodoHabitacion* nodoDesbalanceado) {
    NodoHabitacion* nodoHijoIzquierdo = nodoDesbalanceado->Hizq;
    NodoHabitacion* subArbolTemporal = nodoHijoIzquierdo->Hder;
    nodoHijoIzquierdo->Hder = nodoDesbalanceado;
    nodoDesbalanceado->Hizq = subArbolTemporal;
    nodoDesbalanceado->altura = calcularMaximo(obtenerAltura(nodoDesbalanceado->Hizq), obtenerAltura(nodoDesbalanceado->Hder)) + 1;
    nodoHijoIzquierdo->altura = calcularMaximo(obtenerAltura(nodoHijoIzquierdo->Hizq), obtenerAltura(nodoHijoIzquierdo->Hder)) + 1;
    return nodoHijoIzquierdo;
}

NodoHabitacion* AVLHabitacion::rotacionIzquierda(NodoHabitacion* nodoDesbalanceado) {
    NodoHabitacion* nodoHijoDerecho = nodoDesbalanceado->Hder;
    NodoHabitacion* subArbolTemporal = nodoHijoDerecho->Hizq;
    nodoHijoDerecho->Hizq = nodoDesbalanceado;
    nodoDesbalanceado->Hder = subArbolTemporal;
    nodoDesbalanceado->altura = calcularMaximo(obtenerAltura(nodoDesbalanceado->Hizq), obtenerAltura(nodoDesbalanceado->Hder)) + 1;
    nodoHijoDerecho->altura = calcularMaximo(obtenerAltura(nodoHijoDerecho->Hizq), obtenerAltura(nodoHijoDerecho->Hder)) + 1;
    return nodoHijoDerecho;
}

NodoHabitacion* AVLHabitacion::insertarRecursivo(NodoHabitacion* nodoActual, Habitacion pHabitacion, bool& fueInsertado) {
    if (nodoActual == nullptr) {
        fueInsertado = true;
        return new NodoHabitacion(pHabitacion);
    }

    if (pHabitacion.getIdHabitacion() < nodoActual->valor.getIdHabitacion()) {
        nodoActual->Hizq = insertarRecursivo(nodoActual->Hizq, pHabitacion, fueInsertado);
    }
    else if (pHabitacion.getIdHabitacion() > nodoActual->valor.getIdHabitacion()) {
        nodoActual->Hder = insertarRecursivo(nodoActual->Hder, pHabitacion, fueInsertado);
    }
    else {
        fueInsertado = false;
        return nodoActual;
    }
    nodoActual->altura = 1 + calcularMaximo(obtenerAltura(nodoActual->Hizq), obtenerAltura(nodoActual->Hder));
    int factorBalance = obtenerBalance(nodoActual);
    if (factorBalance > 1 && pHabitacion.getIdHabitacion() < nodoActual->Hizq->valor.getIdHabitacion()) {
        return rotacionDerecha(nodoActual);
    }
    if (factorBalance < -1 && pHabitacion.getIdHabitacion() > nodoActual->Hder->valor.getIdHabitacion()) {
        return rotacionIzquierda(nodoActual);
    }
    if (factorBalance > 1 && pHabitacion.getIdHabitacion() > nodoActual->Hizq->valor.getIdHabitacion()) {
        nodoActual->Hizq = rotacionIzquierda(nodoActual->Hizq);
        return rotacionDerecha(nodoActual);
    }
    if (factorBalance < -1 && pHabitacion.getIdHabitacion() < nodoActual->Hder->valor.getIdHabitacion()) {
        nodoActual->Hder = rotacionDerecha(nodoActual->Hder);
        return rotacionIzquierda(nodoActual);
    }

    return nodoActual;
}

void AVLHabitacion::InsertaNodo(Habitacion pHabitacion) {
    bool fueInsertado = false;
    raiz = insertarRecursivo(raiz, pHabitacion, fueInsertado);
}

bool AVLHabitacion::BuscarHabitacion(int idHabitacion) {
    NodoHabitacion* nodoActual = raiz;
    while (nodoActual != nullptr) {
        if (idHabitacion == nodoActual->valor.getIdHabitacion()) {
            return true;
        }
        if (idHabitacion < nodoActual->valor.getIdHabitacion()) {
            nodoActual = nodoActual->Hizq;
        }
        else {
            nodoActual = nodoActual->Hder;
        }
    }
    return false;
}
Habitacion* AVLHabitacion::ObtenerHabitacion(int idHabitacion) {
    NodoHabitacion* nodoActual = raiz;
    while (nodoActual != nullptr) {
        if (idHabitacion == nodoActual->valor.getIdHabitacion()) {
            return &(nodoActual->valor);
        }
        else if (idHabitacion < nodoActual->valor.getIdHabitacion()) {
            nodoActual = nodoActual->Hizq;
        }
        else {
            nodoActual = nodoActual->Hder;
        }
    }
    return nullptr;
}
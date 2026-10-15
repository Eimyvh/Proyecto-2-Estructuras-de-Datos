#include "RNTratamiento.h"

RNTratamiento::RNTratamiento() {
    nodoNuloHoja = new NodoTratamiento(Tratamiento(0, "", "", 0.0));
    nodoNuloHoja->color = 1;
    nodoNuloHoja->Hizq = nullptr;
    nodoNuloHoja->Hder = nullptr;
    raiz = nodoNuloHoja;
}

void RNTratamiento::rotacionIzquierda(NodoTratamiento* nodoDesbalanceado) {
    NodoTratamiento* nodoHijoDerecho = nodoDesbalanceado->Hder;
    nodoDesbalanceado->Hder = nodoHijoDerecho->Hizq;

    if (nodoHijoDerecho->Hizq != nodoNuloHoja) {
        nodoHijoDerecho->Hizq->padre = nodoDesbalanceado;
    }

    nodoHijoDerecho->padre = nodoDesbalanceado->padre;

    if (nodoDesbalanceado->padre == nullptr) {
        raiz = nodoHijoDerecho;
    }
    else if (nodoDesbalanceado == nodoDesbalanceado->padre->Hizq) {
        nodoDesbalanceado->padre->Hizq = nodoHijoDerecho;
    }
    else {
        nodoDesbalanceado->padre->Hder = nodoHijoDerecho;
    }

    nodoHijoDerecho->Hizq = nodoDesbalanceado;
    nodoDesbalanceado->padre = nodoHijoDerecho;
}

void RNTratamiento::rotacionDerecha(NodoTratamiento* nodoDesbalanceado) {
    NodoTratamiento* nodoHijoIzquierdo = nodoDesbalanceado->Hizq;
    nodoDesbalanceado->Hizq = nodoHijoIzquierdo->Hder;

    if (nodoHijoIzquierdo->Hder != nodoNuloHoja) {
        nodoHijoIzquierdo->Hder->padre = nodoDesbalanceado;
    }

    nodoHijoIzquierdo->padre = nodoDesbalanceado->padre;

    if (nodoDesbalanceado->padre == nullptr) {
        raiz = nodoHijoIzquierdo;
    }
    else if (nodoDesbalanceado == nodoDesbalanceado->padre->Hder) {
        nodoDesbalanceado->padre->Hder = nodoHijoIzquierdo;
    }
    else {
        nodoDesbalanceado->padre->Hizq = nodoHijoIzquierdo;
    }

    nodoHijoIzquierdo->Hder = nodoDesbalanceado;
    nodoDesbalanceado->padre = nodoHijoIzquierdo;
}

void RNTratamiento::corregirInsercion(NodoTratamiento* nodoActual) {
    NodoTratamiento* nodoTio = nullptr;

    while (nodoActual->padre != nullptr && nodoActual->padre->color == 0) {
        if (nodoActual->padre == nodoActual->padre->padre->Hizq) {
            nodoTio = nodoActual->padre->padre->Hder;
            if (nodoTio != nullptr && nodoTio->color == 0) {
                nodoActual->padre->color = 1;
                nodoTio->color = 1;
                nodoActual->padre->padre->color = 0;
                nodoActual = nodoActual->padre->padre;
            }
            else {
                if (nodoActual == nodoActual->padre->Hder) {
                    nodoActual = nodoActual->padre;
                    rotacionIzquierda(nodoActual);
                }
                nodoActual->padre->color = 1;
                nodoActual->padre->padre->color = 0;
                rotacionDerecha(nodoActual->padre->padre);
            }
        }
        else {
            nodoTio = nodoActual->padre->padre->Hizq;
            if (nodoTio != nullptr && nodoTio->color == 0) {
                nodoActual->padre->color = 1;
                nodoTio->color = 1;
                nodoActual->padre->padre->color = 0;
                nodoActual = nodoActual->padre->padre;
            }
            else {
                if (nodoActual == nodoActual->padre->Hizq) {
                    nodoActual = nodoActual->padre;
                    rotacionDerecha(nodoActual);
                }
                nodoActual->padre->color = 1;
                nodoActual->padre->padre->color = 0;
                rotacionIzquierda(nodoActual->padre->padre);
            }
        }
    }
    raiz->color = 1;
}

void RNTratamiento::InsertaNodo(Tratamiento pTratamiento) {
    if (BuscarTratamiento(pTratamiento.getIdTratamiento())) {
        return;
    }

    NodoTratamiento* nuevoNodo = new NodoTratamiento(pTratamiento);
    nuevoNodo->Hizq = nodoNuloHoja;
    nuevoNodo->Hder = nodoNuloHoja;
    nuevoNodo->padre = nullptr;

    NodoTratamiento* nodoPadreAuxiliar = nullptr;
    NodoTratamiento* nodoActual = raiz;

    while (nodoActual != nodoNuloHoja) {
        nodoPadreAuxiliar = nodoActual;
        if (nuevoNodo->valor.getIdTratamiento() < nodoActual->valor.getIdTratamiento()) {
            nodoActual = nodoActual->Hizq;
        }
        else {
            nodoActual = nodoActual->Hder;
        }
    }

    nuevoNodo->padre = nodoPadreAuxiliar;

    if (nodoPadreAuxiliar == nullptr) {
        raiz = nuevoNodo;
    }
    else if (nuevoNodo->valor.getIdTratamiento() < nodoPadreAuxiliar->valor.getIdTratamiento()) {
        nodoPadreAuxiliar->Hizq = nuevoNodo;
    }
    else {
        nodoPadreAuxiliar->Hder = nuevoNodo;
    }

    if (nuevoNodo->padre == nullptr) {
        nuevoNodo->color = 1;
        return;
    }

    if (nuevoNodo->padre->padre == nullptr) {
        return;
    }

    corregirInsercion(nuevoNodo);
}

NodoTratamiento* RNTratamiento::buscarRecursivo(NodoTratamiento* nodoActual, int idTratamiento) {
    if (nodoActual == nodoNuloHoja || nodoActual == nullptr) {
        return nullptr;
    }
    if (idTratamiento == nodoActual->valor.getIdTratamiento()) {
        return nodoActual;
    }
    if (idTratamiento < nodoActual->valor.getIdTratamiento()) {
        return buscarRecursivo(nodoActual->Hizq, idTratamiento);
    }
    return buscarRecursivo(nodoActual->Hder, idTratamiento);
}

bool RNTratamiento::BuscarTratamiento(int idTratamiento) {
    NodoTratamiento* resultado = buscarRecursivo(raiz, idTratamiento);
    return (resultado != nullptr);
}

Tratamiento* RNTratamiento::ObtenerTratamiento(int idTratamiento) {
    NodoTratamiento* resultado = buscarRecursivo(raiz, idTratamiento);
    if (resultado != nullptr) {
        return &(resultado->valor);
    }
    return nullptr;
}
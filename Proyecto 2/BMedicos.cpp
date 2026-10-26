#include "BMedicos.h"
#include <iostream>

BMedicos::BMedicos() {
    raiz = nullptr;
}

void BMedicos::buscarNodo(string claveBusqueda, NodoMedicos* paginaActual, bool& encontrado, int& indiceRama) {
    if (claveBusqueda < paginaActual->claves[1].getIdMedico()) {
        encontrado = false;
        indiceRama = 0;
    }
    else {
        indiceRama = paginaActual->cuenta;
        while ((claveBusqueda < paginaActual->claves[indiceRama].getIdMedico()) && (indiceRama > 1)) {
            indiceRama = indiceRama - 1;
        }
        encontrado = (claveBusqueda == paginaActual->claves[indiceRama].getIdMedico());
    }
}

void BMedicos::insertar(string id, Medicos objetoMedico) {
    bool propagarDivision = false;
    Medicos claveMediana;
    NodoMedicos* nodoDerecho = nullptr;

    empujar(id, objetoMedico, raiz, propagarDivision, claveMediana, nodoDerecho);
    if (propagarDivision) {
        NodoMedicos* nuevaRaiz = new NodoMedicos();
        nuevaRaiz->cuenta = 1;
        nuevaRaiz->claves[1] = claveMediana;
        nuevaRaiz->ramas[0] = raiz;
        nuevaRaiz->ramas[1] = nodoDerecho;
        raiz = nuevaRaiz;
    }
}

void BMedicos::empujar(string claveAInsertar, Medicos objetoMedico, NodoMedicos* paginaActual, bool& propagarDivision, Medicos& claveMediana, NodoMedicos*& nodoDerecho) {
    if (paginaActual == nullptr) {
        propagarDivision = true;
        claveMediana = objetoMedico;
        nodoDerecho = nullptr;
    }
    else {
        bool estaRepetido = false;
        int indiceRama = 0;
        buscarNodo(claveAInsertar, paginaActual, estaRepetido, indiceRama);
        if (estaRepetido) {
            cout << "Elemento repetido (Médico): " << claveAInsertar << endl;
            propagarDivision = false;
            return;
        }
        empujar(claveAInsertar, objetoMedico, paginaActual->ramas[indiceRama], propagarDivision, claveMediana, nodoDerecho);
        if (propagarDivision) {
            if (paginaActual->cuenta < ORDEN_MEDICOS) {
                propagarDivision = false;
                meterHoja(claveMediana, nodoDerecho, paginaActual, indiceRama);
            }
            else {
                propagarDivision = true;
                dividirNodo(claveMediana, nodoDerecho, paginaActual, indiceRama, claveMediana, nodoDerecho);
            }
        }
    }
}

void BMedicos::meterHoja(Medicos medicoAInsertar, NodoMedicos* nodoHijoDerecho, NodoMedicos* paginaActual, int indiceRama) {
    for (int indice = paginaActual->cuenta; indice >= indiceRama + 1; indice--) {
        paginaActual->claves[indice + 1] = paginaActual->claves[indice];
        paginaActual->ramas[indice + 1] = paginaActual->ramas[indice];
    }
    paginaActual->claves[indiceRama + 1] = medicoAInsertar;
    paginaActual->ramas[indiceRama + 1] = nodoHijoDerecho;
    paginaActual->cuenta = paginaActual->cuenta + 1;
}

void BMedicos::dividirNodo(Medicos medicoAInsertar, NodoMedicos* nodoHijoDerecho, NodoMedicos* paginaActual, int indiceRama, Medicos& claveMediana, NodoMedicos*& nuevoNodoDerecho) {
    int limiteMinimo = ORDEN_MEDICOS / 2;
    int posicionMediana;
    if (indiceRama <= limiteMinimo) {
        posicionMediana = limiteMinimo;
    }
    else {
        posicionMediana = limiteMinimo + 1;
    }

    nuevoNodoDerecho = new NodoMedicos();

    for (int indice = posicionMediana + 1; indice <= ORDEN_MEDICOS; indice++) {
        nuevoNodoDerecho->claves[indice - posicionMediana] = paginaActual->claves[indice];
        nuevoNodoDerecho->ramas[indice - posicionMediana] = paginaActual->ramas[indice];
    }
    nuevoNodoDerecho->cuenta = ORDEN_MEDICOS - posicionMediana;
    paginaActual->cuenta = posicionMediana;

    if (indiceRama <= limiteMinimo) {
        meterHoja(medicoAInsertar, nodoHijoDerecho, paginaActual, indiceRama);
    }
    else {
        meterHoja(medicoAInsertar, nodoHijoDerecho, nuevoNodoDerecho, indiceRama - posicionMediana);
    }

    claveMediana = paginaActual->claves[paginaActual->cuenta];
    nuevoNodoDerecho->ramas[0] = paginaActual->ramas[paginaActual->cuenta];
    paginaActual->cuenta = paginaActual->cuenta - 1;
}

NodoMedicos* BMedicos::buscarRecursivo(string claveBusqueda, NodoMedicos* paginaActual) {
    if (paginaActual == nullptr) {
        return nullptr;
    }
    bool encontrada = false;
    int indiceRama = 0;
    buscarNodo(claveBusqueda, paginaActual, encontrada, indiceRama);
    if (encontrada) {
        return paginaActual;
    }
    return buscarRecursivo(claveBusqueda, paginaActual->ramas[indiceRama]);
}

Medicos* BMedicos::buscar(string id) {
    NodoMedicos* nodoEncontrado = buscarRecursivo(id, raiz);
    if (nodoEncontrado != nullptr) {
        for (int indice = 1; indice <= nodoEncontrado->cuenta; indice++) {
            if (nodoEncontrado->claves[indice].getIdMedico() == id) {
                return &(nodoEncontrado->claves[indice]);
            }
        }
    }
    return nullptr;
}
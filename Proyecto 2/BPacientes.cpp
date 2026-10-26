#include "BPacientes.h"
#include <iostream>

BPacientes::BPacientes() {
    raiz = nullptr;
}

void BPacientes::buscarNodo(string claveBusqueda, NodoPacientes* paginaActual, bool& encontrado, int& indiceRama) {
    if (claveBusqueda < paginaActual->claves[1].getIdPaciente()) {
        encontrado = false;
        indiceRama = 0;
    }
    else {
        indiceRama = paginaActual->cuenta;
        while ((claveBusqueda < paginaActual->claves[indiceRama].getIdPaciente()) && (indiceRama > 1)) {
            indiceRama = indiceRama - 1;
        }
        encontrado = (claveBusqueda == paginaActual->claves[indiceRama].getIdPaciente());
    }
}

void BPacientes::insertar(string id, Pacientes objetoPaciente) {
    bool propagarDivision = false;
    Pacientes claveMediana;
    NodoPacientes* nodoDerecho = nullptr;

    empujar(id, objetoPaciente, raiz, propagarDivision, claveMediana, nodoDerecho);
    if (propagarDivision) {
        NodoPacientes* nuevaRaiz = new NodoPacientes();
        nuevaRaiz->cuenta = 1;
        nuevaRaiz->claves[1] = claveMediana;
        nuevaRaiz->ramas[0] = raiz;
        nuevaRaiz->ramas[1] = nodoDerecho;
        raiz = nuevaRaiz;
    }
}

void BPacientes::empujar(string claveAInsertar, Pacientes objetoPaciente, NodoPacientes* paginaActual, bool& propagarDivision, Pacientes& claveMediana, NodoPacientes*& nodoDerecho) {
    if (paginaActual == nullptr) {
        propagarDivision = true;
        claveMediana = objetoPaciente;
        nodoDerecho = nullptr;
    }
    else {
        bool estaRepetido = false;
        int indiceRama = 0;
        buscarNodo(claveAInsertar, paginaActual, estaRepetido, indiceRama);

        if (estaRepetido) {
            cout << "Elemento repetido (Paciente): " << claveAInsertar << endl;
            propagarDivision = false;
            return;
        }

        empujar(claveAInsertar, objetoPaciente, paginaActual->ramas[indiceRama], propagarDivision, claveMediana, nodoDerecho);

        if (propagarDivision) {
            if (paginaActual->cuenta < ORDEN_PACIENTES) {
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

void BPacientes::meterHoja(Pacientes pacienteAInsertar, NodoPacientes* nodoHijoDerecho, NodoPacientes* paginaActual, int indiceRama) {
    for (int indice = paginaActual->cuenta; indice >= indiceRama + 1; indice--) {
        paginaActual->claves[indice + 1] = paginaActual->claves[indice];
        paginaActual->ramas[indice + 1] = paginaActual->ramas[indice];
    }
    paginaActual->claves[indiceRama + 1] = pacienteAInsertar;
    paginaActual->ramas[indiceRama + 1] = nodoHijoDerecho;
    paginaActual->cuenta = paginaActual->cuenta + 1;
}

void BPacientes::dividirNodo(Pacientes pacienteAInsertar, NodoPacientes* nodoHijoDerecho, NodoPacientes* paginaActual, int indiceRama, Pacientes& claveMediana, NodoPacientes*& nuevoNodoDerecho) {
    int limiteMinimo = ORDEN_PACIENTES / 2;
    int posicionMediana = (indiceRama <= limiteMinimo) ? limiteMinimo : limiteMinimo + 1;
    nuevoNodoDerecho = new NodoPacientes();

    for (int indice = posicionMediana + 1; indice <= ORDEN_PACIENTES; indice++) {
        nuevoNodoDerecho->claves[indice - posicionMediana] = paginaActual->claves[indice];
        nuevoNodoDerecho->ramas[indice - posicionMediana] = paginaActual->ramas[indice];
    }
    nuevoNodoDerecho->cuenta = ORDEN_PACIENTES - posicionMediana;
    paginaActual->cuenta = posicionMediana;

    if (indiceRama <= limiteMinimo) {
        meterHoja(pacienteAInsertar, nodoHijoDerecho, paginaActual, indiceRama);
    }
    else {
        meterHoja(pacienteAInsertar, nodoHijoDerecho, nuevoNodoDerecho, indiceRama - posicionMediana);
    }

    claveMediana = paginaActual->claves[paginaActual->cuenta];
    nuevoNodoDerecho->ramas[0] = paginaActual->ramas[paginaActual->cuenta];
    paginaActual->cuenta = paginaActual->cuenta - 1;
}

NodoPacientes* BPacientes::buscarRecursivo(string claveBusqueda, NodoPacientes* paginaActual) {
    if (paginaActual == nullptr) return nullptr;
    bool encontrada = false;
    int indiceRama = 0;
    buscarNodo(claveBusqueda, paginaActual, encontrada, indiceRama);
    if (encontrada) return paginaActual;
    return buscarRecursivo(claveBusqueda, paginaActual->ramas[indiceRama]);
}

Pacientes* BPacientes::buscar(string id) {
    NodoPacientes* nodoEncontrado = buscarRecursivo(id, raiz);
    if (nodoEncontrado != nullptr) {
        for (int indice = 1; indice <= nodoEncontrado->cuenta; indice++) {
            if (nodoEncontrado->claves[indice].getIdPaciente() == id) {
                return &(nodoEncontrado->claves[indice]);
            }
        }
    }
    return nullptr;
}
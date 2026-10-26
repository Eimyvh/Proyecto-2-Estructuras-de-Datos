#ifndef AVLCITAS_H
#define AVLCITAS_H
#include "NodoCitas.h"

class AVLCitas {
private:
    NodoCitas* raiz;
    int obtenerAltura(NodoCitas* n);
    int obtenerBalance(NodoCitas* n);
    NodoCitas* rotarDerecha(NodoCitas* y);
    NodoCitas* rotarIzquierda(NodoCitas* x);
    NodoCitas* insertarRec(NodoCitas* nodo, string clave, Citas dato);
    NodoCitas* buscarRec(NodoCitas* nodo, string clave);

public:
    AVLCitas();
    void insertar(string clave, Citas dato);
    Citas* buscar(string clave);
};
#endif
#ifndef RNTRATAMIENTO_H
#define RNTRATAMIENTO_H
#include "NodoTratamiento.h"

class RNTratamiento {
private:
    NodoTratamiento* raiz;
    NodoTratamiento* nodoNuloHoja;
    void rotacionIzquierda(NodoTratamiento* nodoDesbalanceado);
    void rotacionDerecha(NodoTratamiento* nodoDesbalanceado);
    void corregirInsercion(NodoTratamiento* nodoActual);
    NodoTratamiento* buscarRecursivo(NodoTratamiento* nodoActual, int idTratamiento);

public:
    RNTratamiento();
    void InsertaNodo(Tratamiento pTratamiento);
    bool BuscarTratamiento(int idTratamiento);
    Tratamiento* ObtenerTratamiento(int idTratamiento);
};

#endif
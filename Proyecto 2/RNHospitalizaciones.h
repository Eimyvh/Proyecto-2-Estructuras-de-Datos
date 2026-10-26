#ifndef RNHOSPITALIZACIONES_H
#define RNHOSPITALIZACIONES_H
#include "NodoHospitalizaciones.h"

class RNHospitalizaciones {
private:
    NodoHospitalizaciones* raiz;
    void rotarIzquierda(NodoHospitalizaciones*& raizArbol, NodoHospitalizaciones*& ptr);
    void rotarDerecha(NodoHospitalizaciones*& raizArbol, NodoHospitalizaciones*& ptr);
    void corregirInsercion(NodoHospitalizaciones*& raizArbol, NodoHospitalizaciones*& ptr);
    NodoHospitalizaciones* buscarRec(NodoHospitalizaciones* nodoActual, string clave);

public:
    RNHospitalizaciones();
    void insertar(string clave, Hospitalizaciones dato);
    Hospitalizaciones* buscar(string clave);
};
#endif
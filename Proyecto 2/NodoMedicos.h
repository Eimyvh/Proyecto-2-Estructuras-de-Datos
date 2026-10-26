#ifndef NODOMEDICOS_H
#define NODOMEDICOS_H
#include "Medicos.h"

const int ORDEN_MEDICOS = 4;

class NodoMedicos {
public:
    int cuenta;
    Medicos claves[ORDEN_MEDICOS + 1];
    NodoMedicos* ramas[ORDEN_MEDICOS + 2];

    NodoMedicos();
};
#endif
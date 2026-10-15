#ifndef NODOTRATAMIENTO_H
#define NODOTRATAMIENTO_H
#include "Tratamiento.h"

class NodoTratamiento {
public:
    Tratamiento valor;
    NodoTratamiento* Hizq;
    NodoTratamiento* Hder;
    NodoTratamiento* padre;
    int color;

    NodoTratamiento(Tratamiento pTratamiento);
};

#endif
#ifndef NODOCIUDAD_H
#define NODOCIUDAD_H
#include "Ciudad.h"

class NodoCiudad {
public:
    Ciudad valor;
    NodoCiudad* Hizq;
    NodoCiudad* Hder;

    NodoCiudad(Ciudad pCiudad) {
        valor = pCiudad;
        Hizq = nullptr;
        Hder = nullptr;
    }
};

#endif
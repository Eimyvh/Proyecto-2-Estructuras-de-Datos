#ifndef NODOPAIS_H
#define NODOPAIS_H

#include "Pais.h"

class NodoPais
{
public:
    Pais valor;
    NodoPais* Hizq;
    NodoPais* Hder;

    NodoPais(Pais pPais);
};

#endif
#ifndef ABPAIS_H
#define ABPAIS_H

#include "NodoPais.h"

class ABPais
{
private:
    NodoPais* raiz;

public:
    ABPais();

    void InsertaNodo(Pais pPais);
    bool BuscarPais(int codPais);
};

#endif
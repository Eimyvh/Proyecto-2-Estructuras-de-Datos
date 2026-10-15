#ifndef ABCIUDAD_H
#define ABCIUDAD_H
#include "NodoCiudad.h"

class ABCiudad
{
private:
    NodoCiudad* raiz;

public:
    ABCiudad();
    void InsertaNodo(Ciudad pCiudad);
    bool BuscarCiudad(int codCiudad);
    Ciudad* ObtenerCiudad(int codCiudad);
};
#endif
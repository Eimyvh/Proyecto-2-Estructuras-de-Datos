#include "Pais.h"

Pais::Pais(int pCodPais, string pNombre)
{
    codPais = pCodPais;
    nombre = pNombre;
}

int Pais::getCodPais()
{
    return codPais;
}

string Pais::getNombre()
{
    return nombre;
}

void Pais::setNombre(string pNombre)
{
    nombre = pNombre;
}
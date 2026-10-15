#include "Ciudad.h"

Ciudad::Ciudad(int pCodPais, int pCodCiudad, string pNombre)
{
    codPais = pCodPais;
    codCiudad = pCodCiudad;
    nombre = pNombre;
}
int Ciudad::getCodPais()
{
    return codPais;
}
int Ciudad::getCodCiudad()
{
    return codCiudad;
}
string Ciudad::getNombre()
{
    return nombre;
}
void Ciudad::setNombre(string pNombre)
{
    nombre = pNombre;
}
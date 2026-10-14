#include "Diagnostico.h"

Diagnostico::Diagnostico(string pCodDiagnostico, string pNombre,
    string pDescripcion)
{
    codDiagnostico = pCodDiagnostico;
    nombre = pNombre;
    descripcion = pDescripcion;
}

string Diagnostico::getCodDiagnostico()
{
    return codDiagnostico;
}

string Diagnostico::getNombre()
{
    return nombre;
}

string Diagnostico::getDescripcion()
{
    return descripcion;
}

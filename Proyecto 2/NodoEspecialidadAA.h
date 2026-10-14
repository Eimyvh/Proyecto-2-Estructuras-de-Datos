#ifndef NODOESPECIALIDADAA_H
#define NODOESPECIALIDADAA_H
#include "Especialidad.h"

class NodoEspecialidadAA
{
public:
    Especialidad valor;
    int nivel;
    NodoEspecialidadAA* padre;
    NodoEspecialidadAA* izquierda;
    NodoEspecialidadAA* derecha;

    NodoEspecialidadAA(Especialidad pEspecialidad);
};
#endif

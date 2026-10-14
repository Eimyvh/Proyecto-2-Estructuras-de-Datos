#include "NodoEspecialidadAA.h"

NodoEspecialidadAA::NodoEspecialidadAA(Especialidad pEspecialidad)
    : valor(pEspecialidad)
{
    nivel = 1;
    padre = nullptr;
    izquierda = nullptr;
    derecha = nullptr;
}

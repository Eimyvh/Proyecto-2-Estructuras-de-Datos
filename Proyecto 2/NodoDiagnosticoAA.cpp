#include "NodoDiagnosticoAA.h"

NodoDiagnosticoAA::NodoDiagnosticoAA(Diagnostico pDiagnostico)
    : valor(pDiagnostico)
{
    nivel = 1;
    padre = nullptr;
    izquierda = nullptr;
    derecha = nullptr;
}

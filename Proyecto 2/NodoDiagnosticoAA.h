#ifndef NODODIAGNOSTICOAA_H
#define NODODIAGNOSTICOAA_H
#include "Diagnostico.h"

class NodoDiagnosticoAA
{
public:
    Diagnostico valor;
    int nivel;
    NodoDiagnosticoAA* padre;
    NodoDiagnosticoAA* izquierda;
    NodoDiagnosticoAA* derecha;

    NodoDiagnosticoAA(Diagnostico pDiagnostico);
};
#endif

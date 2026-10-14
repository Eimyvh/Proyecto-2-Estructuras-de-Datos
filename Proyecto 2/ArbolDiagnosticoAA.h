#ifndef ARBOLDIAGNOSTICOAA_H
#define ARBOLDIAGNOSTICOAA_H
#include "NodoDiagnosticoAA.h"

class ArbolDiagnosticoAA
{
private:
    NodoDiagnosticoAA* raiz;

    NodoDiagnosticoAA* insertarRec(
        NodoDiagnosticoAA* nodo, Diagnostico valor
    );

    NodoDiagnosticoAA* Giro(NodoDiagnosticoAA* nodo);
    NodoDiagnosticoAA* Reparto(NodoDiagnosticoAA* nodo);

    void liberarMemoria(NodoDiagnosticoAA* nodo);

public:
    ArbolDiagnosticoAA();
    ~ArbolDiagnosticoAA();

    void Insertar(Diagnostico valor);
    bool Buscar(string codDiagnostico);
    Diagnostico* Obtener(string codDiagnostico);
};

#endif

#ifndef NODOCITAS_H
#define NODOCITAS_H
#include "Citas.h"

class NodoCitas {
public:
    string clave;
    Citas dato;
    int altura;
    NodoCitas* izq;
    NodoCitas* der;

    NodoCitas(string c, Citas d);
};
#endif
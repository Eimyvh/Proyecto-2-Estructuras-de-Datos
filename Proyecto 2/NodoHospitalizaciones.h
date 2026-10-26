#ifndef NODOHOSPITALIZACIONES_H
#define NODOHOSPITALIZACIONES_H
#include "Hospitalizaciones.h"

enum ColorNodo { ROJO, NEGRO };

class NodoHospitalizaciones {
public:
    string clave;
    Hospitalizaciones dato;
    ColorNodo color;
    NodoHospitalizaciones* izq, * der, * padre;

    NodoHospitalizaciones(string c, Hospitalizaciones d);
};
#endif
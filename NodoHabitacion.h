#ifndef NODOHABITACION_H
#define NODOHABITACION_H
#include "Habitacion.h"

class NodoHabitacion {
public:
    Habitacion valor;
    NodoHabitacion* Hizq;
    NodoHabitacion* Hder;
    int altura;
    NodoHabitacion(Habitacion pHabitacion);
};
#endif
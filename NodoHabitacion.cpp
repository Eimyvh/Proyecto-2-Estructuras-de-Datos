#include "NodoHabitacion.h"

NodoHabitacion::NodoHabitacion(Habitacion pHabitacion) : valor(pHabitacion) {
    Hizq = nullptr;
    Hder = nullptr;
    altura = 1;
}
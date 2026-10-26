#include "NodoCitas.h"

NodoCitas::NodoCitas(string c, Citas d) {
    clave = c;
    dato = d;
    altura = 1;
    izq = nullptr;
    der = nullptr;
}
#include "NodoHospitalizaciones.h"

NodoHospitalizaciones::NodoHospitalizaciones(string c, Hospitalizaciones d) {
    clave = c;
    dato = d;
    color = ROJO;
    izq = der = padre = nullptr;
}
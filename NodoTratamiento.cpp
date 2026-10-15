#include "NodoTratamiento.h"

NodoTratamiento::NodoTratamiento(Tratamiento pTratamiento) : valor(pTratamiento) {
    Hizq = nullptr;
    Hder = nullptr;
    padre = nullptr;
    color = 0;
}
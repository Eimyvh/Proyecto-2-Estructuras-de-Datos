#include "NodoMedicos.h"

NodoMedicos::NodoMedicos() {
    cuenta = 0;
    for (int i = 0; i < ORDEN_MEDICOS + 2; i++) {
        ramas[i] = nullptr;
    }
}
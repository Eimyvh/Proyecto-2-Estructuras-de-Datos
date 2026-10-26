#include "NodoPacientes.h"

NodoPacientes::NodoPacientes() {
    cuenta = 0;
    for (int i = 0; i < ORDEN_PACIENTES + 2; i++) {
        ramas[i] = nullptr;
    }
}
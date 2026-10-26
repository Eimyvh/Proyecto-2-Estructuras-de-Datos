#ifndef NODOPACIENTES_H
#define NODOPACIENTES_H
#include "Pacientes.h"

const int ORDEN_PACIENTES = 4;

class NodoPacientes {
public:
    int cuenta;
    Pacientes claves[ORDEN_PACIENTES + 1];
    NodoPacientes* ramas[ORDEN_PACIENTES + 2];

    NodoPacientes();
};

#endif
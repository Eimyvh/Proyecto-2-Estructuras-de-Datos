#ifndef BPACIENTES_H
#define BPACIENTES_H

#include "NodoPacientes.h"

class BPacientes {
private:
    NodoPacientes* raiz;

    void buscarNodo(string clave, NodoPacientes* p, bool& encontrado, int& k);
    void empujar(string c1, Pacientes objC1, NodoPacientes* r, bool& empujaArriba, Pacientes& mdna, NodoPacientes*& xr);
    void meterHoja(Pacientes x, NodoPacientes* xder, NodoPacientes* p, int k);
    void dividirNodo(Pacientes x, NodoPacientes* xder, NodoPacientes* p, int k, Pacientes& mda, NodoPacientes*& mder);
    NodoPacientes* buscarRec(string clave, NodoPacientes* p);

public:
    BPacientes();
    void insertar(string id, Pacientes obj);
    Pacientes* buscar(string id);
};

#endif
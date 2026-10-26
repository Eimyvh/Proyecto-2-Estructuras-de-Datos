#include "Citas.h"
#include <iostream>

Citas::Citas() : idCita(""), idPaciente(""), idMedico(""), idEspecialidad(""), fecha(""), hora(""), motivo(""), estado("") {}

Citas::Citas(string idC, string idP, string idM, string idE, string f, string h, string mot, string est)
    : idCita(idC), idPaciente(idP), idMedico(idM), idEspecialidad(idE), fecha(f), hora(h), motivo(mot), estado(est) {
}

string Citas::getIdCita() const { return idCita; }
string Citas::getFecha() const { return fecha; }
string Citas::getHora() const { return hora; }
string Citas::getMotivo() const { return motivo; }
string Citas::getEstado() const { return estado; }

void Citas::mostrar() const {
    cout << "ID Cita: " << idCita << "    Fecha: " << fecha << "    Hora: " << hora << endl;
}
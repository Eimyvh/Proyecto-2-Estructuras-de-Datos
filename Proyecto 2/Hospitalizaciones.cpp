#include "Hospitalizaciones.h"
#include <iostream>

Hospitalizaciones::Hospitalizaciones() : idHospitalizacion(""), idPaciente(""), idHabitacion(""), idMedico(""), fechaIngreso(""), fechaSalida(""), motivo("") {}

Hospitalizaciones::Hospitalizaciones(string idH, string idP, string idHab, string idM, string fIng, string fSal, string mot)
    : idHospitalizacion(idH), idPaciente(idP), idHabitacion(idHab), idMedico(idM), fechaIngreso(fIng), fechaSalida(fSal), motivo(mot) {
}

string Hospitalizaciones::getIdHospitalizacion() const { return idHospitalizacion; }
string Hospitalizaciones::getFechaIngreso() const { return fechaIngreso; }
string Hospitalizaciones::getMotivo() const { return motivo; }

void Hospitalizaciones::mostrar() const {
    cout << "ID Hospitalización: " << idHospitalizacion << "    Ingreso: " << fechaIngreso << endl;
}
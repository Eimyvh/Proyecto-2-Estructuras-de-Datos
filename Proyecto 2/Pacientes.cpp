#include "Pacientes.h"
#include <iostream>

Pacientes::Pacientes() : idPaciente(""), nombre(""), fechaNacimiento(""), telefono(""), codPais(""), codCiudad(""), correo("") {}

Pacientes::Pacientes(string id, string nom, string fn, string tel, string cPais, string cCiudad, string corr)
    : idPaciente(id), nombre(nom), fechaNacimiento(fn), telefono(tel), codPais(cPais), codCiudad(cCiudad), correo(corr) {
}

string Pacientes::getIdPaciente() const { return idPaciente; }
string Pacientes::getNombre() const { return nombre; }
string Pacientes::getFechaNacimiento() const { return fechaNacimiento; }
string Pacientes::getTelefono() const { return telefono; }
string Pacientes::getCodPais() const { return codPais; }
string Pacientes::getCodCiudad() const { return codCiudad; }
string Pacientes::getCorreo() const { return correo; }

void Pacientes::mostrar() const {
    cout << "ID Paciente: " << idPaciente << " | Nombre: " << nombre << " | Correo: " << correo << endl;
}
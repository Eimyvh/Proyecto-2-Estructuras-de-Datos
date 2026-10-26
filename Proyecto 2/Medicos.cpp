#include "Medicos.h"
#include <iostream>

Medicos::Medicos() : idMedico(""), nombre(""), telefono(""), correo(""), idEspecialidad("") {}

Medicos::Medicos(string id, string nom, string tel, string corr, string esp)
    : idMedico(id), nombre(nom), telefono(tel), correo(corr), idEspecialidad(esp) {
}

string Medicos::getIdMedico() const { return idMedico; }
string Medicos::getNombre() const { return nombre; }
string Medicos::getTelefono() const { return telefono; }
string Medicos::getCorreo() const { return correo; }
string Medicos::getIdEspecialidad() const { return idEspecialidad; }

void Medicos::mostrar() const {
    cout << "ID Médico: " << idMedico << "    Nombre: " << nombre << "    Correo: " << correo << endl;
}
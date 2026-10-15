#include "Tratamiento.h"

Tratamiento::Tratamiento() {
    idTratamiento = 0;
    nombre = "";
    descripcion = "";
    costo = 0.0;
}

Tratamiento::Tratamiento(int pIdTratamiento, string pNombre, string pDescripcion, double pCosto) {
    idTratamiento = pIdTratamiento;
    nombre = pNombre;
    descripcion = pDescripcion;
    costo = pCosto;
}

int Tratamiento::getIdTratamiento() const {
    return idTratamiento;
}

string Tratamiento::getNombre() const {
    return nombre;
}

string Tratamiento::getDescripcion() const {
    return descripcion;
}

double Tratamiento::getCosto() const {
    return costo;
}

void Tratamiento::setNombre(string pNombre) {
    nombre = pNombre;
}

#include "Tratamiento.h"

Tratamiento::Tratamiento() {
    idTratamiento = 0;
    nombre = "";
    descripcion = "";
    costo = 0.0;
}

Tratamiento::Tratamiento(int pIdTratamiento, string pNombre, string pDescripcion, double pCosto) {
    idTratamiento = pIdTratamiento;
    nombre = pNombre;
    descripcion = pDescripcion;
    costo = pCosto;
}

int Tratamiento::getIdTratamiento() const {
    return idTratamiento;
}

string Tratamiento::getNombre() const {
    return nombre;
}

string Tratamiento::getDescripcion() const {
    return descripcion;
}

double Tratamiento::getCosto() const {
    return costo;
}

void Tratamiento::setNombre(string pNombre) {
    nombre = pNombre;
}

void Tratamiento::setDescripcion(string pDescripcion) {
    descripcion = pDescripcion;
}

void Tratamiento::setCosto(double pCosto) {
    costo = pCosto;
}
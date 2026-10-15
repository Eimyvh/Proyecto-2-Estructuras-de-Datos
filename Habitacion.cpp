#include "Habitacion.h"

Habitacion::Habitacion() {
    idHabitacion = 0;
    estado = 0;
    tipo = "";
}
Habitacion::Habitacion(int pIdHabitacion, int pEstado, string pTipo) {
    idHabitacion = pIdHabitacion;
    estado = pEstado;
    tipo = pTipo;
}
int Habitacion::getIdHabitacion() const {
    return idHabitacion;
}
int Habitacion::getEstado() const {
    return estado;
}
string Habitacion::getTipo() const {
    return tipo;
}
void Habitacion::setEstado(int pEstado) {
    estado = pEstado;
}
void Habitacion::setTipo(string pTipo) {
    tipo = pTipo;
}
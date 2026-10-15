#ifndef HABITACION_H
#define HABITACION_H
#include <string>
using namespace std;

class Habitacion {
private:
    int idHabitacion;
    int estado;
    string tipo;

public:
    Habitacion();
    Habitacion(int pIdHabitacion, int pEstado, string pTipo);

    int getIdHabitacion() const;
    int getEstado() const;
    string getTipo() const;

    void setEstado(int pEstado);
    void setTipo(string pTipo);
};

#endif
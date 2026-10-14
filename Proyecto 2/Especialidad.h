#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <string>
using namespace std;

class Especialidad
{
private:
    int idEspecialidad;
    string nombre;
    string descripcion;
public:
    Especialidad(int pIdEspecialidad, string pNombre, string pDescripcion);
    int getIdEspecialidad();
    string getNombre();
    string getDescripcion();
};

#endif

#include "Especialidad.h"

Especialidad::Especialidad(int pIdEspecialidad, string pNombre, string pDescripcion)
{
    idEspecialidad = pIdEspecialidad;
    nombre = pNombre;
    descripcion = pDescripcion;
}

int Especialidad::getIdEspecialidad()
{
    return idEspecialidad;
}

string Especialidad::getNombre()
{
    return nombre;
}

string Especialidad::getDescripcion()
{
    return descripcion;
}

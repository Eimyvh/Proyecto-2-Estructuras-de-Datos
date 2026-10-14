
#include <iostream>
#include <fstream>
#include <string>
#include "Archivos.h"
#include "ArbolEspecialidadAA.h"
#include "Especialidad.h"

using namespace std;

bool cargarPaises(ABPais& arbolPaises)
{
    ifstream archivo("Datos/Paises.csv");
    string linea;

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir Paises.csv" << endl;
        return false;
    }

    getline(archivo, linea);

    while (getline(archivo, linea))
    {
        size_t separador = linea.find(';');
        if (separador != string::npos)
        {
            int codPais = stoi(linea.substr(0, separador));
            string nombre = linea.substr(separador + 1);
            if (!arbolPaises.BuscarPais(codPais))
            {
                Pais pais(codPais, nombre);
                arbolPaises.InsertaNodo(pais);
            }
        }
    }
    archivo.close();
    return true;
}


bool cargarEspecialidades(ArbolEspecialidadAA& arbolEspecialidades)
{
    ifstream archivo("Datos/Especialidades.csv");
    string linea;

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir Especialidades.csv" << endl;
        return false;
    }

    getline(archivo, linea);
    
    while (getline(archivo, linea))
    {
        size_t primero = linea.find(';');

        if (primero != string::npos)
        {
            size_t segundo = linea.find(';', primero + 1);
            if (segundo != string::npos)
            {
                int idEspecialidad = stoi(linea.substr(0, primero));
                string nombre = linea.substr(
                    primero + 1, segundo - primero - 1
                );
                string descripcion = linea.substr(segundo + 1);
                if (!arbolEspecialidades.Buscar(idEspecialidad))
                {
                    Especialidad especialidad(
                        idEspecialidad, nombre, descripcion
                    );
                    arbolEspecialidades.Insertar(especialidad);
                }
            }
        }
    }

    archivo.close();
    return true;
}

bool cargarDiagnosticos(ArbolDiagnosticoAA& arbolDiagnosticos)
{
    ifstream archivo("Datos/Diagnostico.csv");
    string linea;
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir Diagnostico.csv" << endl;
        return false;
    }
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        size_t primero = linea.find(';');
        if (primero != string::npos)
        {
            size_t segundo = linea.find(';', primero + 1);
            if (segundo != string::npos)
            {
                string codDiagnostico = linea.substr(0, primero);
                string nombre = linea.substr(
                    primero + 1, segundo - primero - 1
                );
                string descripcion = linea.substr(segundo + 1);

                if (!arbolDiagnosticos.Buscar(codDiagnostico))
                {
                    Diagnostico diagnostico(
                        codDiagnostico, nombre, descripcion
                    );

                    arbolDiagnosticos.Insertar(diagnostico);
                }
            }
        }
    }
    archivo.close();
    return true;
}

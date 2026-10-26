//Joshua Brenes Hernández carné: 2025088714, Eimy Vega Hidalgo carné: 2026097911
//Fecha de entrega:26/10/2026
//Avance 2 proyecto#2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Archivos.h"

#include "ABPais.h"
#include "Pais.h"

#include "ABCiudad.h"
#include "Ciudad.h"

#include "ArbolEspecialidadAA.h"
#include "Especialidad.h"

#include "ArbolDiagnosticoAA.h"
#include "Diagnostico.h"

#include "AVLHabitacion.h"
#include "Habitacion.h"

#include "RNTratamiento.h"
#include "Tratamiento.h"

#include "BPacientes.h"
#include "Pacientes.h"

#include "BMedicos.h"
#include "Medicos.h"

#include "AVLCitas.h"
#include "Citas.h"

#include "RNHospitalizaciones.h"
#include "Hospitalizaciones.h"

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

bool cargarCiudades(ABCiudad& arbolCiudades) {
    ifstream archivo("Datos/Ciudades.csv");

    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream datos(linea);
        string codPaisTexto, codCiudadTexto, nombre;

        getline(datos, codPaisTexto, ';');
        getline(datos, codCiudadTexto, ';');
        getline(datos, nombre);

        if (codPaisTexto.empty() || codCiudadTexto.empty()
            || nombre.empty()) {
            continue;
        }

        int codPais = stoi(codPaisTexto);
        int codCiudad = stoi(codCiudadTexto);

        if (!arbolCiudades.BuscarCiudad(codCiudad)) {
            Ciudad ciudad(codPais, codCiudad, nombre);
            arbolCiudades.InsertaNodo(ciudad);
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

bool cargarHabitaciones(AVLHabitacion& arbolHabitaciones) {
    ifstream archivo("Datos/Habitaciones.csv");

    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {

        stringstream datos(linea);
        string idTexto, numeroTexto, pisoTexto;
        string tipo, estadoTexto;

        getline(datos, idTexto, ';');
        getline(datos, numeroTexto, ';');
        getline(datos, pisoTexto, ';');
        getline(datos, tipo, ';');
        getline(datos, estadoTexto);

        if (idTexto.empty() || numeroTexto.empty()
            || pisoTexto.empty() || tipo.empty()
            || estadoTexto.empty()) {
            continue;
        }

        int id = stoi(idTexto);
        int numero = stoi(numeroTexto);
        int estado = stoi(estadoTexto);

        if (!arbolHabitaciones.BuscarHabitacion(id)) {
            Habitacion habitacion(id, numero, pisoTexto, tipo, estado);
            arbolHabitaciones.InsertaNodo(habitacion);
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

bool cargarTratamientos(RNTratamiento& arbolTratamientos) {
    ifstream archivo("Datos/Tratamiento.csv");

    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream datos(linea);
        string idTexto, nombre, descripcion, costoTexto;

        getline(datos, idTexto, ';');
        getline(datos, nombre, ';');
        getline(datos, descripcion, ';');
        getline(datos, costoTexto);

        if (idTexto.empty() || nombre.empty()
            || descripcion.empty() || costoTexto.empty()) {
            continue;
        }

        int id = stoi(idTexto);
        double costo = stod(costoTexto);

        if (!arbolTratamientos.BuscarTratamiento(id)) {
            Tratamiento tratamiento(id, nombre, descripcion, costo);
            arbolTratamientos.InsertaNodo(tratamiento);
        }
    }

    archivo.close();
    return true;
}
bool cargarPacientes(BPacientes& arbolPacientes) {
    ifstream archivo("Datos/Pacientes.csv");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir Pacientes.csv" << endl;
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream datos(linea);
        string idPaciente, nombre, fechaNacimiento, telefono, codPais, codCiudad, correo;

        getline(datos, idPaciente, ';');
        getline(datos, nombre, ';');
        getline(datos, fechaNacimiento, ';');
        getline(datos, telefono, ';');
        getline(datos, codPais, ';');
        getline(datos, codCiudad, ';');
        getline(datos, correo);

        if (idPaciente.empty() || nombre.empty()) {
            continue;
        }

        if (arbolPacientes.buscar(idPaciente) == nullptr) {
            Pacientes paciente(idPaciente, nombre, fechaNacimiento, telefono, codPais, codCiudad, correo);
            arbolPacientes.insertar(idPaciente, paciente);
        }
    }

    archivo.close();
    return true;
}

bool cargarMedicos(BMedicos& arbolMedicos) {
    ifstream archivo("Datos/Medicos.csv");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir Medicos.csv" << endl;
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream datos(linea);
        string idMedico, nombre, telefono, correo, idEspecialidad;

        getline(datos, idMedico, ';');
        getline(datos, nombre, ';');
        getline(datos, telefono, ';');
        getline(datos, correo, ';');
        getline(datos, idEspecialidad);

        if (idMedico.empty() || nombre.empty()) {
            continue;
        }

        if (arbolMedicos.buscar(idMedico) == nullptr) {
            Medicos medico(idMedico, nombre, telefono, correo, idEspecialidad);
            arbolMedicos.insertar(idMedico, medico);
        }
    }

    archivo.close();
    return true;
}

bool cargarCitas(AVLCitas& arbolCitas) {
    ifstream archivo("Datos/Citas.csv");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir Citas.csv" << endl;
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream datos(linea);
        string idCita, idPaciente, idMedico, idEspecialidad, fecha, hora, motivo, estado;

        getline(datos, idCita, ';');
        getline(datos, idPaciente, ';');
        getline(datos, idMedico, ';');
        getline(datos, idEspecialidad, ';');
        getline(datos, fecha, ';');
        getline(datos, hora, ';');
        getline(datos, motivo, ';');
        getline(datos, estado);

        if (idCita.empty()) {
            continue;
        }

        if (arbolCitas.buscar(idCita) == nullptr) {
            Citas cita(idCita, idPaciente, idMedico, idEspecialidad, fecha, hora, motivo, estado);
            arbolCitas.insertar(idCita, cita);
        }
    }

    archivo.close();
    return true;
}

bool cargarHospitalizaciones(RNHospitalizaciones& arbolHospitalizaciones) {
    ifstream archivo("Datos/Hospitalizaciones.csv");

    if (!archivo.is_open()) {
        cout << "No se pudo abrir Hospitalizaciones.csv" << endl;
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream datos(linea);
        string idHospitalizacion, idPaciente, idHabitacion, idMedico, fechaIngreso, fechaSalida, motivo;

        getline(datos, idHospitalizacion, ';');
        getline(datos, idPaciente, ';');
        getline(datos, idHabitacion, ';');
        getline(datos, idMedico, ';');
        getline(datos, fechaIngreso, ';');
        getline(datos, fechaSalida, ';');
        getline(datos, motivo);

        if (idHospitalizacion.empty()) {
            continue;
        }

        if (arbolHospitalizaciones.buscar(idHospitalizacion) == nullptr) {
            Hospitalizaciones hospitalizacion(idHospitalizacion, idPaciente, idHabitacion, idMedico, fechaIngreso, fechaSalida, motivo);
            arbolHospitalizaciones.insertar(idHospitalizacion, hospitalizacion);
        }
    }

    archivo.close();
    return true;
}
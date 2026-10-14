#include <iostream>
#include <string>
#include "ABPais.h"
#include "Archivos.h"
#include <sstream>
#include "ArbolEspecialidadAA.h"
#include "ArbolDiagnosticoAA.h"

using namespace std;

int leerEntero(string mensaje)
{
    string entrada;
    int numero;
    char sobrante;

    while (true)
    {
        cout << mensaje;
        getline(cin, entrada);
        stringstream flujo(entrada);
        if ((flujo >> numero) && !(flujo >> sobrante))
        {
            return numero;
        }
        else
        {
            cout << "Debe ingresar un numero entero valido." << endl;
        }
    }
}

int leerCodigoPais()
{
    int codigo;
    while (true)
    {
        codigo = leerEntero("Ingrese el codigo del pais: ");
        if (codigo > 0)
        {
            return codigo;
        }
        else
        {
            cout << "El codigo debe ser mayor que cero." << endl;
        }
    }
}

int leerIdEspecialidad() {
    int id;
    while (true) {
        id = leerEntero("Ingrese el ID de la especialidad: ");
        if (id > 0) {
            return id;
        }
        else {
            cout << "El ID debe ser mayor que cero." << endl;
        }
    }
}
                            
string leerNombrePais()
{
    string nombre;
    while (true)
    {
        cout << "Ingrese el nombre del pais: ";
        getline(cin, nombre);
        if (nombre.find_first_not_of(" \t\n\r") != string::npos)
        {
            return nombre;
        }
        else
        {
            cout << "El nombre no puede estar vacio." << endl;
        }
    }
}

void buscarPais(ABPais& arbolPaises)
{
    int codPais = leerCodigoPais();
    Pais* pais = arbolPaises.ObtenerPais(codPais);
    if (pais != nullptr)
    {
        cout << "Codigo: " << pais->getCodPais() << endl;
        cout << "Nombre: " << pais->getNombre() << endl;
    }
    else
    {
        cout << "No existe un pais con ese codigo." << endl;
    }
}

void insertarPais(ABPais& arbolPaises)
{
    int codPais = leerCodigoPais();
    if (arbolPaises.BuscarPais(codPais))
    {
        cout << "Ya existe un pais con ese codigo." << endl;
    }
    else
    {
        string nombre = leerNombrePais();
        Pais pais(codPais, nombre);
        arbolPaises.InsertaNodo(pais);
        cout << "Pais insertado correctamente." << endl;
    }
}

void buscarEspecialidad(ArbolEspecialidadAA& arbolEspecialidades)
{
    int id = leerIdEspecialidad();
    Especialidad* especialidad = arbolEspecialidades.Obtener(id);
    if (especialidad != nullptr)
    {
        cout << "ID: " << especialidad->getIdEspecialidad() << endl;
        cout << "Nombre: " << especialidad->getNombre() << endl;
        cout << "Descripcion: " << especialidad->getDescripcion() << endl;
    }
    else
    {
        cout << "No existe una especialidad con ese ID." << endl;
    }
}

void insertarEspecialidad(ArbolEspecialidadAA& arbolEspecialidades)
{
    int id = leerIdEspecialidad();
    if (arbolEspecialidades.Buscar(id))
    {
        cout << "Ya existe una especialidad con ese ID." << endl;
    }
    else
    {
        string nombre;
        string descripcion;
        do
        {
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);
            if (nombre.find_first_not_of(" \t\n\r") == string::npos)
            {
                cout << "El nombre no puede estar vacio." << endl;
            }
        } while (nombre.find_first_not_of(" \t\n\r") == string::npos);
        do
        {
            cout << "Ingrese la descripcion: ";
            getline(cin, descripcion);
            if (descripcion.find_first_not_of(" \t\n\r") == string::npos)
            {
                cout << "La descripcion no puede estar vacia." << endl;
            }
        } while (descripcion.find_first_not_of(" \t\n\r") == string::npos);
        Especialidad especialidad(id, nombre, descripcion);
        arbolEspecialidades.Insertar(especialidad);
        cout << "Especialidad insertada correctamente." << endl;
    }
}

void menuBuscar(ABPais& arbolPaises,
    ArbolEspecialidadAA& arbolEspecialidades,
    ArbolDiagnosticoAA& arbolDiagnosticos)
{
    int opcion;
    do
    {
        cout << "\n----- Buscar -----" << endl;
        cout << "1. Paises" << endl;
        cout << "2. Especialidades" << endl;
        cout << "3. Diagnosticos" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            buscarPais(arbolPaises);
        }
        else if (opcion == 2)
        {
            buscarEspecialidad(arbolEspecialidades);
        }
        else if (opcion == 3)
        {
            string codigo;
            cout << "Ingrese el codigo del diagnostico: ";
            getline(cin, codigo);
            Diagnostico* diagnostico =
                arbolDiagnosticos.Obtener(codigo);

            if (diagnostico != nullptr)
            {
                cout << "Codigo: "
                    << diagnostico->getCodDiagnostico() << endl;
                cout << "Nombre: "
                    << diagnostico->getNombre() << endl;
                cout << "Descripcion: "
                    << diagnostico->getDescripcion() << endl;
            }
            else
            {
                cout << "No existe un diagnostico con ese codigo."
                    << endl;
            }
        }
        else if (opcion != 0)
        {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);
}

void menuInsertar(ABPais& arbolPaises,ArbolEspecialidadAA& arbolEspecialidades,ArbolDiagnosticoAA& arbolDiagnosticos)
{
    int opcion;
    do
    {
        cout << "\n----- Insertar -----" << endl;
        cout << "1. Paises" << endl;
        cout << "2. Especialidades" << endl;
        cout << "3. Diagnosticos" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            insertarPais(arbolPaises);
        }
        else if (opcion == 2)
        {
            insertarEspecialidad(arbolEspecialidades);
        }
        else if (opcion == 3)
        {
            string codigo;
            string nombre;
            string descripcion;
            cout << "Ingrese el codigo del diagnostico: ";
            getline(cin, codigo);
            if (codigo.empty() ||
                arbolDiagnosticos.Buscar(codigo))
            {
                cout << "El codigo esta vacio o ya existe." << endl;
            }
            else
            {
                cout << "Ingrese el nombre: ";
                getline(cin, nombre);
                cout << "Ingrese la descripcion: ";
                getline(cin, descripcion);
                if (nombre.find_first_not_of(" \t\n\r") ==
                    string::npos ||
                    descripcion.find_first_not_of(" \t\n\r") ==
                    string::npos)
                {
                    cout << "El nombre y la descripcion no pueden estar vacios." << endl;
                }
                else
                {
                    Diagnostico diagnostico(
                        codigo, nombre, descripcion
                    );
                    arbolDiagnosticos.Insertar(diagnostico);
                    cout << "Diagnostico insertado correctamente."
                        << endl;
                }
            }
        }
        else if (opcion != 0)
        {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);
}

void menuMantenimiento(ABPais& arbolPaises,
    ArbolEspecialidadAA& arbolEspecialidades,
    ArbolDiagnosticoAA& arbolDiagnosticos)
{
    int opcion;
    do
    {
        cout << "\n----- Mantenimiento de la base de datos -----" << endl;
        cout << "1. Buscar" << endl;
        cout << "2. Insertar" << endl;
        cout << "0. Volver al menu principal" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            menuBuscar(arbolPaises, arbolEspecialidades, arbolDiagnosticos);
        }
        else if (opcion == 2)
        {
            menuInsertar(arbolPaises, arbolEspecialidades, arbolDiagnosticos);
        }
        else if (opcion != 0)
        {
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);
}

int main()
{
    ABPais arbolPaises;
    ArbolEspecialidadAA arbolEspecialidades;
    ArbolDiagnosticoAA arbolDiagnosticos;
    int opcion;
    do
    {
        cout << "\n----- Menu principal -----" << endl;
        cout << "1. Leer archivos y construir diccionarios" << endl;
        cout << "2. Mantenimiento de la base de datos" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            bool paisesCargados = cargarPaises(arbolPaises);
            bool especialidadesCargadas =
                cargarEspecialidades(arbolEspecialidades);
            bool diagnosticosCargados =
                cargarDiagnosticos(arbolDiagnosticos);
            if (paisesCargados && especialidadesCargadas &&
                diagnosticosCargados)
            {
                cout << "Carga de archivos finalizada." << endl;
            }
        }
        else if (opcion == 2)
        {
            menuMantenimiento(arbolPaises, arbolEspecialidades, arbolDiagnosticos);
        }
        else if (opcion == 0)
        {
            cout << "Saliendo del programa..." << endl;
        }
        else
        {
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);
    return 0;
}


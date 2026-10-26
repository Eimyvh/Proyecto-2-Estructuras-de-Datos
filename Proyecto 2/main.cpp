//Joshua Brenes Hernández carné: 2025088714, Eimy Vega Hidalgo carné: 2026097911
//Fecha de entrega:26/10/2026
//Avance 2 proyecto#2

#include <iostream>
#include <string>
#include "ABPais.h"
#include "Archivos.h"
#include <sstream>
#include "ArbolEspecialidadAA.h"
#include "ArbolDiagnosticoAA.h"
#include "ABCiudad.h"
#include "AVLHabitacion.h"
#include "RNTratamiento.h"
#include "BPacientes.h"
#include "Pacientes.h"
#include "BMedicos.h"
#include "Medicos.h"
#include "AVLCitas.h"
#include "Citas.h"
#include "RNHospitalizaciones.h"
#include "Hospitalizaciones.h"

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

string leerNombreCiudad()
{
    string nombre;
    while (true)
    {
        cout << "Ingrese el nombre de la ciudad: ";
        getline(cin, nombre);
        if (!nombre.empty())
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

void buscarCiudad(ABPais& arbolPaises, ABCiudad& arbolCiudades)
{
    int codPais = leerCodigoPais();
    Pais* pais = arbolPaises.ObtenerPais(codPais);
    if (pais == nullptr)
    {
        cout << "No existe un pais con ese codigo." << endl;
    }
    else
    {
        int codCiudad = leerEntero("Ingrese el codigo de la ciudad: ");
        Ciudad* ciudad = arbolCiudades.ObtenerCiudad(codCiudad);
        if (ciudad == nullptr)
        {
            cout << "No existe una ciudad con ese codigo." << endl;
        }
        else if (ciudad->getCodPais() != codPais)
        {
            cout << "La ciudad existe, pero no pertenece al pais "
                << pais->getNombre() << "." << endl;
            cout << "La ciudad pertenece al pais con codigo "
                << ciudad->getCodPais() << "." << endl;
        }
        else
        {
            cout << "Codigo del pais: " << ciudad->getCodPais() << endl;
            cout << "Codigo de la ciudad: " << ciudad->getCodCiudad() << endl;
            cout << "Nombre: " << ciudad->getNombre() << endl;
        }
    }
}

void insertarCiudad(
    ABPais& arbolPaises,
    ABCiudad& arbolCiudades)
{
    int codPais = leerCodigoPais();
    if (arbolPaises.BuscarPais(codPais))
    {
        int codCiudad = leerEntero("Ingrese el codigo de la ciudad: ");
        if (codCiudad <= 0)
        {
            cout << "El codigo de la ciudad debe ser mayor que cero." << endl;
        }
        else if (arbolCiudades.BuscarCiudad(codCiudad))
        {
            cout << "Ya existe una ciudad con ese codigo." << endl;
        }
        else
        {
            string nombre = leerNombreCiudad();
            Ciudad ciudad(codPais, codCiudad, nombre);
            arbolCiudades.InsertaNodo(ciudad);
            cout << "Ciudad insertada correctamente." << endl;
        }
    }
    else
    {
        cout << "No existe un pais con ese codigo." << endl;
    }
}

void buscarHabitacion(AVLHabitacion& arbolHabitaciones)
{
    int id = leerEntero("Ingrese el ID de la habitacion: ");
    Habitacion* habitacion =
        arbolHabitaciones.ObtenerHabitacion(id);
    if (habitacion != nullptr)
    {
        cout << "ID: " << habitacion->getIdHabitacion() << endl;
        cout << "Numero: " << habitacion->getNumero() << endl;
        cout << "Piso: " << habitacion->getPiso() << endl;
        cout << "Tipo: " << habitacion->getTipo() << endl;
        cout << "Estado: " << habitacion->getEstado() << endl;
    }
    else
    {
        cout << "No existe una habitacion con ese ID." << endl;
    }
}

void insertarHabitacion(AVLHabitacion& arbolHabitaciones)
{
    int id = leerEntero("Ingrese el ID de la habitacion: ");

    if (id <= 0)
    {
        cout << "El ID debe ser mayor que cero." << endl;
    }
    else if (arbolHabitaciones.BuscarHabitacion(id))
    {
        cout << "Ya existe una habitacion con ese ID." << endl;
    }
    else
    {
        int numero = leerEntero("Ingrese el numero de la habitacion: ");

        string piso;
        do
        {
            cout << "Ingrese el piso: ";
            getline(cin, piso);

            if (piso.empty())
            {
                cout << "El piso no puede estar vacio." << endl;
            }
        } while (piso.empty());
        string tipo;
        do
        {
            cout << "Ingrese el tipo de habitacion: ";
            getline(cin, tipo);
            if (tipo.empty())
            {
                cout << "El tipo no puede estar vacio." << endl;
            }
        } while (tipo.empty());
        int estado = leerEntero("Ingrese el estado de la habitacion: ");
        Habitacion habitacion(id, numero, piso, tipo, estado);
        arbolHabitaciones.InsertaNodo(habitacion);
        cout << "Habitacion insertada correctamente." << endl;
    }
}

void buscarTratamiento(RNTratamiento& arbolTratamientos)
{
    int id = leerEntero("Ingrese el ID del tratamiento: ");
    Tratamiento* tratamiento =
        arbolTratamientos.ObtenerTratamiento(id);
    if (tratamiento != nullptr)
    {
        cout << "ID: " << tratamiento->getIdTratamiento() << endl;
        cout << "Nombre: " << tratamiento->getNombre() << endl;
        cout << "Descripcion: " << tratamiento->getDescripcion() << endl;
        cout << "Costo: " << tratamiento->getCosto() << endl;
    }
    else
    {
        cout << "No existe un tratamiento con ese ID." << endl;
    }
}

void insertarTratamiento(RNTratamiento& arbolTratamientos)
{
    int id = leerEntero("Ingrese el ID del tratamiento: ");
    if (id <= 0)
    {
        cout << "El ID debe ser mayor que cero." << endl;
    }
    else if (arbolTratamientos.BuscarTratamiento(id))
    {
        cout << "Ya existe un tratamiento con ese ID." << endl;
    }
    else
    {
        string nombre;
        string descripcion;
        do
        {
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);

            if (nombre.empty())
            {
                cout << "El nombre no puede estar vacio." << endl;
            }
        } while (nombre.empty());

        do
        {
            cout << "Ingrese la descripcion: ";
            getline(cin, descripcion);

            if (descripcion.empty())
            {
                cout << "La descripcion no puede estar vacia." << endl;
            }
        } while (descripcion.empty());


        double costo;
        while (true)
        {
            string entrada;
            char sobrante;

            cout << "Ingrese el costo: ";
            getline(cin, entrada);

            stringstream flujo(entrada);

            if ((flujo >> costo) && !(flujo >> sobrante) && costo >= 0)
            {
                break;
            }
            else
            {
                cout << "Ingrese un costo valido, mayor o igual que cero." << endl;
            }
        }

        Tratamiento tratamiento(id, nombre, descripcion, costo);
        arbolTratamientos.InsertaNodo(tratamiento);

        cout << "Tratamiento insertado correctamente." << endl;
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
            if (nombre.empty() == string::npos)
            {
                cout << "El nombre no puede estar vacio." << endl;
            }
        } while (nombre.empty() == string::npos);
        do
        {
            cout << "Ingrese la descripcion: ";
            getline(cin, descripcion);
            if (descripcion.empty() == string::npos)
            {
                cout << "La descripcion no puede estar vacia." << endl;
            }
        } while (descripcion.empty() == string::npos);
        Especialidad especialidad(id, nombre, descripcion);
        arbolEspecialidades.Insertar(especialidad);
        cout << "Especialidad insertada correctamente." << endl;
    }
}

void buscarPaciente(BPacientes& arbolPacientes)
{
    string id;
    cout << "Ingrese el ID del paciente: ";
    getline(cin, id);
    Pacientes* paciente = arbolPacientes.buscar(id);
    if (paciente != nullptr)
    {
        paciente->mostrar();
    }
    else
    {
        cout << "No existe un paciente con ese ID." << endl;
    }
}

void insertarPaciente(BPacientes& arbolPacientes)
{
    string id, nombre, fechaNac, tel, cPais, cCiudad, correo;
    cout << "Ingrese el ID del paciente: ";
    getline(cin, id);
    if (arbolPacientes.buscar(id) != nullptr)
    {
        cout << "Ya existe un paciente con ese ID." << endl;
    }
    else
    {
        cout << "Ingrese el nombre: ";
        getline(cin, nombre);
        cout << "Ingrese la fecha de nacimiento (YYYY-MM-DD): ";
        getline(cin, fechaNac);
        cout << "Ingrese el telefono: ";
        getline(cin, tel);
        cout << "Ingrese el codigo de pais: ";
        getline(cin, cPais);
        cout << "Ingrese el codigo de ciudad: ";
        getline(cin, cCiudad);
        cout << "Ingrese el correo: ";
        getline(cin, correo);
        Pacientes paciente(id, nombre, fechaNac, tel, cPais, cCiudad, correo);
        arbolPacientes.insertar(id, paciente);
        cout << "Paciente insertado correctamente." << endl;
    }
}

void buscarMedico(BMedicos& arbolMedicos)
{
    string id;
    cout << "Ingrese el ID del medico: ";
    getline(cin, id);
    Medicos* medico = arbolMedicos.buscar(id);
    if (medico != nullptr)
    {
        medico->mostrar();
    }
    else
    {
        cout << "No existe un medico con ese ID." << endl;
    }
}

void insertarMedico(BMedicos& arbolMedicos)
{
    string id, nombre, tel, correo, idEspecialidad;
    cout << "Ingrese el ID del medico: ";
    getline(cin, id);
    if (arbolMedicos.buscar(id) != nullptr)
    {
        cout << "Ya existe un medico con ese ID." << endl;
    }
    else
    {
        cout << "Ingrese el nombre: ";
        getline(cin, nombre);
        cout << "Ingrese el telefono: ";
        getline(cin, tel);
        cout << "Ingrese el correo: ";
        getline(cin, correo);
        cout << "Ingrese el ID de la especialidad: ";
        getline(cin, idEspecialidad);
        Medicos medico(id, nombre, tel, correo, idEspecialidad);
        arbolMedicos.insertar(id, medico);
        cout << "Medico insertado correctamente." << endl;
    }
}

void buscarCita(AVLCitas& arbolCitas)
{
    string id;
    cout << "Ingrese el ID de la cita: ";
    getline(cin, id);
    Citas* cita = arbolCitas.buscar(id);
    if (cita != nullptr)
    {
        cita->mostrar();
    }
    else
    {
        cout << "No existe una cita con ese ID." << endl;
    }
}

void insertarCita(AVLCitas& arbolCitas)
{
    string idCita, idP, idM, idE, fecha, hora, motivo, estado;
    cout << "Ingrese el ID de la cita: ";
    getline(cin, idCita);
    if (arbolCitas.buscar(idCita) != nullptr)
    {
        cout << "Ya existe una cita con ese ID." << endl;
    }
    else
    {
        cout << "Ingrese el ID del paciente: ";
        getline(cin, idP);
        cout << "Ingrese el ID del medico: ";
        getline(cin, idM);
        cout << "Ingrese el ID de la especialidad: ";
        getline(cin, idE);
        cout << "Ingrese la fecha (YYYY-MM-DD): ";
        getline(cin, fecha);
        cout << "Ingrese la hora (HH:MM): ";
        getline(cin, hora);
        cout << "Ingrese el motivo: ";
        getline(cin, motivo);
        cout << "Ingrese el estado: ";
        getline(cin, estado);
        Citas cita(idCita, idP, idM, idE, fecha, hora, motivo, estado);
        arbolCitas.insertar(idCita, cita);
        cout << "Cita insertada correctamente." << endl;
    }
}

void buscarHospitalizacion(RNHospitalizaciones& arbolHospitalizaciones)
{
    string id;
    cout << "Ingrese el ID de la hospitalizacion: ";
    getline(cin, id);
    Hospitalizaciones* hosp = arbolHospitalizaciones.buscar(id);
    if (hosp != nullptr)
    {
        hosp->mostrar();
    }
    else
    {
        cout << "No existe una hospitalizacion con ese ID." << endl;
    }
}

void insertarHospitalizacion(RNHospitalizaciones& arbolHospitalizaciones)
{
    string idHosp, idP, idHab, idM, fechaIng, fechaSal, motivo;
    cout << "Ingrese el ID de la hospitalizacion: ";
    getline(cin, idHosp);
    if (arbolHospitalizaciones.buscar(idHosp) != nullptr)
    {
        cout << "Ya existe una hospitalizacion con ese ID." << endl;
    }
    else
    {
        cout << "Ingrese el ID del paciente: ";
        getline(cin, idP);
        cout << "Ingrese el ID de la habitacion: ";
        getline(cin, idHab);
        cout << "Ingrese el ID del medico: ";
        getline(cin, idM);
        cout << "Ingrese la fecha de ingreso: ";
        getline(cin, fechaIng);
        cout << "Ingrese la fecha de salida: ";
        getline(cin, fechaSal);
        cout << "Ingrese el motivo: ";
        getline(cin, motivo);
        Hospitalizaciones hosp(idHosp, idP, idHab, idM, fechaIng, fechaSal, motivo);
        arbolHospitalizaciones.insertar(idHosp, hosp);
        cout << "Hospitalizacion insertada correctamente." << endl;
    }
}

void menuBuscar(
    ABPais& arbolPaises,
    ArbolEspecialidadAA& arbolEspecialidades,
    ArbolDiagnosticoAA& arbolDiagnosticos,
    ABCiudad& arbolCiudades, AVLHabitacion& arbolHabitaciones, RNTratamiento& arbolTratamientos,
    BPacientes& arbolPacientes, BMedicos& arbolMedicos, AVLCitas& arbolCitas, RNHospitalizaciones& arbolHospitalizaciones)
{
    int opcion;
    do
    {
        cout << "\n----- Buscar -----" << endl;
        cout << "1. Paises" << endl;
        cout << "2. Ciudades" << endl;
        cout << "3. Especialidades" << endl;
        cout << "4. Habitaciones" << endl;
        cout << "5. Diagnosticos" << endl;
        cout << "6. Tratamientos" << endl;
        cout << "7. Pacientes" << endl;
        cout << "8. Medicos" << endl;
        cout << "9. Citas" << endl;
        cout << "10. Hospitalizaciones" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            buscarPais(arbolPaises);
        }
        else if (opcion == 2)
        {
            buscarCiudad(arbolPaises, arbolCiudades);
        }
        else if (opcion == 3)
        {
            buscarEspecialidad(arbolEspecialidades);
        }
        else if (opcion == 4)
        {
            buscarHabitacion(arbolHabitaciones);
        }
        else if (opcion == 5)
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
        else if (opcion == 6)
        {
            buscarTratamiento(arbolTratamientos);
        }
        else if (opcion == 7)
        {
            buscarPaciente(arbolPacientes);
        }
        else if (opcion == 8)
        {
            buscarMedico(arbolMedicos);
        }
        else if (opcion == 9)
        {
            buscarCita(arbolCitas);
        }
        else if (opcion == 10)
        {
            buscarHospitalizacion(arbolHospitalizaciones);
        }
        else if (opcion != 0)
        {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);
}

void menuInsertar(
    ABPais& arbolPaises,
    ArbolEspecialidadAA& arbolEspecialidades,
    ArbolDiagnosticoAA& arbolDiagnosticos,
    ABCiudad& arbolCiudades, AVLHabitacion& arbolHabitaciones, RNTratamiento& arbolTratamientos,
    BPacientes& arbolPacientes, BMedicos& arbolMedicos, AVLCitas& arbolCitas, RNHospitalizaciones& arbolHospitalizaciones)
{
    int opcion;
    do
    {
        cout << "\n----- Insertar -----" << endl;
        cout << "1. Paises" << endl;
        cout << "2. Ciudades" << endl;
        cout << "3. Especialidades" << endl;
        cout << "4. Habitaciones" << endl;
        cout << "5. Diagnosticos" << endl;
        cout << "6. Tratamientos" << endl;
        cout << "7. Pacientes" << endl;
        cout << "8. Medicos" << endl;
        cout << "9. Citas" << endl;
        cout << "10. Hospitalizaciones" << endl;
        cout << "0. Volver" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            insertarPais(arbolPaises);
        }
        else if (opcion == 2)
        {
            insertarCiudad(arbolPaises, arbolCiudades);
        }
        else if (opcion == 3)
        {
            insertarEspecialidad(arbolEspecialidades);
        }
        else if (opcion == 4)
        {
            insertarHabitacion(arbolHabitaciones);
        }
        else if (opcion == 5)
        {
            string codigo;
            string nombre;
            string descripcion;
            cout << "Ingrese el codigo del diagnostico: ";
            getline(cin, codigo);
            if (codigo.empty() || arbolDiagnosticos.Buscar(codigo))
            {
                cout << "El codigo esta vacio o ya existe." << endl;
            }
            else
            {
                cout << "Ingrese el nombre: ";
                getline(cin, nombre);
                cout << "Ingrese la descripcion: ";
                getline(cin, descripcion);
                if (nombre.empty() || descripcion.empty())
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
        else if (opcion == 6)
        {
            insertarTratamiento(arbolTratamientos);
        }
        else if (opcion == 7)
        {
            insertarPaciente(arbolPacientes);
        }
        else if (opcion == 8)
        {
            insertarMedico(arbolMedicos);
        }
        else if (opcion == 9)
        {
            insertarCita(arbolCitas);
        }
        else if (opcion == 10)
        {
            insertarHospitalizacion(arbolHospitalizaciones);
        }
        else if (opcion != 0)
        {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);
}

void menuMantenimiento(ABPais& arbolPaises,
    ArbolEspecialidadAA& arbolEspecialidades,
    ArbolDiagnosticoAA& arbolDiagnosticos, ABCiudad& arbolCiudades, AVLHabitacion& arbolHabitaciones, RNTratamiento& arbolTratamientos,
    BPacientes& arbolPacientes, BMedicos& arbolMedicos, AVLCitas& arbolCitas, RNHospitalizaciones& arbolHospitalizaciones)
{
    int opcion;
    do
    {
        cout << "\n----- Mantenimiento de la base de datos -----" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "0. Volver al menu principal" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        if (opcion == 1)
        {
            menuInsertar(arbolPaises, arbolEspecialidades, arbolDiagnosticos, arbolCiudades, arbolHabitaciones, arbolTratamientos, arbolPacientes, arbolMedicos, arbolCitas, arbolHospitalizaciones);
        }
        else if (opcion == 2)
        {
            menuBuscar(arbolPaises, arbolEspecialidades, arbolDiagnosticos, arbolCiudades, arbolHabitaciones, arbolTratamientos, arbolPacientes, arbolMedicos, arbolCitas, arbolHospitalizaciones);
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

    ABCiudad arbolCiudades;
    AVLHabitacion arbolHabitaciones;
    RNTratamiento arbolTratamientos;

    BPacientes arbolPacientes;
    BMedicos arbolMedicos;
    AVLCitas arbolCitas;
    RNHospitalizaciones arbolHospitalizaciones;

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
            bool ciudadesCargadas = cargarCiudades(arbolCiudades);
            bool habitacionesCargadas =
                cargarHabitaciones(arbolHabitaciones);
            bool tratamientosCargados =
                cargarTratamientos(arbolTratamientos);
            bool pacientesCargados = cargarPacientes(arbolPacientes);
            bool medicosCargados = cargarMedicos(arbolMedicos);
            bool citasCargadas = cargarCitas(arbolCitas);
            bool hospitalizacionesCargadas = cargarHospitalizaciones(arbolHospitalizaciones);

            if (paisesCargados && especialidadesCargadas &&
                diagnosticosCargados && ciudadesCargadas &&
                habitacionesCargadas && tratamientosCargados &&
                pacientesCargados && medicosCargados &&
                citasCargadas && hospitalizacionesCargadas)
            {
                cout << "Carga de archivos finalizada correctamente." << endl;
            }
            else
            {
                cout << "No se pudieron cargar todos los archivos." << endl;
            }
        }
        else if (opcion == 2)
        {
            menuMantenimiento(arbolPaises, arbolEspecialidades, arbolDiagnosticos, arbolCiudades, arbolHabitaciones, arbolTratamientos, arbolPacientes, arbolMedicos, arbolCitas, arbolHospitalizaciones);
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
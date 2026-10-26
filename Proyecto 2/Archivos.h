//Joshua Brenes Hernández carné: 2025088714, Eimy Vega Hidalgo carné: 2026097911
//Fecha de entrega:26/10/2026
//Avance 2 proyecto#2
#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "ABPais.h"
#include "ArbolEspecialidadAA.h"
#include "ArbolDiagnosticoAA.h"
#include "ABCiudad.h"
#include "AVLHabitacion.h"
#include "RNTratamiento.h"
#include "BPacientes.h"
#include "BMedicos.h"
#include "AVLCitas.h"
#include "RNHospitalizaciones.h"

bool cargarPaises(ABPais& arbolPaises);
bool cargarEspecialidades(ArbolEspecialidadAA& arbolEspecialidades);
bool cargarDiagnosticos(ArbolDiagnosticoAA& arbolDiagnosticos);
bool cargarCiudades(ABCiudad& arbolCiudades);
bool cargarHabitaciones(AVLHabitacion& arbolHabitaciones);
bool cargarTratamientos(RNTratamiento& arbolTratamientos);
bool cargarPacientes(BPacientes& arbolPacientes);
bool cargarMedicos(BMedicos& arbolMedicos);
bool cargarCitas(AVLCitas& arbolCitas);
bool cargarHospitalizaciones(RNHospitalizaciones& arbolHospitalizaciones);

#endif
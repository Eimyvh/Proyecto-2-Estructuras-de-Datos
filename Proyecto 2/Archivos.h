#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "ABPais.h"
#include "ArbolEspecialidadAA.h"
#include "ArbolDiagnosticoAA.h"

bool cargarPaises(ABPais& arbolPaises);
bool cargarEspecialidades(ArbolEspecialidadAA& arbolEspecialidades);
bool cargarDiagnosticos(ArbolDiagnosticoAA& arbolDiagnosticos);
#endif
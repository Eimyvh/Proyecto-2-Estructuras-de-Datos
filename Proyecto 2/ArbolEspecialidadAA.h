
#ifndef ARBOLESPECIALIDADAA_H
#define ARBOLESPECIALIDADAA_H
#include "NodoEspecialidadAA.h"

class ArbolEspecialidadAA
{
private:
    NodoEspecialidadAA* raiz;
    NodoEspecialidadAA* insertarRec(NodoEspecialidadAA* nodo, Especialidad valor);
    NodoEspecialidadAA* Giro(NodoEspecialidadAA* nodo);
    NodoEspecialidadAA* Reparto(NodoEspecialidadAA* nodo);
    void liberarMemoria(NodoEspecialidadAA* nodo);
public:
    ArbolEspecialidadAA();
    ~ArbolEspecialidadAA();
    void Insertar(Especialidad valor);
    bool Buscar(int idEspecialidad);
    Especialidad* Obtener(int idEspecialidad);
};
#endif

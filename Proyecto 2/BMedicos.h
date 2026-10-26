#ifndef BMEDICOS_H
#define BMEDICOS_H
#include "NodoMedicos.h"

class BMedicos {
private:
    NodoMedicos* raiz;

    void buscarNodo(string claveBusqueda, NodoMedicos* paginaActual, bool& encontrado, int& indiceRama);
    void empujar(string claveAInsertar, Medicos objetoMedico, NodoMedicos* paginaActual, bool& propagarDivision, Medicos& claveMediana, NodoMedicos*& nodoDerecho);
    void meterHoja(Medicos medicoAInsertar, NodoMedicos* nodoHijoDerecho, NodoMedicos* paginaActual, int indiceRama);
    void dividirNodo(Medicos medicoAInsertar, NodoMedicos* nodoHijoDerecho, NodoMedicos* paginaActual, int indiceRama, Medicos& claveMediana, NodoMedicos*& nuevoNodoDerecho);
    NodoMedicos* buscarRecursivo(string claveBusqueda, NodoMedicos* paginaActual);

public:
    BMedicos();
    void insertar(string id, Medicos objetoMedico);
    Medicos* buscar(string id);
};
#endif
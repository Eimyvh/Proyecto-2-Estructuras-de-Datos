#include "ArbolEspecialidadAA.h"

ArbolEspecialidadAA::ArbolEspecialidadAA()
{
    raiz = nullptr;
}

ArbolEspecialidadAA::~ArbolEspecialidadAA()
{
    liberarMemoria(raiz);
}

void ArbolEspecialidadAA::liberarMemoria(NodoEspecialidadAA* nodo)
{
    if (nodo != nullptr)
    {
        liberarMemoria(nodo->izquierda);
        liberarMemoria(nodo->derecha);
        delete nodo;
    }
}

void ArbolEspecialidadAA::Insertar(Especialidad valor)
{
    raiz = insertarRec(raiz, valor);

    if (raiz != nullptr)
    {
        raiz->padre = nullptr;
    }
}

NodoEspecialidadAA* ArbolEspecialidadAA::insertarRec(
    NodoEspecialidadAA* nodo, Especialidad valor)
{
    if (nodo == nullptr)
    {
        return new NodoEspecialidadAA(valor);
    }

    if (valor.getIdEspecialidad() < nodo->valor.getIdEspecialidad())
    {
        nodo->izquierda = insertarRec(nodo->izquierda, valor);

        if (nodo->izquierda != nullptr)
        {
            nodo->izquierda->padre = nodo;
        }
    }
    else if (valor.getIdEspecialidad() > nodo->valor.getIdEspecialidad())
    {
        nodo->derecha = insertarRec(nodo->derecha, valor);

        if (nodo->derecha != nullptr)
        {
            nodo->derecha->padre = nodo;
        }
    }
    else
    {
        return nodo;
    }
    nodo = Giro(nodo);
    nodo = Reparto(nodo);

    return nodo;
}

NodoEspecialidadAA* ArbolEspecialidadAA::Giro(NodoEspecialidadAA* nodo)
{
    if (nodo == nullptr)
    {
        return nodo;
    }
    if (nodo->izquierda != nullptr &&
        nodo->izquierda->nivel == nodo->nivel)
    {
        NodoEspecialidadAA* izq = nodo->izquierda;
        nodo->izquierda = izq->derecha;
        if (izq->derecha != nullptr)
        {
            izq->derecha->padre = nodo;
        }
        izq->derecha = nodo;
        izq->padre = nodo->padre;
        nodo->padre = izq;
        return izq;
    }
    return nodo;
}

NodoEspecialidadAA* ArbolEspecialidadAA::Reparto(NodoEspecialidadAA* nodo)
{
    if (nodo == nullptr)
    {
        return nodo;
    }
    if (nodo->derecha != nullptr &&
        nodo->derecha->derecha != nullptr &&
        nodo->nivel == nodo->derecha->derecha->nivel)
    {
        NodoEspecialidadAA* der = nodo->derecha;
        nodo->derecha = der->izquierda;

        if (der->izquierda != nullptr)
        {
            der->izquierda->padre = nodo;
        }
        der->izquierda = nodo;
        der->padre = nodo->padre;
        nodo->padre = der;
        der->nivel += 1;
        return der;
    }
    return nodo;
}

bool ArbolEspecialidadAA::Buscar(int idEspecialidad)
{
    NodoEspecialidadAA* actual = raiz;
    while (actual != nullptr)
    {
        if (idEspecialidad == actual->valor.getIdEspecialidad())
        {
            return true;
        }
        else if (idEspecialidad < actual->valor.getIdEspecialidad())
        {
            actual = actual->izquierda;
        }
        else
        {
            actual = actual->derecha;
        }
    }
    return false;
}

Especialidad* ArbolEspecialidadAA::Obtener(int idEspecialidad)
{
    NodoEspecialidadAA* actual = raiz;
    while (actual != nullptr)
    {
        if (idEspecialidad == actual->valor.getIdEspecialidad())
        {
            return &(actual->valor);
        }
        else if (idEspecialidad < actual->valor.getIdEspecialidad())
        {
            actual = actual->izquierda;
        }
        else
        {
            actual = actual->derecha;
        }
    }
    return nullptr;
}

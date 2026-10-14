
#include "ArbolDiagnosticoAA.h"

ArbolDiagnosticoAA::ArbolDiagnosticoAA()
{
    raiz = nullptr;
}

ArbolDiagnosticoAA::~ArbolDiagnosticoAA()
{
    liberarMemoria(raiz);
}

void ArbolDiagnosticoAA::liberarMemoria(NodoDiagnosticoAA* nodo)
{
    if (nodo != nullptr)
    {
        liberarMemoria(nodo->izquierda);
        liberarMemoria(nodo->derecha);
        delete nodo;
    }
}

void ArbolDiagnosticoAA::Insertar(Diagnostico valor)
{
    raiz = insertarRec(raiz, valor);

    if (raiz != nullptr)
    {
        raiz->padre = nullptr;
    }
}

NodoDiagnosticoAA* ArbolDiagnosticoAA::insertarRec(
    NodoDiagnosticoAA* nodo, Diagnostico valor)
{
    if (nodo == nullptr)
    {
        return new NodoDiagnosticoAA(valor);
    }

    if (valor.getCodDiagnostico() <
        nodo->valor.getCodDiagnostico())
    {
        nodo->izquierda = insertarRec(nodo->izquierda, valor);

        if (nodo->izquierda != nullptr)
        {
            nodo->izquierda->padre = nodo;
        }
    }
    else if (valor.getCodDiagnostico() >
        nodo->valor.getCodDiagnostico())
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

NodoDiagnosticoAA* ArbolDiagnosticoAA::Giro(
    NodoDiagnosticoAA* nodo)
{
    if (nodo == nullptr)
    {
        return nodo;
    }

    if (nodo->izquierda != nullptr &&
        nodo->izquierda->nivel == nodo->nivel)
    {
        NodoDiagnosticoAA* izq = nodo->izquierda;

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

NodoDiagnosticoAA* ArbolDiagnosticoAA::Reparto(
    NodoDiagnosticoAA* nodo)
{
    if (nodo == nullptr)
    {
        return nodo;
    }

    if (nodo->derecha != nullptr &&
        nodo->derecha->derecha != nullptr &&
        nodo->nivel == nodo->derecha->derecha->nivel)
    {
        NodoDiagnosticoAA* der = nodo->derecha;
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

bool ArbolDiagnosticoAA::Buscar(string codDiagnostico)
{
    NodoDiagnosticoAA* actual = raiz;
    while (actual != nullptr)
    {
        if (codDiagnostico == actual->valor.getCodDiagnostico())
        {
            return true;
        }
        else if (codDiagnostico <
            actual->valor.getCodDiagnostico())
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

Diagnostico* ArbolDiagnosticoAA::Obtener(string codDiagnostico)
{
    NodoDiagnosticoAA* actual = raiz;
    while (actual != nullptr)
    {
        if (codDiagnostico == actual->valor.getCodDiagnostico())
        {
            return &(actual->valor);
        }
        else if (codDiagnostico <
            actual->valor.getCodDiagnostico())
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

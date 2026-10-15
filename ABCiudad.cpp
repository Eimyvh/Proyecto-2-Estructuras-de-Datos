#include "ABCiudad.h"

ABCiudad::ABCiudad()
{
    raiz = nullptr;
}

void ABCiudad::InsertaNodo(Ciudad pCiudad)
{
    if (raiz == nullptr)
    {
        raiz = new NodoCiudad(pCiudad);
        return;
    }
    NodoCiudad* actual = raiz;
    while (true)
    {
        if (pCiudad.getCodCiudad() < actual->valor.getCodCiudad())
        {
            if (actual->Hizq == nullptr)
            {
                actual->Hizq = new NodoCiudad(pCiudad);
                return;
            }
            actual = actual->Hizq;
        }
        else if (pCiudad.getCodCiudad() > actual->valor.getCodCiudad())
        {
            if (actual->Hder == nullptr)
            {
                actual->Hder = new NodoCiudad(pCiudad);
                return;
            }
            actual = actual->Hder;
        }
        else
        {
            return;
        }
    }
}

bool ABCiudad::BuscarCiudad(int codCiudad)
{
    NodoCiudad* actual = raiz;
    while (actual != nullptr)
    {
        if (codCiudad == actual->valor.getCodCiudad())
        {
            return true;
        }
        if (codCiudad < actual->valor.getCodCiudad())
        {
            actual = actual->Hizq;
        }
        else
        {
            actual = actual->Hder;
        }
    }
    return false;
}

Ciudad* ABCiudad::ObtenerCiudad(int codCiudad)
{
    NodoCiudad* actual = raiz;

    while (actual != nullptr)
    {
        if (codCiudad == actual->valor.getCodCiudad())
        {
            return &(actual->valor);
        }
        else if (codCiudad < actual->valor.getCodCiudad())
        {
            actual = actual->Hizq;
        }
        else
        {
            actual = actual->Hder;
        }
    }

    return nullptr;
}
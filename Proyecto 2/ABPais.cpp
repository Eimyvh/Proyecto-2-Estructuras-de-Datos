#include "ABPais.h"
ABPais::ABPais()
{
    raiz = nullptr;
}

void ABPais::InsertaNodo(Pais pPais)
{
    if (raiz == nullptr)
    {
        raiz = new NodoPais(pPais);
        return;
    }
    NodoPais* actual = raiz;
    while (true)
    {
        if (pPais.getCodPais() < actual->valor.getCodPais())
        {
            if (actual->Hizq == nullptr)
            {
                actual->Hizq = new NodoPais(pPais);
                return;
            }
            actual = actual->Hizq;
        }
        else if (pPais.getCodPais() > actual->valor.getCodPais())
        {
            if (actual->Hder == nullptr)
            {
                aual->Hder = new NodoPais(pPais);
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

bool ABPais::BuscarPais(int codPais)
{
    NodoPais* actual = raiz;
    while (actual != nullptr)
    {
        if (codPais == actual->valor.getCodPais())
        {
            return true;
        }
        if (codPais < actual->valor.getCodPais())
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

Pais* ABPais::ObtenerPais(int codPais) 
{
    NodoPais* actual = raiz;

    while (actual != nullptr)
    {
        if (codPais == actual->valor.getCodPais())
        {
            return &(actual->valor);
        }
        else if (codPais < actual->valor.getCodPais())
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

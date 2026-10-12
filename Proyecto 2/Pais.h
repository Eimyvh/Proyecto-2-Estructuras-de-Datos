#ifndef PAIS_H
#define PAIS_H

#include <string>
using namespace std;

class Pais
{
private:
    int codPais;
    string nombre;

public:
    Pais(int pCodPais, string pNombre);

    int getCodPais();
    string getNombre();

    void setNombre(string pNombre);
};

#endif
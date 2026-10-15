#ifndef CIUDAD_H
#define CIUDAD_H
#include <string>
using namespace std;

class Ciudad
{
private:
    int codPais;
    int codCiudad;
    string nombre;
public:
    Ciudad(int pCodPais, int pCodCiudad, string pNombre);

    int getCodPais();
    int getCodCiudad();
    string getNombre();

    void setNombre(string pNombre);
};
#endif

#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H
#include <string>
using namespace std;

class Diagnostico
{
private:
    string codDiagnostico;
    string nombre;
    string descripcion;

public:
    Diagnostico(string pCodDiagnostico, string pNombre,
        string pDescripcion);

    string getCodDiagnostico();
    string getNombre();
    string getDescripcion();
};
#endif

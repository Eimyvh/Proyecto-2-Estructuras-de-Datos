#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
using namespace std;

class Tratamiento {
private:
    int idTratamiento;
    string nombre;
    string descripcion;
    double costo;

public:
    Tratamiento();
    Tratamiento(int pIdTratamiento, string pNombre, string pDescripcion, double pCosto);

    int getIdTratamiento() const;
    string getNombre() const;
    string getDescripcion() const;
    double getCosto() const;

    void setNombre(string pNombre);
    void setDescripcion(string pDescripcion);
    void setCosto(double pCosto);
};

#endif
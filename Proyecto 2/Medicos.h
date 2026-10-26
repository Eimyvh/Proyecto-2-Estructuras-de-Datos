#ifndef MEDICOS_H
#define MEDICOS_H
using namespace std;

class Medicos {
private:
    string idMedico;
    string nombre;
    string telefono;
    string correo;
    string idEspecialidad;
public:
    Medicos();
    Medicos(string id, string nom, string tel, string corr, string esp);
    string getIdMedico() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    string getIdEspecialidad() const;
    void mostrar() const;
};
#endif

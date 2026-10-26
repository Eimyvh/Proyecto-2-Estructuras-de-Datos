#ifndef CITAS_H
#define CITAS_H
#include <string>
using namespace std;

class Citas {
private:
    string idCita;
    string idPaciente;
    string idMedico;
    string idEspecialidad;
    string fecha;
    string hora;
    string motivo;
    string estado;
public:
    Citas();
    Citas(string idC, string idP, string idM, string idE, string f, string h, string mot, string est);
    string getIdCita() const;
    string getFecha() const;
    string getHora() const;
    string getMotivo() const;
    string getEstado() const;
    void mostrar() const;
};
#endif
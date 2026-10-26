#ifndef HOSPITALIZACIONES_H
#define HOSPITALIZACIONES_H
using namespace std;

class Hospitalizaciones {
private:
    string idHospitalizacion;
    string idPaciente;
    string idHabitacion;
    string idMedico;
    string fechaIngreso;
    string fechaSalida;
    string motivo;
public:
    Hospitalizaciones();
    Hospitalizaciones(string idH, string idP, string idHab, string idM, string fIng, string fSal, string mot);
    string getIdHospitalizacion() const;
    string getFechaIngreso() const;
    string getMotivo() const;
    void mostrar() const;
};
#endif
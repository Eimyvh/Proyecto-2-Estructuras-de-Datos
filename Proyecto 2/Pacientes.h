#ifndef PACIENTES_H
#define PACIENTES_H
using namespace std;

class Pacientes {
private:
    string idPaciente;
    string nombre;
    string fechaNacimiento;
    string telefono;
    string codPais;
    string codCiudad;
    string correo;

public:
    Pacientes();
    Pacientes(string id, string nom, string fn, string tel, string cPais, string cCiudad, string corr);

    string getIdPaciente() const;
    string getNombre() const;
    string getFechaNacimiento() const;
    string getTelefono() const;
    string getCodPais() const;
    string getCodCiudad() const;
    string getCorreo() const;

    void mostrar() const;
};

#endif
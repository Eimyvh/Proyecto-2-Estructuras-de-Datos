#ifndef AVLHABITACION_H
#define AVLHABITACION_H
#include "NodoHabitacion.h"

class AVLHabitacion {
private:
    NodoHabitacion* raiz;
    int obtenerAltura(NodoHabitacion* nodo);
    int obtenerBalance(NodoHabitacion* nodo);
    int calcularMaximo(int alturaIzquierda, int alturaDerecha);
    NodoHabitacion* rotacionDerecha(NodoHabitacion* nodoDesbalanceado);
    NodoHabitacion* rotacionIzquierda(NodoHabitacion* nodoDesbalanceado);
    NodoHabitacion* insertarRecursivo(NodoHabitacion* nodoActual, Habitacion pHabitacion, bool& fueInsertado);

public:
    AVLHabitacion();
    void InsertaNodo(Habitacion pHabitacion);
    bool BuscarHabitacion(int idHabitacion);
    Habitacion* ObtenerHabitacion(int idHabitacion);
};
#endif
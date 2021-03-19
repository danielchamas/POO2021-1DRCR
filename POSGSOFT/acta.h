#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include "detallesCriterio.h"
#include <ctime>
using std::list;
using namespace std;

enum class tipoTrabajo
{
    aplicado = 1,
    investigacion = 2

};

enum class estadoActa
{
    abierto = 1,
    cerrado = 2
};

enum class estadoEvaluacion
{
    aprobado = 1,
    rechazado = 2,
    pendiente = 3
};

class Acta
{
private:
    int numero;
    string fecha;
    string nombreTrabajo;
    tipoTrabajo tipo;
    string periodo;
    string director;
    string codirector;
    string jurado1;
    string jurado2;
    list<DetallesCriterio> listaDetallesCriterio; 
    string obsevaciones;
    string condiciones;
    float calificaciontotal;
    estadoActa estadoActa;
    estadoEvaluacion estadoEval;
public:
    Acta();
    Acta( int );
    int calcularNotafinal();
    void cerrarActa();
    void setEstadoActual(int);
    tipoTrabajo getTipoTrabajo();
    void incluirObservaciones();
    void incluirCondiciones();
    estadoEvaluacion getEstadoEvaluacion();
};

#endif

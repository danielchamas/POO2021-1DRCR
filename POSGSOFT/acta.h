#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include "detallesCriterio.h"
#include <ctime>
#include "persona.h"
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
    string enfasis;
    Persona estudiante;
    Persona director;
    Persona codirector;
    Persona jurado1;
    Persona jurado2;
    list<DetallesCriterio> listaDetallesCriterio; 
    string obsevaciones;
    string condiciones;
    float calificacionTotal;
    estadoActa estadoAct; // No pueden ser del mismo nombre
    estadoEvaluacion estadoEval;
public:
    ~Acta();
    Acta(int);
    void calcularNotafinal();
    void cerrarActa();
    tipoTrabajo getTipoTrabajo();
    void incluirObservaciones();
    void incluirCondiciones();
    void setEstadoEvaluacion(int);
    estadoEvaluacion getEstadoEvaluacion();
    void calificarCriterio(int, Criterio);
    void mostrarActa();
    Persona getJurado1();
    Persona getJurado2();
    string getNombreTrabajo();
    estadoActa getEstadoAct();
    void eliminarActa();
    int getNumero();
    void setEstudiante(Persona);
    void setJurado1(Persona);
    void setJurado2(Persona);
    void setDirector(Persona);
    void setCodirector(Persona);
};

#endif
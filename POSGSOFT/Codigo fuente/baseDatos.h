#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <iostream>
#include <list>
#include "acta.h"
#include "criterio.h"
#include "persona.h"

using namespace std;

class BaseDatos
{
private:
    int contadorActas, contadorCriterios;
    list<Acta> listaActas;
    list<Criterio> listaCriterios;
    list<Persona> listaPersonas;
public:
    BaseDatos();
    void listarActas();
    void listarTrabajosJurado(Persona); // Lista las actas en las que la persona ha sido jurado
    void listarTrabajosProfesor(Persona); // Lista las actas en las que la persona ha sido jurado interno
    void listarTrabajosAplicado();
    void listarTrabajosInvestigacion();
    void listarJurados(); // Listar los jurados participantes en las actas.
    void listarActasPendientes();
    void listarActasRechazadas();
    void listarActasAbiertas();
    void listarActasCerradas();
    void listarJuradosInternos();
    void listarJuradosExternos();
    void listarCriterios();
    void crearActa();  
    void eliminarActas();
    void crearPersona();
    Persona buscarPersonaRol(rol);
    Persona validarPersona();
    void crearCriterio();
    int verificarPorcentaje();
    float calcularPorcentajeTotal();
    void calificarCriteriosActa(int);
    void incluirObservacionesActa(int);
    void incluirCondicionesActa(int);
    int validarActa();
    void cerrarActas(int);
};

#endif
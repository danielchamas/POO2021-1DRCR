#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <iostream>
#include <list>
#include "acta.h"
#include "Criterio.h"
#include "persona.h"

using namespace std;

class BaseDatos
{
private:
    list<Acta> listaActas;
    list<Criterio> listaCriterios;
    list<Persona> listaPersonas;
public:
    BaseDatos();
    void generarArchivo();
    void listarActas();
    void listarTrabajosJurado();
    void listarTrabajosProfesor();
    void listarJurado();
    void mostrarActasPendientes();
    void mostrarActasRechazadas();
    void mostrarJuradosInternos();
    void mostrarJuradosExternos();
    void mostrarCriterios();
    void agregarCriterioLista( Criterio );
    void agregarActaLista( Acta );
};

#endif
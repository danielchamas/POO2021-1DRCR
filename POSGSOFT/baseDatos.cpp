#include "baseDatos.h"

BaseDatos::BaseDatos()
{
    // Se declaran los 8 criterios por defecto
    this->listaCriterios.push_back(Criterio(1, "Desarrollo y profundidad en el tratamiento del tema", 20));
    this->listaCriterios.push_back(Criterio(2, "Desafio academico y cientifico del tema", 15));
    this->listaCriterios.push_back(Criterio(3, "Cumplimiento de los objetivos propuestos", 10));
    this->listaCriterios.push_back(Criterio(4, "Creatividad e innovacion de las soluciones y desarrollos propuestos", 10));
    this->listaCriterios.push_back(Criterio(5, "Validez de los resultados y conclusiones", 20));
    this->listaCriterios.push_back(Criterio(6, "Manejo y procesamiento de la informacion y bibliografia", 10));
    this->listaCriterios.push_back(Criterio(7, "Calidad y presentacion del documento escrito", 7.5));
    this->listaCriterios.push_back(Criterio(8, "Presentacion oral", 7.5));
    this->listaActas.push_back(Acta(1));
    this->listaActas.push_back(Acta(2));
}

void BaseDatos::listarCriterios()
{
    for (list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        it->mostrarCriterio();
    }
}

void BaseDatos::listarActas()
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        it->mostrarActa();
    }
}

void BaseDatos::listarTrabajosJurado(Persona persona)
{
    int numeroActas;
    cout << endl;
    cout << "Actas que ha participado como jurado:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre de la persona esta de jurado en algun acta
        if( (it->getJurado1()).getNombre() == persona.getNombre() || 
        (it->getJurado2()).getNombre() == persona.getNombre() )
        {
            it->getNombreTrabajo();
            numeroActas++;
        }
        cout << "Numero de actas: " << numeroActas << endl;
    }
}

void BaseDatos::listarTrabajosProfesor(Persona persona)
{
    int numeroActas;
    if(persona.getTipo() != tipo::interno)
    {
        cout << "La persona no es profesor" << endl;
        return;
    }
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre de la persona esta de jurado en algun acta
        if( (it->getJurado1()).getNombre() == persona.getNombre() || 
        (it->getJurado2()).getNombre() == persona.getNombre())
        {
            it->mostrarActa();
            numeroActas++;
        }
        cout << "Numero de actas: " << numeroActas << endl;
    }
}

void BaseDatos::listarJurados()
{
    cout << "Lista de jurados participantes: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->rol.begin(); it2 != it->rol.end(); it2++)
        {
            if(*it2 == rol::jurado)
            {
                cout << it->getNombre() << endl;
                break;
            }
        }
    }
}

void BaseDatos::listarJuradosExternos()
{
    cout << "Lista de jurados externos: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->rol.begin(); it2 != it->rol.end(); it2++)
        {
            if(*it2 == rol::jurado && it->getTipo() == tipo::externo)
            {
                cout << it->getNombre() << endl;
                break;
            }
        }
    }
}

void BaseDatos::listarJuradosInternos()
{
    cout << "Lista de jurados internos: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->rol.begin(); it2 != it->rol.end(); it2++)
        {
            if(*it2 == rol::jurado && it->getTipo() == tipo::interno)
            {
                cout << it->getNombre() << endl;
                break;
            }
        }
    }
}
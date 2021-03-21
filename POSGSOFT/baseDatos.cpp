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
    this->contadorActas = 0;
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

void BaseDatos::listarActasAbiertas()
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getEstadoAct() == estadoActa::abierto)
        {
            it->mostrarActa();
        }
        
    }
    
}
void BaseDatos::listarActasCerradas()
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getEstadoAct() == estadoActa::cerrado)
        {
            it->mostrarActa();
        }
        
    }
    
}

void BaseDatos::listarActasPendientes()
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getEstadoEvaluacion() == estadoEvaluacion::pendiente)
        {
            it->mostrarActa();
        }
    }
}

void BaseDatos::listarActasRechazadas()
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getEstadoEvaluacion() == estadoEvaluacion::rechazado)
        {
            it->mostrarActa();
        }
    }
}

void BaseDatos::listarTrabajosJurado(Persona persona)
{
    int numeroActas;
    cout << endl;
    cout << "Actas que ha participado como jurado:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre de la persona esta de jurado en algun acta.
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
    // Verifica si es profesor (interno).
    if(persona.getTipo() != tipo::interno)
    {
        cout << "La persona no es profesor" << endl;
        return;
    }
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre de la persona esta de jurado en algun acta.
        if( (it->getJurado1()).getNombre() == persona.getNombre() || 
        (it->getJurado2()).getNombre() == persona.getNombre())
        {
            it->getNombreTrabajo();
            numeroActas++;
        }
        cout << "Numero de actas: " << numeroActas << endl;
    }
}

void BaseDatos::listarTrabajosAplicado()
{
    int numeroActas;
    cout << endl;
    cout << "Lista de trabajos aplicados:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el trabajo es de tipo aplicado.
        if(it->getTipoTrabajo() == tipoTrabajo::aplicado)
        {
            it->getNombreTrabajo();
            numeroActas++;
        }
        cout << "Numero de actas: " << numeroActas << endl;
    }
}

void BaseDatos::listarTrabajosInvestigacion()
{
    int numeroActas;
    cout << endl;
    cout << "lista de trabajos de investigacion:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el trabajo es de tipo investigacion.
        if(it->getTipoTrabajo() == tipoTrabajo::investigacion)
        {
            it->getNombreTrabajo();
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
            if(*it2 == rol::jurado) // Verifica si la persona tiene rol de jurado.
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
            if(*it2 == rol::jurado && it->getTipo() == tipo::externo) // Verifica si la persona tiene rol de jurado y es externo.
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
            if(*it2 == rol::jurado && it->getTipo() == tipo::interno) // Verifica si la persona tiene rol de jurado y es externo.
            {
                cout << it->getNombre() << endl;
                break;
            }
        }
    }
}

void BaseDatos::eliminarActas()
{
    int acta;
    cout << "Digite el numero del acta a eliminar: " << endl;
    cin >> acta;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(acta == it->getNumero()) // Verifica el numero del acta para poder eliminar
        {
            it->eliminarActa();
            break;
        }
        else
        {
            cout << "Error. Acta no registrada." << endl;
        }
    }   
}

void BaseDatos::crearActa()
{
    Acta actaTemporal(++this->contadorActas);
    listaActas.push_back(actaTemporal);
}

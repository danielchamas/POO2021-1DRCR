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
    int numeroActas = 0;
    cout << endl;
    cout << "Actas que ha participado como jurado:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre de la persona esta de jurado en algun acta.
        if( (it->getJurado1()).getNombre() == persona.getNombre() || 
        (it->getJurado2()).getNombre() == persona.getNombre() )
        {
            cout << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarTrabajosProfesor(Persona persona)
{
    int numeroActas = 0;
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
            cout << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarTrabajosAplicado()
{
    int numeroActas = 0;
    cout << endl;
    cout << "Lista de trabajos aplicados:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el trabajo es de tipo aplicado.
        if(it->getTipoTrabajo() == tipoTrabajo::aplicado)
        {
            cout << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarTrabajosInvestigacion()
{
    int numeroActas = 0;
    cout << endl;
    cout << "lista de trabajos de investigacion:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el trabajo es de tipo investigacion.
        if(it->getTipoTrabajo() == tipoTrabajo::investigacion)
        {
            cout << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarJurados()
{
    cout << "Lista de jurados participantes: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->listaRoles.begin(); it2 != it->listaRoles.end(); it2++) 
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
        for(list<rol>::iterator it2 = it->listaRoles.begin(); it2 != it->listaRoles.end(); it2++)
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
        for(list<rol>::iterator it2 = it->listaRoles.begin(); it2 != it->listaRoles.end(); it2++)
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

Persona BaseDatos::buscarPersonaRol(rol estudiante)
{ 
    long int id;  // Bandera para saber si la persona fue encontrada en la lista
    cout << "Ingrese el ID: " << endl;
    cin >> id;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        if(it->getId() == id)
        {
            it->agregarRol(estudiante);
            return *it;
        }
    }
    cout << "ID no registrado, no se puede crear el acta." << endl;
    return Persona("NA", 0, "NA", tipo::externo);
}

void BaseDatos::crearActa()
{
    int opcion;
    long int id;
    Persona personaTemporal;
    Acta actaTemporal(++this->contadorActas);
    cout << "Estudiante" << endl;
    // Incorporando estudiante
    personaTemporal = buscarPersonaRol(rol::estudiante);
    if(personaTemporal.getNombre() == "NA")
    {
        return;
    }
    actaTemporal.setEstudiante(personaTemporal);
    cout << "Director" << endl;
    // Incorporando director
    personaTemporal = buscarPersonaRol(rol::director);
    if(personaTemporal.getNombre() == "NA")
    {
        return;
    }
    actaTemporal.setDirector(personaTemporal);
    cout << "Jurado 1" << endl;
    // Incorporando jurado 1
    personaTemporal = buscarPersonaRol(rol::jurado);
    if(personaTemporal.getNombre() == "NA")
    {
        return;
    }
    actaTemporal.setJurado1(personaTemporal);
    cout << "Jurado 2" << endl;
    personaTemporal = buscarPersonaRol(rol::jurado);
    if(personaTemporal.getNombre() == "NA")
    {
        return;
    }
        actaTemporal.setJurado2(personaTemporal);
    // Preguntar si hay codirector
    cout << "Desea incorporar un codirector?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            cout << "Codirector" << endl;
            personaTemporal = buscarPersonaRol(rol::director);
            if(personaTemporal.getNombre() == "NA")
            {
                return;
            }
            actaTemporal.setCodirector(personaTemporal);
        default:
            actaTemporal.setCodirector(Persona("NA", 0, "NA", tipo::externo));
    }
    listaActas.push_back(actaTemporal);
    cout << "Acta creada con exito" << endl << endl;
}

void BaseDatos::crearPersona()
{
    int opcion, flag; // Bandera para saber si fue encontrada una persona con ID repetido
    long int id;
    string nombre, email;
    tipo tipo;
    cout << "Ingrese el nombre:" << endl;
    getline(cin >> ws, nombre);
    do{
        flag = 0;
        cout << "Ingrese el numero de identificacion:" << endl;
        cin >> id;
        for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
        {   // Busca si hay una persona con el mismo ID que el ingresado
            if(it->getId() == id)
            {
                cout << "Error. ID repetido. Intentalo de nuevo" << endl;
                flag = 1;
                break;
            }
        }
    } while(flag == 1);
    cout << "Ingrese el correo:" << endl;
    cin >> email;
    do{ // Se pregunta el tipo de persona. Si escoje una opcion incorrecta le da otro intento
        // hasta que elija una opcion correcta 
        cout << "Ingrese el tipo de persona:" << endl;
        cout << "1. Externo" << endl;
        cout << "2. Interno" << endl;
        cin >> opcion;
        switch( opcion )
        {
            case 1:
                tipo = tipo::externo;
                break;
            case 2:
                tipo = tipo::interno;
                break;
            default:
                cout << "Error. Opcion incorrecta. Intentelo de nuevo." << endl;
        }
    } while( opcion < 1 || opcion > 2 );
    Persona personaTemporal(nombre, id, email, tipo);
    this->listaPersonas.push_back(personaTemporal);
}

Persona BaseDatos::validarPersona() 
{
    long int id;
    cout << "Ingresa el ID de la persona" << endl;
    cin >> id;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        if(it->getId() == id)
        {
            return *it;
        }
    }
    cout << "ID no registrado." << endl;
    return Persona("NA", 0, "NA", tipo::externo);
}
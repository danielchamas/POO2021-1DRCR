#include "baseDatos.h"
#include <conio.h>

BaseDatos::BaseDatos()
{
    
    this->contadorActas = 1; // Contador de las actas registradas
    this->contadorCriterios = 8;
    // Se declaran los 8 criterios por defecto
    this->listaCriterios.push_back(Criterio(1, "Desarrollo y profundidad en el tratamiento del tema", 20));
    this->listaCriterios.push_back(Criterio(2, "Desafio academico y cientifico del tema", 15));
    this->listaCriterios.push_back(Criterio(3, "Cumplimiento de los objetivos propuestos", 10));
    this->listaCriterios.push_back(Criterio(4, "Creatividad e innovacion de las soluciones y desarrollos propuestos", 10));
    this->listaCriterios.push_back(Criterio(5, "Validez de los resultados y conclusiones", 20));
    this->listaCriterios.push_back(Criterio(6, "Manejo y procesamiento de la informacion y bibliografia", 10));
    this->listaCriterios.push_back(Criterio(7, "Calidad y presentacion del documento escrito", 7.5));
    this->listaCriterios.push_back(Criterio(8, "Presentacion oral", 7.5));

    this->listaPersonas.push_back(Persona("Esteban Quito", 1, "estebannq@gmail.com", tipo::interno));
    this->listaPersonas.push_back(Persona("Armando Casas Torres", 2, "armandocasas@gmail.com", tipo::externo));
    this->listaPersonas.push_back(Persona("Héctor Tuga", 3, "hectrtug@outlook.com", tipo::interno));
    this->listaPersonas.push_back(Persona("Elba Lazo Fuertes", 4, "elbalazito@yahoo.com", tipo::externo));
    this->listaPersonas.push_back(Persona("Susana Oria", 5, "oriasana@outlook.com", tipo::interno));
    this->listaPersonas.push_back(Persona("Alex Plosivo", 6, "alexploplo@yahoo.com", tipo::interno));
    this->listaPersonas.push_back(Persona("Oscar Pintero", 7, "carpintero@gmail.com", tipo::interno));
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
    int numeroActas = 0, cont = 0;
    cout << endl;
    cout << endl << "Actas que ha participado como jurado:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre de la persona esta de jurado en algun acta.
        if( (it->getJurado1()).getNombre() == persona.getNombre() || 
        (it->getJurado2()).getNombre() == persona.getNombre() )
        {
            cout << ++cont << ") " << it->getNombreTrabajo() << endl; // Imprime el nombre del acta en la que participa la persona
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarTrabajosProfesor(Persona persona)
{
    int numeroActas = 0, cont = 0;
    // Verifica si es profesor (interno).
    if(persona.getTipo() != tipo::interno)
    {
        cout << "La persona no es profesor" << endl;
        return;
    }
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el nombre del director está en algun acta.
        if( (it->getDirector()).getNombre() == persona.getNombre())
        {
            cout << ++cont << ") " << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarTrabajosAplicado()
{
    int numeroActas = 0, cont = 0;
    cout << endl;
    cout << "Lista de trabajos aplicados:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el trabajo es de tipo aplicado.
        if(it->getTipoTrabajo() == tipoTrabajo::aplicado)
        {
            cout << ++cont << ") " << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarTrabajosInvestigacion()
{
    int numeroActas = 0, cont = 0;
    cout << endl;
    cout << "lista de trabajos de investigacion:" << endl << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {   // Verifica si el trabajo es de tipo investigacion.
        if(it->getTipoTrabajo() == tipoTrabajo::investigacion)
        {
            cout << ++cont << ") " << it->getNombreTrabajo() << endl;
            numeroActas++;
        }
    }
    cout << "Numero de actas: " << numeroActas << endl;
}

void BaseDatos::listarJurados()
{
    int cont = 0;
    cout << endl << "Lista de jurados participantes: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->listaRoles.begin(); it2 != it->listaRoles.end(); it2++) 
        {
            if(*it2 == rol::jurado) // Verifica si la persona tiene rol de jurado.
            {
                cout << ++cont << ")" << it->getNombre() << endl;
                break;
            }
        }
    }
}

void BaseDatos::listarJuradosExternos()
{
    int cont = 0;
    cout << endl << "Lista de jurados externos: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->listaRoles.begin(); it2 != it->listaRoles.end(); it2++)
        {
            if(*it2 == rol::jurado && it->getTipo() == tipo::externo) // Verifica si la persona tiene rol de jurado y es externo.
            {
                cout << ++cont << ") "<< it->getNombre() << endl;
                break;
            }
        }
    }
}

void BaseDatos::listarJuradosInternos()
{
    int cont = 0;
    cout << endl << "Lista de jurados internos: " << endl << endl;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        for(list<rol>::iterator it2 = it->listaRoles.begin(); it2 != it->listaRoles.end(); it2++)
        {
            if(*it2 == rol::jurado && it->getTipo() == tipo::interno) // Verifica si la persona tiene rol de jurado y es externo.
            {
                cout << ++cont << ") " << it->getNombre() << endl;
                break;
            }
        }
    }
}

void BaseDatos::eliminarActas()
{
    int acta;
    cout << endl << "Digite el numero del acta a eliminar: " << endl;
    cin >> acta;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(acta == it->getNumero()) // Verifica el numero del acta para poder eliminar
        {
            it->eliminarActa();
            listaActas.erase(it); //Elimina el objeto de la lista de actas
            return;
        }
    }
    cout << "Error. Acta no registrada." << endl;
}

Persona BaseDatos::buscarPersonaRol(rol rol)
{ 
    long int id;  // Bandera para saber si la persona fue encontrada en la lista
    cout << "Ingrese el ID: " << endl;
    cin >> id;
    for (list<Persona>::iterator it = listaPersonas.begin(); it != listaPersonas.end(); it++)
    {
        if(it->getId() == id) // Verifica el Id en la lista de personas para ver si ya esta registrada.
        {
            it->agregarRol(rol);
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
    Acta actaTemporal(this->contadorActas); // Le pasamos el contador de actas que lleva el registro de actas totales.
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
    // Incorporando jurado 2
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
            break;
        default:
            actaTemporal.setCodirector(Persona("NA", 0, "NA", tipo::externo));
    }
    //Agregar detalles criterio a Criterios.
    for (list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        actaTemporal.listaDetallesCriterio.push_back(DetallesCriterio(*it));
    }
    listaActas.push_back(actaTemporal); //Agregar el acta a la lista de actas.
    cout << "Acta creada con exito" << endl << endl;
    this->contadorActas++;
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
    Persona personaTemporal(nombre, id, email, tipo); //Crea la persona
    this->listaPersonas.push_back(personaTemporal); // Agrega la persona a la lista de personas
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

float BaseDatos::calcularPorcentajeTotal()
{   //Calcula el porcentaje total de ponderacion de los criterios
    float sumaPorcentajes;
    for (list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        sumaPorcentajes += it->getPorcentajePonderacion();
    }
    return sumaPorcentajes;
}

int BaseDatos::verificarPorcentaje()
{   // Verifica que el nuevo porcentaje de ponderacion sea igual a 100.
    int id;
    float porcentaje, sumaPorcentajes;
    while(sumaPorcentajes != 100)
    {
        cout << endl << "El porcentaje de ponderacion total no es igual a 100%" << endl;
        listarCriterios();
        cout << endl << "Porcentaje total actual: " << calcularPorcentajeTotal() << endl;
        cout << "Elija un criterio para cambiar su porcentaje: ";
        cin >> id; cout << endl;
        for (list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
        {   // Se recorre la lista de criterios para encontrar el criterio a cambiar
            if(it->getIdentificador() == id)
            {
                cout << endl << "Ingrese el nuevo porcentaje de ponderacion: ";
                cin >> porcentaje; cout << endl;
                it->setPorcentajePonderacion(porcentaje);
                break;
            }
        }
        sumaPorcentajes = calcularPorcentajeTotal();
    }
    cout << endl << "Porcentajes de ponderacion correctamente balanceados." << endl;
    getch();
}

void BaseDatos::crearCriterio()
{
    int id = ++this->contadorCriterios; 
    string texto;
    float porcentaje;
    cout << "Ingresa el nombre del criterio" << endl;
    getline(cin >> ws, texto);
    cout << "Ingresa el porcentaje de ponderacion" << endl;
    cin >> porcentaje;
    Criterio criterioTemporal(id, texto, porcentaje);
    listaCriterios.push_back(criterioTemporal); // Agrega el criterio nuevo a la lista de criterios.
    verificarPorcentaje(); // Verificar que el porcentaje de ponderación total sea 100%
}

int BaseDatos::validarActa()
{   // Verifica que el acta exista en la lista de actas.
    int id;
    cout << endl << "Ingrese el ID del acta a calificar: ";
    cin >> id;
    cout << endl;
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getNumero() == id)
        {
            return id;
        }
    }
    return 0;
}

void BaseDatos::calificarCriteriosActa(int id)
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getNumero() == id)
        {
            it->calificarCriterios();
            return;
        }
    }
    cout << "Error. Acta no encontrada." << endl;
}

void BaseDatos::incluirObservacionesActa(int id)
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getNumero() == id)
        {
            it->incluirObservaciones();
            return;
        }
    }
    cout << "Error. Acta no encontrada." << endl;
}

void BaseDatos::incluirCondicionesActa(int id)
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getNumero() == id)
        {
            it->evaluarCondiciones();
            return;
        }
    }
    cout << "Error. Acta no encontrada." << endl;
}

void BaseDatos::cerrarActas(int id)
{
    for(list<Acta>::iterator it = listaActas.begin(); it != listaActas.end(); it++)
    {
        if(it->getNumero() == id)
        {
            if(it->getEstadoEvaluacion() != estadoEvaluacion::pendiente) // No se puede cerrar un acta en estado de evaluacion pendiente.
            {
                it->cerrarActa();
                cout << endl << "====Acta cerrada exitosamente===" << endl;
                getch();

            }
            else
            {
                cout << endl << "===No se puede cerrar un acta pendiente===" << endl;
            }
            return;
        }
    }
    cout << "Error. Acta no encontrada." << endl;
}
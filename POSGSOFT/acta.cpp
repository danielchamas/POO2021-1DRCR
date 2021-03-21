#include "acta.h"

Acta::Acta(int numeroActa)
{
    int opcion;
    this->numero = numeroActa;
    time_t fecha = time(0); // Establece la fecha actual
    this->fecha = ctime(&fecha); // Se convierte a string
    cout << "Ingrese el nombre del acta" << endl;
    getline(cin >> ws, this->nombreTrabajo);
    do{ // Si no se ingresa una opcion valida, la pregunta se repite hasta que ingrese una valida.
        cout << endl << "Ingrese el tipo de trabajo del acta" << endl;
        cout << "1. Aplicado" << endl;
        cout << "2. Investigacion" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch(opcion)
        {
            case 1:
                this->tipo = tipoTrabajo::aplicado;
                break;
            case 2:
                this->tipo = tipoTrabajo::investigacion;
                break;
            default:
                cout << "Opcion incorrecta. Intentalo de nuevo." << endl;
        }
    } while(opcion < 1 || opcion > 2);
    cout << "Ingrese el periodo" << endl;
    cin >> this->periodo;
    cout << "Ingrese el enfasis" << endl;
    getline(cin >> ws, this->enfasis);
    this->estadoAct = estadoActa::abierto;
    this->estadoEval = estadoEvaluacion::pendiente;
}

void Acta::calcularNotafinal()
{
    float notaFinal = 0;
    for (list<DetallesCriterio>::iterator it = listaDetallesCriterio.begin(); it != listaDetallesCriterio.end(); it++)
    {
        // Nota final es la suma de: cada nota parcial por el porcentaje de ponderacion del criterio / 100
        notaFinal += it->calcularCalificacionParcial() * it->getCriterio().getPorcentajePonderacion() / 100;
    }
    this->calificacionTotal = notaFinal;
}

void Acta::cerrarActa()
{
    this->estadoAct = estadoActa::cerrado;
}

void Acta::setEstadoEvaluacion(int estado)
{
    switch(estado)
    {
        case 1:
            this->estadoEval = estadoEvaluacion::aprobado;
            break;
        case 2:
            this->estadoEval = estadoEvaluacion::pendiente;
            break;
        case 3:
            this->estadoEval = estadoEvaluacion::rechazado;
            break;
        default: 
            cout << "Error. Digite un campo valido";
            break;
    }
}

tipoTrabajo Acta::getTipoTrabajo()
{
    return this->tipo;
}

void Acta::incluirObservaciones()
{
    cout << "Ingrese las observaciones" << endl;
    cin >> this->obsevaciones;
}

void Acta::incluirCondiciones()
{
    cout << "Ingrese las condiciones de aprobacion" << endl;
    cin >> this->condiciones;
}

estadoEvaluacion Acta::getEstadoEvaluacion()
{
    return this->estadoEval;
}

void Acta::calificarCriterio(int id, Criterio criterio)
{
    DetallesCriterio criterioTemporal(id, criterio); // Aqui se guarda la info para luego añadirla a la lista
    criterioTemporal.setCalificacion();
    criterioTemporal.setObservacion();
    this->listaDetallesCriterio.push_back(criterioTemporal); //Se agrega a la lista Detalles criterio
}

void Acta::mostrarActa()
{
    cout << endl;
    cout << "Acta #" << this->numero << endl << endl;
    cout << "Nombre: " << this->nombreTrabajo << endl;
    cout << "Enfasis: " << this->enfasis << endl;
    cout << "Fecha: " << this->fecha;
    cout << "Estudiante: " << this->estudiante.getNombre() << endl;
    cout << "Estado del acta: ";

    if(this->estadoAct == estadoActa::abierto)
    
        cout << "Abierto" << endl;
    
    else
    {
        cout << "Cerrado" << endl;
    }
    if(this->calificacionTotal < 0 || this->calificacionTotal > 5)
    {
        cout << "Calificacion: NA" << endl;
    }
    else
    {
        cout << "Calificacion: " << this->calificacionTotal << endl;
    }
    cout << "Estado evaluacion: ";
    if(this->estadoEval == estadoEvaluacion::aprobado)
    {
        cout << "Aprobado" << endl;
    }
    else if(this->estadoEval == estadoEvaluacion::pendiente)
    {
        cout << "Pendiente" << endl;
    }
    else
    {
        cout << "Rechazado" << endl;
    } 
}

Persona Acta::getJurado1()
{
    return this->jurado1;
}

Persona Acta::getJurado2()
{
    return this->jurado2;
}

string Acta::getNombreTrabajo()
{
    return this->nombreTrabajo;
}

estadoActa Acta::getEstadoAct()
{
    return this->estadoAct;
}

Acta::~Acta()
{
    
}

//nombreDeLaVariable.~Acta();

void Acta::eliminarActa()
{
    this->jurado1.listaRoles.remove(rol::jurado);
    this->jurado2.listaRoles.remove(rol::jurado);
    this->estudiante.listaRoles.remove(rol::estudiante);
    this->director.listaRoles.remove(rol::director);
    if( this->codirector.getNombre() != "NA" )
    {
        this->codirector.listaRoles.remove(rol::director);
    }
    this->~Acta();
}

int Acta::getNumero()
{
    return this->numero;
}

void Acta::setEstudiante(Persona estudiante)
{
    this->estudiante = estudiante;
}

void Acta::setJurado1(Persona jurado1)
{
    this->jurado1 = jurado1;
}

void Acta::setJurado2(Persona jurado2)
{
    this->jurado2 = jurado2;
}

void Acta::setDirector(Persona director)
{
    this->director = director;
}

void Acta::setCodirector(Persona codirector)
{
    this->codirector = codirector;
}
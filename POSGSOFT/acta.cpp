#include "acta.h"

Acta::Acta(int numeroActa)
{
    int opcion;
    this->numero = numeroActa;
    time_t fecha = time(0); // Establece la fecha actual
    this->fecha = ctime(&fecha); // Se convierte a string
    cout << "Ingrese el nombre del acta" << endl;
    cin >> this->nombreTrabajo;
    do{ // Si no se ingresa una opcion valida, la pregunta se repite hasta que ingrese una valida.
        cout << "Ingrese el tipo de trabajo del acta" << endl;
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
    /*
        Pendiente: añadir director, codirector, estudiante y jurados
    */
    this->estadoActa = estadoActa::abierto;
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
    this->estadoActa = estadoActa::cerrado;
}

void Acta::setEstadoActual(int estado)
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
    cout << "Fecha: " << this->fecha;
    cout << "Estudiante: " << this->estudiante.getNombre();
    cout << "Estado del acta: "; //<< static_cast<char>(this->estadoActa);

    if(this->estadoActa == estadoActa::abierto)
    
        cout << "Abierto" << endl;
    
    else
    {
        cout << "Cerrado" << endl;
    }
    if(this->calificacionTotal < 0 || this->calificacionTotal > 5)
    {
        cout << "Calificacion: NA";
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

Persona Acta::getJurado1()
{
    return this->jurado2;
}

string Acta::getNombreTrabajo()
{
    return this->nombreTrabajo;
}
#include "acta.h"

Acta::Acta(int numeroActa)
{
    int opcion;
    this->numero = numeroActa;
    time_t fecha = time(0);
    this->fecha = ctime(&fecha);
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

int Acta::calcularNotafinal()
{
    int notaFinal = 0, contadorCriterios = 0;
    for (list<DetallesCriterio>::iterator it = listaDetallesCriterio.begin(); it != listaDetallesCriterio.end(); it++)
    {
        notaFinal += it->calcularCalificacionParcial();
        contadorCriterios++;
    }
    notaFinal /= contadorCriterios;
    return notaFinal;
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
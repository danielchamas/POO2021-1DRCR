#include "acta.h"
#include <iomanip>

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
    this->estadoEval = estadoEvaluacion::aprobado; /// cambiar a pendiente????????????????????????????????????????
    this->calificacionTotal = 0;
}

void Acta::calcularNotaFinal()
{
    float notaFinal = 0;
    for (list<DetallesCriterio>::iterator it = listaDetallesCriterio.begin(); it != listaDetallesCriterio.end(); it++)
    {
        // Nota final es la suma de: cada nota parcial por el porcentaje de ponderacion del criterio / 100
        notaFinal += it->calcularCalificacionParcial() * it->getCriterio().getPorcentajePonderacion() / 100;
    }
    this->calificacionTotal = notaFinal;
    if( notaFinal > 3.5 && this->condiciones == "")
    {
        this->estadoEval = estadoEvaluacion::aprobado;
    }
    else if( notaFinal <= 3.5 && this->condiciones == "")
    {
         this->estadoEval = estadoEvaluacion::rechazado;
    }
    else if(this->condiciones != "")
    {
        this->estadoEval = estadoEvaluacion::pendiente;
    }
}

void Acta::cerrarActa()
{
    this->estadoAct = estadoActa::cerrado;
    generarArchivo();
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
    getline(cin >> ws, this->observaciones);
}

void Acta::incluirCondiciones()
{
    int opcion;
    cout << endl;
    cout << "1. Agregar condiciones" << endl;
    cout << "2. Eliminar condiciones" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    switch(opcion)
    {
        case 1:
            cout << "Ingrese las condiciones de aprobacion:" << endl;
            getline(cin >> ws, this->condiciones);
            this->calcularNotaFinal();
            break;
        case 2:
            this->condiciones = "";
            this->calcularNotaFinal();
            break;
        default:
            cout << "Error. Opcion no disponible." << endl;
    }
    
}

estadoEvaluacion Acta::getEstadoEvaluacion()
{
    return this->estadoEval;
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
    if(this->calificacionTotal <= 0 || this->calificacionTotal > 5)
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

Persona Acta::getDirector()
{
    return this->director;
}

void Acta::calificarCriterios()

{

    for (list<DetallesCriterio>::iterator it = listaDetallesCriterio.begin(); it != listaDetallesCriterio.end(); it++)
    {
        cout << endl << it->getCriterio().getIdentificador() << ". ";
        cout << it->getCriterio().getTexto() << endl << endl; // Muestra el nombre del criterio
        it->setCalificacion();
        it->setObservacion();
    }
    this->calcularNotaFinal();
}

void Acta::borrarObservaciones()
{
    this->condiciones = "";
}
void Acta::borrarCondiciones()
{
    this->condiciones = "";
}

void Acta::generarArchivo()
{
    string nombreArchivo = "acta" + to_string(this->getNumero()) + ".txt";
    ofstream file(nombreArchivo);
    if (!file.is_open())
    {
        cout << "Error al abrir archivo" << endl;
    }
    else
    {
        file << "\t\t\t       Pontificia Universidad Javeriana Cali" << endl;
        file << "\t\t\t\t    Facultad de Ingenieria" << endl;
        file << "\t\t\t\t    Maestria en Ingenieria" << endl << endl;
        file << "  ACTA: " << this->numero << "\t\t\t\t\t\t\t       Fecha: " << this->fecha << endl;
        file << "\t\t\t   ACTA DE EVALUACIÓN DE TRABAJO DE GRADO" << endl << endl;
        file << "  Trabajo de grado denominado: " << '"' << this->nombreTrabajo << '"' << endl << endl;
        file << "  Autor:\t      " << this->estudiante.getNombre() << "\t" << "ID:" << this->estudiante.getId() << endl << endl;
        file << "  Periodo:\t      " << this->periodo << endl << endl;
        file << "  Director:\t      " << this->director.getNombre() << endl << endl;
        file << "  Co-Director:\t      " << this->codirector.getNombre() << endl << endl;
        file << "  Énfasis en:\t      " << this->enfasis << endl << endl;
        if(this->tipo == tipoTrabajo::aplicado)
        {
            file << "  Modalidad:\t      Aplicado" <<  endl << endl;
        }
        else
        {
            file << "  Modalidad:\t      Investigación" <<  endl << endl;
        }
        file << "  Jurado 1:\t      " << this->jurado1.getNombre() << endl << endl;
        file << "  Jurado 2:\t      " << this->jurado2.getNombre() << endl << endl;
        file << "  En atención al desarrollo de este Trabajo de Grado y al documento y sustentación que presentó el(la) autor(a)," << endl;
        file << "  los Jurados damos las siguientes calificaciones parciales y observaciones (los criterios a evaluar y sus" << endl;
        file << "  ponderaciones se estipulan en el artículo 7.1 de las Directrices para Trabajo de Grado de Maestría):" << endl << endl;
        for(list<DetallesCriterio>::iterator it = listaDetallesCriterio.begin(); it != listaDetallesCriterio.end(); it++)
        {
        file << "  " << (it->getCriterio()).getIdentificador() << ". " << (it->getCriterio()).getTexto() << ":" << endl << endl;
        file << "\tCalificación parcial: " << it->calcularCalificacionParcial();
        file << "   \t\t\t\t\t\t\t\tPonderacion: " << (it->getCriterio()).getPorcentajePonderacion() << endl;
        file << "\tObservaciones: " << it->getObservacion() << endl << endl;
        }
        file << "  Como resultado de estas calificaciones parciales y sus ponderaciones, la calificación del Trabajo de" << endl;
        file << "  Grado es: " << setprecision(2) << this->calificacionTotal << endl << endl;
        file << "  Observaciones adicionales: " << this->observaciones << endl << endl;
        file << "  La calificación final queda sujeta a que se implementen las siguientes correcciones: " << this->condiciones << endl << endl;
        file << "--------------------------------------------------------------------------------------------------------------------" << endl;
        file << "\t\t\t\t    Firmado\t\t   Firmado" << endl;
        file << "\t\t\t    ________________________  ________________________" << endl;
        file << "\t\t\t\tFirma del Jurado 1\tFirma del Jurado 2" << endl;

    }
}
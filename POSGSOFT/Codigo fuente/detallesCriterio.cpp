#include "detallesCriterio.h"

DetallesCriterio::DetallesCriterio(Criterio criterio)
{
    this->criterio = criterio;
}

void DetallesCriterio::setCalificacion()
{
    cout << "Ingresa la calificacion del jurado 1: ";
    cin >> this->calificacionJurado1;
    cout << "Ingresa la calificacion del jurado 2: ";
    cin >> this->calificacionJurado2;
}

float DetallesCriterio::calcularCalificacionParcial()
{
    float calificacion = (this->calificacionJurado1 + this->calificacionJurado2) / 2;
    return calificacion;
}

void DetallesCriterio::setObservacion()
{
    cout << "Ingresa las observaciones respecto al criterio:" << endl;
    getline(cin >> ws, this->observacionesJurados);
}

Criterio DetallesCriterio::getCriterio()
{
    return this->criterio;
}

string DetallesCriterio::getObservacion()
{
    return this->observacionesJurados;
}
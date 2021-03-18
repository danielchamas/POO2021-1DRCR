#include "detallesCriterio.h"

DetallesCriterio::DetallesCriterio( int id, Criterio criterio )
{
    this->id = id;
    this->criterio = criterio;
}

int DetallesCriterio::calcularCalificacionParcial()
{
    float calificacion = (this->calificacionJurado1 + this->calificacionJurado2) / 2;
    return calificacion;
}

void DetallesCriterio::setCalificacion()
{
    cout << "Ingresa la calificacion del jurado 1" << endl;
    cin >> this->calificacionJurado1;
    cout << "Ingresa la calificacion del jurado 2" << endl;
    cin >> this->calificacionJurado2;
}

void DetallesCriterio::setObservacion()
{
    cout << "Ingresa las observaciones respecto al criterio" << endl;
    cin >> this->observacionesJurados;
}
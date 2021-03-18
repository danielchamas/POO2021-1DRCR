#ifndef DETALLECRITERIOS_H
#define DETALLECRITERIOS_H

#include <iostream>
#include "criterio.h"

using namespace std;

class DetallesCriterio
{
private:

    int id;
    Criterio criterio;
    float calificacionJurado1;
    float calificacionJurado2;
    string observacionesJurados;

public:
    DetallesCriterio( int, Criterio ); // Constructor
    void setCalificacion();
    void setObservacion();
    void calcularCalificacionParcial();
};

#endif
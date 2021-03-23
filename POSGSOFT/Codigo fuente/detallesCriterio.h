#ifndef DETALLECRITERIOS_H
#define DETALLECRITERIOS_H

#include <iostream>
#include "criterio.h"

using namespace std;

class DetallesCriterio
{
private:
    Criterio criterio;
    float calificacionJurado1;
    float calificacionJurado2;
    string observacionesJurados;

public:
    DetallesCriterio(Criterio); // Constructor
    void setCalificacion();
    void setObservacion();
    float calcularCalificacionParcial();
    Criterio getCriterio();
    string getObservacion();
};

#endif
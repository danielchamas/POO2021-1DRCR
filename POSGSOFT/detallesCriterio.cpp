#include "detallesCriterio.h"

DetallesCriterio::DetallesCriterio( int id, Criterio criterio ){
    this->id = id;
    this->criterio = criterio;
    cout << "Ingresa la calificacion del jurado 1" << endl;
    cin >> this->calificacionJurado1;
    cout << "Ingresa la calificacion del jurado 2" << endl;
    cin >> this->calificacionJurado2;
    cout << "Ingresa las observaciones respecto al criterio" << endl;
    cin >> this->observacionesJurados;
}
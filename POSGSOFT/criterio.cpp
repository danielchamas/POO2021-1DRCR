#include "criterio.h"

Criterio::Criterio()
{

}

Criterio::Criterio( int identificador, string texto, float porcentajePonderacion)
{
    this->identificador = identificador;
    this->texto = texto;
    this->porcentajePonderacion = porcentajePonderacion;
}

void Criterio::mostrarCriterio()
{
    cout << endl;
    cout << this->identificador << ". " << this->texto << endl;
    cout << "Porcentaje de ponderacion: " << this->porcentajePonderacion << "%" << endl;
}
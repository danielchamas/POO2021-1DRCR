#include "criterio.h"

Criterio::Criterio()
{

}

Criterio::Criterio(int identificador, string texto, float porcentajePonderacion)
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

void Criterio::setTexto(string texto)
{
    this->texto = texto;
}

void Criterio::setPorcentajePonderacion(float porcentaje)
{
    this->porcentajePonderacion = porcentaje;
}


float Criterio::getPorcentajePonderacion()
{
    return this->porcentajePonderacion;
}

void Criterio::setIdentificador(int id)
{
    this->identificador = id;
}

int Criterio::getIdentificador()
{
    return this->identificador;
}

string Criterio::getTexto()
{
    return this->texto;
}
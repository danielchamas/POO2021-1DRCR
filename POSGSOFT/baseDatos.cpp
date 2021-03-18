#include "baseDatos.h"

BaseDatos::BaseDatos()
{
    // Se declaran los 8 criterios por defecto
    this->listaCriterios.push_back(Criterio(1, "Desarrollo y profundidad en el tratamiento del tema", 20));
    this->listaCriterios.push_back(Criterio(2, "Desafio academico y cientifico del tema", 15));
    this->listaCriterios.push_back(Criterio(3, "Cumplimiento de los objetivos propuestos", 10));
    this->listaCriterios.push_back(Criterio(4, "Creatividad e innovacion de las soluciones y desarrollos propuestos", 10));
    this->listaCriterios.push_back(Criterio(5, "Validez de los resultados y conclusiones", 20));
    this->listaCriterios.push_back(Criterio(6, "Manejo y procesamiento de la informacion y bibliografia", 10));
    this->listaCriterios.push_back(Criterio(7, "Calidad y presentacion del documento escrito", 7.5));
    this->listaCriterios.push_back(Criterio(8, "Presentacion oral", 7.5));
}

void BaseDatos::mostrarCriterios()
{
    for (list<Criterio>::iterator it = listaCriterios.begin(); it != listaCriterios.end(); it++)
    {
        it->mostrarCriterio();
    }
}

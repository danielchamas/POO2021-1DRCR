#include "baseDatos.h"

BaseDatos::BaseDatos()
{
    // Se declaran los 8 criterios por defecto
    this->listaCriterios.push_front(Criterio(1, "Desarrollo y profundidad en el tratamiento del tema", 20));
    this->listaCriterios.push_front(Criterio(1, "Desafio academico y cientifico del tema", 15));
    this->listaCriterios.push_front(Criterio(1, "Cumplimiento de los objetivos propuestos", 10));
    this->listaCriterios.push_front(Criterio(1, "Creatividad e innovacion de las soluciones y desarrollos propuestos", 10));
    this->listaCriterios.push_front(Criterio(1, "Validez de los resultados y conclusiones", 20));
    this->listaCriterios.push_front(Criterio(1, "Manejo y procesamiento de la informacion y bibliografia", 10));
    this->listaCriterios.push_front(Criterio(1, "Calidad y presentacion del documento escrito", 7.5));
    this->listaCriterios.push_front(Criterio(1, "Presentacion oral", 7.5));
}
#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>

using namespace std;

class Criterio
{
private:
    int identificador;
    string texto;
    float porcentajePonderacion;
public:
    Criterio();
    Criterio(int, string, float );
    void modificarCriterio();
    void agregarCriterio();
    void borrarCriterio();
    void mostrarCriterio();
};

#endif
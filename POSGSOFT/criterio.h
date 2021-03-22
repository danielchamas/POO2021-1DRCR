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
    void mostrarCriterio();
    void setTexto(string);
    void setPorcentajePonderacion(float);
    float getPorcentajePonderacion();
    void setIdentificador(int);
    int getIdentificador();
    string getTexto();
};

#endif
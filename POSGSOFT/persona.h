#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum class tipo
{
    interno = 1,
    externo = 2
};

enum class rol
{
    director = 1,
    asistente = 2,
    jurado = 3,
    estudiante = 4
};

class Persona
{
private:
    string nombre;
    int id;
    string email;
    tipo tipoPersona;
    
public:
    Persona();
    list<rol> rol;
    void agregarRol();
    string getNombre();
    tipo getTipo();
};

#endif
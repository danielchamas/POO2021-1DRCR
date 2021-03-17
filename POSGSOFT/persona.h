#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

enum class tipo
{
    interno,
    externo
};

enum class rol
{
    director,
    jurado,
    estudiante
};

class Persona
{
private:
    string nombre;
    int id;
    string email;
    tipo tipo;
    rol rol;
public:
    Persona();
};

#endif
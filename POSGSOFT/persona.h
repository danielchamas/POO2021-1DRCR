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

enum class rol // Usamos enum class para evitar problemas con el tipo de dato del enum. Así será solo tipo class rol.
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
    long int id; 
    string email;
    tipo tipoPersona;
    
public:
    Persona();
    Persona(string, int, string, tipo);
    list<rol> listaRoles; // Por cada participacion en un acta, se le añade el rol a la persona
    void agregarRol(rol);
    string getNombre();
    tipo getTipo();
    long int getId();
};

#endif
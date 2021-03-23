#include "persona.h"
Persona::Persona()
{

}

Persona::Persona(string nombre, int id, string email, tipo tipoPersona)
{
    this->nombre = nombre;
    this->id = id;
    this->email = email;
    this->tipoPersona = tipoPersona;
}

void Persona::agregarRol(rol rol) //Agrega roles a la lista de de roles de la persona. Ya que una persona puede ser Director o jurado.
{
    this->listaRoles.push_back(rol);
}

string Persona::getNombre()
{
    return this->nombre;
}

tipo Persona::getTipo()
{
    return this->tipoPersona;
}

long int Persona::getId()
{
    return this->id;
}
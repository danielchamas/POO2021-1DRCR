#include "persona.h"
 
Persona::Persona()
{
    int opcion;
    cout << "Ingrese el nombre:" << endl;
    cin >> this->nombre;
    cout << "Ingrese el numero de identificacion:" << endl;
    cin >> this->id;
    cout << "Ingrese el correo:" << endl;
    cin >> this->email;
    do{ // Se pregunta el tipo de persona. Si escoje una opcion incorrecta le da otro intento
        // hasta que elija una opcion correcta 
        cout << "Ingrese el tipo de persona:" << endl;
        cout << "1. Externo" << endl;
        cout << "2. Interno" << endl;
        cin >> opcion;
        switch( opcion )
        {
            case 1:
                this->tipoPersona = tipo::externo;
                break;
            case 2:
                this->tipoPersona = tipo::interno;
                break;
            default:
                cout << "Error. Opcion incorrecta. Intentelo de nuevo." << endl;
        }
    } while( opcion < 1 || opcion > 2 );
    this->agregarRol();
}

void Persona::agregarRol() //hola
{
    int opcion;
    do{
        cout << "Ingrese el rol de la persona:" << endl;
        cout << "1. Director/Codirector" << endl;
        cout << "2. Asistente" << endl;
        cout << "3. Jurado" << endl;
        cout << "4. Estudiante" << endl;
        cin >> opcion; 
        switch( opcion )
        {
            case 1:
                this->rol.push_back(rol::director);
                break;
            case 2:
                this->rol.push_back(rol::asistente);
                break;
            case 3:
                this->rol.push_back(rol::jurado);
                break;
            case 4:
                this->rol.push_back(rol::estudiante);
                break;
            default:
                cout << "Opcion incorrecta. Intentalo de nuevo" << endl;
        }
    } while (opcion < 1 || opcion > 4);
}

string Persona::getNombre()
{
    return this->nombre;
}

tipo Persona::getTipo()
{
    return this->tipoPersona;
}
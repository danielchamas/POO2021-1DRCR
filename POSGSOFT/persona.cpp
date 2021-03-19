#include "persona.h"

int Persona::agregarRol(int rol)
{
    switch(rol)
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
            return 0;
    }
    return 1;
}

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
        switch(opcion)
        {
            case 1:
                this->tipo = tipo::externo;
                break;
            case 2:
                this->tipo = tipo::interno;
                break;
            default:
                cout << "Error. Opcion incorrecta. Intentelo de nuevo." << endl;
        }
    } while(opcion < 1 || opcion > 2);
    do{ // Se pregunta el rol de la persona. Si escoje una opcion incorrecta le da otro intento
        // hasta que elija una opcion correcta 
        cout << "Ingrese el rol de la persona:" << endl;
        cout << "1. Director/Codirector" << endl;
        cout << "2. Asistente" << endl;
        cout << "3. Jurado" << endl;
        cout << "4. Estudiante" << endl;
        cin >> opcion; 
    } while(agregarRol(opcion));
}
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
        switch( opcion )
        {
            case 1:
                this->rol = rol::director;
                break;
            case 2:
                this->rol = rol::asistente;
                break;
            case 3:
                this->rol = rol::jurado;
                break;
            case 4:
                this->rol = rol::estudiante;
                break;
            default:
                cout << "Error. Opcion incorrecta. Intentelo de nuevo." << endl;
        }
    } while(opcion < 1 || opcion > 2);
}

int main(){
    Persona Juan;
    return 0;
}
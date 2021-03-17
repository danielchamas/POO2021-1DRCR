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
    do{
        cout << "Ingrese el tipo de usuario:" << endl;
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
    cout << "Ingrese el rol de la persona:" << endl;
    cout << "1. Asistente" << endl;
    cout << "1. Estudiante" << endl;
    cout << "2. Jurado" << endl;
    cout << "3. Director/Codirector" << endl;
    cin >> opcion; 
}

int main(){
    Persona Juan;
    return 0;
}
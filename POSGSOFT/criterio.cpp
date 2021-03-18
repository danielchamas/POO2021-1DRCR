#include "criterio.h"

Criterio::Criterio()
{

}

Criterio::Criterio(int identificador, string texto, float porcentajePonderacion)
{
    this->identificador = identificador;
    this->texto = texto;
    this->porcentajePonderacion = porcentajePonderacion;
}

void Criterio::mostrarCriterio()
{
    cout << endl;
    cout << this->identificador << ". " << this->texto << endl;
    cout << "Porcentaje de ponderacion: " << this->porcentajePonderacion << "%" << endl;
}

void Criterio::setTexto(string texto)
{
    this->texto = texto;
}

void Criterio::setPorcentajePonderacion(float porcentaje)
{
    this->porcentajePonderacion = porcentaje;
}

void Criterio::modificarCriterio()
{
    int opcion, porcentaje;
    string texto;
    do{ // Pregunta al usuario que desea modificar y verifica que exista la opcion.
        // En caso de no existir se itera el menú.
        cout << "Ingrese la opcion a modificar:" << endl;
        cout << "1. Texto del criterio" << endl;
        cout << "2. Porcentaje de ponderacion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch(opcion)
        {   // En cada caso se verifica que la opcion sea correcta
            case 0:
                break;
            case 1:
                cout << "Ingrese el texto" << endl;
                cin >> texto;
                this->setTexto(texto);
                break;
            case 2:
                cout << "Ingrese el porcentaje de ponderacion" << endl;
                cin >> porcentaje;
                this->setPorcentajePonderacion(porcentaje);
                break;
            default:
                cout << "Error. Opcion incorrecta" << endl;
        }
    } while opcion != 0;
}
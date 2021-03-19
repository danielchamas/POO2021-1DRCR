#include "menu.h"

int menuPrincipal()
{
    int opcion;
    cout << endl;
    cout << "======MENU PRINCIPAL====== " << endl << endl;
    cout << "1. Asistente." << endl;
    cout << "2. Director / Codirector." << endl;
    cout << "3. Jurado." << endl;
    cout << "0. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int menuAsistente()
{
    int opcion;
    cout << endl;
    cout << "======MENU ASISTENETE====== " << endl << endl;
    cout << "1. Crear acta." << endl;
    cout << "2. Volver al menu principal." << endl;
    cout << "0. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int menuListaActa()
{
    int opcion;
    cout << endl;
    cout << "1. Listar todas las actas." << endl;
    cout << "2. Listar actas abiertas." << endl;
    cout << "3. Listar actas cerradas." << endl;
    cout << "4. Volver." << endl;
    cout << "0. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}
int menuDirector()
{
    int opcion;
    cout << endl;
    cout << "======MENU DIRECTOR====== " << endl << endl;
    cout << "1. Listar actas." << endl;
    cout << "2. Listar trabajos aplicados." << endl;
    cout << "3. Listar trabajos Investigacion." << endl;
    cout << "4. Consultar No. Trabajos por profesor." << endl;
    cout << "5. Consultar trabajos como jurado por persona." << endl;
    cout << "6. Listar todos los jurados participantes." << endl;
    cout << "7. Consultar actas pendientes y rechazadas." << endl;
    cout << "8. Crear informacion jurados." << endl;
    cout << "9. Conultar lista de jurados internos / externos." << endl;
    cout << "10. Eliminar acta de grado." << endl;
    cout << "11. Consultar lista de criterios." << endl;
    cout << "12. Volver al menu principal." << endl;
    cout << "0. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int menuCalificacionJurado()
{
    int opcion;
    cout << endl;
    cout << "1. Calificar Criterios." << endl;
    cout << "2. Ingresar observaciones." << endl;
    cout << "3. Ingresar comentarios especificos." << endl;
    cout << "4. Cerrar acta." << endl;
    cout << "5. Volver." << endl;
    cout << "0. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int menuJurado()
{
    int opcion;
    cout << endl;
    cout << "======MENU JURADO====== " << endl << endl;
    cout << "1. Calificar acta." << endl;
    cout << "2. Volver al menu principal." << endl;
    cout << "0. Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}



#include <iostream>
#include "baseDatos.h"
#include "menu.h"
#include <conio.h>

int main()
{
    BaseDatos juanito;
    int opcion, opcion2, opcion3, opcion3a, opcion4, opcion4a;
    cout << endl;
    cout << "======SISTEMA BASE DE DATOS ACTAS DE GRADO====== " << endl;
    do
    {
        opcion = menuPrincipal();
        switch( opcion )
        {
            case 0: 
                break;
            case 1: 
                do
                {
                    opcion2 = menuAsistente();
                    switch( opcion2 )
                    {
                        case 0:
                            opcion = 0;
                        case 1:
                            break;
                        case 2: 
                            opcion2 = 0;
                            break;
                        default:
                            cout << "Error. Digite un campo valido." << endl;
                            break;
                    }
                } while( opcion2 != 0 );
                break;
            case 2: 
                do 
                {
                    opcion3 = menuDirector();
                    switch( opcion3 )
                    {
                        case 0: 
                            opcion = 0;
                            break;
                        case 1:
                            do
                            {
                                opcion3a = menuListaActa();
                                switch( opcion3a )
                                {
                                    case 0:
                                        opcion = 0;
                                        opcion3 = 0;
                                        break;
                                    case 1:
                                        juanito.listarActas();
                                        break;
                                    case 2:
                                        break;
                                    case 3:
                                        break;
                                    case 4:
                                        opcion3a = 0;
                                        break;
                                    default:
                                        cout << "Error. Digite un campo valido." << endl;
                                        break;
                                }
                            } while( opcion3a != 0 );
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 8:
                            break;
                        case 9:
                            
                            break;
                        case 10:
                
                            break;
                        case 11:
                            juanito.mostrarCriterios();
                            getch();
                            break;
                        case 12:
                            opcion3 = 0;
                            break;
                        default:
                            cout << "Error. Digite un campo valido." << endl;
                            break;     
                    }
                } while( opcion3 != 0 );
                break;
            case 3: 
                do
                {
                   opcion4 = menuJurado();
                   switch( opcion4 )
                   {
                        case 0:
                            opcion = 0;
                            break;
                        case 1:
                            do
                            {
                                opcion4a = menuCalificacionJurado();
                                switch( opcion4a )
                                {
                                    case 0:
                                        opcion = 0;
                                        opcion4 = 0;
                                        break;
                                    case 1:
                                        break;
                                    case 2:
                                        break;
                                    case 3:
                                        break;
                                    case 4:
                                        break;
                                    case 5:
                                        opcion4a = 0;
                                        break;
                                    default:
                                        cout << "Error. Digite un campo valido." << endl;
                                        break;
                                }
                            } while( opcion4a != 0 );
                            break;
                        case 2: 
                            opcion4 = 0;
                            break;
                        default:
                            cout << "Error. Digite un campo valido." << endl;
                            break;
                   }
                } while( opcion4 != 0 );
                break;
            default:
                cout << "Error. Digite un campo valido." << endl;
                break;
        }
    } while( opcion != 0);
    
    return 0;
}
/* Escriba un programa pra guardar numeros telefonicos que muestre un menu con las siguientes opciones. Investigue como usar archivos de texto de 
tal manera que los contactos queden creados en un archivo de texto: 

1. Crear(nombre,apellidos,telefono) 
2. Agregar más contactos(nombre,apellidos,telefono) 
3. Visualizar contactos */

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct persona{
    char name[10];
    char apellido[15];
    char tel[20];
}contacto;

void menu(){
   cout << "\n";
   cout << "MENU CONTACTOS \n";
   cout << "==================\n";
   cout << "1. Crear Agenda\n";
   cout << "2. Agregar Contacto\n";
   cout << "3. Mostrar Agenda\n";
   cout << "4. Salir\n";
   cout << "opc: ";
   return;
}

void crearAgenda(){
    int opc;
    ofstream archivo;
    archivo.open( "contactos.txt", ios::out  ); //Open a file.
    if( archivo.fail() ){
        cout << "Error al abrir el archivo.";
        exit(1);
    }
    do{
        cout<<"\nDigite su nombre: ";
        cin >> contacto.name;
        cout<<"\nDigite su apellido:";
        cin >> contacto.apellido;
        cout<<"\nDigite su telefono: ";
        cin >> contacto.tel;
        archivo << "NOMBRE " << " " << "APELLIDO " << " " << "NUMERO" << "\n";
        archivo << "-------------------------------\n";
        archivo << contacto.name << "  " << contacto.apellido << "    " << contacto.tel << "\n";
        cout<<"\nDesea ingresar otro contacto a la agenda? ";
        cout<<"\n1)Si\n2)No"<<endl; cin >> opc;
    }while( opc != 2 );
    archivo.close();
    
}

void agregarContacto(){
    int opc;
    ofstream archivo;
    archivo.open("contactos.txt",ios::app); // Open an existing file and add text.
    if( archivo.fail() ){
        cout << "Error al abrir el archivo";
        exit(1);
    }
    do{
        cout<<"\nDigite su nombre: ";
        cin >> contacto.name;
        cout<<"\nDigite su apellido:";
        cin >> contacto.apellido;
        cout<<"\nDigite su telefono: ";
        cin >> contacto.tel;
        archivo << contacto.name << "  " << contacto.apellido << "    " << contacto.tel << "\n";
        cout<<"\nDesea ingresar otro contacto a la agenda? ";
        cout<<"\n1)Si\n2)No"<<endl; cin >> opc;
    }while( opc != 2 );
    archivo.close();
}

void mostrarAgenda(){
    ifstream archivo;
    string agenda;
    archivo.open( "contactos.txt",ios::in ); //Oen file read mode.
    if( archivo.fail() ){
        cout << "Error al abrir el archivo";
    }
    cout << "\n";
    while( !archivo.eof() ){        // While not the end of the file....
        getline(archivo, agenda);
        cout << agenda << endl;
    }
    archivo.close();
}

int main(){
    int opc;
    do{
        menu();
        cin >> opc;
        switch( opc ){
            case 1: crearAgenda(); break;
            case 2: agregarContacto(); break;
            case 3: mostrarAgenda(); break;
            default: break;
        }
    }while( opc != 4);
    return 0;
}
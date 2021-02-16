/*Realice un programa que lea los siguientes datos de una persona: Edad: dato de tipo entero. Sexo: dato de tipo caracter.  
Altura en metros: dato de tipo flotante. Muestre los datos leidos.  Desarrolle su programa usando funciones.*/

#include <iostream>
#include <conio.h>

using namespace std;

void imprimirDatos( int edad, char sexo[], float altura ){
    cout << "\nEdad: " << edad << endl;
    cout << "Sexo: " << sexo  << endl;
    cout << "Altura: " << altura << " metros" << endl;
}

void leerDatos(){
    int edad;
    char sexo[ 10 ];
    float altura;
    cout << "Digite su edad: "; cin >> edad;
    cout << "Digite su sexo: "; cin >> sexo;
    cout << "Digite su altura en metro: "; cin >> altura;
    imprimirDatos( edad, sexo, altura );
}

int main(){
    leerDatos();
    getch();
    return 0;
}
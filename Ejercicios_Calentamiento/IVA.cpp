#include <iostream> 
#include <conio.h>

using namespace std;

float calcularIva( float iva, float producto){
    int costoTotal;
    costoTotal = ( ( iva / 100 ) + 1 ) * producto;
    return costoTotal;
}

int main(){
    float producto, iva, resultado;
    cout << "\nDigite el precio del producto: "; cin >> producto;
    cout << "Digite el porcentaje del iva: "; cin >> iva;
    resultado = calcularIva(iva, producto);
    cout << "El costo total del producto es: COP " << resultado << endl;
    getch();
    return 0;
}
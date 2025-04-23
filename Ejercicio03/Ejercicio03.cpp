#include <iostream>
#include <cstdlib>      
#include <vector>
#include "Opciones.h"

using namespace std;

void pausarPantalla() {
    cout << "\nPresione ENTER para continuar...";
    cin.get();
}

int main() {
    vector<int> datos;
    int opcion;

    do {
        system("cls"); // Limpia la pantalla
        menu();
        cin >> opcion;
        cin.ignore(); // Limpia el buffer del ENTER
        switch (opcion) {
        case 1:
            generarVector(datos);cin.get();
            pausarPantalla();
            break;
        case 2:
            contarImpares(datos);cin.get();
            pausarPantalla();
            break;
        case 3:
            detectarDuplicados(datos);cin.get();
            pausarPantalla();
            break;
        case 4:
            mostrarPrimero(datos);cin.get();
            pausarPantalla();
            break;
        case 5:
            verVector(datos);cin.get();
            pausarPantalla();
            break;
        case 6:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            pausarPantalla();
        }
    } while (opcion != 6);

    return 0;
}

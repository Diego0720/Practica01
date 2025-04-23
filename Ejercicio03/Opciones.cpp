
/*Nombre : Diego David Alva Sandoval
           codigo: U202420023*/

#include "Opciones.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>   // srand, rand
#include <ctime>     // clock(), CLOCKS_PER_SEC, time()

using namespace std;

void menu() {
    cout << "===== MENU PRINCIPAL =====\n";
    cout << "1. Generar vector aleatorio  (O(n))\n";
    cout << "2. Contar impares con bucle (O(n))\n";
    cout << "3. Detectar duplicados tras ordenar (O(n log n))\n";
    cout << "4. Mostrar primer elemento (O(1))\n";
    cout << "5. Ver contenido del vector (O(n))\n";
    cout << "6. Salir\n";
    cout << "Selecciona una opcion: ";
}

void generarVector(vector<int>& v) {
    int n;
    cout << "\nIngrese el tamanio del vector: ";
    cin >> n;
    v.clear();     // vacio mi vector  //PESO n
    v.reserve(n);  //reservo espacio en la memoria para n elementos  // Peso 1

    srand((time(nullptr)));  // inicializa rand()

    for (int i = 0; i < n; ++i) {  //1+n(1+1) = 2n+1= O(n)
        int val = (rand() % 10000) + 1;  // [1,10000]  // PESO 1
        v.push_back(val);  // PESO 1
    }

    cout << "Vector generado con " << n << " elementos.\n";
    cout << "\nComplejidad esperada: O(n)\n";
}

void contarImpares(const vector<int>& v) {
    if (v.empty()) { // PESO = 1+ MAX(1)
        cout << "\nEl vector esta vacio. Generelo primero.\n";
        return;
    }

    int ultimo = 0; // PESO 1
    clock_t start = clock();

    int contador = count_if(v.begin(), v.end(), [&ultimo](int num) { // PESO n 
        ultimo = num; // PESO 1
        return num % 2 != 0; // PESO 1
        });

    clock_t end = clock();
    double duracion_ms = double(end - start) * 1000.0 / CLOCKS_PER_SEC;

    cout << "Impares: " << contador << "\n";  
    cout << "Ultimo evaluado: " << ultimo << "\n";
    cout << "Tiempo de ejecucion: " << duracion_ms << " ms\n";
    cout << "\nComplejidad esperada: O(n) \n";

}


void detectarDuplicados(vector<int> v) {
    if (v.empty()) {    // PESO = 1+MAX(1)
        cout << "\nEl vector esta vacio. Generelo primero.\n"; // PESO =1
        return;
    }

    cout << "\nComplejidad esperada: O(n log n)+ O(n) = O(n log n) \n";

    clock_t start = clock();

    sort(v.begin(), v.end()); // PESO = n(Logn)

    bool dup = false;  //PESO =1 
    for (size_t i = 1; i < v.size(); ++i) { // PESO = 1+(n-1)(3) = 3n-2 = O(n)
        if (v[i] == v[i - 1]) {//peso = 2+1=3
            dup = true; // Peso 1
            break;
        }
    }

    clock_t end = clock();
    double duracion_ms = double(end - start) * 1000.0 / CLOCKS_PER_SEC;

    cout << (dup ? "Se encontraron duplicados.\n" : "No hay duplicados.\n");
    cout << "Tiempo de ejecucion: " << duracion_ms << " ms\n";
}

void mostrarPrimero(const vector<int>& v) {
    if (v.empty()) {  //1+MAX(1) = 1
        cout << "\nEl vector esta vacio. Generelo primero.\n"; // PESO 1
        return;
    }

    cout << "\nComplejidad esperada: O(1)\n";

    clock_t start = clock();
    int primero = v.front();  //PESO 1
    clock_t end = clock();
    double duracion_ms = double(end - start) * 1000.0 / CLOCKS_PER_SEC; //peso 1

    cout << "Primer elemento: " << primero << "\n";
    cout << "Tiempo de ejecucion: " << duracion_ms << " ms\n";
}

void verVector(const vector<int>& v) {
    if (v.empty()) {  // PESO = 1+ MAX( 1 )= 1
        cout << "\nEl vector esta vacio. Generelo primero.\n";  // PESO 1 
        return;
    }
    cout << "\nContenido completo del vector (" << v.size() << " elementos):\n"; // PESO 1
    for (size_t i = 0; i < v.size(); ++i) { //PESO = 1+ n(1) = n
        cout << v[i] << (i + 1 < v.size() ? ", " : "\n"); //PESO 1 
    }
    cout << "\nComplejidad esperada de la funcion = O(n)\n ";
}

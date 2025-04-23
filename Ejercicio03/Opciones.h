/*Nombre : Diego David Alva Sandoval
           codigo: U202420023*/

#pragma once
#ifndef OPCIONES_H
#define OPCIONES_H

#include <vector>
using namespace std;

// Muestra el menú principal
void menu();

// Genera un vector de tamaño n con valores aleatorios [1,10000]
void generarVector(vector<int>& v);

// Cuenta impares con un bucle for y guarda el último evaluado
void contarImpares(const vector<int>& v);

// Detecta duplicados tras ordenar con bucle for por sort 
void detectarDuplicados(vector<int> v);

// Muestra el primer elemento (O(1))
void mostrarPrimero(const vector<int>& v);

// Imprime todo el vector en pantalla
void verVector(const vector<int>& v);

#endif 

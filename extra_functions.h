#ifndef EXTRA_FUNCTIONS_H
#define EXTRA_FUNCTIONS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

int * newRandomArray(int n);
void printArray(int *array, int n);

int * newRandomArray(int n) {
    int *array;
    
    srand (time(NULL));

    array = new int[n];
    
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
    
    return array;
}

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void generateArrayFile(int *array, int n) {
    ofstream myfile;
    string filename = to_string(n)+".txt";
    myfile.open (filename);
    for(int i = 0; i < n; i++) {
        myfile << array[i] << "\n";
    }
    myfile.close();
}

void readFromFile(int **array, int n) {
    string line;        //Para almacenar líneas de texto de archivo
    int cont = 0;      //Se inicia con un contador en -1
    ifstream myfile (to_string(n)+".txt");      //Inicializa variable ifstream con nombre de archivo
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )     //Obtiene línea por línea de archivo
        {
            array[0][cont] = atoi(line.c_str());       //Se asignan valores al arreglo en posición contador
            cont++;     //Se aumenta contador
        }
        myfile.close();     //Se cierra archivo
    }
    
    else cout << "Unable to open file";     //Mensaje de error
}

void getRuntime(void (*sortFunction)(int**, int), int **array, int n) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    (*sortFunction)(array, n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    
    cout << "n = " << n << " --------- " << duration << " ms\n";
}

#endif

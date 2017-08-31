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
        array[i] = rand() % 10000;
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
        myfile << array[i] << " ";
    }
    myfile.close();
}

void readFromFile(int **array, int n) {
    int cont = 0;      //Se inicia con un contador en -1
    ifstream myfile (to_string(n)+".txt");      //Inicializa variable ifstream con nombre de archivo
    if (myfile.is_open())
    {
        int current_number;
        while (myfile >> current_number)
        {
            array[0][cont] = current_number;
            cont++;
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
    
    cout << "n = " << n << " --------- " << (float)duration/1000 << " ms\n";
}

void testAllCases(void (*sortFunction)(int **, int)) {
    for(int i = 10; i <= 1000000; i*=10) {
        int *array = new int[i];
        readFromFile(&array, i);
        getRuntime(sortFunction, &array, i);
    }
}

#endif

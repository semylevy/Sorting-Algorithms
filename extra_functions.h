#ifndef EXTRA_FUNCTIONS_H
#define EXTRA_FUNCTIONS_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

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

void getRuntime(void (*sortFunction)(int**, int), int **array, int n) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    (*sortFunction)(array, n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    
    cout << "n = " << n << " --------- " << duration << " ms\n";
}

#endif

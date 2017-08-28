#ifndef ARRAY_GENERATION_H
#define ARRAY_GENERATION_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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

#endif

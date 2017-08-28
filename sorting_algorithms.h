#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include "array_generation.h"

using namespace std;

void swap(int **array, int a, int b);
int getMax(int **array, int n);
void bubbleSort(int **array, int n);
void cocktailSort(int **array, int n);
void insertionSort(int **array, int n);
void bucketSort(int **array, int n);
void countingSort(int **array, int n);
void mergeSort(int **array, int n);
void binaryTreeSort(int **array, int n);
void radixSort(int **array, int n);
void shellSort(int **array, int n);
void selectionSort(int **array, int n);
void heapSort(int **array, int n);
void quickSort(int **array, int n);

void swap(int **array, int a, int b) {
    int tmp = array[0][a];
    array[0][a] = array[0][b];
    array[0][b] = tmp;
}

int getMax(int **array, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if(array[0][i] > max) max = array[0][i];
    }
    return max;
}

void bubbleSort(int **array, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n; j > i; j--) {
            if(array[0][j-1] > array[0][j]) {
                swap(array, j-1, j);
            }
        }
    }
}

void cocktailSort(int **array, int n) {
    bool swapCheck;
    for(int i = 0; i < n; i++) {
        swapCheck = false;
        for(int j = i; j < n-i; j++) {
            if(array[0][j] > array[0][j+1]) {
                swap(array, j, j+1);
                swapCheck = true;
            }
        }
        
        if(!swapCheck) {
            cout << endl << i << endl;
            return;
        }
        
        for(int j = n-i; j > i; j--) {
            if(array[0][j-1] > array[0][j]) {
                swap(array, j-1, j);
            }
        }
    }
}

void insertionSort(int **array, int n) {
    int i, j, temp;
    for(i = 1; i < n; i++) {
        j = i-1;
        temp = array[0][i];
        while(j >= 0 && array[0][j] > temp) {
            array[0][j+1] = array[0][j];
            j--;
        }
        array[0][j+1] = temp;
        printArray(*array, n);
    }
}

//bucketSort para valores
void bucketSort(int **array, int n) {
    
    int bucketNumber, max, min, divider, i, j, k;
    bucketNumber = 10;
    vector<int> buckets[10];
    
    max = getMax(array, n);
    
    divider = ceil(float(max+1) / bucketNumber);
    
    for(i = 0; i < n; i++) {
        j = floor(array[0][i] / divider);
        buckets[j].push_back(array[0][i]);
    }
    
    for (i = 0; i < bucketNumber; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    k = 0;
    for(i = 0; i < bucketNumber; i++) {
        for (j = 0; j < buckets[i].size(); j++) {
            array[0][k] = buckets[i][j];
            k++;
        }
    }
}

#endif

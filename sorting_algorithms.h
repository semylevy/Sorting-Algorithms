#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include "extra_functions.h"

using namespace std;

void swap(int **array, int a, int b);
int getMax(int **array, int n);
void bubbleSort(int **array, int n);
void brickSort(int **array, int n);
void brickSortAlt(int **array, int n);
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
        for(int j = 0; j < n-i-1; j++) {
            if(array[0][j+1] < array[0][j]) {
                swap(array, j+1, j);
            }
        }
    }
}

void brickSort(int **array, int n) {
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for (int i = 0; i < n; i+=2) {
            if(array[0][i] > array[0][i+1]){
                swap(array, i, i+1);
                sorted = false;
            }
        }
        for (int i = 1; i < n; i+=2) {
            if(array[0][i] > array[0][i+1]){
                swap(array, i, i+1);
                sorted = false;
            }
        }
    }
}

void brickSortAlt(int **array, int n) {
    for(int i = 0; i < n; i++) {
        if(i&1) {
            for (int j = 0; j < n-2; j+=2) {
                if(array[0][j] > array[0][j+1]){
                    swap(array, j, j+1);
                }
            }
        } else {
            for (int j = 1; j < n-2; j+=2) {
                if(array[0][j] > array[0][j+1]){
                    swap(array, j, j+1);
                }
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
    }
}

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

void countingSort(int **array, int n) {
    int max = getMax(array, n);
    int *indexQ = new int[max+1];
    int *res = new int[n];
    int i, count;
    for(i = 0, count = 0; i <= max && count < n; i++) {
        indexQ[array[0][i]]++;
        count++;
    }
    for (i = 1; i <= max; i++) {
        indexQ[i]+=indexQ[i-1];
    }
    for (i = n-1; i >= 0; i--) {
        res[--indexQ[array[0][i]]] = array[0][i];
    }
    for(i = 0; i < n; i++) {
        array[0][i] = res[i];
    }
    
}

void radixSort(int **array, int n) {
    
}

#endif

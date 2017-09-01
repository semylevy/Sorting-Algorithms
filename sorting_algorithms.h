#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include "extra_functions.h"
#include "Arbol.h"

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
void modCountingSort(int **array, int n, int div);
void mergeSort(int **array, int n);
void mergeSort(int **array, int high, int low);
void mergeArrays(int **array, int low, int mid, int high);
void binaryTreeSort(int **array, int n);
void radixSort(int **array, int n);
void shellSort(int **array, int n);
void selectionSort(int **array, int n);
void heapSort(int **array, int n);
void heapify(int **array, int n, int root);
void quickSort(int **array, int n);
void quickSort(int **array, int low, int high);
int particion(int **array, int lo, int hi);

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

void modCountingSort(int **array, int n, int div) {
    int max = getMax(array, n);
    int *indexQ = new int[max+1];
    int *res = new int[n];
    int i, count;
    for(int i = 0; i < max+1; i++) {
        indexQ[i] = 0;
    }
    for(i = 0, count = 0; i <= max && count < n; i++) {
        indexQ[(array[0][i]/div)%10]++;
        count++;
    }
    for (i = 1; i <= max; i++) {
        indexQ[i]+=indexQ[i-1];
    }
    for (i = n-1; i >= 0; i--) {
        res[--indexQ[(array[0][i]/div)%10]] = array[0][i];
    }
    for(i = 0; i < n; i++) {
        array[0][i] = res[i];
    }
    
}

void mergeSort(int **array, int n) {
    mergeSort(array, 0, n-1);
}

void mergeSort(int **array, int low, int high) {
    if(high <= low) {       //verifica si el arreglo contiene un solo elemento
        return;
    }
    
    int mid = low + (high - low) / 2;       //Se genera un punto medio a partir de high y low
    
    mergeSort(array, low, mid);        //llamada recursiva para la parte izquierda del arreglo
    mergeSort(array, mid+1, high);     //llamada recursiva para la parte derecha del arreglo
    
    mergeArrays(array, low, mid, high);        //se combinan ambos arreglos de forma ordenada
}

void mergeArrays(int **array, int low, int mid, int high) {      //Método para hacer merge de dos arreglos ordenados
    int auxiliar[high-low+1];     //Genera arreglo auxiliar
    int i = low;        //Mitad derecha index
    int j = mid+1;      //Mitad izquierda index
    int k = 0;
    while(i <= mid && j <= high) {     //Desde el principio hasta el fin del arreglo
        if (array[0][i] < array[0][j]) { //Verifica si el elemento izquierdo es mayor que el derecho
            auxiliar[k] = array[0][i];     //Agrega elemento en auxiliar
            i++;
            k++;
        } else {
            auxiliar[k] = array[0][j];     //Agrega elemento
            j++;        //Incremento del lado izquierdo
            k++;
        }
    }
    while(i <= mid) {
        auxiliar[k] = array[0][i];
        i++;
        k++;
    }
    while(j <= high) {
        auxiliar[k] = array[0][j];
        j++;
        k++;
    }
    for(i = low; i <= high; i++) {
        array[0][i] = auxiliar[i-low];
    }
}

void radixSort(int **array, int n) {
    int max = getMax(array, n);
    for(int i = 1; max / i > 0; i*=10) {
        modCountingSort(array, n, i);
    }
}

void binaryTreeSort(int **array, int n) {
    ArbolBinario tempTree;
    for(int i = 0; i < n; i++) {
        tempTree.agregaNodo(array[0][i], tempTree.raiz);
    }
    tempTree.infijo(tempTree.raiz, array);
}

void shellSort(int **array, int n) {
    int gap = n/2;
    int temp, i, j, k;
    for(i = gap; i > 0; i/=2) {
        for(j = i; j < n; j++) {
            temp = array[0][j];
            for(k = j; k >= i && array[0][k-i] > temp; k-=i) {
                array[0][k] = array[0][k-i];
            }
            array[0][k] = temp;
        }
    }
}

void selectionSort(int **array, int n) {
    for (int i = 0; i < n; i++) {
        int min = array[0][i], pos = i;
        for (int j = i+1; j < n; j++) {
            if(array[0][j] < min) {
                min = array[0][j];
                pos = j;
            }
        }
        if(pos != i)
            swap(array, i, pos);
    }
}

void heapSort(int **array, int n) {
    int heap_size = n;
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for(int i = n-1; i >= 0; i--) {
        swap(array, i, 0);
        heapify(array, i, 0);
    }
}

void heapify(int **array, int n, int root) {
    int largest = root;
    int left = (2 * root) + 1;
    int right = (2 * root) + 2;
    
    if(left < n && array[0][left] > array[0][largest]) {
        largest = left;
    }
    if(right < n && array[0][right] > array[0][largest]) {
        largest = right;
    }
    
    if(largest != root) {
        swap(array, root, largest);
        heapify(array, n, largest);
    }
}

void quickSort(int **array, int n) {
    quickSort(array, 0, n-1);
}

void quickSort(int **array, int lo, int hi) {
    if (hi <= lo) {     //Verifica caso base
        return;
    }
    int j = particion(array, lo, hi);      //Llama el método de partición desde lo a hi
    quickSort(array, lo, j-1);     //Llamada recursiva a la izquierda de pivote
    quickSort(array, j+1, hi);     //Llamada recursiva a la derecha de pivote

}

int particion(int **array, int lo, int hi) {
    int i = lo+1, j = hi, v = array[0][lo];       //Inicializa i, j y pivote
    while (true) {
        while(array[0][i] < v) {       //Checa si arreglo en i es menor que pivote
            i++;        //Incrementa i
        }
        while (array[0][j] > v) {      //Checa si arreglo en j es mayor que pivote
            j--;        //Incrementa j
        }
        if(j <= i) {        //Si se cruzan i y j se terminó
            swap(array, j,lo);      //Se cambia pivote con j
            break;
        } else {
            swap(array, i,j);       //Se hace el intercambio de i y j
            i++;        //Evitan loop infinito por valores repetidos
            j--;        // ^^
        }
    }
    return j;
}


#endif

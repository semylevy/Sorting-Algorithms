#include <iostream>
#include "sorting_algorithms.h"
#include "array_generation.h"

using namespace std;

int main() {
    int *arr1, n;
    n = 11;
    
    arr1 = newRandomArray(n);
    printArray(arr1, n);
    
    bucketSort(&arr1, n);
    printArray(arr1, n);
    
    return 1;
}

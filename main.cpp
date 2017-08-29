#include <iostream>
#include "sorting_algorithms.h"
#include "extra_functions.h"

using namespace std;

int main() {
    int *arr1, n;
    n = 10;
    
    arr1 = newRandomArray(n);
    //printArray(arr1, n);
    
    //getRuntime(countingSort, &arr1, n);
    //arr1 = newRandomArray(n);
    //getRuntime(bucketSort, &arr1, n);
    
    radixSort(&arr1, n);
    //printArray(arr1, n);
    
    return 1;
}

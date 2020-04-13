#include <stdio.h>
#include <assert.h>
#include "binary_search.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int arrSize = 15;

    assert(binarySearch(arr, arrSize, 5) == 4);
    assert(binarySearchRecursive(arr, 0, arrSize-1, 13) == 12);
    assert(binarySearch(arr, arrSize, 16) == -1);
    assert(binarySearchRecursive(arr, 0, arrSize-1, 17) == -1);

    return 0;
}
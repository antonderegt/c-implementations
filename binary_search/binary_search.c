#include "binary_search.h"

int binarySearch(int* arr, int arrSize, int value) {
    int min = 0, max = arrSize - 1, mid;

    while(max >= min) {
        mid = (min + max) / 2;
        if(arr[mid] == value) {
            return mid;
        } else if(value < arr[mid]) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }

    return -1;
}

int binarySearchRecursive(int* arr, int min, int max, int value) {
    int mid = (min + max) / 2;
    if(max < min) {
        return -1;
    } else if(arr[mid] == value) {
        return mid;
    } else if(value < arr[mid]) {
        return binarySearchRecursive(arr, min, mid - 1, value);
    } else {
        return binarySearchRecursive(arr, mid + 1, max, value);
    }
}
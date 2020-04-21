#include "quick_sort.h"

void print_array(int* array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void swap(int* array, int low, int high) {
    int temp = array[low];
    array[low] = array[high];
    array[high] = temp;
}

void partition(int* array, int low, int high) {
    if(high - low <= 2) return;

    int mid = low + (high - low) / 2;
    int pivot = array[mid], i = low, j = high - 1;
    printf("Pivot: %d selected, moving it to the end\n", pivot);
    swap(array, mid, high);
    print_array(array, 10);
    while(i < j) {
        while(array[i] < pivot) {
            i++;
        }
        while(array[j] > pivot && i < j) {
            j--;
        }

        // printf("i: %d - %d, j: %d - %d\n", i, array[i], j, array[j]);
        swap(array, i, j);
    }
    swap(array, i, high);
    // print_array(array, 10);
    partition(array, low, mid + 1);
    partition(array, mid + 1, high);
}

void quick_sort(int* array, int size) {
    partition(array, 0, size - 1);
}
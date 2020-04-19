#include "merge_sort.h"

void print_array(int* array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int* array, int begin, int mid, int end) {

}

void merge_sort(int* array, int begin, int end) {
    if(begin < end) {
        int mid = begin + (end - begin) / 2;
        merge_sort(array, begin, mid);
        merge_sort(array, mid + 1, end);

        merge(array, begin, mid, end);
    }
}
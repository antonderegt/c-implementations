#include "merge_sort.h"

void print_array(int* array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int* array, int begin, int mid, int end) {
    int size = end - begin + 1;
    int temp[size];
    int begin2 = mid + 1;
    int i = begin;
    int j = begin2;
    int k = 0;
    while(i < begin2 && j <= end) {
        if(array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while(i < begin2) temp[k++] = array[i++];
    while(j <= end) temp[k++] = array[j++];

    for(i = 0; i < size; i++) {
        array[begin + i] = temp[i];
    }
}

void merge_split(int* array, int begin, int end) {
    if(begin < end) {
        int mid = begin + (end - begin) / 2;
        merge_split(array, begin, mid);
        merge_split(array, mid + 1, end);

        merge(array, begin, mid, end);
    }
}

void merge_sort(int* array, int size) {
    merge_split(array, 0, size - 1);
}
#include "max_heap.h"
#include <stdio.h>

void sift_up(int* heap, int index) {
    int parent = index % 2 == 0 ? index / 2 : (index - 1) / 2;
    if(heap[parent] < heap[index] && index > 1) {
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        sift_up(heap, parent);
    }
}

void insert(int* heap, int value) {
    if(*heap == 0) {
        *heap = 1;
        *(heap + 1) = value;
    } else {
        (*heap)++;
        *(heap + (*heap)) = value;
        sift_up(heap, *heap);
    }
}

void print_heap(int* heap) {
    printf("Printing heap:\n\n");
    for(int i = 1; i < heap[0]; i++) {
        printf("%d\t", heap[i]);
    }
    printf("\n");
}
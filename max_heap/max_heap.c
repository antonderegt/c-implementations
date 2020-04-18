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

int get_max(int* heap) {
    return heap[1];
}

int get_size(int* heap) {
    return heap[0];
}

bool is_empty(int* heap) {
    return !heap[0];
}

int max(int a, int b) {
    return a > b ? a : b;
}

void sift_down(int* heap, int index) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int biggestChild = max(heap[left], heap[right]);
    if(heap[index] < heap[biggestChild]) {
        int temp = heap[index];
        heap[index] = heap[biggestChild];
        heap[biggestChild] = temp;
        sift_down(heap, biggestChild);
    }
}

int extract_max(int* heap) {
    if(heap[0] == 0) {
        return 0;
    }

    int max = heap[1];
    int size = heap[0];
    heap[1] = heap[size]; 
    heap[0]--;
    sift_down(heap, 1);

    return max;
}
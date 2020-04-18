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
    if(heap[0] == 0) {
        heap[0] = 1;
        heap[1] = value;
    } else {
        heap[0]++;
        int size = heap[0];
        heap[size] = value;
        sift_up(heap, size);
    }
}

void print_heap(int* heap) {
    if(heap[0] == 0) return;
    printf("Printing heap:\n");
    for(int i = 1; i <= heap[0]; i++) {
        printf("%d\t", heap[i]);
    }
    printf("\n\n");
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
    if(heap[0] > index * 2) {
        int left = 2 * index;
        int right = 2 * index + 1;
        int biggestChild = max(heap[left], heap[right]);
        if(heap[index] < heap[biggestChild]) {
            int temp = heap[index];
            heap[index] = heap[biggestChild];
            heap[biggestChild] = temp;
            sift_down(heap, biggestChild);
        }
    } else if (heap[0] >= index * 2) {
        int left = 2 * index;
        if(heap[index] < heap[left]) {
            int temp = heap[index];
            heap[index] = heap[left];
            heap[left] = temp;
            sift_down(heap, left);
        }
    }
}

int extract_max(int* heap) {
    if(heap[0] == 0) {
        return 0;
    }

    int max = heap[1];

    remove_node(heap, 1);

    return max;
}

void remove_node(int* heap, int index) {
    int size = heap[0];
    if(size == 0 || index > size) return;

    heap[index] = heap[size]; 
    heap[0] = size - 1;
    sift_down(heap, index);
}
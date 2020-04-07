#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void initVector(struct vector *v, int *arr, int arrSize) {
    int size = 16, i;
    while(size < arrSize) {
        size = 2 * size;
    }
    int *initArray = (int*) malloc(size * sizeof(int));
    for(i = 0; i < arrSize; i++) {
        initArray[i] = arr[i];
    }
    v->array = initArray; 
    v->size = arrSize;
    v->capacity = size;
}

int size(struct vector *v) {
    return v->size;
}

int capacity(struct vector *v) {
    return v->capacity;
}
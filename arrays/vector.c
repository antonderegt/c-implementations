#include "vector.h"

vector initVector(int arrSize) {
    int size = 16;
    while(size < arrSize) {
        size = 2 * size;
    }
    vector v;
    int *initArray = (int*) malloc(size * sizeof(int));
    
    v.array = initArray; 
    v.size = arrSize;
    v.capacity = size;

    return v;
}

int size(vector *v) {
    return v->size;
}

int capacity(vector *v) {
    return v->capacity;
}
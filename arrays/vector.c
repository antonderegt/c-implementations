#include "vector.h"

vector initVector(int arrSize) {
    int size = 16;
    while(size < arrSize) {
        size = 2 * size;
    }
    vector v;
    int *initArray = (int*) malloc(size * sizeof(int));
    
    v.array = initArray; 
    v.size = 0;
    v.capacity = size;

    return v;
}

int size(vector *v) {
    return v->size;
}

int capacity(vector *v) {
    return v->capacity;
}

bool isEmpty(vector *v) {
    return !v->size;
}

int at(vector *v, int index) {
    if(index < v->size) {
        return v->array[index];
    } else {
        return -1;
    }
}

void push(vector *v, int item) {
    if(v->size < v->capacity) {
        v->array[v->size++] = item;
    } else {
        resize(v, v->capacity * 2);
        push(v, item);
    }
}

void resize(vector *v, int newCapacity){
    v->array = (int *)realloc(v->array, newCapacity);
    v->capacity = newCapacity;
}
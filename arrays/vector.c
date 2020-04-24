#include "vector.h"

const int minCapacity = 16;

vector *initVector(int arrSize) {
    int size = minCapacity;
    while(size < arrSize) {
        size = 2 * size;
    }
    vector *v = malloc(sizeof(vector));
    int *initArray = (int*) malloc(size * sizeof(int));
    
    v->array = initArray; 
    v->size = 0;
    v->capacity = size;

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
        return *(v->array + index);
    } else {
        return -1;
    }
}

void push(vector *v, int item) {
    if(v->size < v->capacity) {
        int size = v->size++;
        *(v->array + size) = item;
    } else {
        resize(v, v->capacity * 2);
        push(v, item);
    }
}

void resize(vector *v, int newCapacity){
    v->array = (int *)realloc(v->array, newCapacity);
    v->capacity = newCapacity;
}

int pop(vector *v) {
    int size = --v->size;
    int popValue = *(v->array + size);
    if(v->size <= (v->capacity/4) && v->size/2 >= minCapacity) {
        resize(v, v->size/2);
    }
    return popValue;
}

void insert(vector *v, int index, int item) {
    if(v->size < v->capacity) {
        for(int i = v->size; i > index; i--) {
            *(v->array + i) = *(v->array + i - 1);
        }
        *(v->array + index) = item;
        v->size++;
    } else {
        resize(v, v->capacity * 2);
        insert(v, index, item);
    } 
}

void prepend(vector *v, int item) {
    insert(v, 0, item);
}

void deleteAt(vector *v, int index) {
    if(v->size - 1 == index) {
        pop(v);
    } 
    else if(index < v->size) {
        for(int i = index; i < v->size-1; i++) {
            *(v->array + i) = *(v->array + i + 1);
        }
        v->size--;
        if(v->size <= (v->capacity/4) && v->size/2 >= minCapacity) {
            resize(v, v->size/2);
        }
    }
}

int find(vector *v, int item) {
    for(int i = 0; i < v->size; i++) {
        if (*(v->array + i) == item) {
            return i;
        }
    }
    return -1;
}

void findRemove(vector *v, int item) {
    int index;
    while((index = find(v, item)) != -1) {
        deleteAt(v, index);
    }
}